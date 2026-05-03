#include <iostream>
#include <string>
#include "schedule.h"

int main() {
    ScheduleManager manager;
    int n;
    cout << "Введите количество запросов (N): ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == "CLASS") {
            int day;
            string discipline;
            cin >> day >> discipline;
            manager.addClass(day, discipline);
        } else if (command == "NEXT") {
            manager.nextMonth();
        } else if (command == "VIEW") {
            int day;
            cin >> day;
            manager.viewDay(day);
        }
    }
    return 0;
}