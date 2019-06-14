/******************************************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Michael Childress
** Date: 4/25/2018
** Description: This is the implementation file for the Turtle class. Beyond the members
inherited from the Animal class, it has its own constructor and a costToFeedTurtle
function, which are detailed below.
******************************************************************************************/


#include "Turtle.hpp"

/*****************************************************************************************
** Description: The turtle constructor calls the necessary set functions to set the
member variables to turtle specific values.  It also passes an integer argument to the
base class constructor, which sets the value of the age member variable.
*****************************************************************************************/

Turtle::Turtle(int startAge) : Animal(startAge)
{
	setCost(100);	// Turtle costs $100
	setNumberOfBabies(10);
	setPayoff(5);	// = 100 * 0.05
}

/*****************************************************************************************
** Description: The costToFeedTurtle function returns one-half the value stored in the
baseFoodCost member variable per program requirements.
*****************************************************************************************/

int Turtle::costToFeedTurtle()
{
	return getBaseFoodCost() * 0.5;	// 50% of base cost
	// Though the result technically becomes a double, I decided to have function simply
	// return int because the result will always be 5
}