/******************************************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Michael Childress
** Date: 4/25/2018
** Description: This is the implementation file for the various input validiation
functions used by the Zoo Tycoon program. Please see below for more detailed information.
******************************************************************************************/


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::stoi;

/*****************************************************************************************
** Description: The inputValidationNumber1Or2 function is called anytime input validation
is needed and the user was choosing between two choices. It accepts the input as a string
argument and first checks to see whether the user actually entered anything. If not, an
error displays and the user is reprompted. The function then checks to make sure all the
characters entered were digits. If they were not all digits, the user is reprompted. If
all characters were digits, the string is converted to an integer by the stoi function.
The last step is to check that the number entered was either 1 or 2. If not, the user is
reprompted. If everything is fine, the function returns the validated integer to the
calling function for processing.
*****************************************************************************************/

int inputValidationNumber1Or2(string dataToCheck)
{
	bool validSentinel = false;
	int checkedData;

	while (validSentinel == false)
	{
		bool allDigits = true;

		// Help with catching empty user input from:
		// https://stackoverflow.com/questions/4999650/c-how-do-i-check-if-the-cin-buffer-is-empty
		while (dataToCheck.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, dataToCheck);
		}

		for (unsigned int count = 0; count < dataToCheck.length(); count++)
		{
			if (!isdigit(dataToCheck[count]))
			{
				allDigits = false;
			}

		}


		if (allDigits == false)
		{
			cout << "Error: this was not a correct integer. It must be 1 or 2." << endl;
			getline(cin, dataToCheck);
		}

		else if (allDigits == true)
		{
			checkedData = stoi(dataToCheck);

			if (checkedData != 1 && checkedData != 2)
			{
				cout << "Error: this integer was not in range. It must be 1 or 2." << endl;
				getline(cin, dataToCheck);
			}

			else
			{
				validSentinel = true;
			}
		}

	}

	return checkedData;
}

/*****************************************************************************************
** Description: The inputValidationEndOfDayAnimalStore function is called from the end of 
day store for input validation. The user was choosing between four choices. It accepts 
the input as a string argument and first checks to see whether the user actually entered 
anything. If not, an error displays and the user is reprompted. The function then checks 
to make sure all the characters entered were digits. If they were not all digits, the 
user is reprompted. If all characters were digits, the string is converted to an integer 
by the stoi function. The last step is to check that the number entered was 1, 2, 3, 
or 4. If not, the user is reprompted. If everything is fine, the function returns the 
validated integer to the calling function for processing.
*****************************************************************************************/

int inputValidationEndOfDayAnimalStore(string dataToCheck)
{
	bool validSentinel = false;
	int checkedData;

	while (validSentinel == false)
	{
		bool allDigits = true;

		// Help with catching empty user input from:
		// https://stackoverflow.com/questions/4999650/c-how-do-i-check-if-the-cin-buffer-is-empty
		while (dataToCheck.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, dataToCheck);
		}

		for (unsigned int count = 0; count < dataToCheck.length(); count++)
		{
			if (!isdigit(dataToCheck[count]))
			{
				allDigits = false;
			}

		}


		if (allDigits == false)
		{
			cout << "Error: this was not a correct integer. It must be 1, 2, 3, or 4." << endl;
			getline(cin, dataToCheck);
		}

		else if (allDigits == true)
		{
			checkedData = stoi(dataToCheck);

			if (checkedData < 1 || checkedData > 4)
			{
				cout << "Error: this integer was not in range. It must be 1, 2, 3, or 4." << endl;
				getline(cin, dataToCheck);
			}

			else
			{
				validSentinel = true;
			}
		}

	}

	return checkedData;

}