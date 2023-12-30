#pragma once
#include<string>
class EntryRawData
{
	std::string title;
	std::string author;
	std::string origin;
	std::string description;
	std::string userOpinion;
	std::string userScore;
	std::string EntryCategory;

public:
	EntryRawData(std::string="tytul ", std::string = "autor ", std::string = "pochodzenie ", std::string = "opis ", std::string = "pochodzenie ", std::string ="0/10 ", std::string = "brak ");
	
	void setTitle(std::string title_);
	void setAuthor(std::string author_);
	void setOrigin(std::string origin_);
	void setDescription(std::string description_);
	void setUserOpinion(std::string opinion_);
	void setUserScore(std::string score_);
	void setEntryCategory(std::string EntryCategory_);

	std::string getTitle();
	std::string getAuthor();
	std::string getOrigin();
	std::string getDescription();
	std::string getUserOpinion();
	std::string getUserScore();
	std::string getEntryCategory();
	
	~EntryRawData();
};

