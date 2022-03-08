#pragma once
#include <string>
using namespace std;

class Object {
    // Will further divide this in the future
public:
    Object();

    void setTypeOfAttack(string dmgtype);
    string getTypeOfAttack();
    void setName(string newName);
    string getName();
    void setDMG(int setDMG);
    int getDMG();
    void setRange(int setRange);
    int getRange();
    void setDurability(int setDurability);
    int getDurability();
    void setConsumable(bool setConsumable);
    void displayInfo(void);
    string displayObjLine(short a);

private:
    string name;
    string typeOfAttack;
    int addDMG;
    int addRange;
    int durability;
    bool consumable;
};

