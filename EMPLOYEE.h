#pragma once
#include <iostream>


class EMPLOYEE
{
private:
	std::string Name, LastName, Patronymic, Position;
	int YearOfEmployment = 0, Salary = 0;

public:

	EMPLOYEE() = default; 
	EMPLOYEE(std::string n, std::string ln, std::string pat, std::string pos, int yoe, int s)
		:Name(n), LastName(ln), Patronymic(pat), Position(pos), YearOfEmployment(yoe), Salary(s)
	{}

	std::string GetName();

	std::string GetLastName();

	std::string GetPatronymic();

	std::string GetPosition();

	int GetYearOfEmployment();

	int GetSalary();

	bool operator == (const EMPLOYEE& other);    

	bool operator!=(const EMPLOYEE& other);

};

