#include "BinaryTree.h"

template<typename T>
Binary_tree<T>::Binary_tree()
{
	counter = 0;
	counter2 = 0;
	pRoot = nullptr;
}

template<typename T>
Binary_tree<T>::Binary_tree(const Bt_node<T>& to_copy)
{
	Binary_tree();
	preOrder(pRoot);
	clear();
	for (int i = 0; i < counter2; i++)
	{
		insert(tab[i]);
	}
	counter2 = 0;
	insert(to_copy);
}

template<typename T>
Binary_tree<T>::Binary_tree(Bt_node<T>&& to_move) noexcept
{
	Binary_tree();
	preOrder(pRoot);
	clear();
	for (int i = 0; i < counter2; i++)
	{
		insert(tab[i]);
	}
	counter2 = 0;
	insert(to_move);
	clear();
}

template<typename T>
typename Bt_node<T>* Binary_tree<T>::operator=(const Bt_node<T>&& to_copy)
{
	if (this != &to_copy)
	{
		Binary_tree();
		preOrder(pRoot);
		clear();
		for (int i = 0; i < counter2; i++)
		{
			insert(tab[i]);
		}
		counter2 = 0;
		insert(to_copy);
	}
	return *this;
}

template<typename T>
Bt_node<T>* Binary_tree<T>::operator=(Bt_node<T>&& to_move) noexcept
{
	if (this != &to_move)
	{
		Binary_tree();
		preOrder(pRoot);
		clear();
		for (int i = 0; i < counter2; i++)
		{
			insert(tab[i]);
		}
		counter2 = 0;
		insert(to_move);
		clear();
	}
	return *this;
}

template<typename T>
Binary_tree<T>::~Binary_tree()
{
	clear();
}

template<typename T>
void Binary_tree<T>::clear()
{
	clear(pRoot);
}

template<typename T>
void Binary_tree<T>::inkrement_counter()
{
	counter++;
}

template<typename T>
void Binary_tree<T>::dekrement_counter()
{
	counter--;
}

template<typename T>
int Binary_tree<T>::get_counter()
{
	return counter;
}

template<typename T>
void Binary_tree<T>::inkrement_counter2()
{
	counter2++;
}

template<typename T>
int Binary_tree<T>::get_counter2()
{
	return counter2;
}

template<typename T>
void Binary_tree<T>::insert(T data_)
{
	inkrement_counter();
	insert(pRoot, data_);
}

template<typename T>
typename Bt_node<T>* Binary_tree<T>::search(T data_)
{
	return search(pRoot, data_);
}

template<typename T>
void Binary_tree<T>::delete_node(T data_)
{
	dekrement_counter();
	delete_node(pRoot, data_);
}

template<typename T>
typename Bt_node<T>* Binary_tree<T>::balance()
{
	inOrder(pRoot);
	clear();
	pRoot = nullptr;
	counter2 = 0;
	return balance(pRoot, 0, (get_counter() - 1));
}

template<typename T>
void Binary_tree<T>::preOrder()
{
	preOrder(Bt_node<T>*&pRoot);
}

template<typename T>
typename Bt_node<T>* Binary_tree<T>::findMin(T data)
{
	Bt_node<T>* result = this->findMin_(this->search(data));
	return result;
}


///////////////////////////////////////////////


template<typename T>
void Binary_tree<T>::clear(Bt_node<T>* elem)
{
	if (elem != nullptr)
	{
		elem->Parent = nullptr;
		clear(elem->pRight);
		clear(elem->pLeft);
		delete elem;
	}
}

template<typename T>
typename Bt_node<T>* Binary_tree<T>::insert(Bt_node<T>*& elem, T data_)
{
	if (not elem)
	{
		elem = new Bt_node<T>{ data_, nullptr,nullptr, nullptr };
	}
	else
	{
		if (data_ < elem->data)
		{
			elem->pLeft = insert(elem->pLeft, data_);
			elem->pLeft->Parent = elem;
		}
		else
		{
			elem->pRight = insert(elem->pRight, data_);
			elem->pRight->Parent = elem;
		}
	}
	return elem;
}

