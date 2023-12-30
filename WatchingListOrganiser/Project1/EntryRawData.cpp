#include "EntryRawData.h"

EntryRawData::EntryRawData(std::string t, std::string a, std::string o, std::string d, std::string u, std::string uS, std::string eC)
{
	title = t;
	author = a;
	origin = o;
	description = d;
	userOpinion = u;
	userScore = uS;
	EntryCategory = eC;
}

void EntryRawData::setTitle(std::string title_)
{
	title = title_;
}

void EntryRawData::setAuthor(std::string author_)
{
	author = author_;
}

void EntryRawData::setOrigin(std::string origin_)
{
	origin = origin_;
}

void EntryRawData::setDescription(std::string description_)
{
	description = description_;
}

void EntryRawData::setUserOpinion(std::string opinion_)
{
	userOpinion = opinion_;
}

void EntryRawData::setUserScore(std::string score_)
{
	userScore = score_;
}

void EntryRawData::setEntryCategory(std::string EntryCategory_)
{
	EntryCategory = EntryCategory_;
}

std::string EntryRawData::getTitle()
{
	return title;
}

std::string EntryRawData::getAuthor()
{
	return author;
}

std::string EntryRawData::getOrigin()
{
	return origin;
}

std::string EntryRawData::getDescription()
{
	return description;
}

std::string EntryRawData::getUserOpinion()
{
	return userOpinion;
}

std::string EntryRawData::getUserScore()
{
	return userScore;
}

std::string EntryRawData::getEntryCategory()
{
	return EntryCategory;
}

EntryRawData::~EntryRawData()
{
}
