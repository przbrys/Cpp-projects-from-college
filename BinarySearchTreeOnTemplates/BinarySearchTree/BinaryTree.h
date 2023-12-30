#ifndef _Binary_tree_H_
#define _Binary_tree_H_
#include<iostream>

template<typename T>
struct Bt_node
{
	T data;
	Bt_node* pLeft;
	Bt_node* pRight;
	Bt_node* Parent;
};

template<typename T>
class Binary_tree
{
public:

	Binary_tree();
	Binary_tree(const Bt_node<T>& to_copy);
	Binary_tree(Bt_node<T>&& to_move) noexcept;
	Bt_node<T>* operator=(const Bt_node<T>&& to_copy);
	Bt_node<T>* operator=(Bt_node<T>&& to_move) noexcept;
	~Binary_tree();

	void clear();

	void inkrement_counter();
	void dekrement_counter();
	int get_counter();
	void inkrement_counter2();
	int get_counter2();

	void insert(T data_);
	Bt_node<T>* search(T data_);
	void delete_node(T data_);
	Bt_node<T>* balance();
	void preOrder();
	Bt_node<T>* findMin(T data);

private:
	Bt_node<T>* pRoot;
	int counter;
	int counter2;
	T tab[20];

	void clear(Bt_node<T>* elem);
	Bt_node<T>* insert(Bt_node<T>*& elem, T data_);
	Bt_node<T>* search(Bt_node<T>* elem, T data_);
	Bt_node<T>* delete_node(Bt_node<T>*& elem, T data_);
	void inOrder(Bt_node<T>*& elem);
	void preOrder(Bt_node<T>*& elem);
	void saveTab(T data_);
	Bt_node<T>* balance(Bt_node<T>* elem, int start, int end);
	Bt_node<T>* findMin_(Bt_node<T>* elem);
};

#endif 