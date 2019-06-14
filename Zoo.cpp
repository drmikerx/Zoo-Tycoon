/******************************************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Michael Childress
** Date: 4/25/2018
** Description: This is the implementation file for the Zoo class. The majority of the
game's functions are found here. Please see below for more specific details.
******************************************************************************************/


#include "Zoo.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

int inputValidationNumber1Or2(string dataToCheck);
int inputValidationEndOfDayAnimalStore(string dataToCheck);

/*****************************************************************************************
** Description: The Zoo constructor calls each of the necessary set functions and passes
predetermined values based on program specifications so that the member variables are
correctly assigned. It also dynamically allocates each of the arrays of Animal*'s and
starts each at a size of 10. Once the array is allocated, each element within it is set
to NULL as NULL will be used to represent an empty slot in the pen.
*****************************************************************************************/

Zoo::Zoo()
{
	setMoneyInBank(100000);	// Starts with $100,000 by design choice
	setCurrentSizeOfTigerPen(10);
	setCurrentSizeOfPenguinPen(10);
	setCurrentSizeOfTurtlePen(10);

	tigerPen = new Animal*[getCurrentSizeOfTigerPen()];	// Each Animal* points to a Tiger object
	penguinPen = new Animal*[getCurrentSizeOfPenguinPen()];	// Each Animal* points to a Penguin object
	turtlePen = new Animal*[getCurrentSizeOfTurtlePen()];	// Each Animal* points to a Turtle object

	// No actual animal objects have been created yet so set all elements to NULL at start

	for (int count = 0; count < getCurrentSizeOfTigerPen(); count++)
	{
		tigerPen[count] = NULL;
	}

	for (int count = 0; count < getCurrentSizeOfPenguinPen(); count++)
	{
		penguinPen[count] = NULL;
	}

	for (int count = 0; count < getCurrentSizeOfTurtlePen(); count++)
	{
		turtlePen[count] = NULL;
	}
}

/*****************************************************************************************
** Description: The Zoo destructor is responsible for freeing the dynamic memory at the
end of the program. It first deletes each of the Tiger, Penguin, and Turtle objects
pointed to by the Animal*'s in the array, and then deletes the actual array of Animal*'s.
*****************************************************************************************/

Zoo::~Zoo()
{
	
	// Needs to free all dynamic memory
	for (int count = 0; count < getCurrentSizeOfTigerPen(); count++)
	{
		if (tigerPen[count] != NULL)	// Only delete elements where an object was actually created
		{
			delete tigerPen[count];	// Delete all dynamically allocated Tiger objects
		}
	}

	for (int count = 0; count < getCurrentSizeOfPenguinPen(); count++)
	{
		if (penguinPen[count] != NULL)
		{
			delete penguinPen[count];	// Delete all dynamically allocated Penguin objects
		}
	}

	for (int count = 0; count < getCurrentSizeOfTurtlePen(); count++)
	{
		if (turtlePen[count] != NULL)
		{
			delete turtlePen[count];	// Delete all dynamically allocated Turtle objects
		}
	}


	// Delete the arrays of Animal*'s

	delete [] tigerPen;
	delete [] penguinPen;
	delete [] turtlePen;
}

/*****************************************************************************************
** Description: setMoneyInBank accepts an integer argument and assigns it to the
appropriate member variable.
*****************************************************************************************/

void Zoo::setMoneyInBank(int startingMoney)
{
	moneyInBank = startingMoney;
}

/*****************************************************************************************
** Description: getMoneyInBank returns the current value stored in the moneyInBank
variable.
*****************************************************************************************/

int Zoo::getMoneyInBank()
{
	return moneyInBank;
}

/*****************************************************************************************
** Description: setCurrentSizeOfTigerPen accepts an integer argument and assigns it to the
appropriate member variable.
*****************************************************************************************/

void Zoo::setCurrentSizeOfTigerPen(int tigerPenSize)
{
	currentSizeOfTigerPen = tigerPenSize;
}

/*****************************************************************************************
** Description: getCurrentSizeOfTigerPen returns the current value stored in the
currentSizeOfTigerPen member variable.
*****************************************************************************************/

int Zoo::getCurrentSizeOfTigerPen()
{
	return currentSizeOfTigerPen;
}

/*****************************************************************************************
** Description: setCurrentSizeOfPenguinPen accepts an integer argument and assigns it to 
the appropriate member variable.
*****************************************************************************************/

void Zoo::setCurrentSizeOfPenguinPen(int penguinPenSize)
{
	currentSizeOfPenguinPen = penguinPenSize;
}

