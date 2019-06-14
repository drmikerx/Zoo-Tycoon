/******************************************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Michael Childress
** Date: 4/25/2018
** Description: This is the implementation file for the Penguin class. Beyond the members
inherited from the Animal class, it has its own constructor and a costToFeedPenguin
function, which are detailed below.
******************************************************************************************/


#include "Penguin.hpp"

/*****************************************************************************************
** Description: The penguin constructor calls the necessary set functions to set the
member variables to penguin specific values.  It also passes an integer argument to the
base class constructor, which sets the value of the age member variable.
*****************************************************************************************/

Penguin::Penguin(int startAge) : Animal(startAge)
{
	setCost(1000);	// Penguin costs $1,000
	setNumberOfBabies(5);
	setPayoff(100);	// = 1,000 * 0.10
}

/*****************************************************************************************
** Description: The costToFeedPenguin function returns the value stored in the
baseFoodCost member variable per program requirements.
*****************************************************************************************/

int Penguin::costToFeedPenguin()
{
	return getBaseFoodCost();	// cost to feed penguin is the same as the base cost
}