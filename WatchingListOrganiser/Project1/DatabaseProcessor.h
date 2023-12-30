#pragma once
#include"Entry.h"
#include<vector>
#include"Parameter.h"
#include"Element.h"

class DatabaseProcessor
{
	std::vector<Entry> entries;
public:
	std::vector<Entry>getEntryListByParam(ENTRY_TYPE type, Parameter param);
	void addNewEntry(Entry newEntry);
	DatabaseProcessor();
	~DatabaseProcessor();
	void readAFiles();
	void readFile(const std::string FileName, ENTRY_TYPE type_);
	void saveFile(std::vector<Entry> &entryList, element*head_, Parameter param_);
	std::string setFileName(element*head_, Parameter param_);
};