/*****************************************************************************************
** Description: getCurrentSizeOfPenguinPen returns the current value stored in the
currentSizeOfPenguinPen member variable.
*****************************************************************************************/

int Zoo::getCurrentSizeOfPenguinPen()
{
	return currentSizeOfPenguinPen;
}

/*****************************************************************************************
** Description: setCurrentSizeOfTurtlePen accepts an integer argument and assigns it to 
the appropriate member variable.
*****************************************************************************************/

void Zoo::setCurrentSizeOfTurtlePen(int turtlePenSize)
{
	currentSizeOfTurtlePen = turtlePenSize;
}

/*****************************************************************************************
** Description: getCurrentSizeOfTurtlePen returns the current value stored in the
currentSizeOfTurtlePen member variable.
*****************************************************************************************/

int Zoo::getCurrentSizeOfTurtlePen()
{
	return currentSizeOfTurtlePen;
}

/*****************************************************************************************
** Description: The startingAnimalStore is called at the beginning of the game and asks
the user to input the desired number of animals to start with. Each type needs to have
either 1 or 2 purchased per program specifications. All input is validated through
various functions. Once input is obtained, the appropriate Animal type objects are
created and their cost is subtracted from the moneyInBank.
*****************************************************************************************/

void Zoo::startingAnimalStore()
{
	string startingTigers;
	int startingTigersValidated;

	string startingPenguins;
	int startingPenguinsValidated;

	string startingTurtles;
	int startingTurtlesValidated;

	// Get starting tigers

	cout << "\nPlease input the number of Tigers desired. Each one costs $10,000. "
		<< "\nFor the first buy, this number must be either 1 or 2." << endl;
	getline(cin, startingTigers);

	while (startingTigers.empty())
	{
		cout << "No data input. Try again." << endl;
		getline(cin, startingTigers);
	}

	startingTigersValidated = inputValidationNumber1Or2(startingTigers);


	// Get starting penguins

	cout << "\nPlease input the number of Penguins desired. Each one costs $1,000. "
		<< "\nFor the first buy, this number must be either 1 or 2." << endl;
	getline(cin, startingPenguins);

	while (startingPenguins.empty())
	{
		cout << "No data input. Try again." << endl;
		getline(cin, startingPenguins);
	}

	startingPenguinsValidated = inputValidationNumber1Or2(startingPenguins);


	// Get starting turtles

	cout << "\nPlease input the number of Turtles desired. Each one costs $100. "
		<< "\nFor the first buy, this number must be either 1 or 2." << endl;
	getline(cin, startingTurtles);

	while (startingTurtles.empty())
	{
		cout << "No data input. Try again." << endl;
		getline(cin, startingTurtles);
	}

	startingTurtlesValidated = inputValidationNumber1Or2(startingTurtles);


	// Add the new animals to their respective pens
	// Since first time getting animals we know elements 0 and 1 of array are open

	for (int count = 0; count < startingTigersValidated; count++)
	{
		tigerPen[count] = new Tiger(1);	// Each tiger is 1 day old
	}

	for (int count = 0; count < startingPenguinsValidated; count++)
	{
		penguinPen[count] = new Penguin(1);	// Each penguin is 1 day old
	}

	for (int count = 0; count < startingTurtlesValidated; count++)
	{
		turtlePen[count] = new Turtle(1);	// Each turtle is 1 day old
	}

	// Subtract the cost of each animal from the current moneyInBank

	this->moneyInBank -= startingTigersValidated * tigerPen[0]->getCost();
	this->moneyInBank -= startingPenguinsValidated * penguinPen[0]->getCost();
	this->moneyInBank -= startingTurtlesValidated * turtlePen[0]->getCost();

}

/*****************************************************************************************
** Description: The continueMenu function is called at the end of each day and asks the
user whether they want to continue or not. If they do, the function returns true which
causes the do while loop in the runGame function to continue. If they do not wish to
continue, the function returns false, thus ending the loop. All user input is validated.
*****************************************************************************************/

bool Zoo::continueMenu()
{
	string userChoice;
	int userChoiceValidated;

	cout << "\nYou have reached the end of the day. Would you like to continue playing?" << endl;
	cout << "1. Keep Playing" << endl;
	cout << "2. End The Game" << endl;
	getline(cin, userChoice);

	while (userChoice.empty())
	{
		cout << "No data input. Try again." << endl;
		getline(cin, userChoice);
	}

	userChoiceValidated = inputValidationNumber1Or2(userChoice);

	if (userChoiceValidated == 1)
	{
		return true;
	}

	else
	{
		return false;
	}

}

