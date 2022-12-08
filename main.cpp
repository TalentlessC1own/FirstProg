#include <iostream>
#include "EMPLOYEE.h"
#include "InputOutput.h"
#include "CheckingFunctions.h"
#include "MENU.h"

//#include <windows.h>
//#include <clocale>




enum class HowToInput 
{
	ByConsole = 1,
	ByFile,
	//Again
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

	while (true) {

		ShowGreeting();

		HowToInput InputMenu = static_cast<HowToInput>(AskMenuItem());

		EMPLOYEE* arr = nullptr;
		int count = 0;

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
			arr = File();
			count = sizeof(*arr) / sizeof(arr[0]);
			//std::cin.clear();
			//std::cin.ignore(30000, '\n');
			//ConsoleOutput(arr, count);
			break;
		}
			/*case HowToInput::Again:		//check if arr != 0, ask about lists again
			{
				if (arr != nullptr)
				{
					//"get list"
				}
				else
				{
					std::cout << "Choose another menu point.";
				}

			}
			*/
		}

		//ЭТУ ЧАСТЬ КОДА, КОТОРЫЙ НИЖЕ, Я КОПИРУЮ И ВСТАВЛЯЮ ДВА РАЗА В ЧАСТЬ КОДА ВВЕРХУ В КОНСОЛЬНЫЙ ВВОД И В ФАЙЛОВЫЙ ВВОД
		// 
		// 
		// 
		// 
		// 
		// 
		// 
		// ascing user how to save the data
		if (InputMenu == HowToInput::ByConsole)
		{
			
			//std::cout << "Would you like to save the data?" << std::endl << "1 - Yes \n2 - No" << std::endl;

			Quit SaveOrNot = static_cast<Quit>(AskToSaveOrNotToSave());

			switch (SaveOrNot)
			{
			case Quit::Yes:
			{
				InitialFileOutput(arr, count);
				//??in new file or in existed one
			}
			}
		}


		//getting input in lists
		//может быть все эти обЪявления вне вайла, ну посмотрим

		
		bool loop = true;

		EMPLOYEE* EndList = nullptr;
		int SizeOfList = 0;

		int YOE_YouWant = 0;
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
				
				YOE_YouWant = CheckInt();
				list = "Years of service: " + std::to_string(YOE_YouWant) + " \n";
				EndList = GetListByYOE(arr, count, YOE_YouWant, SizeOfList);
				//ConsoleOutput(arr, list, SizeOfList);
				break;
			}

			case List::ByS:
			{
				std::cout << "Enter salary: ";
				Salary_YouWant = CheckInt();

				list = "Salary: " + std::to_string(Salary_YouWant) +" \n";
				EndList = GetListByS(arr, count, Salary_YouWant, SizeOfList);
				//ConsoleOutput(arr, list, SizeOfList);
				//std::cout << Endlist;
				break;
			}

			case List::ByPos:
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Enter position: ";
				std::getline(std::cin, Position_YouWant);			//

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
				ConsoleOutput(arr, list, SizeOfList);
				break;
			}

			case HowToInput::ByFile:
			{
				FileOutput(arr, list, SizeOfList);
				break;
			}
			}

			/*std::cout << "1 - Save the list\n2 - Continue without saving" << std::endl; //надо ли прописывать сейв
			
																					//если да, то через чек меню айтем и инпутвалидейшен
			Quit ListSaver = static_cast<Quit>(CheckMenuItem(2));
			switch (ListSaver) {
			case Quit::Yes:
			{
				//
				FileOutput(EndList, list, SizeOfList); // изменения в этой ф, не забыть убрать
				//InitialFileOutput(EndList, SizeOfList);
			}
			case Quit::No:
			{
				break;
			}
			}*/
			

			
			std::cout << "Would you like to get another list?" << std::endl;
			std::cout << "1 - Yes \n2 - No" << std::endl;
			Quit Again = static_cast <Quit>(CheckMenuItem(2));
			if (Again == Quit::No)
			{
				loop = false;
				break;
			}
			
		}


			/*std::cout << "Would you like to get another list?" << std::endl;
			std::cout << "1 - Yes \n2 - No" << std::endl;

			Quit Again = static_cast <Quit>(CheckMenuItem(2));
			if (Again == Quit::No)
			{

				break;
			}*/




			







			//EMPLOYEE* arr = nullptr;
			//delete[] EndList;
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

				//std::cout<<"1 - Go back to list types \n2 - Run the program again";
				//int answ = CheckMenuItem(2);
				//if (answ == 1)
				//{

				//}//вернуться к меню списков или начать прогу занаво
				//else
				continue;
			}
			}


		
			/*cout << "Задайте зарплату для сравнения:" << endl;
			int zp;
			while (!(cin >> zp) && zp < 0)
			{cout << "Введите корректное значение";
				cin.clear();
				cin.ignore(10, '\n');
			}cout << "Вы ввели значение:" << zp;*/
	}
}

