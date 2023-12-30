#pragma once
#include"EntryRawData.h"
#include"EntryUserData.h"

enum ENTRY_TYPE{Movie_, Podcast_, YT_film_, YT_stream_};


class Entry :private EntryRawData , public EntryUserData
{
public:
	EntryRawData rawData;
	ENTRY_TYPE type;
	EntryUserData userData;

	Entry(ENTRY_TYPE type_, std::string title_);

	~Entry();
};