template<typename T>
typename Bt_node<T>* Binary_tree<T>::search(Bt_node<T>* elem, T data_)
{
	if (elem == nullptr)
		return nullptr;
	else
	{
		if (data_ == elem->data)
			return elem;
		if (data_ < elem->data)
			return search(elem->pLeft, data_);
		else
			return search(elem->pRight, data_);
	}
}

template<typename T>
typename Bt_node<T>* Binary_tree<T>::delete_node(Bt_node<T>*& elem, T data_)
{
	if (elem == nullptr)
		return nullptr;
	else
	{
		if (data_ == elem->data)
		{
			if (elem->pLeft == nullptr && elem->pRight == nullptr)
			{
				delete elem;
				elem = nullptr;
				return elem;
			}
			if (elem->pLeft == nullptr && elem->pRight)
			{
				Bt_node<T>* rightFromDelete = elem->pRight;
				Bt_node<T>* parent = elem->Parent;
				Bt_node<T>* toDelete = elem;
				(parent->pRight == toDelete ? parent->pRight = rightFromDelete : parent->pLeft = rightFromDelete);
				rightFromDelete->Parent = parent;
				delete toDelete;
				toDelete = nullptr;

			}
			if (elem->pRight == nullptr && elem->pLeft)
			{
				Bt_node<T>* leftFromDelete = elem->pLeft;
				Bt_node<T>* parent = elem->Parent;
				Bt_node<T>* toDelete = elem;
				(parent->pRight == toDelete ? parent->pRight = leftFromDelete : parent->pLeft = leftFromDelete);
				leftFromDelete->Parent = parent;
				delete toDelete;
				toDelete = nullptr;
			}
			if (elem->pRight && elem->pLeft)
			{
				Bt_node<T>* replacement = findMin_(elem->pRight);
				elem->data = replacement->data;
				if (replacement->pRight != nullptr)
				{
					Bt_node<T>* parent = replacement->Parent;
					Bt_node<T>* rightFromReplacement = replacement->pRight;
					rightFromReplacement->Parent = parent;
					parent->pLeft = rightFromReplacement;
				}
				delete replacement;
				replacement = nullptr;
			}
		}
		if (data_ < elem->data)
		{
			return delete_node(elem->pLeft, data_);
			return elem;
		}
		else
		{
			return delete_node(elem->pRight, data_);
			return elem;
		}
	}
}

template<typename T>
void Binary_tree<T>::inOrder(Bt_node<T>*& elem)
{
	if (elem)
	{
		inOrder(elem->pLeft);
		saveTab(elem->data);
		inOrder(elem->pRight);
	}
}

template<typename T>
void Binary_tree<T>::preOrder(Bt_node<T>*& elem)
{
	if (elem != nullptr)
		saveTab(elem->data);
	preOrder(elem->pLeft);
	preOrder(elem->pRight);
}

template<typename T>
void Binary_tree<T>::saveTab(T data_)
{
	tab[get_counter2()] = data_;
	inkrement_counter2();
}

template<typename T>
typename Bt_node<T>* Binary_tree<T>::balance(Bt_node<T>* elem, int start, int end)
{
	{
		if (start > end)
			return elem;
		int mid = (start + end) / 2;
		insert(elem, tab[mid]);
		balance(elem, start, mid - 1);
		balance(elem, mid + 1, end);
	}
	pRoot = elem;
	return pRoot;
}

template<typename T>
typename Bt_node<T>* Binary_tree<T>::findMin_(Bt_node<T>* elem)
{
	Bt_node<T>* temp = elem;
	Bt_node<T>* temp2;
	while (temp->pLeft != nullptr)
	{
		temp2 = temp->pLeft;
		temp = temp2;
	}
	return temp;
}
