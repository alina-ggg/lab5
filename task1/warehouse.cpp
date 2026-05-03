#include "warehouse.h"
#include <iomanip>

void addProduct(Warehouse& wh, const string& name, int qty, const string& addr) {
    if (wh.cells.find(addr) == wh.cells.end()) {
        cout << "Ошибка: Неверный адрес " << addr << endl;
        return;
    }

    Cell& cl = wh.cells[addr];
    if (cl.isOccupied && cl.itemName != name) {
        cout << "Ошибка: Ячейка " << addr << " занята товаром " << cl.itemName << endl;
    } else if (cl.quantity + qty > 10) {
        cout << "Ошибка: Превышена вместимость ячейки (максимум 10)" << endl;
    } else {
        cl.itemName = name;
        cl.quantity += qty;
        cl.isOccupied = true;
        cout << "Добавлено " << qty << " " << name << " в " << addr << endl;
    }
}

void removeProduct(Warehouse& wh, const string& name, int qty, const string& addr) {
    if (wh.cells.find(addr) == wh.cells.end() || !wh.cells[addr].isOccupied || wh.cells[addr].itemName != name) {
        cout << "Ошибка: Товар " << name << " не найден в ячейке " << addr << endl;
        return;
    }

    Cell& cl = wh.cells[addr];
    if (cl.quantity < qty) {
        cout << "Ошибка: Недостаточно товаров для удаления" << endl;
    } else {
        cl.quantity -= qty;
        cout << "Удалено " << qty << " " << name << " (остаток: " << cl.quantity << ")" << endl;
        if (cl.quantity == 0) {
            cl.isOccupied = false;
            cl.itemName = "";
        }
    }
}

void showInfo(const Warehouse& wh) {
    int totalStored = 0;
    for (const auto& [addr, cell] : wh.cells) {
        if (cell.isOccupied) totalStored += cell.quantity;
    }

    cout << "Загруженность склада: " << fixed << setprecision(2)
        << (double)totalStored / wh.totalCapacity * 100 << " %" << endl;
    
    cout << "Заполненные ячейки:" << endl;
    for (const auto& [addr, cell] : wh.cells) {
        if (cell.isOccupied) {
            cout << addr << ": " << cell.itemName << " (" << cell.quantity << ")" << endl;
        }
    }

    cout << "Пустые ячейки:" << endl;
    bool foundEmpty = false;
    for (const auto& [addr, cell] : wh.cells) {
        if (!cell.isOccupied) {
            cout << addr << " ";
            foundEmpty = true;
        }
    }
    cout << endl;
}