/*****************************************************************************************
** Description: The countAnimalsInPen function is called any time another function needs
to know how many objects are present in the given pen. It receives the appropriate array
of Animal*'s and the current size of that array as arguments. It then goes through each
element of the array and increments a counter each time an object is found. An object is
considered found when that array location does not equal NULL. The function then returns
the integer value from this counter variable back to the calling function.
*****************************************************************************************/

int Zoo::countAnimalsInPen(Animal** penToCheck, int currentSizeOfPen)
{
	int numberOfAnimals = 0;

	for (int i = 0; i < currentSizeOfPen; i++)
	{
		if (penToCheck[i] != NULL)
		{
			numberOfAnimals++;
		}
	}


	return numberOfAnimals;
}

/*****************************************************************************************
** Description: The animalAgeUp function is called at the beginning of each day to age
each of the current animals by 1 day. It receives the array of Animal*'s and the current
size of the array as arguments and any time an Animal pointer is not NULL, it calls the
setAge function for that object and increases the current value by 1.
*****************************************************************************************/

void Zoo::animalAgeUp(Animal** penToAge, int currentSizeOfPen)
{
	for (int i = 0; i < currentSizeOfPen; i++)
	{
		if (penToAge[i] != NULL)
		{
			penToAge[i]->setAge(penToAge[i]->getAge() + 1);	// Increase the age of animal by 1 day
		}
	}

}

/*****************************************************************************************
** Description: The increasePenSize function is called any time an animal is added to the
pen and the current array is full. It receives the array of Animal*'s and the current
size of the array as arguments by reference. It then puts the current size into a local 
variable, and doubles the original current size variable. Then it dynamically allocates a 
new array that is twice as big as the original, initialzes each Animal* to NULL and then 
copies all values from the previous array into the new one. Lastly, it deletes the old 
array, and assigns the original Animal** to the newly created double sized array.
*****************************************************************************************/

// This gets called if it was found that the pen was full (in addAnimalToPen or the baby function)
void Zoo::increasePenSize(Animal** & penToIncrease, int & currentSizeOfPen)
{
	int originalArraySize = currentSizeOfPen;
	currentSizeOfPen *= 2;	// Current size of pen set to twice its original value


	Animal** newArray = new Animal*[currentSizeOfPen];	// Should have twice the spaces

	for (int count = 0; count < currentSizeOfPen; count++)	// Initialize all new slots to NULL
	{
		newArray[count] = NULL;
	}
	
	
	for (int count = 0; count < originalArraySize; count++)
	{
		newArray[count] = penToIncrease[count];	// Copy previous values to new array
	}

	

	delete[] penToIncrease;	// Delete old array
	penToIncrease = newArray;	// Now points to new array
	
}

/*****************************************************************************************
** Description: The payFeedingCostTigers function accepts the tigerPen and the current
size of the tigerPen as arguments. It then counts how many tigers there are, and
multiplies this number by the value stored in the costToFeedTiger member variable and
returns the total charge to the calling function.
*****************************************************************************************/

int Zoo::payFeedingCostTigers(Animal** penToCharge, int currentSizeOfPen)
{
	int numberOfAnimals;
	int totalCharge;

	numberOfAnimals = countAnimalsInPen(penToCharge, currentSizeOfPen);

	if (penToCharge[0] != NULL)
	{
		totalCharge = static_cast<Tiger*>(penToCharge[0])->costToFeedTiger() * numberOfAnimals;
		// Needed to cast the Animal pointer to a Tiger* to access the Tiger specific costToFeedFunction
		return totalCharge;
	}

	// If no tigers left
	else
	{
		return 0;
	}
}

/*****************************************************************************************
** Description: The payFeedingCostPenguins function accepts the penguinPen and the current
size of the penguinPen as arguments. It then counts how many penguins there are, and
multiplies this number by the value stored in the costToFeedPenguin member variable and
returns the total charge to the calling function.
*****************************************************************************************/

int Zoo::payFeedingCostPenguins(Animal** penToCharge, int currentSizeOfPen)
{
	int numberOfAnimals;
	int totalCharge;

	numberOfAnimals = countAnimalsInPen(penToCharge, currentSizeOfPen);

	if (penToCharge[0] != NULL)
	{
		totalCharge = static_cast<Penguin*>(penToCharge[0])->costToFeedPenguin() * numberOfAnimals;
		// Needed to cast the Animal pointer to a Penguin* to access the Penguin specific costToFeedFunction
		return totalCharge;
	}

	// If no penguins left
	else
	{
		return 0;
	}

}

