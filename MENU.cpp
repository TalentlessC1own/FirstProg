#include "MENU.h"

int AskMenuItem()
{
	int ChosenItem = 0;

	std::cout << "1 - Input by console" << std::endl;
	std::cout << "2 - Input by file" << std::endl;

	ChosenItem = CheckMenuItem(2);

	return ChosenItem;
}



int AskToQuitOrToStay()
{
	int ChosenItem = 0;

	std::cout << "1 - To end the program" << std::endl <<
		"2 - To run the program again" << std::endl; 
		

	ChosenItem = CheckMenuItem(3);
	return ChosenItem;
}

int AskOutputType()
{
	int ChosenItem = 0;

	std::cout << "1 - Console output \n2 - File output" << std::endl << std::endl;

	ChosenItem = CheckMenuItem(2);
	return ChosenItem;
}

int AskToSaveOrNotToSave()
{
	int ChosenItem = 0;

	std::cout << "Would you like to save the data?" << std::endl << "1 - Yes \n2 - No" << std::endl;

	ChosenItem = CheckMenuItem(2);
	return ChosenItem;
}