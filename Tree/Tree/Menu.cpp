#include "Menu.h"

void Menu::displayMenue()
{
	std::cout << "\n[1] Wyswietl drzewo genealogiczne\n[2] Podaj sciezke do pliku\n[3] Wyjscie\n";
}

void Menu::displayTree(Genealogical_tree relVec, std::vector<std::string> namesVec)
{
	int with = 60;
	for (size_t i = 0; i < relVec.actualRelations.size(); i++)
	{
		if (relVec.actualRelations[i]->parent_2 != nullptr)
		{
			auto x1 = (std::find(namesVec.begin(), namesVec.end(), relVec.actualRelations[i]->parent_2->name));
			if (x1 != namesVec.end())
			{
				std::cout << std::setw(with / 2) << relVec.actualRelations[i]->parent_2->name << "\n";
				namesVec.erase(x1);
			}
		}
		if (relVec.actualRelations[i]->parent_1 != nullptr)
		{
			auto x = (std::find(namesVec.begin(), namesVec.end(), relVec.actualRelations[i]->parent_1->name));
			if (x != namesVec.end())
			{
				std::cout << std::setw(with / 2) << relVec.actualRelations[i]->parent_1->name << "\n";
				namesVec.erase(x);
			}
		}

		for (size_t q = 0; q < relVec.actualRelations[i]->offsprings.size(); q++)
		{
			auto x2 = (std::find(namesVec.begin(), namesVec.end(), relVec.actualRelations[i]->offsprings[q]->name));
			if (x2 != namesVec.end())
			{
				std::cout << std::setw(with / (relVec.actualRelations[i]->offsprings.size())) << relVec.actualRelations[i]->offsprings[q]->name;
				namesVec.erase(x2);
			}
		}
		std::cout << "\n";
	}
}
