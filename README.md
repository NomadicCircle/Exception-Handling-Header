# Exception-Handling-Header
This is a header file in c++ containing functions to allow exception handeling for common inputs.

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
