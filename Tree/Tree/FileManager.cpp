#include "FileManager.h"


FileManager::FileManager()
{
	data_path = "C:\\Users\\NowyMSEK\\Desktop\\DATA.txt";
}

void FileManager::savePath()
{
	std::cout << "Podaj sciezke.\n";
	std::cin >> data_path;
}

void FileManager::setVec(std::vector<std::string> vec_)
{
	for (size_t i = 0; i < vec_.size(); i++)
	{
		this->namesVec.push_back(vec_[i]);
	}
}

void FileManager::read_file(fs::path dataPath)
{
	std::string line;
	std::fstream data;
	Genealogical_tree* geneTree = new Genealogical_tree();
	data.open(data_path, std::ios::in);
	if (data.good())
	{
		while (getline(data, line))
		{
			geneTree->countGeneration++;
			std::string tmp;
			tmp = line;
			bool plusExist = 0;
			{
				std::regex plusPattern("[\\+]+");
				std::smatch plusResult;  
				while (regex_search(tmp, plusResult, plusPattern))
				{
					for (auto x : plusResult)
					{
						tmp = plusResult.suffix().str();
						plusExist = 1;
					}
				}

				std::regex namePattern("[a-zA-Z]+");
				std::smatch nameResult;    
				std::vector<std::string> tempVec;
				while (regex_search(line, nameResult, namePattern))
				{
					tempVec.push_back(nameResult[0]);
					for (auto x : nameResult)
					{
						line = nameResult.suffix().str();
					}					
				}
				this->setVec(tempVec);
				geneTree->createTree(tempVec, plusExist);
			}
		}
	}
	data.close();
	std::sort(namesVec.begin(), namesVec.end());
	namesVec.erase(std::unique(namesVec.begin(), namesVec.end()), namesVec.end());
	Menu::displayTree(*geneTree, namesVec);
}