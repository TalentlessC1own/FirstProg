#include <iostream>
#include "EMPLOYEE.h"
#include "InputOutput.h"
#include "CheckingFunctions.h"
#include "MENU.h"
#include <array>

#include <windows.h>

enum class HowToInput 
{
	ByConsole = 1,
	ByFile
};

enum class List
{
	ByYOE = 1,
	ByS,
	ByPos
};

enum class Quit
{
	Yes = 1,
	No
};

int main()

{	
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);   
	SetConsoleOutputCP(1251);

	//std::cout << "Tap Enter buttom";
	while (true) {
		
		
		ShowGreeting();
		
		HowToInput InputMenu = static_cast<HowToInput>(AskMenuItem());

		EMPLOYEE* arr = nullptr;
		int count = 0;
		//std::cin.clear();
		//std::cin.ignore();
		switch (InputMenu)
		{

		case HowToInput::ByConsole:
		{
			std::cout << "Enter a count of employees:" << std::endl;
			count = CheckInt();
			arr = Console(count);
			

			break;
		}


		case HowToInput::ByFile:
		{
			arr = File(count);
			
			break;
		}
		}

		if (InputMenu == HowToInput::ByConsole)
		{

			Quit SaveOrNot = static_cast<Quit>(AskToSaveOrNotToSave());

			switch (SaveOrNot)
			{
			case Quit::Yes:
			{
				InitialFileOutput(arr, count);
			}
			}
		}

		bool loop = true;

		EMPLOYEE* EndList = nullptr;
		int SizeOfList = 0;

		int YOS_YouWant = 0;
		int Salary_YouWant = 0;
		std::string Position_YouWant;
		std::string list;

		while (loop) {
			
			List var = static_cast <List>(TypesOfLists());
			switch (var)
			{
			case List::ByYOE:
			{
				std::cout << "Enter length of service: ";
				
				YOS_YouWant = CheckInt();
				list = "Years of service: " + std::to_string(YOS_YouWant) + " \n";
				EndList = GetListByYOE(arr, count, YOS_YouWant, SizeOfList);
	
				break;
			}

			case List::ByS:
			{
				
				std::cout << "Enter salary: ";
				Salary_YouWant = CheckInt();

				list = "Salary: " + std::to_string(Salary_YouWant) +" \n";
				EndList = GetListByS(arr, count, Salary_YouWant, SizeOfList);
				
				break;
			}

			case List::ByPos:
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Enter position: ";
				std::getline(std::cin, Position_YouWant);

				list = "Position is " + Position_YouWant + " \n";
				EndList = GetListByPos(arr, count, Position_YouWant, SizeOfList);
				//ConsoleOutput(arr, list, SizeOfList);
				break;
			}
			}

			HowToInput outputting = static_cast<HowToInput>(AskOutputType());

			
			switch (outputting)
			{
			case HowToInput::ByConsole:
			{
				ConsoleOutput(EndList, list, SizeOfList);
				break;
			}

			case HowToInput::ByFile:
			{
				FileOutput(EndList, list, SizeOfList);
				break;
			}
			}

			

			std::cout << "Would you like to get another list?" << std::endl;
			std::cout << "1 - Yes \n2 - No" << std::endl;
			Quit Again = static_cast <Quit>(CheckMenuItem(2));
			if (Again == Quit::No)
			{
				loop = false;
				break;
			}
			
		}
			delete[] EndList;
			delete[] arr;
		
			Quit YesOrNo = static_cast<Quit>(AskToQuitOrToStay());
			switch (YesOrNo)
			{
			case Quit::Yes:
			{
				return 0;
			}
			case Quit::No:
			{
				break;

			}
			}
	}
}

