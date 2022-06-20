#pragma once


template<typename T>
class BinaryTree
{
public:
	struct  Node;

	BinaryTree() {}

	~BinaryTree()
	{
		Destroy(root);

	}


	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = node->Right = nullptr;

		return node;
	}

	void DestroyNode(Node* node)
	{
		delete node;
		node = nullptr;
	}

	void Root(Node* node) { root = node; }


private:
	void Destroy(Node* node)
	{
		if (node == nullptr) return;
		Destroy(node->Left);
		Destroy(node->Right);
		DestroyNode(node);

	}

public:
	void PreOrder(Node* node)
	{
		if (node == nullptr) return;

		cout << node->Data << " ";
		PreOrder(node->Left);
		PreOrder(node->Right);
	}

	void InOrder(Node* node)
	{
		if (node == nullptr) return;

		InOrder(node->Left);
		cout << node->Data << " ";
		InOrder(node->Right);


	}

	void PostOrder(Node* node)
	{
		if (node == nullptr) return;

		PostOrder(node->Left);
		PostOrder(node->Right);
		cout << node->Data << " ";
	}

private:
	struct Node
	{
		T Data;
		Node* Left;
		Node* Right;
	};

	Node* root;




};