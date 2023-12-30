#pragma once
#include"Genealogical_tree.h"
#include"Menu.h"
#include <filesystem>
#include <fstream>
#include <algorithm>

namespace fs = std::filesystem;

class FileManager
{
public:
	friend class Menu;
	fs::path data_path; 
	std::vector<std::string> namesVec;

	FileManager();
	~FileManager() = default;

	void read_file(fs::path dataPath);
	void savePath();
	void setVec(std::vector<std::string> vec_);
};