/*****************************************************************************************
** Description: The payFeedingCostTurtles function accepts the turtlePen and the current
size of the turtlePen as arguments. It then counts how many turtles there are, and
multiplies this number by the value stored in the costToFeedTurtle member variable and
returns the total charge to the calling function.
*****************************************************************************************/

int Zoo::payFeedingCostTurtles(Animal** penToCharge, int currentSizeOfPen)
{
	int numberOfAnimals;
	int totalCharge;

	numberOfAnimals = countAnimalsInPen(penToCharge, currentSizeOfPen);

	if (penToCharge[0] != NULL)
	{
		totalCharge = static_cast<Turtle*>(penToCharge[0])->costToFeedTurtle() * numberOfAnimals;
		// Needed to cast the Animal pointer to a Turtle* to access the Turtle specific costToFeedFunction
		return totalCharge;
	}

	// If no turtles left
	else
	{
		return 0;
	}

}

/*****************************************************************************************
** Description: The calculateProft function accepts an array of Animal*'s and the current
size of that array as arguments. It then counts the number of objects in that array and
uses this to calculate the total payoff generated by that particular type of animal. It
returns this integer value back to the calling function.
*****************************************************************************************/

int Zoo::calculateProfit(Animal** penToCalculate, int currentSizeOfPen)
{
	int numberOfAnimals;
	int totalProfit;

	numberOfAnimals = countAnimalsInPen(penToCalculate, currentSizeOfPen);

	if (penToCalculate[0] != NULL)
	{
		totalProfit = penToCalculate[0]->getPayoff() * numberOfAnimals;
		
		return totalProfit;
	}

	// If no animals left
	else
	{
		return 0;
	}

}

/*****************************************************************************************
** Description: The addAnimalToPen function is called when the user has bought an adult
animal from the end of day store. It accepts the array of Animal*'s and current size of
the array by reference so these values can be changed by the increasePenSize function if
needed. It also accepts an integer argument that represents the user's choice from the
store. It first counts the number of animals currently in the pen. If it is full, it calls
the increasePenSize function. Once this is complete, it adds 1 animal of the appropriate
type to the designated array. The animals start at age 3 days per program specification.
*****************************************************************************************/

void Zoo::addAnimalToPen(Animal** &penToAdd, int & currentSizeOfPen, int animalChosen)
{
	int numberOfAnimals;

	numberOfAnimals = countAnimalsInPen(penToAdd, currentSizeOfPen);

	if (numberOfAnimals == currentSizeOfPen)	// If all spots in array are occupied
	{
		increasePenSize(penToAdd, currentSizeOfPen);	// This will double the array size to accept new animal
	}


	if (animalChosen == 1)	// They picked tiger
	{
		penToAdd[numberOfAnimals] = new Tiger(3);
	}

	else if (animalChosen == 2)	// They picked penguin
	{
		penToAdd[numberOfAnimals] = new Penguin(3);
	}

	else if (animalChosen == 3)	// They picked turtle
	{
		penToAdd[numberOfAnimals] = new Turtle(3);
	}

}

/*****************************************************************************************
** Description: The randomEvent function receives all 3 of the Animal* arrays and their
sizes by reference. Reference is used primarily in the case of the babyBorn event at
which time it may be necessary to increase the size of that array to accommodate all of
the babies. It first generates a random number between 1 and 3 and uses this to determine
what random event will occur. If 1 is picked, sickness occurs and the sicknessEvent
function is called. If 2 is picked, the tiger bonus event occurs and the attendanceBoom
function is called. If 3 is picked the baby born event occurs and the babyBorn function
is called. Otherwise, the nothing happens event occurs. The randomEvent function has a 
return type of integer to accommodate the case where there is a tiger bonus. It is able 
to return this value in that case. Otherwise, it returns 0 since there was no bonus.
*****************************************************************************************/

int Zoo::randomEvent(Animal** & tigerPen, int& sizeOfTigerPen, Animal**& penguinPen, int& sizeOfPenguinPen, 
	Animal**& turtlePen, int& sizeOfTurtlePen)
{
	int eventToPick;

	eventToPick = randomNumberGeneratorForEvent();

	if (eventToPick == 1)
	{
		// sickness
		cout << "An animal has become sick." << endl;
		sicknessEvent(tigerPen, sizeOfTigerPen, penguinPen, sizeOfPenguinPen, turtlePen, sizeOfTurtlePen);
		return 0;
	}

	else if (eventToPick == 2)
	{
		int tigerBonus;
		// Tiger bonus
		cout << "A boom in zoo attendance has occurred. You get a bonus for each tiger you own." << endl;
		tigerBonus = attendanceBoom(tigerPen, sizeOfTigerPen);
		return tigerBonus;
	}

	else if (eventToPick == 3)
	{
		// Baby born
		cout << "A baby animal has been born." << endl;
		babyBorn(tigerPen, sizeOfTigerPen, penguinPen, sizeOfPenguinPen, turtlePen, sizeOfTurtlePen);
		return 0;
	}

	else
	{
		cout << "Nothing happens." << endl;
		return 0;
	}
}

