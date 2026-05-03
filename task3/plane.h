#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum class CommandType {
    CREATE_PLANE,
    PLANES_FOR_TOWN,
    TOWNS_FOR_PLANE,
    PLANES,
    UNKNOWN
};

struct Plane {
    string name;
    vector<string> towns;
};

CommandType parseCommand(const string& cmd);
void createPlane(vector<Plane>& planes, const string& name, const vector<string>& towns);
void planesForTown(const vector<Plane>& planes, const string& towm);
void townsForPlane(const vector<Plane>& planes, const string& planeName);
void allPlanes(const vector<Plane>& planes);

#endif