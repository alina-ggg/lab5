#include "container.h"
#include <iostream>
#include <algorithm>

void handleArrive(vector<stack<Container>>& stacks, int maxWeight, const string& id, int weight) {
    bool placed = false;
    int stackIndex = 1;

    for (auto& s : stacks) {
        int currentWeight = 0;
        stack<Container> temp = s;
        while (!temp.empty()) {
            currentWeight += temp.top().weight;
            temp.pop();
        }

        if (currentWeight + weight <= maxWeight) {
            s.push({id, weight});
            cout << "Контейнер " << id << " размещен в стек " << stackIndex << endl;
            placed = true;
            break;
        }
        stackIndex++;
    }

    if (!placed) {
        stack<Container> newStack;
        newStack.push({id, weight});
        stacks.push_back(newStack);
        cout << "Контейнер " << id << " размещен в стек " << stackIndex << endl;
    }
}

void handleLoad(vector<stack<Container>>& stacks, int sectionCount){
    struct Section {
        int totalWeight = 0;
        vector<string> containerIds;
    };

    vector<Section> sections(sectionCount);

    // Цикл, пока хотя бы в одном стеке есть контейнеры
    bool containersRemaining = true;
    while (containersRemaining) {
        containersRemaining = false;

        // Проходим по всем стекам по порядку
        for (auto it = stacks.rbegin(); it != stacks.rend(); ++it) {
            auto& s = *it;
            if (!s.empty()) {
                Container current = s.top();
                s.pop();
                containersRemaining = true;

                // поиск минимальной секции и добавление 
                int minIdx = 0;
                for (int i = 1; i < sectionCount; ++i) {
                    if (sections[i].totalWeight < sections[minIdx].totalWeight) {
                    minIdx = i;
                    }
                }
        
                sections[minIdx].totalWeight += current.weight;
                sections[minIdx].containerIds.push_back(current.id);
            }
        }
    }
    
    int i = 1;
    for (const auto& sec : sections) {
        cout << "Секция " << i++ << " (" << sec.totalWeight << " тонн):";
        
        for (size_t j = 0; j < sec.containerIds.size(); ++j) {
            cout << " " << sec.containerIds[j] << (j < sec.containerIds.size() - 1 ? "," : "");
        }
        cout << endl;
    }
}