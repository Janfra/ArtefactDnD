#include "Object.h"
#include <string>
// Added <iostream> to be able to cout
#include <iostream>
using namespace std;

Object::Object() {
    name = "Unknown";
    addDMG = 0;
    addRange = 0;
    durability = 0;
    typeOfAttack = "No Type";
    consumable = false;
}

void Object::setTypeOfAttack(string dmgtype) {
    typeOfAttack = dmgtype;
}

string Object::getTypeOfAttack() {
    return typeOfAttack;
}

void Object::setName(string newName) {
    name = newName;
}

string Object::getName() {
    return name;
}

void Object::setDMG(int setDMG) {

    if (setDMG < 1) {
        addDMG = 1;
    }
    else if (setDMG > 100){
        addDMG = 100;
    }
    else {
        addDMG = setDMG;
    }
}

int Object::getDMG() {
    if (addDMG > 99) {
        //cout << "This weapon is too strong!!" << endl;
        name = "Kirito Sword";
        addRange = 2;
    }
    return addDMG;
}

    /* Sets weapon range while automatically setting the type and name of object depending on the range. 
    For efficiency after a tip from a coder I changed the setRange to happen before the switch case so that it 
    would only be changed in the specific cases were it was needed instead of frequently typing it*/
void Object::setRange(int setRange) {
    addRange = setRange;
    switch (setRange) {
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

int Object::getRange() {
    return addRange;
}

// After starting to do this code I realised that HP in objects was kind of weird and decided to go for durability instead, I'll later add an object breaking feature
void Object::setDurability(int setDurability) {
    durability = setDurability;
}

int Object::getDurability() {
    return durability;
}

// May end up making consumables another class entirelly, an Is-A class for object.
void Object::setConsumable(bool setConsumable) {
    consumable = setConsumable;
}

// After having to write more than once this whole line of cout, I decided that I didn't want to keep copy pasting it every time and add it as an object function to save time.
// There was a problem with the getDMG function which was running weirdly and the range wasn't being changed. After some help we got to the conclusion that it would run correctly if 
// the function was called and stored in a variable ahead of time.
void Object::displayInfo(void) {
    int dmg = getDMG();
    cout << "Name: " << getName() << endl << "Damage: " << dmg << endl << "Durability: " 
    << getDurability() << endl << "Range: " << getRange() << endl << "Type: " << getTypeOfAttack() << endl << endl;
}

string Object::displayObjLine(short a)
{
    string rv[5];
    rv[0] = "Name: " + getName();
    rv[1] = "Damage: " + getDMG();
    rv[2] = "Durability: " + getDurability();
    rv[3] = "Range: " + getRange();
    rv[4] = "Type: " + getTypeOfAttack();

    return rv[a];
}

