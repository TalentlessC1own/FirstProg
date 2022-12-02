#include "EMPLOYEE.h"


std::string EMPLOYEE::GetName()
{
	return Name;
}

std::string EMPLOYEE::GetLastName()
{
	return LastName;
}

std::string EMPLOYEE::GetPatronymic()
{
	return Patronymic;
}

std::string EMPLOYEE::GetPosition()
{
	return Position;
}

int EMPLOYEE::GetYearOfEmployment()
{
	return YearOfEmployment;
}

int EMPLOYEE::GetSalary()
{
	return Salary;
}


bool EMPLOYEE::operator==(const EMPLOYEE& other)
{
	return  YearOfEmployment == other.YearOfEmployment && Salary == other.Salary
		&& Position == other.Position;
}

bool EMPLOYEE::operator!=(const EMPLOYEE& other)
{
	return !(*this == other);
}