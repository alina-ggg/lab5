#include "container.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>

int main() {
    int maxWeight, sectionCount;

    cout << "Введите максимальный размер стека: ";
    cin >> maxWeight;
    cout << "Введите количество секций судна: ";
    cin >> sectionCount;

    vector<stack<Container>> stacks;
    string command;

    while (cin >> command && command != "LOAD") {
        string id;
        int weight;
        cin >> id >> weight;
        handleArrive(stacks, maxWeight, id, weight);
    }

    handleLoad(stacks, sectionCount);
}