# ArtefactDnD
My TOGA artefact for the assignment. I decided to upload it to GitHub to practice source control and let other people see it and give me feedback/help

UPDATE FROM UPDATE 2 TO UPDATE 4:
First version of update 4.
Fully working, merging it before starting to do changes on it to have the latest working version on main.

Added since last update:
1. General

Added regions to divide content into more organised sections

Added comments for a lot of the solutions, still on process

2. Display

Created a display class to be able to update any part of the display at any point

Now the display is overwritten using a function that sets the cursor position to overwrite old display instead of "re-drawn" every frame using system("CLS"). Further updates were using this function

New clear functions were made for: console, encounter (bottom), encounter display

Reset function for every time that the screen is fully generated again

Display functions for the new encounter class which were done to easily access their section of the top display

Display function to update the player HP during battle

Updated the display to have player item under player stats (this one was made through using the old function infoDisplay()), now minimum y size of the top display is 22

Right side of the top display is now dedicated to encounter information display. Divided in two, stats of the encounter display and description of the encounter
All encounters display a random description out of 3 options for each.

Colour added to the display

Moved all #defines related to changing display size, like map size setting defines, to the display class

3. Map

Functioning automatic room display until hitting grid border

Player Movement

Player Movement Display

Room Randomizer

One simple map display

Wall check for determining encounters using the room type

Clamping for general use in map

4. Room

Wall storing for checks

Updating the room setting function for randomizing using a switch

5. Encounters

Encounter class to define all the encounters that happen in each room and their results

Difficulty

Enemy encounter to the room type 1

Enemy generation based on difficulty

Basic battle mechanics, including: attacking, dodging and dying.

Healing fountain encounter to the room type 2 and 0

Rolling a D20 was implemented to get good or bad results

Healing mechanic

Item found encounter to the room type 3

Random item generation

Trap encounter to the room type 4

Moved the questionYesOrNo() function to the encounter class

6. Stats

Fixed dodge to return the correct value upon level up

7. Player

Updated display line

Updated the variable 'PDMG' that returns the damage done by the player to take into consideration the player STR, item damage and use DEX to give a random number that will add to it.

Updated player DODGE to also include item range.

8. Objects

Added an overloaded constructor that takes difficulty as a parameter to generate an item with random stats. The higher the difficulty, the higher the possible total stop and the minimum possible value goes up as well.

Took out some of the objects stats as they won't be developed for now, leaving only: name, damage, range and type.

9. Enemy

Enemy class was finally added to be able to generate enemies

Enemies drop a random amount of EXP depending on their level.

Enemy has a boss bool in case a boss is generated for the final boss. Still not implemented.

Enemy has an overloaded constructor that takes difficulty as a parameter to define the enemy level, which changes all the stats, including the possible amount of EXP dropped.

The amount of HP of an enemy is random, using their level to define the cap of it.

10. Game

Started not deleting test functions for later

Updated the infoDisplay() function

Main game loop function defined

Game finishes when the player dies

DISCLAIMER: Some changes may have not been mentioned. Big changes and details from the top of my head were added. Will update more frequently now.
