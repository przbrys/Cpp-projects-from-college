#pragma once
#include "enum_STATE.h"


struct element
{
	STATE state;
	element* next;
};

void pushElement(element*&head_, STATE state_);
void popElement(element*&head_);
void deleteElement(element*&head_);