#pragma once
#include <string>
using namespace std;

class Object {
    // Will further divide this in the future
public:
 #pragma region Constructor & Destructor

    Object();

#pragma endregion

 #pragma region Setters & Getters
    // SETTERS //

    void setTypeOfAttack(string dmgtype);
    void setName(string newName);
    void setDMG(int setDMG);
    void setRange(int setRange);

    // GETTERS // 

    string getTypeOfAttack();
    string getName();
    int getDMG();
    int getRange();

#pragma endregion

 #pragma region Objects Functions

    string displayObjLine(short a);

#pragma endregion

 #pragma region Outdated

    void displayInfo(void);

#pragma endregion

private:
    string name;
    string typeOfAttack;
    int addDMG;
    int addRange;
};

