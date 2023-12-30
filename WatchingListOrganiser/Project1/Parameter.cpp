#include "Parameter.h"

Parameter::Parameter()
{
}
Parameter::~Parameter()
{
}

bool Parameter::getToWatch()
{
	return toWatch;
}

bool Parameter::getWatched()
{
	return watched;
}

bool Parameter::getPlanned()
{
	return planned;
}

bool Parameter::getPremiere()
{
	return premiere;
}

std::string Parameter::getMovieCategory()
{
	return movieCategory;
}

void Parameter::setToWatch(bool toWatch_)
{
	toWatch = toWatch_;
}

void Parameter::setWatched(bool watched_)
{
	watched = watched_;
}

void Parameter::setPlanned(bool Planned_)
{
	planned=Planned_;
}

void Parameter::setPremiere(bool Premiere_)
{
	premiere=Premiere_;
}

void Parameter::setMovieCategory(std::string MovieCategory_)
{
	movieCategory = MovieCategory_;
}


const int constant3 = 4;
const std::string  boolTypes[constant3] = { "toWatch", "planned", "watched", "premiere" };

std::string Parameter::convertBoolToString(bool x)
{
	if (x == toWatch)
		return boolTypes[0];
	if (x == planned)
		return boolTypes[1];
	if (x == watched)
		return boolTypes[2];
	if (x == premiere)
		return boolTypes[3];
}

