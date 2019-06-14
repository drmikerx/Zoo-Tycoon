/******************************************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Michael Childress
** Date: 4/25/2018
** Description: This is the header file for the Turtle class. It is a child class of the
Animal base class. In addition to the members inherited from the Animal class, it has its
own constructor which sets each of the variables to the turtle specific values, and calls
the base constructor to set the age of the animal. It also has a costToFeedTurtle
function which returns the food cost based on the baseFoodCost.
******************************************************************************************/


#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle : public Animal
{
private:

public:

	Turtle(int startAge);

	int costToFeedTurtle();


};



#endif