#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

template <class T>
class Node {
public:
	T data;
	Node<T>* left;
	Node<T>* right;

	Node() {
		left = nullptr;
		right = nullptr;
	}
	Node(T value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}
};

template <class T>
class BinaryTree {
private:
	Node<T>* root;
	int size;

public:

	BinaryTree() {
		root = nullptr;
		size = 0;
	}

	BinaryTree(T value) {
		root = new Node<T>(value);
		size = 1;
	}

	// BinaryTree(const BinaryTree& tree)
	// {
	// 	queue<Node<T>*> seque;
	// 	seque.push(tree.root);
	// 	cout << seque.front()->data << endl;
	// 	while(!seque.empty())
	// 	{
	// 		if (seque.front()->left != nullptr) seque.push(seque.front()->left);
	// 		cout << seque.front()->data << endl;
	// 		if (seque.front()->right != nullptr) seque.push(seque.front()->right);
	// 		cout << seque.front()->data << endl;
	// 		Insert(seque.front()->data);
	// 		seque.pop();
	// 	}		
	// }

	int GetSize() {
		return size;
	}

	void ExTree(int count) {
		for (int i = 0; i < count; Insert(i), i++);
	}

	void Insert(T value) {
		//Node<T>* ptr = new Node<T>(value);
		Node<T>* ptr = root;
		if (!root || size == 0) {
			root = new Node<T>(value);
			//root = ptr;
			// root->data = value;
			size++;
			return;
		}

		while (ptr && ptr->data != value) {
			if (value >= ptr->data && ptr->right == nullptr) {
				ptr->right = new Node<T>(value);
				size++;
				return;
			}
			if (value < ptr->data && ptr->left == nullptr) {
				ptr->left = new Node<T>(value);
				size++;
				return;
			}
			if (value >= ptr->data) ptr = ptr->right;
			if (value < ptr->data) ptr = ptr->left;
		}
	}

	int Find(T value) {
		Node<T>* ptr = root;
		while (ptr && ptr->data != value) {
			if (value > ptr->data) ptr = ptr->right;
			else ptr = ptr->left;
		}
		return ptr != nullptr;
	}

	void Delete(T value) {
		if (size == 1) {
			delete root;
			root = nullptr;
			size--;
			return;
		}

		Node<T>* ptr = root;
		Node<T>* prev_ptr = nullptr;

		while (ptr && ptr->data != value) {
			prev_ptr = ptr;
			if (value > ptr->data) ptr = ptr->right;
			else ptr = ptr->left;
		}

		if (!ptr) return;
		if (ptr->left == nullptr) {
			if (prev_ptr && prev_ptr->left == ptr) prev_ptr->left = ptr->right;
			if (prev_ptr && prev_ptr->right == ptr) prev_ptr->right = ptr->right;
			size--;
			delete ptr;
			ptr = nullptr;
			return;
		}
		if (ptr->right == nullptr) {
			if (prev_ptr && prev_ptr->left == ptr) prev_ptr->left = ptr->left;
			if (prev_ptr && prev_ptr->right == ptr) prev_ptr->right = ptr->left;
			size--;
			delete ptr;
			ptr = nullptr;
			return;
		}
		//else
		Node<T>* buff = ptr->right;
		while (buff->left) {
			buff = buff->left;
		}
		T replace_val = ptr->data;
		Delete(replace_val);
		ptr->data = replace_val;

		cout << "Success!" << endl;

	}

	// string ToStringKLP(Node<T>* node, string res) {
	// 	if (node) {
	// 		res += " < " + to_string;
	// 		res = ToStringKLP
	// 	}
	// }

	void InorderToString(Node<T>* node, string& res) {
		if (!node)
			return;
		InorderToString(node->left, res);
		res+= " " + to_string(node->data);
		InorderToString(node->right, res);
	}


	string ToString() {
		string res = "";
		if (!root || size == 0) { res+= "Empty!"; return res; }
		InorderToString(root, res);
		return res;
	}



	void InorderPrint(Node<T>* node) {
		if (!node)
			return;
		InorderPrint(node->left);
		cout << node->data << " ";
		InorderPrint(node->right);
	}


	void Print() {
		if (!root || size == 0) { cout << "Empty!" << endl; return; }
		InorderPrint(root);
		cout << endl;
	}


	void InorderMap(T scalar, Node<T>* node) {
		if (!node)
			return;
		InorderMap(scalar, node->left);
		node->data = (node->data) * scalar;
		InorderMap(scalar, node->right);
	}

	void Map(T scalar) {
		if (!root || size == 0) return;
		InorderMap(scalar, root);
	}

	void InorderReduce(T& res, Node<T>* node) {
		if (!node) return;
		InorderReduce(res, node->left);
		res = res + node->data;
		InorderReduce(res, node->right); 
	}

	T Reduce() {
		T res = 0;
		if (!root || size == 0) return 0;
		InorderReduce(res, root);
		return res;
	}

	void InorderWhere(T& res, Node<T>* node) {
		if (!node) return;
		InorderReduce(res, node->left);
		res = res + node->data;
		InorderReduce(res, node->right);
	}

	void Where(T condition) {
		if (!root || size == 0) return;
		WhereCondition(condition, root);
		return;
	}

	void WhereCondition(T condition, Node<T>* node) {
		if (!node) return;
		WhereCondition(condition, node->left);
		WhereCondition(condition, node->right);
		if (node->data >= condition) Delete(node->data);
	}

	void Merge(BinaryTree<T>* tree2) {
		T* arr2 = tree2->ToArray();
		for (int i = 0; i < tree2->size; Insert(arr2[i]), i++);
	}

	void SubTreeEntry(BinaryTree<T>* tree2) {
		bool res = false;
		Node<T>* node1 = FindNode(tree2->root->data);
		res = DetourSubTreeFind(node1, tree2->root);
		cout << "SUDA :" << res << endl;
		return;
	}

	bool DetourSubTreeFind(Node<T>* node1, Node<T>* node2) {
		if (!node2) return true;
		if (node1->data != node2->data) return false;
		bool res;
		res = DetourSubTreeFind(node1->left, node2->left);
		if (!res) return false;
		res = DetourSubTreeFind(node1->right, node2->right);
		return true;
	}
	
	Node<T>* FindNode(T value) {
		Node<T>* ptr = root;
		while (ptr && ptr->data != value) {
			if (value > ptr->data) ptr = ptr->right;
			else ptr = ptr->left;
		}
		return ptr;
	}
	
	void InorderArray(Node<T>* node, T* arr) {
		if (!node)
			return;
		InorderArray(node->left, arr);
		*arr = node->data; arr++;
		InorderArray(node->right, arr);
	}


	T* ToArray() {
		T* arr = new T[size];
		if (!root || size == 0) { return NULL;}
		InorderArray(root, arr);
		return arr;
	}

	void InsertFromMassive(T* array, int lenght)
	{
		for (int i = 0; i < lenght; Insert(array[i]), i++);
		return;
	}

	BinaryTree<T>* SubTree(T value) {
		Node<T>* ptr = root;
		while (ptr && ptr->data != value) {
			if (value > ptr->data) ptr = ptr->right;
			else ptr = ptr->left;
		}
		BinaryTree<T>* res = new BinaryTree<T>();
		res->root = ptr;
		return res;
	}

	int BinaryRight(BinaryTree<T> tree)
	{

	}

	int BinaryWay(Node<T>* node, bool flag) {
		if (!flag)
		if (!node) return 0;
		if (node->left->data > node->data) return 0;
		BinaryWay(node->left);

		BinaryWay(node->right);
	}

};

