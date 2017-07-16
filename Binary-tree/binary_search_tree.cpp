#include <iostream>
#include <cstdlib>
using namespace std;

class bst
{
	struct node
	{
		int key;
		node* left;
		node* right;
	};
	node* root;
	node* createLeaf(int key) {
		node* n = new node;
		n->key = key;
		n->left = n->right = NULL;

		return n;
	}
	void addLeafPrivate(int key, node* ptr) {
		if(root == NULL) {
			root = createLeaf(key);
		}
		else if(key < ptr->key) {
			if(ptr->left != 0) {
				addLeafPrivate(key,ptr->left);
			}
			else {
				ptr->left = createLeaf(key);
			}
		}
		else if(key > ptr->key) {
			if(ptr->right != 0) {
				addLeafPrivate(key,ptr->right);
			}
			else {
				ptr->right = createLeaf(key);
			}
		}
		else {
			cout<<"The key "<<key<<" has already been added to the tree\n";
		}
	}
	void printInOrderPrivate(node* ptr) {
		if(root != 0) {
			if(ptr->left != 0) {
				printInOrderPrivate(ptr->left);
			}
			cout<<ptr->key<<" ";
			if(ptr->right != 0) {
				printInOrderPrivate(ptr->right);
			}
		}
		else {
			cout<<"The tree is empty\n";
		}
	}
public:
	bst():root(0){}
	void addLeaf(int key) {
		addLeafPrivate(key,root);
	}
	void printInOrder() {
		printInOrderPrivate(root);
	}

};

int main() {
	int treekeys[] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

	bst myTree;

	cout<<"Print the tree in order \nbefore adding numbers\n";

	myTree.printInOrder();

	cout<<"Print the tree in order \nafter adding numbers\n";

	for(int i = 0; i<16; i++) {
		myTree.addLeaf(treekeys[i]);
	}
	myTree.printInOrder();

	return 0;
}
