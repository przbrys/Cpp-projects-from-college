#include "Menu.h"

const std::string convertEnumToString(STATE x);
std::string convertEnumToString2(STATE x);

void Menu::displayMainMenue()
{
	system("cls");

	std::cout.width(60);
	std::cout << "Menue\n\n";
	std::cout << "1. Filmy\n";
	std::cout << "2. Podcasty\n";
	std::cout << "3. Filmiki YouTube\n";
	std::cout << "4. Stream'y YouTube\n";
	std::cout << "esc. Zakoncz program\n";
}

void Menu::changeState(element*head_, STATE newState)
{
	if (newState != getCurrentState())
	{
		pushElement(head_, newState);
		this->setCurrentState(head_);
	}

	system("cls");

	if (newState != Main_Menu and newState != Entry_category)
	{
		std::cout.width(60);
		std::cout << convertEnumToString(head_->state) << "->" << convertEnumToString(head_->next->state) << "\n" << "\n";

		if (newState == Podcast_STATE)
			std::cout << "1. Do odsluchania\n";
		else
			std::cout << "1. Do obejrzenia\n";

		std::cout << "2. Zaplanowane\n";

		if (newState == Podcast_STATE)
			std::cout << "3. Odsluchane\n";
		else
			std::cout << "3. Obejrzane\n";

		std::cout << "4. Najblizsze Premiery\n";
		std::cout << "p. Powrot\n";
		std::cout << "esc.Zakoncz program\n";
	}
	else if (newState == Entry_category)
	{
		std::cout.width(60);
		std::cout << convertEnumToString(head_->state) << "->" << convertEnumToString(head_->next->state) << "\n" << "\n";
		std::cout << "1. Akcja\n";
		std::cout << "2. Dramat\n";
		std::cout << "3. Horror\n";
		std::cout << "4. Komedia\n";
		std::cout << "p. Powrot\n";
		std::cout << "esc. Zakoncz program\n";
	}
}

void Menu::displayCategoryMenu(std::string categoryName)
{
	system("cls");
	this->isNeedForEntrys = true;
	std::cin.get();
}

