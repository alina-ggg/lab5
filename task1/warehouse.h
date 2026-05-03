#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// структура одной ячейки
struct Cell {
    string itemName = "";
    int quantity = 0;
    bool isOccupied = false;
};

// объединение всех ячеек
struct Warehouse {
    map<string, Cell> cells;
    int totalCapacity = 13440;
};

void addProduct(Warehouse& wh, const string& name, int qty, const string& addr);
void removeProduct(Warehouse& wh, const string& name, int qty, const string& addr);
void showInfo(const Warehouse& wh);

#endif