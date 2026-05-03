#ifndef CONTAINER_H
#define CONTAINER

#include <vector>
#include <stack>
#include <string>

using namespace std;

struct Container {
    string id;
    int weight;
};

// Функция для обработки прибытия контейнера
void handleArrive(vector<stack<Container>>& stacks, int maxWeight, const string& id, int weight);
// Функция для распределения контейнеров на судно
void handleLoad(vector<stack<Container>>& stacks, int sectionCount);
#endif