#include<iostream>
#include<cstdlib>
#include<ctime>
#include<queue>

using namespace std;

class Node
{
public:
	int level, data;
	Node *left, *right;
};

class Tree
{
public:
	Tree()
	{
		root = NULL;
	}
	int insert(Node *n)
	{
		insert(&root, n);
        return true;
	}
	void inorder()
	{
		Node *temp = root;
		inorder(temp);
	}
	void inorder(Node *root)
	{
        if(root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
	}
	void preorder()
	{
		Node *temp = root;
		preorder(temp);
	}
	void preorder(Node *root)
	{
        if(root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
	}
	void postorder()
	{
		Node *temp = root;
		postorder(temp);
	}
	void postorder(Node *root)
	{
        if(root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
        
	}
	void levelorder()
	{
        Node *temp = root;
        if(root == NULL)
            return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())//while there exist at least one discovered node
        {
            Node *cur = q.front();
            cout << cur->data << " ";
            if(cur->left != NULL)
                q.push(cur->left);
            if(cur-> right != NULL)
                q.push(cur->right);
            q.pop();//removing element from front
        }
	}
private:
	Node *root;
	void insert(struct Node **r, struct Node *n)
	{
		if(*r == NULL)
			*r = n;
		else if(n->data > (*r)->data)
			insert(&((*r)->right), n);
		else
			insert(&((*r)->left), n);
	}
};

int main()
{
	Tree *tree = new Tree();
	Node *node;
	int j;
	srand(time(NULL));
	for(j = 0;j < 5;j ++)
	{
		node = new Node();
		node->data = j;
		node->left = NULL;
		node->right = NULL;
		tree->insert(node);

	}
	tree->inorder();
	printf("\n");
	tree->preorder();
	printf("\n");
	tree->postorder();
	printf("\n");
	tree->levelorder();
	printf("\n");
}
