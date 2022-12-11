#pragma once
#include <iostream>
#include <fstream>
#include <ostream>


#include "EMPLOYEE.h"
#include "CheckingFunctions.h"

void ShowGreeting();

EMPLOYEE* Console(int count);

EMPLOYEE* File(int& count);


int TypesOfLists();

EMPLOYEE* GetListByYOE(EMPLOYEE* arr, int size, int Years, int &SizeOfList);

EMPLOYEE* GetListByS(EMPLOYEE* arr, int size, int Money, int& SizeOfList);

EMPLOYEE* GetListByPos(EMPLOYEE* arr, int size, std::string JobTitle, int& SizeOfList); //&


void FileOutput(EMPLOYEE* arr, std::string var, int SizeOfList); //&

void ConsoleOutput(EMPLOYEE* arr,std::string var, int SizeOfList);  //&

void InitialFileOutput(EMPLOYEE* arr, int size);

