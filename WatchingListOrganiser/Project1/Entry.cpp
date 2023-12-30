#include "Entry.h"
#include<conio.h>

Entry::Entry(ENTRY_TYPE type_, std::string title_)
{
	rawData.setTitle(title_);
    type=type_;
}

Entry::~Entry()
{
}