/*****************************************************************************************
** Description: The randomNumberGeneratorForEvent function generates a random number
between 1 and 4 and returns this integer to the randomEvent function to determine the
event that will occur.
*****************************************************************************************/

int Zoo::randomNumberGeneratorForEvent()
{
	int randomNumber;      // the value accounting for range of 1 to 4
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 4;

	randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + 1;

	return randomNumber;
}

/*****************************************************************************************
** Description: The attendanceBoom function receives the tigerPen and the current size
of the tigerPen as arguments and first generates a random number between 250 and 500 for
the bonus per tiger. It then counts the number of tigers, displays the information to the
user and returns the total bonus to the calling function.
*****************************************************************************************/

int Zoo::attendanceBoom(Animal** tigerPen, int sizeOfTigerPen)
{
	int bonusPerTiger;
	int numberOfTigers;

	bonusPerTiger = randomNumberGeneratorForTigerBonus();
	numberOfTigers = countAnimalsInPen(tigerPen, sizeOfTigerPen);

	cout << "You receive $" << bonusPerTiger << " for each of your " << numberOfTigers 
		<< " tigers!" << endl;

	return bonusPerTiger * numberOfTigers;
}

/*****************************************************************************************
** Description: The randomNumberGeneratorForTigerBonus function generates a random number
between 250 and 500 and sends this integer back to the calling function to be used as
the bonus per tiger amount in the attendance boom event.
*****************************************************************************************/

int Zoo::randomNumberGeneratorForTigerBonus()
{
	int randomNumber;      // the value accounting for range of 250 to 500
	const int MIN_VALUE = 250;
	const int MAX_VALUE = 500;

	randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + 250;

	return randomNumber;
}

/*****************************************************************************************
** Description: The randomNumberGeneratorPickAnimal function is called anytime an animal
type needs to be selected randomly. It generates a random number between 1 and 3 and
returns this integer to the calling function.
*****************************************************************************************/

int Zoo::randomNumberGeneratorPickAnimal()
{
	int randomNumber;      // the value accounting for range of 1 to 3
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 3;

	randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + 1;

	return randomNumber;
}

/*****************************************************************************************
** Description: The sicknessEvent function is used to implement the sickness event. It
receives all 3 of the Animal* arrays and their sizes as arguments. It first makes sure
there are animals of each type present. If not, their respective bool variable gets set
to false so that type will not be used in the event. It then randomly picks an available
animal type and removes the last object in the appropriate array by making it NULL. If 
the type had no animals left, a new random number is generated until a match is found.
Once a match is found and the animal object removed, all bool variables are then set to 
false so the do while loop will end.
*****************************************************************************************/


void Zoo::sicknessEvent(Animal** tigerPen, int sizeOfTigerPen, Animal** penguinPen, int sizeOfPenguinPen, 
	Animal** turtlePen, int sizeOfTurtlePen)
{
	int animalTypeToDie;
	int numberOfTigers;
	int numberOfPenguins;
	int numberOfTurtles;

	bool tigersAvailable = true;
	bool penguinsAvailable = true;
	bool turtlesAvailable = true;


	// Have to ensure there is at least 1 animal available to die
	numberOfTigers = countAnimalsInPen(tigerPen, sizeOfTigerPen);
	numberOfPenguins = countAnimalsInPen(penguinPen, sizeOfPenguinPen);
	numberOfTurtles = countAnimalsInPen(turtlePen, sizeOfTurtlePen);

	if (numberOfTigers == 0)
	{
		tigersAvailable = false;
	}

	if (numberOfPenguins == 0)
	{
		penguinsAvailable = false;
	}

	if (numberOfTurtles == 0)
	{
		turtlesAvailable = false;
	}

	// Keep checking for an animal to die until one found, or it's shown that no animals available to die
	do 
	{
		animalTypeToDie = randomNumberGeneratorPickAnimal();

		if (animalTypeToDie == 1 && tigersAvailable)
		{
			// Tiger dies
			cout << "A tiger has died of sickness." << endl;
			delete tigerPen[numberOfTigers - 1];	// Delete old animal
			tigerPen[numberOfTigers - 1] = NULL;	// Remove last tiger from array
			penguinsAvailable = false;	// Once one animal has been killed we want to ensure the while loop ends
			turtlesAvailable = false;
			tigersAvailable = false;
		}

		else if (animalTypeToDie == 2 && penguinsAvailable)
		{
			// Penguin dies
			cout << "A penguin has died of sickness." << endl;
			delete penguinPen[numberOfPenguins - 1];
			penguinPen[numberOfPenguins - 1] = NULL;	// Remove last penguin from array
			penguinsAvailable = false;
			turtlesAvailable = false;
			tigersAvailable = false;
		}

		else if (animalTypeToDie == 3 && turtlesAvailable)
		{
			// Turtle dies
			cout << "A turtle has died of sickness." << endl;
			delete turtlePen[numberOfTurtles - 1];
			turtlePen[numberOfTurtles - 1] = NULL;	// Remove last turtle from array
			penguinsAvailable = false;
			turtlesAvailable = false;
			tigersAvailable = false;
		}


	} while (tigersAvailable && penguinsAvailable && turtlesAvailable);

}

