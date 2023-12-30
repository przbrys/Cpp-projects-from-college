#pragma once
class EntryUserData
{
	bool toWatch=false;
	bool planned=false;
	bool watched=false;
	bool premiereSoon=false;

public:
	void setToWatch(bool toWatch_);
	void setPlanned(bool planned_);
	void setWatched(bool watched_);
	void setPremiereSoon(bool premiere_);

	bool getToWatch();
	bool getPlanned();
	bool getWatched();
	bool getPremiereSoon();

	EntryUserData();
	~EntryUserData();
};

