#include "plane.h"
#include <algorithm>
#include <set>

CommandType parseCommand(const string& cmd) {
    if (cmd == "CREATE_PLANE") return CommandType::CREATE_PLANE;
    if (cmd == "PLANES_FOR_TOWN") return CommandType::PLANES_FOR_TOWN;
    if (cmd == "TOWNS_FOR_PLANE") return CommandType::TOWNS_FOR_PLANE;
    if (cmd == "PLANES") return CommandType::PLANES;
    return CommandType::UNKNOWN;
}

void createPlane(vector<Plane>& planes, const string& name, const vector<string>& towns) {
    // 1. Проверка на уникальность имени
    for (const auto& p : planes) {
        if (p.name == name) {
            cout << "Ошибка: Самолет с именем " << name << " уже создан" << endl;
            return;
        }
    }
    // 2. Проверка количества остановок (минимум 2)
    if (towns.size() < 2) {
        cout << "Ошибка: Самолет не может быть создан с одной остановкой" << endl;
        return;
    }
    // 3. Проверка на одинаковые города в маршруте
    set<std::string> unique_towns(towns.begin(), towns.end());
    if (unique_towns.size() != towns.size()) {
        cout << "Ошибка: Самолет не может быть создан с двумя одинаковыми городами" << endl;
        return;
    }

    planes.push_back({name, towns});
    cout << "Самолет " << name << " создан" << endl;
}

void planesForTown(const vector<Plane>& planes, const string& town) {
    bool found = false;
    vector<string> result;
    for (const auto& p : planes) {
        for (const auto& t : p.towns) {
            if (t == town) {
                result.push_back(p.name);
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Ошибка: Город не найден" << endl;
    } else {
        for (const auto& name : result) cout << name << " ";
        cout << endl;
    }
}

void townsForPlane(const vector<Plane>& planes, const string& planeName) {
    for (const auto& p : planes) {
        if (p.name == planeName) {
            for (const auto& t : p.towns) {
                cout << "Город " << t << ": ";
                bool other_found = false;
                for (const auto& other : planes) {
                    if (other.name != planeName) {
                        for (const auto& ot : other.towns) {
                            if (ot == t) {
                                cout << other.name << " ";
                                other_found = true;
                            }
                        }
                    }
                }
                if (!other_found) cout << "-";
                cout << endl;
            }
            return;
        }
    }
    cout << "Ошибка: Самолет " << planeName << " не найден" << endl;
}

void allPlanes(const vector<Plane>& planes) {
    if (planes.empty()) {
        cout << "Ошибка: Самолеты не найдены" << endl;
        return;
    }
    for (const auto& p : planes) {
        cout << "Самолет " << p.name << ": ";
        for (const auto& t : p.towns) cout << t << " ";
        cout << endl;
    }
}