#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>
#include <set>

using namespace std;

struct ScheduleManager {
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currentMonthIdx = 0; // 0 - январь
    vector<set<string>> calendar;

    ScheduleManager();
    void resetCalendar();
    void addClass(int day, const string& discipline);
    void nextMonth();
    void viewDay(int day) const;
};

#endif