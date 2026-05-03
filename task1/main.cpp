#include "warehouse.h"

int main() {
    Warehouse myWarehouse;

    // Инициализация пустых ячеек (зоны А, Б, В)

    string zones[] = {"А", "Б", "В"};
    for (const string& zone : zones) {
        for (int s = 1; s <= 14; ++s) {
            for (int sec = 1; sec <= 4; ++sec) {
                for (int p = 1; p <= 8; ++p) {
                    string addr = zone + to_string(s) + to_string(sec) + to_string(p);
                    myWarehouse.cells[addr] = Cell();
                }
            }
        }
    }

    string cmd, name, addr;
    int qty;

    while (cin >> cmd && cmd != "EXIT") {
        if (cmd == "ADD") {
            cin >> name >> qty >> addr;
            addProduct(myWarehouse, name, qty, addr);
        } else if (cmd == "REMOVE") {
            cin >> name >> qty >> addr;
            removeProduct(myWarehouse, name, qty, addr);
        } else if (cmd == "INFO") {
            showInfo(myWarehouse);
        }
    }
    return 0;
}