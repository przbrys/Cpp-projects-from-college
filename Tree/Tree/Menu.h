#pragma once
#include<iostream>
#include<algorithm>
#include <iomanip>
#include"Genealogical_tree.h"
#include"FileManager.h"

class Menu
{
public:
	friend class Filemanager;
	void static displayTree(Genealogical_tree relVec, std::vector<std::string> namesVec);
	void displayMenue();
};