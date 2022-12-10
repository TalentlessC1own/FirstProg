#include "InputOutput.h"

void ShowGreeting()
{
	setlocale(LC_ALL, "rus");
	std::cout << std::endl << "=========================================================================================\n" << 
		"Контрольная работа номер 1. Вариант 5." << std::endl
		<< "Яндиева Хава Багаудиновна 415." << std::endl
		<<"Задание: необходимо разработать класс для указанной предметной области. \n"<<
		"Доступ к данным реализовать с помощью методов Set, Get, Show." << std::endl<<std::endl;

	std::cout<< "Сотрудник: фамилия, имя, отчество, должность, год поступления на работу"<<
		",зарплата.\nСоздать массив объектов."<< std::endl << "Реализовать возможность получения:"<< std::endl <<
		"– списка работников, стаж работы которых на данном предприятии "<<
		"превышает заданное число лет," <<std::endl<<
		"– списка работников, зарплата которых больше заданной," << std::endl <<
		"– списка работников, занимающих заданную должность.\n" << 
		"=========================================================================================" << std::endl << std::endl;

}

EMPLOYEE* Console(int count)
{
	std::string Name, LastName, Patronymic, Position;
	int YearOfEmployment, Salary;

	EMPLOYEE* arr = new EMPLOYEE[count];

	std::cout << "Enter employee details:" << std::endl << std::endl;

	for (int i = 0; i < count; i++)
	{
		std::cout << "Last name:" << std::endl;
		std::cin >> LastName;
		std::cout << std::endl;

		std::cout << "Name:" << std::endl;
		std::cin >> Name;
		std::cout << std::endl;

		std::cout << "Patronymic:" << std::endl;
		std::cin >> Patronymic;
		std::cout << std::endl;

		std::cout << "Position:" << std::endl;
		std::cin >> Position;
		std::cout << std::endl;

		std::cout << "Year of employment:" << std::endl;
		YearOfEmployment = CheckInt();
		std::cout << std::endl;

		std::cout << "Salary:" << std::endl;
		Salary = CheckInt();
		std::cout << std::endl << std::endl;
	
		arr[i] = EMPLOYEE(Name, LastName, Patronymic, Position, YearOfEmployment, Salary);
		
		
			std::cout << "Last Name of " << i + 1 << " Employee: " << LastName << std::endl;
			std::cout << "Name of " << i + 1 << " Employee: " << Name << std::endl;
			std::cout << "Patronymic of " << i + 1 << " Employee: " << Patronymic << std::endl;
			std::cout << "Position of " << i + 1 << " Employee: " << Position << std::endl;
			std::cout << "Years of employment " << i + 1 << " Employee: " << YearOfEmployment << std::endl;
			std::cout << "Salary of " << i + 1 << " Employee: " << Salary << std::endl << std::endl;

		}return arr;
}

EMPLOYEE *File ()
{
	std::cin.clear();
		std::cin.ignore();
		std::string fileName = "";
		std::ifstream file;
		int count = 0;

		file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
		while (true)
		{
			std::cout << "Enter file name: " << std::endl;
			std::getline(std::cin ,fileName);
			try
			{
				file.open(fileName);
				std::cout << "Sucefull file open " << std::endl << std::endl;
			}
			catch (const std::exception)
			{
				std::cout << "Eror.Try again ." << std::endl << std::endl;
				continue;

			}

			std::string Name, LastName, Patronymic, Position;
			int YearOfEmployment, Salary;
			EMPLOYEE* arr;

			try
			{	
				count = CheckLineInt(file);
				arr = new EMPLOYEE[count];
				for (int i = 0; i < count; i++)
				{
					LastName = CheckLineString(file);
					Name = CheckLineString(file);
					Patronymic = CheckLineString(file);
					Position = CheckLineString(file);
					YearOfEmployment = CheckLineInt(file);
					Salary = CheckLineInt(file);
					
					std::cout << "Last Name of " << i + 1 << " Employee: " << LastName << std::endl;
					std::cout << "Name of " << i + 1 << " Employee: " << Name << std::endl;
					std::cout << "Patronymic of " << i + 1 << " Employee: " << Patronymic << std::endl;
					std::cout << "Position of " << i + 1 << " Employee: " << Position << std::endl;
					std::cout << "Years of employment of " << i + 1 << " Employee: " << YearOfEmployment << std::endl;
					std::cout << "Salary of " << i + 1 << " Employee: " << Salary << std::endl << std::endl;

					arr[i] = EMPLOYEE(Name, LastName, Patronymic, Position, YearOfEmployment, Salary);

				}

				
			}
			catch (std::invalid_argument iaex)
			{
				file.close();
				continue;
			}

			file.close();
			return arr;

		}
	}


