#include "RedBlackTree.h"

Node* binaryInsert(Node *&point, Node *&ptr);
void inorderHelper(Node *&point);
void levelOrderHelper(Node *&point);
void leafSumHelper(Node *&point, int &c);
void pointsAverageHelper(Node *&point, int &c, int &d);

RedBlackTree::RedBlackTree() {
	string value;

	///Beginning
	cout << "\n Enter values to build a tree \n";
	cout << "To end input, enter \"end\" \n";
	cin >> value;

	///Filling the first node
	this -> addElement(stoi(value));

	cin >> value; ///Billet for the second node

	///Fill the tree
	while (value != "end") {
		this -> addElement(stoi(value));
		cin >> value;
	}
}

void RedBlackTree::addElement(const int &value) {
	Node *ptr = new Node(value);

	///Regular tree insert
	point = binaryInsert(point, ptr);

	///Make balance
	makeBalance(point, ptr);
}

Node* binaryInsert(Node *&point, Node *&ptr) {
	///If the tree is emptry return a new node
	if (point == nullptr) {
		return ptr;
	}

	///Recur down the tree
	if (ptr -> value < point -> value) {
		point -> left = binaryInsert(point -> left, ptr);
		point -> left -> parent = point;

	} else if (ptr -> value > point -> value) {
		point -> right = binaryInsert(point -> right, ptr);
		point -> right -> parent = point;
	}

	return point;
}

void RedBlackTree::makeBalance(Node *&point, Node *&ptr) {
	Node *parent_ptr = nullptr;
	Node *grand_parent_ptr = nullptr;
	bool temp;

	while ((ptr != point) && ptr->red && ptr->parent->red) {

		parent_ptr = ptr -> parent;
		grand_parent_ptr = ptr -> parent -> parent;

		///Parent of ptr is left child of grand-parent of ptr
		if (parent_ptr == grand_parent_ptr -> left) {

			Node *uncle_ptr = grand_parent_ptr -> right;

			///The uncle of ptr is also red -> recoloring required
			if (uncle_ptr != nullptr && uncle_ptr->red) {
				grand_parent_ptr -> red = true;
				parent_ptr -> red = false;
				uncle_ptr -> red = false;
				ptr = grand_parent_ptr;

			} else {
				///Ptr is right child of its parent -> left-rotation required
				if (ptr == parent_ptr -> right) {
					rotateLeft(point, parent_ptr);
					ptr = parent_ptr;
					parent_ptr = ptr -> parent;
				}

				///Ptr is left child of its parent -> right-rotation required
				rotateRight(point, grand_parent_ptr);

				temp = parent_ptr -> red;
				parent_ptr -> red = grand_parent_ptr -> red;
				grand_parent_ptr -> red = temp;

				ptr = parent_ptr;
			}

		///Parent of ptr is right child of grand-parent of ptr
		} else {
			Node *uncle_ptr = grand_parent_ptr -> left;

			///The uncle of ptr is also red -> recoloring required
			if ((uncle_ptr != nullptr) && uncle_ptr->red) {
				grand_parent_ptr -> red = true;
				parent_ptr -> red = false;
				uncle_ptr -> red = false;
				ptr = grand_parent_ptr;

			} else {
				///Ptr is left child of its parent -> right-rotation required
				if (ptr == parent_ptr -> left) {
					rotateRight(point, parent_ptr);
					ptr = parent_ptr;
					parent_ptr = ptr -> parent;
				}

				///Ptr is right child of its parent -> left-rotation required
				rotateLeft(point, grand_parent_ptr);

				temp = parent_ptr -> red;
				parent_ptr -> red = grand_parent_ptr -> red;
				grand_parent_ptr -> red = temp;

				ptr = parent_ptr;
			}
		}
	}

	point -> red = false;
}

	void RedBlackTree::rotateRight(Node *&point, Node *&ptr) {
		Node *ptr_left = ptr -> left;

		ptr -> left = ptr_left -> right;

		if (ptr -> left != nullptr) {
			ptr -> left -> parent = ptr;
		}

		ptr_left -> parent = ptr -> parent;

		if (ptr -> parent == nullptr) {
			point = ptr_left;

		} else if (ptr == ptr -> parent -> left) {
			ptr -> parent -> left = ptr_left;

		} else {
			ptr -> parent -> right = ptr_left;
		}

		ptr_left -> right = ptr;
		ptr -> parent = ptr_left;
	}

void RedBlackTree::rotateLeft(Node *&point, Node *&ptr) {
	Node *ptr_right = ptr -> right;

	ptr -> right = ptr_right -> left;

	if (ptr -> right != nullptr) {
		ptr->right->parent = ptr;
	}

	ptr_right -> parent = ptr -> parent;

	if (ptr -> parent == nullptr) {
		point = ptr_right;

	} else if (ptr == ptr -> parent -> left) {
		ptr -> parent -> left = ptr_right;

	} else {
		ptr -> parent -> right = ptr_right;
	}

	ptr_right -> left = ptr;
	ptr -> parent = ptr_right;
}

void RedBlackTree::inorder() {
	cout << "\n Inorder traversal of tree: \n";
	inorderHelper(point);
	cout << endl;
}

void inorderHelper(Node *&point) {
	if (point == nullptr) {
		return;
	}

	inorderHelper(point -> left);
	cout << point -> value << " ";
	inorderHelper(point -> right);
}

void RedBlackTree::levelOrder() {
	cout << "\n Level order traversal of tree: \n";
	levelOrderHelper(point);
	cout << endl;
}

void levelOrderHelper(Node *&point) {
	if (point == nullptr) {
		return;
	}

	queue <Node*> q;
	q.push(point);

	///While queue isn't empty
	while (!q.empty()) {
		Node *temp = q.front();
		cout << temp -> value << " ";
		q.pop();

		if (temp -> left != nullptr) {
			q.push(temp -> left);
		}

		if (temp -> right != nullptr) {
			q.push(temp -> right);
		}
	}
}

void RedBlackTree::leafSum() {
	int c = 0;

	leafSumHelper(point, c);

	cout << "\n The sum of the leaves is: \n";
	cout << c << endl;
}

void leafSumHelper(Node *&point, int &c) {
	if (point -> right != nullptr && point -> left != nullptr) {
		leafSumHelper(point -> left, c);
		leafSumHelper(point -> right, c);

	} else {
		c += point -> value;
	}
}

void RedBlackTree::pointsAverage() {
	int c = 0;
	int d = 0;

	pointsAverageHelper(point, c, d);

	cout << "\n The average of all points is: \n";
	cout << (float) c / float (d)<< endl;
}

void pointsAverageHelper(Node *&point, int &c, int &d) {
	if (point == nullptr) {
		return;
	}

	pointsAverageHelper(point -> left, c, d);
	c += point -> value;
	d++;
	pointsAverageHelper(point -> right, c, d);
}