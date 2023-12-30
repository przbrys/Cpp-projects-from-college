#pragma once
#include<string>
#include<vector>
#include<iostream>

class Person;
class Relation
{
public:
	Person* parent_1;
	Person* parent_2;
	std::vector<Person*> offsprings;

	Relation();
	Relation(Person* x, Person* y);
	~Relation();
};

class Person
{
public:
	std::string name;
	std::vector<Relation*> relation_partners; 
	Relation* relation_parents; 

	Person(std::string x);
	~Person();
	void setName(std::string name_);

};

