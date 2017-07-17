#include <iostream>
#include <cstdlib>
#include <queue>
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

	int findHeightPrivate(node* ptr) {
		if(ptr ==0) {
			return -1;
		}
		return max(findHeightPrivate(ptr->left),findHeightPrivate(ptr->right)) +1;
	}

	//Function to print the keys in preorder
	void preOrderPrivate(node* ptr) {
		if(ptr == 0) return;
		cout<<ptr->key<<" ";
		preOrderPrivate(ptr->left);
		preOrderPrivate(ptr->right);
	}

	//Function to print the keys in postorder
	void postOrderPrivate(node* ptr) {
		if(ptr == 0) return;
		postOrderPrivate(ptr->left);
		postOrderPrivate(ptr->right);
		cout<<ptr->key<<" ";
	}

	//Function to print the keys in level Order
	void levelOrderPrivate(node* ptr) {
		if(ptr == 0) return;
		queue<node*> Q;
		Q.push(ptr);
		while(!Q.empty()) {
			node* current = Q.front();
			cout<<current->key<<" ";
			if(current->left!=0) Q.push(current->left);
			if(current->right!=0) Q.push(current->right);
			Q.pop();
		}
	}

	bool SearchPrivate(node* ptr,int data) {
		if(ptr == NULL) {
			return false;
		}
		else if(ptr->key == data) {
			return true;
		}
		else if(data < ptr->key) {
			return SearchPrivate(ptr->left,data);
		}
		else {
			return SearchPrivate(ptr->right,data);
		}
	}


	//Returns the address of the node with minimum value
	node* findMin(node* ptr) {
		while(ptr->left != NULL) ptr = ptr->left;
		return ptr;
	}

	//Returns the address of the node with maximum value
	node* findMax(node* ptr) {
		while(ptr->right != NULL) ptr = ptr->right;
		return ptr;
	}

		// Function to search a delete a value from tree.
	node* Delete(node *ptr, int key) {
		if(ptr == NULL) return ptr;
		else if(key < ptr->key) ptr->left = Delete(ptr->left,key);
		else if (key > ptr->key) ptr->right = Delete(ptr->right,key);
		// Found, Get ready to be deleted
		else {
			// Case 1:  No child
			if(ptr->left == NULL && ptr->right == NULL) {
				delete ptr;
				ptr = NULL;
			}
			//Case 2: One child
			else if(ptr->left == NULL) {
				node *temp = ptr;
				ptr = ptr->right;
				delete temp;
			}
			else if(ptr->right == NULL) {
				node *temp = ptr;
				ptr = ptr->left;
				delete temp;
			}
			// case 3: 2 children
			else {
				node *temp = findMin(ptr->right);
				ptr->key = temp->key;
				ptr->right = Delete(ptr->right,temp->key);
			}
		return ptr;
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
	int findMinVal() {
		if(root == 0) {
			cout<<"Error!! empty tree\n";
			return -1;
		}
		node* current = root;
		while(current->left != 0) {
			current = current->left;
		}
		return current->key;
	}

	int findMaxVal() {
		if(root == 0) {
			cout<<"Error!! empty tree\n";
			return -1;
		}
		node* current = root;
		while(current->right != 0) {
			current = current->right;
		}
		return current->key;
	}

	void DeleteNode(int data) {
		Delete(root,data);
	}


	int findHeight() {
		return findHeightPrivate(root);
	}

	void preOrder() {
		if(root!=0)
			preOrderPrivate(root);
		else
			cout<<"Error!! empty tree\n";
	}

	void postOrder() {
		if(root!=0)
			postOrderPrivate(root);
		else
			cout<<"Error!! empty tree\n";
	}

	void levelOrder() {
		if(root==0)
			cout<<"Can't print from an empty tree\n";
		else
			levelOrderPrivate(root);
	}

	bool Search(int data) {
		return SearchPrivate(root,data);
	}

};

int main() {
	int treekeys[] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

	bst myTree;

	cout<<"Print the tree in order \nbefore adding numbers\n";

	myTree.printInOrder();
    myTree.preOrder();
	cout<<"Print the tree in order \nafter adding numbers\n";

	for(int i = 0; i<16; i++) {
		myTree.addLeaf(treekeys[i]);
	}

	cout<<"Enter the key that should be Searched in the tree: ";
	int number;
	cin>>number;
	if(myTree.Search(number))
		cout<<"Found\n";
	else
		cout<<"Not Found\n";
    cout<<endl;
	cout<<"Inorder traversal\n";
	myTree.printInOrder();
	cout<<"\nPreorder traversal\n";
	myTree.preOrder();
	cout<<"\nPostOrder traversal\n";
	myTree.postOrder();
	cout<<"\nLevelOrder traversal\n";
	myTree.levelOrder();

	cout<<"\nMin value "<<myTree.findMinVal()<<endl;
	cout<<"Max value "<<myTree.findMaxVal()<<endl;

	myTree.DeleteNode(50);
	cout<<endl;
	myTree.printInOrder();
	cout<<endl;

	cout<<"Height of the tree is "<<myTree.findHeight()<<endl;

	return 0;
}
