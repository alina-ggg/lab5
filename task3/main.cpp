#include "plane.h"
#include <iostream>
#include <sstream>

int main() {
    vector<Plane> planes;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string cmdStr, name;
        ss >> cmdStr;

        CommandType cmd = parseCommand(cmdStr);

        switch (cmd) {
            case CommandType::CREATE_PLANE: {
                int n;
                ss >> name >> n;
                vector<string> towns(n);
                for (auto& t : towns) ss >> t;
                createPlane(planes, name, towns);
                break;
            }
            case CommandType::PLANES_FOR_TOWN: {
                string town;
                ss >> town;
                planesForTown(planes, town);
                break;
            }
            case CommandType::TOWNS_FOR_PLANE:{
                ss >> name;
                townsForPlane(planes, name);
                break;
            }
            case CommandType::PLANES: {
                allPlanes(planes);
                break;
            }
            default:
                cout << "Неизвестная команда" << endl;
        }
    }
    return 0;
}