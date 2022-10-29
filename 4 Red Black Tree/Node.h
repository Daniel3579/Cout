#ifndef COUT_NODE_H
#define COUT_NODE_H

struct Node {
	int value;
	bool red;
	Node* parent;
	Node* right;
	Node* left;

	Node(int value) {
		this -> value = value;
		parent = nullptr;
		right = nullptr;
		left = nullptr;
		this -> red = true;
	}
};

#endif //COUT_NODE_H