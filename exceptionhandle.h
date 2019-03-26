#pragma once

#include <iostream>
#define NoRequirment 0;
template <typename T>


//Overview
/*********************************************************************************************************
Function list:

Function definition: promptAndInput(prompt, input)
Function utility: Allows input from the user quickly with no exception handling
Function warning: *Not recommended* *No handeling*

Function definition: promptAndLogInputInRange(prompt, userInput, lowestValue, highestValue)
Function utility: Allows input from the user within a numeric range
Function warning: *does not prevent alphabetical input* *No float controll*

Function definition: promptAndLogAsNumeric(const char* prompt, varT userInput)
Function utility: Allows input from the user by preventing alphabetical input
Function warning: *does not check for range* *No float controll*

Function definition: promptAndLogInputInRangeAsNumeric(prompt, userInput, lowestValue, highestValue)
Function utility: Allows input from the user by preventing aphabetical input along with range control
Function warning: *Inputs with a number then a charactar(s) will truncate the charactar(s)* *No float control*

Function definition: promptAndLogInputInRangeAsInterger(prompt, userInput, lowestValue, highestValue)
Function Utility: Allows input from the user by allowing only an interger to be inputed with range control
Function warning: *Inputs with a number then a charactar(s) will truncate the charactar(s)*

Notes:

Note: When creating a handle object the type that is returned by the called functions
must be specified as so...

Handle<int> handle

where int is the return type of the functions called from the handle object

**********************************************************************************************************/


class Handle {

public:

	T promptAndInput(const char* prompt, T userInput) {
		logPrompt(prompt);
		userInput = logInput(userInput);
		return userInput;
	}

	T promptAndLogInputInRange(const char* prompt, T userInput, double lowestValue, double highestValue) {
		userInput = promptAndInput(prompt, userInput);

		while (checkRange(userInput, lowestValue, highestValue)) {
			logPrompt(prompt);
			userInput = logInput(userInput);

		}
		return userInput;
	}

	T promptAndLogAsNumeric(const char* prompt, T userInput) {
		userInput = promptAndInput(prompt, userInput);

		while (checkAlpha()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			logPrompt(prompt);
			userInput = logInput(userInput);

		}

		return userInput;
	}

	T promptAndLogInputInRangeAsNumeric(const char* prompt, T userInput, double lowestValue, double highestValue) {
		userInput = promptAndInput(prompt, userInput);

		while (checkAlpha() || checkRange(userInput, lowestValue, highestValue)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			logPrompt(prompt);
			userInput = logInput(userInput);

		}

		return userInput;
	}

	int promptAndLogInputInRangeAsInterger(const char* prompt, double lowestValue, double highestValue) {
		double userInputAsDouble;
		userInputAsDouble = promptAndInput(prompt, userInputAsDouble);

		while (checkAlpha() || checkRange(userInputAsDouble, lowestValue, highestValue) || checkIfDecimal(userInputAsDouble)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			logPrompt(prompt);
			userInputAsDouble = logInput(userInputAsDouble);
		}

		return userInputAsDouble;
	}

	T promptAndLogUnique(const char* prompt, T userInput, bool alphaCheck, double lowestValue, double highestValue) {
		userInput = promptAndInput(prompt, userInput);

		while (checkAlpha() || checkRange(userInput, lowestValue, highestValue) || checkIfDecimal(userInput)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			logPrompt(prompt);
			userInput = logInput(userInput);
		}

		return userInput;

	}

private:

	void logPrompt(const char* prompt) {
		std::cout << prompt;
	}

	T logInput(T userInput) {
		std::cin >> userInput;
		return userInput;
	}

	bool checkAlpha() {

		if (std::cin.fail())
			return true;

		return false;
	}

	bool checkRange(T userInput, double lowestValue, double highestValue) {

		if (userInput < lowestValue || userInput > highestValue)
			return true;

		return false;
	}

	bool checkIfDecimal(T userInput) {

		if (userInput - trunc(userInput) != 0)
			return true;

		return false;
	}

};