/******************************************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Michael Childress
** Date: 4/25/2018
** Description: This is the implementation file for the main function. Since several
random number generators are used by the Zoo Tycoon program, srand is seeded using time.
The function then creates a Zoo object that contains the necessary functions to run the
game. After displaying a welcome message, the starting store is called for initial user
input. After this, the player's money remaining is displayed and the runGame function is
called which takes over the remainder of the operations. When the main function ends, the
Zoo destructor is called to free all dynamic memory used during the game.
******************************************************************************************/


#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>
#include <ctime>

#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Zoo.hpp"

// Need to seed rand() here for the random number generator

int main()
{
	unsigned seed;         // srand expects an unsigned integer
	seed = time(0);        // seed set to changing value of time
	srand(seed);           // initiating seed in srand

	Zoo zooTycoon;

	cout << "Welcome to Zoo Tycoon. You are the owner of a new zoo and have $"
		<< zooTycoon.getMoneyInBank() << " to start. First you need to buy some animals.\n"
		<< endl;

	zooTycoon.startingAnimalStore();	// Player chooses either 1 or 2 of each animal type

	cout << "\nAfter your inital purchases, the money you have left is: $" << zooTycoon.getMoneyInBank()
		<< endl;

	zooTycoon.runGame();


	return 0;
}