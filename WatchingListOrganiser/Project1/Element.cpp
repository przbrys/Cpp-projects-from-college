#include "Element.h"

void pushElement(element*&head_, STATE state_)
{
	element*temp = head_;
	while(temp->next)
		temp = temp->next;

	temp->next = new element{ state_, nullptr };
}
void popElement(element*&head_)
{
	element*temp = head_;
	if(temp->next->next)
	{
		while (temp->next->next)
			temp = temp->next;

		delete temp->next;
		temp->next = nullptr;
	}
	else if (temp->next)
	{
		delete temp->next;
		temp->next = nullptr;
	}
}

void deleteElement(element*&head_)
{
	while (head_)
	{
		auto p = head_->next;
		delete head_;
		head_ = p;
	}
}