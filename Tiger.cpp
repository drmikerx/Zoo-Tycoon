/******************************************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Michael Childress
** Date: 4/25/2018
** Description: This is the implementation file for the Tiger class. Beyond the members
inherited from the Animal class, it has its own constructor and a costToFeedTiger
function, which are detailed below.
******************************************************************************************/


#include "Animal.hpp"
#include "Tiger.hpp"

/*****************************************************************************************
** Description: The tiger constructor calls the necessary set functions to set the
member variables to tiger specific values.  It also passes an integer argument to the
base class constructor, which sets the value of the age member variable.
*****************************************************************************************/

Tiger::Tiger(int startAge) : Animal(startAge)
{
	setCost(10000);	// Tiger costs $10,000
	setNumberOfBabies(1);
	setPayoff(2000);	// = 10,000 * 0.20
}

/*****************************************************************************************
** Description: The costToFeedTiger function returns the value stored in the
baseFoodCost member variable times 5 per program requirements.
*****************************************************************************************/

int Tiger::costToFeedTiger()
{
	return getBaseFoodCost() * 5;	// 5 times base food cost
}