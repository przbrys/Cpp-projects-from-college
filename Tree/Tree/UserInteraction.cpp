#include "UserInteraction.h"

void UserInteraction::user_interaction()
{
	FileManager FileManager_obj;
	Menu Menu_obj;
	
	bool p = true;
	while (p == true)
	{
		Menu_obj.displayMenue();
		int choose;
		std::cin >> choose;
		switch (choose)
		{
		case 1:
		{	
			std::thread t1(&FileManager::read_file, FileManager_obj, FileManager_obj.data_path);
			t1.join();
		}
		break;
		case 2:
		{
			std::cout << "Wczesniejsza sciezka: " << FileManager_obj.data_path << "\n";
			FileManager_obj.savePath();
			std::cout << "Aktualna sciezka: " << FileManager_obj.data_path;
		}
		break;
		case 3:
		{
			p = false;
			std::cout << "Do zobaczenia!\n";
		}
		break;
		default:
		{
			std::cout << "Wybierz 1, 2 lub 3.\n";
		}
		break;
		}
	}
}
