#include "Genealogical_tree.h"

Genealogical_tree::~Genealogical_tree()
{
	helper = nullptr;
	first = nullptr;
	delete helper;
	delete first;
}

void Genealogical_tree::setRelationPartners(Person* p1, Person* p2)
{
	this->helper = new Relation(p1,p2);

	this->helper->parent_1->relation_partners.push_back(this->helper);
	if (p2 != nullptr)
	{
		this->helper->parent_2->relation_partners.push_back(this->helper);
	}

}

void Genealogical_tree::setRelationParents(Relation* &temp)
{
	for (size_t i = 0; i < temp->offsprings.size(); i++)
	{
		(temp->offsprings[i]->relation_parents) = temp;
	}
}



void Genealogical_tree::createTree(std::vector<std::string> tempVec, bool plusExist)
{
		if (this->countGeneration == 1)
		{
			this->first = new Person(tempVec[0]);
			this->setRelationPartners(this->first,( plusExist ? new Person(tempVec[1]) : nullptr));
			this->actualRelations.push_back(this->helper);
		}
		else
		{
			this->setRelationPartners(new Person(tempVec[0]),( plusExist ? new Person(tempVec[1]) : nullptr));
			this->actualRelations.push_back(this->helper);
		}	
		for (auto i = plusExist ?2:1; i < tempVec.size(); i++)
		{
			this->helper->offsprings.push_back(new Person(tempVec[i]));
		}
		this->setRelationParents(helper);
}
