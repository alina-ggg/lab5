#include "schedule.h"
#include <iostream>

ScheduleManager::ScheduleManager() {
    resetCalendar();
}

void ScheduleManager::resetCalendar() {
    calendar.assign(daysInMonth[currentMonthIdx], set<string>());
}

void ScheduleManager::addClass(int day, const string& discipline) {
    if (day < 1 || day > daysInMonth[currentMonthIdx]) {
        cout << "Ошибка: В этом месяце всего " << daysInMonth[currentMonthIdx] << " дней" << endl;
        return;
    }
    if (calendar[day - 1].count(discipline)) {
        cout << "Ошибка: Дисциплина " << discipline << " уже есть в этот день" << endl;
    } else {
        calendar[day - 1].insert(discipline);
        cout << "Добавлена дисциплина " << discipline << " на день " << day << endl;
    }
}

void ScheduleManager::nextMonth() {
    vector<set<string>> oldCalendar = calendar;
    currentMonthIdx = (currentMonthIdx + 1) % 12;
    int newDays = daysInMonth[currentMonthIdx];

    calendar.assign(newDays, set<string>());

    for (int i = 0; i < oldCalendar.size(); ++i) {
        int targetDay = (i + 1 > newDays) ? newDays : i + 1;
        for (const auto& discipline : oldCalendar[i]) {
            calendar[targetDay - 1].insert(discipline);
        }
    }
    cout << "Переход на следующий месяц" << endl;
}

void ScheduleManager::viewDay(int day) const {
    if (day < 1 || day > daysInMonth[currentMonthIdx]) {
        cout << "Ошибка: В этом месяце всего " << daysInMonth[currentMonthIdx] << " дней" << endl;
        return;
    }
    if (calendar[day - 1].empty()) {
        cout << "В день " << day << " мы свободны!" << endl;
    } else {
        cout << "В день " << day << " занятия в университете: ";
        for (const auto& discipline : calendar[day - 1]) {
            cout << discipline << " ";
        }
        cout << endl;
    }
}