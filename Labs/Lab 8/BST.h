/*
Title: Lab8.h
Author: Mitchell Koester
Date: 11/6/2023
Purpose: Header and implementation for BST class
*/
#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

class BST
{
	private:
		struct treeNode
		{
			int value;
			treeNode* left;
			treeNode* right;
		};
		treeNode* root;

		//copy constructor
		void copy(treeNode*& newTreeNode, treeNode* oldTreeNode)
		{
			//base case. If oldTreeNode is null, set newTreeNode to null
			if(!oldTreeNode) newTreeNode = nullptr;
			else
			{
				//set the value for the new tree node to the old tree node
				newTreeNode = new treeNode;
				newTreeNode->value = oldTreeNode->value;

				//if there are children, copy them as well. If values are null, that shouldn't affect the copy
				copy(newTreeNode->left, oldTreeNode->left);
				copy(newTreeNode->right, oldTreeNode->right);
				
			}
		}
		//insert function
		//recursively traverses the tree and inserts the new node in the correct place
		//parameters: treeNode&* oldNode, treeNode* newNode
		//returns void
		void insert(treeNode*& nodePtr, treeNode* newNode)
		{
			//if the node is empty, insert at the current position
			if (!nodePtr)
				nodePtr = newNode;
			//search left branch if the new node value is less than the current node value
			else if (newNode->value < nodePtr->value)
				insert(nodePtr->left, newNode);
			//search right branch if the new node value is greater than the current node value
			else
				insert(nodePtr->right, newNode);
		}
		//displayInOrder function
		//recursively traverses the tree and prints out the values of the nodes
		//parameters: treeNode*
		//returns void
		void displayInOrder(treeNode* nodePtr) const
		{
			//base case if the node is empty
			if(!nodePtr) return;

			displayInOrder(nodePtr->left);
			cout << nodePtr->value << " ";
			displayInOrder(nodePtr->right);
		}
		//destroySubTree function
		//recursively traverses the tree and deletes the nodes
		//parameters: treeNode*
		//returns void
		void destroySubTree(treeNode* nodePtr)
		{
			//base case if the node is empty
			if(!nodePtr) return;

			//call destroySubTree on the left and right branches
			destroySubTree(nodePtr->left);
			destroySubTree(nodePtr->right);
			
			delete nodePtr;
		}

	public:
		//default constructor
		BST()
		{
			root = NULL;
		}			//default constructor
		//copy constructor
		BST(const BST &tree)
		{
			root = NULL;
			copy(root, tree.root);
		}
		//destructor
		~BST()
		{
			destroySubTree(root);
		}

		//insertNode function
		//starts inserting at root and calls insert helper function
		//parameters: int
		//returns void
		void insertNode(int value)
		{
			treeNode* newNode = new treeNode;
			newNode->value = value;
			newNode->left = NULL;
			newNode->right = NULL;
			//insert treenode into the tree
			insert(root, newNode);
		}
		//display function
		//takes root node and calls displayInOrder helper function
		//parameters: none
		//returns void
		void display()
		{
			displayInOrder(root);
		}
};

#endif
