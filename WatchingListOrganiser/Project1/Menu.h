#pragma once
#include <iostream>
#include <vector>
#include "Entry.h"
#include "Element.h"
#include<conio.h>

class Menu
{
private:
	STATE currentState;

public:
	bool isNeedForEntrys = false;
	void changeState(element*head_, STATE newState);
	void displayMainMenue();
	void displayCategoryMenu(std::string categoryName);
	void displayRequiredEntrys(std::vector<Entry>& entryList, element*head_, std::string s);
	STATE getCurrentState();
	void setCurrentState(element*head_);
	Menu();
	~Menu();
};

