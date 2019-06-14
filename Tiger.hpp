/******************************************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Michael Childress
** Date: 4/25/2018
** Description: This is the header file for the Tiger class. It is a child class of the
Animal base class. In addition to the members inherited from the Animal class, it has its
own constructor which sets each of the variables to the tiger specific values, and calls
the base constructor to set the age of the animal. It also has a costToFeedTiger
function which returns the food cost based on the baseFoodCost.
******************************************************************************************/


#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal
{
	// Will have all variables from animal class (will need to call Animal functions to access)
private:

public:

	// Tiger constructor will pass this argument off to the Animal constructor to set age
	Tiger(int startAge);

	int costToFeedTiger();	// = 10*5

};



#endif
