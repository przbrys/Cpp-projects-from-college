#include "EntryUserData.h"

EntryUserData::EntryUserData()
{
}

EntryUserData::~EntryUserData()
{
}

void EntryUserData::setToWatch(bool toWatch_)
{
	toWatch = toWatch_;
}

void EntryUserData::setPlanned(bool planned_)
{
	planned = planned_;
}

void EntryUserData::setWatched(bool watched_)
{
	watched = watched_;
}

void EntryUserData::setPremiereSoon(bool premiere_)
{
	premiereSoon = premiere_;
}

bool EntryUserData::getToWatch()
{
	return toWatch;
}

bool EntryUserData::getPlanned()
{
	return planned;
}

bool EntryUserData::getWatched()
{
	return watched;
}

bool EntryUserData::getPremiereSoon()
{
	return premiereSoon;
}
