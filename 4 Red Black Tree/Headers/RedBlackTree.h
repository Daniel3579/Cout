#ifndef COUT_REDBLACKTREE_H
#define COUT_REDBLACKTREE_H

#include "Node.h"
#include <iostream>
#include <queue>

using namespace std;

class RedBlackTree {
	private:
		Node *point = nullptr;

	public:
		RedBlackTree();
		void inorder();
		void levelOrder();
		void leafSum();
		void pointsAverage();

	private:
		void addElement(const int &value);
		void makeBalance(Node *&point, Node *&ptr);
		void rotateRight(Node *&point, Node *&ptr);
		void rotateLeft(Node *&point, Node *&ptr);
};

#endif //COUT_REDBLACKTREE_H
