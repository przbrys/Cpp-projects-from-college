#include "Person,Relation.h"

Person::Person(std::string x) 
{
	this->name = x;
	this->relation_parents = nullptr;
}

Person::~Person()
{
	relation_parents = nullptr;
	delete relation_parents;
}

void Person::setName(std::string name_)
{
	this->name = name_;
}

Relation::Relation()
{
	this->parent_1 = nullptr;
	this->parent_2 = nullptr;
}

Relation::Relation(Person* x, Person* y) :parent_1(x), parent_2(y) {}

Relation::~Relation()
{
	parent_1 = nullptr;
	parent_2 = nullptr;

	delete parent_1;
	delete parent_2;
}