void Menu::displayRequiredEntrys(std::vector<Entry>& entryList, element*head_, std::string s)
{
	isNeedForEntrys = false;

	bool list = true;

	while (list)
	{
		system("cls");
		printf("Type 0 to go back \nType 1000 to add new Entry \nType id to show details\n\n");

		int id = 1;
		for (auto i : entryList)
		{
			std::cout << id << ".	" << i.rawData.getTitle() << std::endl;
			id++;
		}
		int number;
		std::cin.clear();
		std::cin >> number;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> number;
		}
		if (number == 0)
			list = false;
		else if (number == 1000)
		{
			id++;
			int number_ = id;

			ENTRY_TYPE h;
			if (head_->next->state == Movies)
				h = Movie_;
			if (head_->next->state == Podcast_STATE)
				h = Podcast_;
			if (head_->next->state == YT_films)
				h = YT_film_;
			if (head_->next->state == YT_streams)
				h = YT_stream_;

			std::string tmp = "";
			system("cls");
			std::cout << "Podaj tytul: ";
			std::cin.ignore();
			std::getline(std::cin, tmp);
			Entry A(h, tmp);

			std::cout << "Podaj Autora: ";
			std::cin.clear();
			std::getline(std::cin, tmp);
			A.rawData.setAuthor(tmp);

			std::cout << "Podaj pochodzenie: ";
			std::cin.clear();
			std::getline(std::cin, tmp);
			A.rawData.setOrigin(tmp);

			std::cout << "Skomponuj opis: ";
			std::cin.clear();
			std::getline(std::cin, tmp);
			A.rawData.setDescription(tmp);

			std::cout << "Napisz wlasny komentarz: ";
			std::cin.clear();
			std::getline(std::cin, tmp);
			A.rawData.setUserOpinion(tmp);

			std::cout << "Wstaw ocene: ";
			std::cin.clear();
			std::getline(std::cin, tmp);
			A.rawData.setUserScore(tmp);

			A.rawData.setEntryCategory(s);
			(entryList).push_back(A);
		}
		else
		{
			int b = 1;
			bool indetails = true;
			for (auto i : entryList)
			{
				if (b == number && indetails)
				{

					system("cls");
					std::cout << "Tytul : " << i.rawData.getTitle() << "\nAutor: " << i.rawData.getAuthor() << "\nPochodzenie: " << i.rawData.getOrigin() << "\n\nOpis: " << i.rawData.getDescription() << "\n\nUser Moja opinia:  " << i.rawData.getUserOpinion() << "\nMoja ocena: " << i.rawData.getUserScore() << "\n";
					printf_s("\nAby wrocic nacisnij p. Jezeli chcesz edytowac film nacisnij e. W celu usuniêcia tytulu z listy kliknij d.\n");

					while (indetails)
					{
						std::string tmp2;
						std::string tempEntry;
						switch (_getch())
						{
						case 'p':
							indetails = false;
							break;
						case 'd':
							indetails = false;
							std::cout << "\nCzy napewno chcesz usunac pozycje z listy? aby potwierdzic wpisz tak";
							tmp2="";
							std::cin.ignore();
							std::getline(std::cin, tmp2);
							if (tmp2 == "tak")
								entryList.erase(entryList.begin()+b-1);

							break;
						case 'e':
							bool editNotEnded = true;
							system("cls");
							std::cout << "Tytul ->t\n";
							std::cout << "Autor ->a\n";
							std::cout << "Pochodzenie ->d\n";
							std::cout << "Opis ->o\n";
							std::cout << "Opinia uzytkownika ->u\n";
							std::cout << "Ocena uzytkownika ->c\n";
							std::cout << "Koniec edycji ->p\n\n";
							while (editNotEnded)
							{
								tempEntry = "";
								switch (_getch())
								{
								case 't':
									std::cin.ignore();
									std::cout << "Podaj tytul.\n";
									std::getline(std::cin, tempEntry);
									(entryList).at(b - 1).rawData.setTitle(tempEntry);
									std::cout << "OK. Mozesz edytowac dalej\n\n\n";
									break;
								case 'a':
									std::cout << "Podaj autora.\n";
									std::cin.clear();
									std::getline(std::cin, tempEntry);
									(entryList).at(b - 1).rawData.setAuthor(tempEntry);
									std::cout << "OK. Mozesz edytowac dalej\n\n\n";
									break;
								case 'd':
									std::cout << "Podaj pochodzenie.\n";
									std::cin.clear();
									std::getline(std::cin, tempEntry);
									(entryList).at(b - 1).rawData.setOrigin(tempEntry);
									std::cout << "OK. Mozesz edytowac dalej\n\n\n";
									break;
								case 'o':
									std::cout << "Podaj opis.\n";
									std::cin.clear();
									std::getline(std::cin, tempEntry);
									(entryList).at(b - 1).rawData.setDescription(tempEntry);
									std::cout << "OK. Mozesz edytowac dalej\n\n\n";
									break;
								case 'u':
									std::cout << "Podaj opinie.\n";
									std::cin.clear();
									std::getline(std::cin, tempEntry);
									(entryList).at(b - 1).rawData.setUserOpinion(tempEntry);
									std::cout << "OK. Mozesz edytowac dalej\n\n\n";
									break;
								case 'c':
									std::cout << "Podaj ocene koncowa.\n";
									std::cin.ignore();
									std::getline(std::cin, tempEntry);
									(entryList).at(b - 1).rawData.setUserScore(tempEntry);
									std::cout << "OK. Mozesz edytowac dalej\n\n\n";
									break;
								case 'p':
									editNotEnded = false;
									break;
								default:
									std::cout << "Wybierz poprawna opcje.\n";
									break;
								}
								if (editNotEnded)
								{
									system("cls");
									std::cout << "Tytul ->t\n";
									std::cout << "Autor ->a\n";
									std::cout << "Pochodzenie ->d\n";
									std::cout << "Opis ->o\n";
									std::cout << "Opinia uzytkownika ->u\n";
									std::cout << "Ocena uzytkownika ->c\n";
									std::cout << "Koniec edycji ->p\n\n";
									std::cout << "Poprawnie zedytowano! mozesz edytowac dalej\n\n";
								}
							}
							indetails = false;
							break;
						}
					}
				}
				else
					b++;
			}
		}
	}
}

STATE Menu::getCurrentState()
{
	return currentState;
}

void Menu::setCurrentState(element*head_)
{
	element*temp = head_;
	while (temp->next)
		temp = temp->next;

	this->currentState = temp->state;
}

Menu::Menu()
{
	isNeedForEntrys = false;
	currentState = Main_Menu;
}

Menu::~Menu()
{
}
