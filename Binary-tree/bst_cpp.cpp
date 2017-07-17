#include <iostream>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree.
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree.
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

//Iterative solution
/*int findMin(BstNode* root) {
    if(root == 0) {
        cout<<"Error!! Empty tree\n";
        return -1;
    }
    while(root->left != 0) {
        root = root->left;
    }
    return root->data;
}*/

//Recursive solution
int findMin(BstNode* root) {
    if(root == 0) {
        cout<<"Error!! Empty tree\n";
        return -1;
    }
    else if(root->left == 0){
        return root->data;
    }
    return findMin(root->left);
}

int findMax(BstNode* root) {
    if(root == 0) {
        cout<<"Error!! Empty tree\n";
        return -1;
    }
    while(root->right != 0) {
        root = root->right;
    }
    return root->data;
}

int findHeight(BstNode* root) {
    if (root == 0) {
        return -1;
    }
    return max(findHeight(root->left),findHeight(root->right))+1;
}

int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,15);
	Insert(root,10);/*root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);      can be assigned like this
	root = Insert(root,8);       root always get the same address
	root = Insert(root,12);*/
	Insert(root,20);
	Insert(root,25);
	Insert(root,8);
	Insert(root,12);
	// Ask user to enter a number.
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";

	cout<<"Min value= "<<findMin(root)<<endl;
	cout<<"Max value= "<<findMax(root)<<endl;

	cout<<"Height of the tree is "<<findHeight(root)<<endl;
}
