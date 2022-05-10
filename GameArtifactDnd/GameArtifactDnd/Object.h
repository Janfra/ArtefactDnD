#pragma once
#include <string>
#include <time.h>
using namespace std;

class Object {
public:
 #pragma region Constructor & Destructor

    Object();

    Object(short difficulty);

#pragma endregion

 #pragma region Setters & Getters
    // SETTERS //

    void setTypeOfAttack(string dmgtype);
    void setName(string newName);
    void setDMG(int newDMG);
    void setRange(int newRange);

    // GETTERS // 

    string getTypeOfAttack();
    string getName();
    int getDMG();
    int getRange();

#pragma endregion

 #pragma region Objects Functions

    // Display Function
    string displayObjLine(short lineNumber);

#pragma endregion

 #pragma region Outdated

    void displayInfo(void);

#pragma endregion

private:
    // Stores the object's name 
    string name;
    // Stores the type of attack dealt by the object
    string typeOfAttack;
    // Stores the amount of damage that will be added when using this object
    int addDMG;
    // Stores the amount of bonus to dodge that will be given when using this object
    int addRange;
};

