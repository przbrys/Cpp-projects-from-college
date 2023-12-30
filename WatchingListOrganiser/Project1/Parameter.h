#pragma once
#include<string>
class Parameter
{
	bool toWatch = false;
	bool planned = false;
	bool watched = false;
	bool premiere = false;
	std::string movieCategory = "";

public:
	Parameter();
	~Parameter();
	bool getToWatch();
	bool getPlanned();
	bool getWatched();
	bool getPremiere();
	std::string getMovieCategory();
	void setToWatch(bool toWatch_);
	void setWatched(bool Watched_);
	void setPlanned(bool Planned_);
	void setPremiere(bool Premiere_);
	void setMovieCategory(std::string MovieCategory_);

	std::string convertBoolToString(bool x);
};
