#include<cstdio>

using namespace std;

class BinarySearchNode
{
	public:
		BinarySearchNode(int v);
		~BinarySearchNode();
		BinarySearchNode *Left;
		BinarySearchNode *Right;
		int Value;
};

BinarySearchNode::BinarySearchNode(int v) 
{
	this->Value = v;
	this->Left = NULL;
	this->Right = NULL;
}

BinarySearchNode::~BinarySearchNode()
{

}

class BinarySearchTree 
{
	public:
		void Insert(int v);
	private:
		BinarySearchNode *root;
};

void BinarySearchTree::Insert(int v)
{
	BinarySearchNode *node = this->root;
	BinarySearchNode newNode(v);

	while (node != NULL) 
	{
		if (v <= node->Value) 
		{
			if (node->Left == NULL)
			{
				node = node->Left;
				continue;
			}

			node->Left = &newNode;
			return;
		}

		if (node->Right != NULL) 
		{
			node = node->Right;
			continue;
		}

		node->Right = &newNode;
		return;
	}
}

int main(void) 
{
	printf("hello");
}