/*****************************************************************************************
** Description: The babyBorn function is used to implement the baby born event. It
accepts all 3 Animal* arrays and their sizes by reference in case the array size needs
to be increased to accommodate the new babies. It first ensures that an animal of at
least age 3 is present in the zoo. If no adults are present, all bools
get set to false so the while loop will never run, and a message is displayed. If adults
are present a while loop begins where a random number is chosen and consequently a type
of animal is chosen to have babies. It then calls the addBabiesToPen function to add the
new animals and sets the continueLoop bool to false to end the loop.
*****************************************************************************************/


void Zoo::babyBorn(Animal**& tigerPen, int& sizeOfTigerPen, Animal**& penguinPen, int& sizeOfPenguinPen, 
	Animal**& turtlePen, int& sizeOfTurtlePen)
{
	int animalPicked;
	bool adultTiger;
	bool adultPenguin;
	bool adultTurtle;

	adultTiger = scanForAdult(tigerPen, sizeOfTigerPen);
	adultPenguin = scanForAdult(penguinPen, sizeOfPenguinPen);
	adultTurtle = scanForAdult(turtlePen, sizeOfTurtlePen);

	bool continueLoop = true;

	if (adultTiger == false && adultPenguin == false && adultTurtle == false)
	{
		cout << "You had no adult animals in your zoo yet. No baby born." << endl;
		continueLoop = false;	// If no adults, exit loop right away
	}

	while (continueLoop)
	{
		animalPicked = randomNumberGeneratorPickAnimal();

		if (animalPicked == 1 && adultTiger)	// tiger
		{
			cout << "A tiger has had 1 baby!" << endl;
			addBabiesToPen(tigerPen, sizeOfTigerPen, 1);
			continueLoop = false;
		}

		else if (animalPicked == 2 && adultPenguin)	// penguin
		{
			cout << "A penguin has had 5 babies!" << endl;
			addBabiesToPen(penguinPen, sizeOfPenguinPen, 2);
			continueLoop = false;
		}

		else if (animalPicked == 3 && adultTurtle)	// turtle
		{
			cout << "A turtle has had 10 babies!" << endl;
			addBabiesToPen(turtlePen, sizeOfTurtlePen, 3);
			continueLoop = false;
		}

	}

}

/*****************************************************************************************
** Description: The addBabiesToPen function accepts an Animal* array and size of the
array as arguments by reference in case the array size needs to increase, and also an
integer argument representing the type of animal that will be born. Using this information
it counts the number of animals currently present of that type and calls increasePenSize
if needed to accommodate the new babies. It then adds a number of animals equal to the 
numberOfBabies variable for that type and initializes them to age 0 per program 
specifications.
*****************************************************************************************/

