/******************************************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Michael Childress
** Date: 4/25/2018
** Description: This is the header file for the Animal class.  It serves as the base
class for the Tiger, Penguin, and Turtle classes. The variables, age, cost, numberOfBabies,
baseFoodCost, and payoff are inherited by all the child classes. It also has set and get
functions for each variable and a constructor that sets the age of the animal.
******************************************************************************************/


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
private:
	int age;
	int cost;
	int numberOfBabies;
	int baseFoodCost;	// Same value for all animal objects created
	int payoff;


public:
	void setAge(int);
	int getAge();

	void setCost(int);
	int getCost();

	void setNumberOfBabies(int);
	int getNumberOfBabies();

	void setBaseFoodCost(int);
	int getBaseFoodCost();

	void setPayoff(int);
	int getPayoff();

	Animal(int startAge);	// Constructor


};




#endif
