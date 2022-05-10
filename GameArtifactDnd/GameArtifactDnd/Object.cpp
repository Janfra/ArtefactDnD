#include "Object.h"
#include <string>
// Added <iostream> to be able to cout
#include <iostream>
using namespace std;

 #pragma region Constructor & Destructor

Object::Object() 
{
    // Initiating Variables //
    name = "Unknown";
    addDMG = 1;
    addRange = 1;
    typeOfAttack = "No Type";
}

// Overloaded constructor to randomly set the items variables. Parameter 'difficulty' adds to the minimun result possible.  
Object::Object(short difficulty) 
{
    // Initiating Variables //
    name = "Random";
    addDMG = (rand() % 10) + 1 + difficulty;
    setRange((rand() % 5));
}

#pragma endregion

 #pragma region Setters & Getters
    // SETTERS // 
// Sets the 'typeOfAttack' variable of the object to the 'dmgType' parameter.
void Object::setTypeOfAttack(string dmgType) 
{
    typeOfAttack = dmgType;
}

// Sets the 'name' variable to 'newName' parameter. 
void Object::setName(string newName) 
{
    name = newName;
}

// Sets 'addDMG' variable to 'setDMG' parameter.
void Object::setDMG(int setDMG) 
{
    if (setDMG < 1) 
    {
        addDMG = 1;
    }
    else if (setDMG > 100) 
    {
        addDMG = 100;
    }
    else 
    {
        addDMG = setDMG;
    }
}

/* For efficiency after a tip from a coder I changed the setRange to happen before the switch case so that it
would only be changed in the specific cases were it was needed instead of frequently typing it*/

// Sets the 'addRange' variable to 'setRange' parameter. Then depending on the parameter given it sets the objects name and type of attack.
void Object::setRange(int setRange) 
{
    addRange = setRange;
    switch (setRange) 
    {
    case 1:
        name = "Dagger";
        typeOfAttack = "Short Range";
        break;
    case 2:
        name = "Sword";
        typeOfAttack = "Normal Range";
        break;
    case 3:
        name = "Spear";
        typeOfAttack = "Long Range";
        break;
    case 4:
        name = "Bow";
        typeOfAttack = "Long Distance Attack";
        break;
    default:
        name = "Dagger";
        typeOfAttack = "Short Range";
        addRange = 1;
        break;
    }
}

// GETTERS //
// Returns type of attack of the object.
string Object::getTypeOfAttack() 
{
    return typeOfAttack;
}

// Returns name of the object.
string Object::getName() 
{
    return name;
}

// Returns damage addition of the object. If the 'addDMG' variable exceeds 99 changes the objects type.
int Object::getDMG() 
{
    if (addDMG > 99) 
    {
        addRange = 2;
        name = "Kirito Sword";
    }
    return addDMG;
}

// Returns range of the object.
int Object::getRange() 
{
    return addRange;
}

#pragma endregion

 #pragma region Object Functions

// Returns a string depending on the 'lineNumber' parameter given. 
string Object::displayObjLine(short lineNumber)
{
    if (lineNumber >= 3) 
    {
        lineNumber = 3;
    }
    if (lineNumber < 0) 
    {
        lineNumber = 0;
    }
    string rv[4];
    rv[0] = "+ Name: " + getName();
    rv[1] = "+ Damage: " + to_string(getDMG());
    rv[2] = "+ Range: " + to_string(getRange());
    rv[3] = "+ Type: " + getTypeOfAttack();

    return rv[lineNumber];
}

// Couts the stats sheet of the object. 
void Object::displayInfo(void) 
{
    int dmg = getDMG();
    cout << "Name: " << getName() << endl << "Damage: " << dmg << endl << "Range: " << getRange() << endl << "Type: " << getTypeOfAttack() << endl << endl;
}

#pragma endregion

 #pragma region Outdated
        // I'LL LEAVE THIS, BUT IN THE END THE displayInfo() FUNCTION WAS USED
    // After having to write more than once this whole line of cout, I decided that I didn't want to keep copy pasting it every time and add it as an object function to save time.
// There was a problem with the getDMG function which was running weirdly and the range wasn't being changed. After some help we got to the conclusion that it would run correctly if 
// the function was called and stored in a variable ahead of time.

#pragma endregion