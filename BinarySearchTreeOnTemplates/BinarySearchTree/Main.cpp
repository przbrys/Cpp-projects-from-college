#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include<string>
int main()
{
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		Binary_tree<std::string> bst1{};
		Binary_tree<int> bst{};

		int tab[8] = { 10,5,15,12,20,14,2,13 };
		//int tab2[8] = { 15,20,17,25,27,1,1,1 };

		for (auto i = 0; i < 8; i++)
		{
			bst.insert(tab[i]);
			//bst1.insert(tab[i]);
		}

		bst.delete_node(15);
		bst.search(12);
		//bst.delete_node(5);
		//bst.delete_node(12);

		bst1.balance();
		bst.search(12);
	}
	_CrtDumpMemoryLeaks();
	return 0;
}