int TypesOfLists()
{
	int variant = 0;

	std::cout << "Which list do you want to get?\n";
	std::cout << "1 - A list of employees whose work experience in this enterprise" <<
		"exceeds the set number of years \n2 - A list of employees  whose salary is higher than specified one \n" <<
		"3 - A list of employees holding a given position" << std::endl;

	variant = CheckMenuItem(3);

	return variant;
}

EMPLOYEE* GetListByYOE(EMPLOYEE* arr, int size, int Years, int &SizeOfList)
{
	EMPLOYEE* tmp_list = new EMPLOYEE[size];
	SizeOfList = 0;
	for (int i = 0; i < size; i++)
		if (Years < 2022 - arr[i].GetYearOfEmployment())
		{
			tmp_list[SizeOfList] = arr[i];
			SizeOfList++;
		}
	EMPLOYEE* EndList = new EMPLOYEE[SizeOfList];
	for (int i = 0; i < SizeOfList; i++)
		EndList[i] = tmp_list[i];

	return EndList;
}

EMPLOYEE* GetListByS(EMPLOYEE* arr, int size, int Money, int &SizeOfList)			//  //
{
	EMPLOYEE* tmp_list = new EMPLOYEE[size];
	SizeOfList = 0;
	for (int i = 0; i < size; i++)
		if (Money < arr[i].GetSalary())
		{
			tmp_list[SizeOfList] = arr[i];
			SizeOfList++;
		}
	EMPLOYEE* EndList = new EMPLOYEE[SizeOfList];
	for (int i = 0; i < SizeOfList; i++)
		EndList[i] = tmp_list[i];
		

	return EndList;
}

EMPLOYEE* GetListByPos(EMPLOYEE* arr, int size, std::string JobTitle, int &SizeOfList)
{
	EMPLOYEE* tmp_list = new EMPLOYEE[size];
	SizeOfList = 0;
	for (int i = 0; i < size; i++)
		if (arr[i].GetPosition() == JobTitle)	
		{
			tmp_list[SizeOfList] = arr[i];
			SizeOfList++;
		}
	EMPLOYEE* EndList = new EMPLOYEE[SizeOfList];
	for (int i = 0; i < SizeOfList; i++)
	{
		EndList[i] = tmp_list[i];
		
	}
	return EndList;
}


void FileOutput(EMPLOYEE* arr, std::string var, int SizeOfList) 
{
	std::ofstream fileRecorder = CheckFileOutput();

	fileRecorder << var << std::endl;

	for (int i = 0; i < SizeOfList; i++)
	{
		fileRecorder << "Employee #" << i + 1 << std::endl;

		fileRecorder << "Last Name is " + arr[i].GetLastName() << std::endl;

		fileRecorder << "Name is " + arr[i].GetName() << std::endl;

		fileRecorder << "Patronymic is " + arr[i].GetPatronymic() << std::endl;

		fileRecorder << "Position is " + arr[i].GetPosition() << std::endl;

		fileRecorder << "Years of service are " + std::to_string(arr[i].GetYearOfEmployment()) << std::endl;

		fileRecorder << "Salary is " + std::to_string(arr[i].GetSalary()) + "\n" << std::endl;

	}
	std::cout << "File is saved" << std::endl << std::endl;

	fileRecorder.close();
}


void InitialFileOutput(EMPLOYEE* arr, int size)
{
	std::ofstream fileRecorder = CheckFileOutput();
	fileRecorder << size << std::endl;
	for (int i = 0; i < size; i++)
	{
		fileRecorder << arr[i].GetLastName() << std::endl;
		fileRecorder << arr[i].GetName() << std::endl;
		fileRecorder << arr[i].GetPatronymic() << std::endl;
		fileRecorder << arr[i].GetPosition() << std::endl;
		fileRecorder << arr[i].GetYearOfEmployment() << std::endl;
		fileRecorder << arr[i].GetSalary() << std::endl;

	}
}

void ConsoleOutput(EMPLOYEE* arr, std::string var, int SizeOfList) 
{
	std::cout << var;
	for (int i = 0; i < SizeOfList; i++)
	{
		std::cout << "Employee #" << i + 1 << std::endl;

		std::cout << "Last Name is is " + arr[i].GetLastName() << std::endl;

		std::cout << "Name is " + arr[i].GetName() << std::endl;

		std::cout << "Patronymic is " + arr[i].GetPatronymic() << std::endl;

		std::cout << "Position is " + arr[i].GetPosition() << std::endl;

		std::cout << "Years of service are " + std::to_string(arr[i].GetYearOfEmployment()) << std::endl;

		std::cout << "Salary is " + std::to_string(arr[i].GetSalary()) + "\n" << std::endl;
	}
}