void Zoo::addBabiesToPen(Animal**& penToAdd, int& currentSizeOfPen, int animalChosen)
{
	int numberOfAnimals;

	numberOfAnimals = countAnimalsInPen(penToAdd, currentSizeOfPen);


	if (animalChosen == 1)	// They picked tiger
	{
		// Tiger adds one baby so just have to make sure there's one space
		if (numberOfAnimals == currentSizeOfPen)	// If all spots in array are occupied
		{
			increasePenSize(penToAdd, currentSizeOfPen);	// This will double the array size to accept new animal
		}

		if (penToAdd[0] != NULL)
		{
			for (int count = 0; count < penToAdd[0]->getNumberOfBabies(); count++)
			{
				penToAdd[numberOfAnimals] = new Tiger(0);	// Baby starts at age 0
			}
		}
	}

	else if (animalChosen == 2)	// They picked penguin
	{
		if (penToAdd[currentSizeOfPen - 5] != NULL)	// There needs to be at least 5 spaces open to accommadate babies
		{
			increasePenSize(penToAdd, currentSizeOfPen);
		}

		if (penToAdd[0] != NULL)
		{
			for (int count = 0; count < penToAdd[0]->getNumberOfBabies(); count++)
			{
				penToAdd[numberOfAnimals] = new Penguin(0);
				numberOfAnimals++;	// Keep moving one space to the right in the array
			}
		}
	}

	else if (animalChosen == 3)	// They picked turtle
	{
		if (penToAdd[currentSizeOfPen - 10] != NULL)	// Need at least 10 spaces open to accommodate the babies
		{
			increasePenSize(penToAdd, currentSizeOfPen);
		}

		if (penToAdd[0] != NULL)
		{
			for (int count = 0; count < penToAdd[0]->getNumberOfBabies(); count++)
			{
				penToAdd[numberOfAnimals] = new Turtle(0);
				numberOfAnimals++;
			}
		}
	}

}

/*****************************************************************************************
** Description: The scanForAdult function is used by the babyBorn function to determine
if the given animal type has any adults present. It accepts an Animal* array and its
size as arguments. It then scans each element of the array, specifically the value stored 
in the age variable of each object. If it finds one adult (age >=3) it will return true. 
Otherwise, it will return false.
*****************************************************************************************/

bool Zoo::scanForAdult(Animal** penToScan, int sizeOfPen)
{
	bool adultFound = false;

	for (int count = 0; count < sizeOfPen; count++)
	{
		if (penToScan[count] != NULL)
		{
			if (penToScan[count]->getAge() >= 3)	// Adult found
			{
				adultFound = true;
			}
		}
	}

	return adultFound;
}

/*****************************************************************************************
** Description: The endOfDayAnimalStore function is called at the end of each day of the
game. It asks the user specify a type of animal to purchase. This input is validated and
then the integer is returned to the calling function.
*****************************************************************************************/

int Zoo::endOfDayAnimalStore()
{
	string chosenAnimal;
	int chosenAnimalValidated;

	cout << "\nYou have chosen to visit the adult animal store." << endl;
	cout << "You currently have $" << this->moneyInBank << endl;
	cout << "Please choose one of the following options:" << endl;

	cout << "\n1. Buy a tiger ($10,000)" << endl;
	cout << "2. Buy a penguin ($1,000)" << endl;
	cout << "3. Buy a turtle ($100)" << endl;
	cout << "4. Buy nothing" << endl;

	getline(cin, chosenAnimal);

	while (chosenAnimal.empty())
	{
		cout << "No data input. Try again." << endl;
		getline(cin, chosenAnimal);
	}

	chosenAnimalValidated = inputValidationEndOfDayAnimalStore(chosenAnimal);

	return chosenAnimalValidated;

}

/*****************************************************************************************
** Description: The runGame function, once called from the main function, implements
each day of the game in a do while loop. Animals are aged by one day at the start, feeding
costs are determined and subtracted from the moneyInBank variable, and a random event
takes place. After the event, the daily profit is calculated and added to the moneyInBank
variable. The function then determines if the user has any money left. If they don't
a bool variable gets set to false so the do while loop will end. Otherwise, the end of
day store is shown and the appropriate animal is added to its pen after which its cost
is subtracted from the moneyInBank variable. The function again determines if the user
has any money left. If not a bool variable gets set to false to end the do while loop.
After this, the current zoo stats are shown and the dayNumber variable is incremented.
Lastly, the continue menu is shown and the user is asked whether they want to continue 
or not. If they do, the process repeats. If not, the program will end.
*****************************************************************************************/

