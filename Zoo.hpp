/******************************************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Michael Childress
** Date: 4/25/2018
** Description: This is the header file for the Zoo class. It has a moneyInBank variable
that represents the player's current funds available, as well as 3 Animal**'s which
represent one "pen" for each animal type in the zoo. They will be used as arrays of
Animal*'s and each Animal* will point to an object of type Tiger, Penguin, or Turtle.
The class also has variables to keep track of the size of each pen as it will change if
it becomes full. The Zoo constructor dynamically allocates each of the arrays, and the
Zoo destructor sees to their deletion. See the implementation file for more details on
the other functions.
******************************************************************************************/


#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"

class Zoo
{
private:
	int moneyInBank;	// starts at 100,000 by design choice
	Animal** tigerPen;	// These Animal**'s will be assigned addresses in Zoo constructor
	Animal** penguinPen;
	Animal** turtlePen;

	int currentSizeOfTigerPen;	// These variables start at 10 and increase as needed
	int currentSizeOfPenguinPen;
	int currentSizeOfTurtlePen;

public:
	Zoo();	// Constructor
	~Zoo();	// Destructor

	void setMoneyInBank(int);
	int getMoneyInBank();

	void setCurrentSizeOfTigerPen(int);
	int getCurrentSizeOfTigerPen();

	void setCurrentSizeOfPenguinPen(int);
	int getCurrentSizeOfPenguinPen();

	void setCurrentSizeOfTurtlePen(int);
	int getCurrentSizeOfTurtlePen();

	void startingAnimalStore();
	bool continueMenu();

	int countAnimalsInPen(Animal**, int);

	void animalAgeUp(Animal**, int);

	void increasePenSize(Animal**&, int&);
	
	int payFeedingCostTigers(Animal**, int);
	int payFeedingCostPenguins(Animal**, int);
	int payFeedingCostTurtles(Animal**, int);

	int calculateProfit(Animal**, int);

	void addAnimalToPen(Animal**&, int&, int);

	int randomEvent(Animal**&, int&, Animal**&, int&, Animal**&, int&);
	int randomNumberGeneratorForEvent();

	int attendanceBoom(Animal**, int);
	void sicknessEvent(Animal**, int, Animal**, int, Animal**, int);
	void babyBorn(Animal**&, int&, Animal**&, int&, Animal**&, int&);
	void addBabiesToPen(Animal**&, int&, int);
	int randomNumberGeneratorForTigerBonus();
	int randomNumberGeneratorPickAnimal();

	bool scanForAdult(Animal**, int);

	int endOfDayAnimalStore();

	void runGame();

};



#endif
