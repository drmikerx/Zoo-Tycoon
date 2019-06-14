/******************************************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Michael Childress
** Date: 4/25/2018
** Description: This is the implementation file for the Animal class. Please see below
for more function specifics.
******************************************************************************************/


#include "Animal.hpp"

/*****************************************************************************************
** Description: The setAge function accepts an integer argument which it uses to assign
a value to the age member variable.
*****************************************************************************************/

void Animal::setAge(int startingAge)
{
	age = startingAge;
}

/*****************************************************************************************
** Description: The getAge function returns the current value stored in the age member
variable.
*****************************************************************************************/

int Animal::getAge()
{
	return age;
}

/*****************************************************************************************
** Description: The setCost function accepts an integer argument which it uses to assign
a value to the cost member variable.
*****************************************************************************************/

void Animal::setCost(int costOfAnimal)
{
	cost = costOfAnimal;
}

/*****************************************************************************************
** Description: The getCost function returns the current value stored in the cost
member variable.
*****************************************************************************************/

int Animal::getCost()
{
	return cost;
}

/*****************************************************************************************
** Description: The setNumberOfBabies function accepts an integer argument which it uses 
to assign a value to the numberOfBabies member variable.
*****************************************************************************************/

void Animal::setNumberOfBabies(int babiesBorn)
{
	numberOfBabies = babiesBorn;
}

/*****************************************************************************************
** Description: The getNumberOfBabies function returns the current value stored in the
numberOfBabies member variable.
*****************************************************************************************/

int Animal::getNumberOfBabies()
{
	return numberOfBabies;
}

/*****************************************************************************************
** Description: The setBaseFoodCost function accepts an integer argument which it uses to 
assign a value to the baseFoodCost member variable.
*****************************************************************************************/

void Animal::setBaseFoodCost(int baseCostOfFood)
{
	baseFoodCost = baseCostOfFood;
}

/*****************************************************************************************
** Description: The getBaseFoodCost function returns the value currently stored in the
baseFoodCost member variable.
*****************************************************************************************/

int Animal::getBaseFoodCost()
{
	return baseFoodCost;
}

/*****************************************************************************************
** Description: The setPayoff function accepts an integer argument which it uses to assign
a value to the payoff member variable.
*****************************************************************************************/

void Animal::setPayoff(int payoffOfAnimal)
{
	payoff = payoffOfAnimal;
}

/*****************************************************************************************
** Description: The getPayoff function returns the value currently stored in the payoff
member variable.
*****************************************************************************************/

int Animal::getPayoff()
{
	return payoff;
}

/*****************************************************************************************
** Description: The Animal class constructor serves as the base class constructor for
the tiger, penguin, and turtle child classes. It accepts an integer argument that it
uses to pass to the setAge function as an argument to assign the value to the age member 
variable. It also calls the setBaseFoodCost function passing a value of 10 because this 
value is constant by design choice.
*****************************************************************************************/


Animal::Animal(int startAge)
{
	setAge(startAge);
	setBaseFoodCost(10);	// Base food cost is $10 by design choice

	// All other variables will be assigned via set functions in the derived class constructors
}