void Zoo::runGame()
{
	int dayNumber = 1;
	bool keepPlaying = true;	// Becomes false if user picks quit or runs out of money
	bool stillHasMoney = true;
	int feedingCostOfTigers;
	int feedingCostOfPenguins;
	int feedingCostOfTurtles;
	int payOffTigers;
	int payOffPenguins;
	int payOffTurtles;
	int totalProfit;
	int tigerBonus;

	// The game runs in a loop
	do
	{
		cout << "\n\n\nWelcome to Day " << dayNumber << "!" << endl;
		cout << "\nThe age of all of your animals has increased by 1 day." << endl;

		// Call the age increase functions
		animalAgeUp(tigerPen, currentSizeOfTigerPen);
		animalAgeUp(penguinPen, currentSizeOfPenguinPen);
		animalAgeUp(turtlePen, currentSizeOfTurtlePen);


		// Pay the feeding cost of each animal

		feedingCostOfTigers = payFeedingCostTigers(tigerPen, currentSizeOfTigerPen);
		feedingCostOfPenguins = payFeedingCostPenguins(penguinPen, currentSizeOfPenguinPen);
		feedingCostOfTurtles = payFeedingCostTurtles(turtlePen, currentSizeOfTurtlePen);

		// Subtract amount from bank
		this->moneyInBank -= (feedingCostOfTigers + feedingCostOfPenguins + feedingCostOfTurtles);
		cout << "\nAfter feeding all of your animals, your current amount of money is: $"
			<< this->moneyInBank << endl;

		// Random event takes place
		cout << "\nA event takes place...." << endl;

		tigerBonus = randomEvent(tigerPen, currentSizeOfTigerPen, penguinPen, currentSizeOfPenguinPen, 
			turtlePen, currentSizeOfTurtlePen);

		payOffTigers = calculateProfit(tigerPen, currentSizeOfTigerPen);
		payOffPenguins = calculateProfit(penguinPen, currentSizeOfPenguinPen);
		payOffTurtles = calculateProfit(turtlePen, currentSizeOfTurtlePen);

		cout << "\nYour animals produced the following payoffs for today:" << endl;
		cout << "Tigers: $" << payOffTigers << "  " << "Penguins: $" << payOffPenguins << "  "
			<< "Turtles: $" << payOffTurtles << endl;

		cout << "Bonus from tigers: $" << tigerBonus << endl;

		totalProfit = payOffTigers + payOffPenguins + payOffTurtles + tigerBonus;
		cout << "Your total profit for the day is: $" << totalProfit << endl;
		this->moneyInBank += totalProfit;


		// Check to see if they still have money
		if (this->moneyInBank <= 0)
		{
			stillHasMoney = false;
			cout << "\nSorry, you have run out of money. The game is over." << endl;
		}

		// If they still had money they can visit the animal store
		else
		{
			string wantsToBuyAnimal;
			int wantsToBuyAnimalValidated;

			cout << "\nBefore the day ends, you have the option of buying an adult animal."
				<< " Would you like to do so?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			getline(cin, wantsToBuyAnimal);

			while (wantsToBuyAnimal.empty())
			{
				cout << "No data input. Try again." << endl;
				getline(cin, wantsToBuyAnimal);
			}

			wantsToBuyAnimalValidated = inputValidationNumber1Or2(wantsToBuyAnimal);

			if (wantsToBuyAnimalValidated == 1)
			{

				int animalChosen = endOfDayAnimalStore();

				if (animalChosen == 1)	// They picked tiger
				{
					addAnimalToPen(tigerPen, currentSizeOfTigerPen, animalChosen);	// This fxn will be able to resize pen if needed

					if (tigerPen[0] != NULL)
					{
						this->moneyInBank -= tigerPen[0]->getCost();
					}
				}

				else if (animalChosen == 2)	// They picked penguin
				{
					addAnimalToPen(penguinPen, currentSizeOfPenguinPen, animalChosen);

					if (penguinPen[0] != NULL)
					{
						this->moneyInBank -= penguinPen[0]->getCost();
					}
				}

				else if (animalChosen == 3)	// They picked turtle
				{
					addAnimalToPen(turtlePen, currentSizeOfTurtlePen, animalChosen);

					if (turtlePen[0] != NULL)
					{
						this->moneyInBank -= turtlePen[0]->getCost();
					}
				}
			}

			else
			{
				cout << "\nOk, you have skipped the animal store for today." << endl;
			}
		}

		cout << "\nAt the end of the day you have $ " << this->moneyInBank << endl;

		if (this->moneyInBank <= 0)
		{
			stillHasMoney = false;
			cout << "\nSorry, you have run out of money. The game is over." << endl;
		}

		
		cout << "\n\nThe number of turtles is now: " << countAnimalsInPen(turtlePen, currentSizeOfTurtlePen) << endl;
		cout << "The current size of the turtle pen is: " << currentSizeOfTurtlePen << endl;
		cout << "\n\nThe number of tigers is now: " << countAnimalsInPen(tigerPen, currentSizeOfTigerPen) << endl;
		cout << "The current size of the tiger pen is: " << currentSizeOfTigerPen << endl;
		cout << "\n\nThe number of penguins is now: " << countAnimalsInPen(penguinPen, currentSizeOfPenguinPen) << endl;
		cout << "The current size of the penguin pen is: " << currentSizeOfPenguinPen << endl;
		

		dayNumber++;

	} while (stillHasMoney == true && continueMenu());


}