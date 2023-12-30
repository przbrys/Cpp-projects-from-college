#include "DatabaseProcessor.h"
#include<sstream>
#include<fstream>

const std::string convertEnumToString(STATE x);
std::string convertEnumToString2(STATE x);

std::vector<Entry> DatabaseProcessor::getEntryListByParam(ENTRY_TYPE type, Parameter param)
{
	std::vector<Entry> tmpVec;
	for (auto i : this->entries)
	{
		if (i.type == type && i.rawData.getEntryCategory() == param.getMovieCategory())
		{
			if ((param.getToWatch() && i.userData.getToWatch()) ||
				(param.getPlanned() && i.userData.getPlanned()) ||
				(param.getWatched() && i.userData.getWatched()) ||
				(param.getPremiere() && i.userData.getPremiereSoon()))
			{
				tmpVec.push_back(i);
			}
		}
	}
	return tmpVec;
}

void DatabaseProcessor::addNewEntry(Entry newEntry)
{
	entries.push_back(newEntry);
}

void DatabaseProcessor::readAFiles()
{
	this->entries.clear();
	std::string properFileName = "";

	std::string param1[4] = { "Movies","Podcast","YT_films","YT_streams" };
	std::string param2[4] = { "toWatch","planned","watched","premiere" };
	std::string param3[4] = { "Akcja","Dramat","Horror","Komedia" };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				properFileName = "./data/" + param1[i] + "_" + param2[j] + "_" + param3[k] + ".txt";

				ENTRY_TYPE t;
				if (param1[i] == "Movies")
					t = Movie_;
				else if (param1[i] == "Podcast")
					t = Podcast_;
				else if (param1[i] == "YT_films")
					t = YT_film_;
				else if (param1[i] == "YT_streams")
					t = YT_stream_;

				readFile(properFileName, t);
			}
		}
	}
}

DatabaseProcessor::DatabaseProcessor()
{
	std::string properFileName = "";

	std::string param1[4] = { "Movies","Podcast","YT_films","YT_streams" };
	std::string param2[4] = { "toWatch","planned","watched","premiere" };
	std::string param3[4] = { "Akcja","Dramat","Horror","Komedia" };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				properFileName = "./data/" + param1[i] + "_" + param2[j] + "_" + param3[k] + ".txt";

				ENTRY_TYPE t;
				if (param1[i] == "Movies")
					t = Movie_;
				else if (param1[i] == "Podcast")
					t = Podcast_;
				else if (param1[i] == "YT_films")
					t = YT_film_;
				else if (param1[i] == "YT_streams")
					t = YT_stream_;

				readFile(properFileName, t);
			}
		}
	}
}

DatabaseProcessor::~DatabaseProcessor()
{
}

void DatabaseProcessor::readFile(const std::string FileName, ENTRY_TYPE type_)
{
	std::string category = "";
	std::string type = "";
	std::string state = "";
	int bp1 = 0, bp2 = 0, bp3 = 0;

	const int l = FileName.length();
	char* arr = new char[l + 1];

	for (int i = 0; i < l; i++)
		arr[i] = FileName[i];

	for (int i = 0; i < l; i++)
	{
		if (arr[i] == '_' && i != 2)
		{
			if (bp1 == 0)
				bp1 = i;
			else
				bp2 = i;
		}
		if (arr[i] == '.')
			bp3 = i;
	}
	for (int k = 0; k < bp1 + 1; k++)
	{
		type += arr[k];
	}

	for (int k = bp1 + 1; k < bp2; k++)
	{
		state += arr[k];
	}
	for (int k = bp2 + 1; k < bp3; k++)
	{
		category += arr[k];
	}

	delete[] arr;

	std::string ss;
	std::ifstream data;

	data.open(FileName, std::ios::in);
	if (data.good())
	{
		getline(data, ss);
		while (!data.eof())
		{
			getline(data, ss);
			getline(data, ss);
			std::string temp;
			temp = ss;
			Entry e(type_, temp);

			getline(data, ss);
			temp = ss;
			e.rawData.setAuthor(temp);

			getline(data, ss);
			temp = ss;
			e.rawData.setOrigin(temp);

			getline(data, ss);
			temp = ss;
			e.rawData.setDescription(temp);

			getline(data, ss);
			temp = ss;
			e.rawData.setUserOpinion(temp);

			getline(data, ss);
			temp = ss;
			e.rawData.setUserScore(temp);


			if (state == "toWatch")
				e.userData.setToWatch(true);
			if (state == "Planned")
				e.userData.setPlanned(true);
			if (state == "Watched")
				e.userData.setWatched(true);
			if (state == "toWatch")
				e.userData.setPremiereSoon(true);

			e.rawData.setEntryCategory(category);
			addNewEntry(e);
		}
	}
}

void DatabaseProcessor::saveFile(std::vector<Entry>& entryList, element*head_, Parameter param_)
{
	std::fstream file;
	file.open(setFileName(head_, param_), std::ios::out);
	for (auto i : entryList)
	{
		file << "\n\n" << i.rawData.getTitle() << "\n" << i.rawData.getAuthor() << "\n" << i.rawData.getOrigin() << "\n" << i.rawData.getDescription() << "\n" << i.rawData.getUserOpinion() << "\n" << i.rawData.getUserScore();
	}
	file.close();
	this->readAFiles();
}

std::string DatabaseProcessor::setFileName(element*head_, Parameter param_)
{
	std::string FileName;
	bool isOkey = false;
	if (param_.getToWatch() == true)
		isOkey = param_.getToWatch();
	if (param_.getPlanned() == true)
		isOkey = param_.getPlanned();
	if (param_.getWatched() == true)
		isOkey = param_.getWatched();
	if (param_.getPremiere() == true)
		isOkey = param_.getPremiere();

	FileName = "./data/" + convertEnumToString2(head_->next->state) + "_" + param_.convertBoolToString(isOkey) + "_" + param_.getMovieCategory() + ".txt";
	return FileName;
}

