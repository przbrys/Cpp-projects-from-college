#pragma once
#include"Person,Relation.h"
#include<regex>

class Genealogical_tree
{
public:
	friend class Menu;
	Relation* helper;
	Person* first = nullptr;
	int countGeneration = 0;
	std::vector<Relation*> actualRelations;
	~Genealogical_tree();

	void setRelationPartners(Person* p1, Person* p2);//1
	void setRelationParents(Relation* &temp);//3
	void createTree(std::vector<std::string> tempVec, bool plusExist);
};