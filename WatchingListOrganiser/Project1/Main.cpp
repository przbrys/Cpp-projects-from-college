#include "Menu.h"
#include "DatabaseProcessor.h"
#include<string>

const int constant = 6;
const std::string  enumTypes[constant] = { "Filmy", "Podcasty", "Filmy YouTube", "Streamy YouTube", "Menu", "Kategorie" };
const std::string  enumTypes2[constant] = { "Movies", "Podcast", "YT_film", "YT_stream" };

const std::string convertEnumToString(STATE x)
{
	if (x == Movies)
		return enumTypes[0];
	if (x == Podcast_STATE)
		return enumTypes[1];
	if (x == YT_films)
		return enumTypes[2];
	if (x == YT_streams)
		return enumTypes[3];
	if (x == Main_Menu)
		return enumTypes[4];
	if (x == Entry_category)
		return enumTypes[5];
}

std::string convertEnumToString2(STATE x)
{
	if (x == Movies)
		return enumTypes2[0];
	if (x == Podcast_STATE)
		return enumTypes2[1];
	if (x == YT_films)
		return enumTypes2[2];
	if (x == YT_streams)
		return enumTypes2[3];
}

ENTRY_TYPE type1(element*&head)
{
	switch(head->next->state)
	{
		case Movies:
			return Movie_;
			break;
		case Podcast_STATE:
			return Podcast_;
			break;
		case YT_films:
			return YT_film_;
			break;
		case YT_streams:
			return YT_stream_;
			break;
	}
}

int main()
{
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		std::string FileName_;
		element*head = new element{ Main_Menu, nullptr };

		std::unique_ptr<Menu> m1 = std::make_unique<Menu>();
		std::unique_ptr<DatabaseProcessor> x = std::make_unique<DatabaseProcessor>();
		m1->displayMainMenue();
		Parameter param;

		bool wannaSaveFile = false;
		bool exitNotPressed = true;
		while (exitNotPressed)
		{
			switch (_getch())
			{
			case 49:
				if (m1->getCurrentState() == Main_Menu)
					m1->changeState(head, Movies);
				else if (m1->getCurrentState() != Main_Menu and m1->getCurrentState() != Entry_category)
				{
					m1->changeState(head, Entry_category);
					param.setToWatch(true);
				}
				else
				{
					param.setMovieCategory("Akcja");
					m1->isNeedForEntrys = true;
				}

				break;
			case 50:
				if (m1->getCurrentState() == Main_Menu)
					m1->changeState(head, Podcast_STATE);
				else if (m1->getCurrentState() != Main_Menu and m1->getCurrentState() != Entry_category)
				{
					m1->changeState(head, Entry_category);
					param.setPlanned(true);
				}
				else
				{
					param.setMovieCategory("Dramat");
					m1->isNeedForEntrys = true;
				}


				break;
			case 51:
				if (m1->getCurrentState() == Main_Menu)
					m1->changeState(head, YT_films);
				else if (m1->getCurrentState() != Main_Menu and m1->getCurrentState() != Entry_category)
				{
					m1->changeState(head, Entry_category);
					param.setWatched(true);
				}
				else
				{
					param.setMovieCategory("Horror");
					m1->isNeedForEntrys = true;
				}

				break;
			case 52:
				if (m1->getCurrentState() == Main_Menu)
					m1->changeState(head, YT_streams);
				else if (m1->getCurrentState() != Main_Menu and m1->getCurrentState() != Entry_category)
				{
					m1->changeState(head, Entry_category);
					param.setPremiere(true);
				}
				else
				{
					param.setMovieCategory("Komedia");
					m1->isNeedForEntrys = true;
				}


				break;
			case 'p':
				if (m1->getCurrentState() != Main_Menu)
				{
					popElement(head);
					m1->setCurrentState(head);
				}
				if (m1->getCurrentState() == Main_Menu)
				{
					m1->displayMainMenue();
				}
				else
					m1->changeState(head, m1->getCurrentState());
				break;
			case 27:
				exitNotPressed = false;
				break;

			default:
				std::cout << "Prosze wybrac poprawna opcje. \n";
				break;
			}

			if (m1->isNeedForEntrys == true)
			{
				std::vector<Entry> x2 = x->getEntryListByParam(type1(head), param);
				m1->displayRequiredEntrys(x2, head, param.getMovieCategory());
				x->saveFile(x2, head, param);
				m1->changeState(head, m1->getCurrentState());
			}

		}

		deleteElement(head);
		return 0;
	}	
	{}
	_CrtDumpMemoryLeaks();
}