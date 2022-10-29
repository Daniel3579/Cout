#include "RedBlackTree.h"

int main() {
	RedBlackTree tree;

	tree.inorder();
	tree.levelOrder();
	tree.leafSum();
	tree.pointsAverage();

	return 0;
}