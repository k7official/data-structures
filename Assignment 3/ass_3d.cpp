//Tree template class
#ifndef _IOSTREAM_H
#include <iostream>
#define _IOSTREAM_H
#endif

using namespace std;

enum Boolean { FALSE, TRUE};

class Tree;

class TreeNode {
friend class Tree;
friend int equal(TreeNode*, TreeNode*);
private:
    TreeNode *LeftChild;
    int data;
    TreeNode *RightChild;
    TreeNode() {LeftChild = RightChild = 0;};
    TreeNode(int d, TreeNode *Lefty, TreeNode *Righty)
    {
	data = d;
	LeftChild = Lefty;
	RightChild = Righty;
    }
};

class Tree {
friend int operator==(const Tree&, const Tree&);
private:
    TreeNode *root;
    void inorder(TreeNode *);
    void preorder(TreeNode *);
    void postorder(TreeNode *);
    TreeNode* copy(TreeNode *);
public:
    void setup();
    void inorder();
    void preorder();
    void postorder();
    Tree(const Tree&);
    Tree() {root = 0;};
    int size(TreeNode *);
    int height(TreeNode *);
    TreeNode* getRoot();
    int sum(TreeNode*);
};

int Tree::sum(TreeNode *p)
{
    int x=0,y=0;
    if(p)
    {
        x = sum(p->LeftChild);
        y = sum(p->RightChild);
        return x+y+p->data;
    }
    return 0;
}

TreeNode* Tree::getRoot(){return root;}

int Tree::size(TreeNode *p)
{
    int x=0,y=0;
    if(p)
    {
        x = size(p->LeftChild);
        y = size(p->RightChild);
        return x+y+1;
    }
    return 0;
}

int Tree::height(TreeNode *p)
{
    int x=0, y=0;
    if(p==0)
        return 0;
    x = height(p->LeftChild);
    y = height(p->RightChild);
    if(x > y)
        return x + 1;
    else
        return y + 1;
}

void Tree::setup()
{
    root = new TreeNode(1,0,0);
    root->LeftChild = new TreeNode(2,0,0);
    root->LeftChild->LeftChild = new TreeNode(3, 0, 0);
    root->LeftChild->RightChild = new TreeNode(4, 0, 0);
    root->LeftChild->LeftChild->LeftChild = new TreeNode(5, 0, 0);
}

void Tree::inorder()
{
   inorder(root);
}

void Tree::preorder()
{
   preorder(root);
}

void Tree::postorder()
{
   postorder(root);
}

void Tree::inorder(TreeNode *CurrentNode)
{
     if (CurrentNode) {
	 inorder(CurrentNode->LeftChild);
	 cout << CurrentNode->data;
	 inorder(CurrentNode->RightChild);
     }
}

void Tree::preorder(TreeNode *CurrentNode)
{
     if (CurrentNode) {
	 cout << CurrentNode->data;
	 preorder(CurrentNode->LeftChild);
	 preorder(CurrentNode->RightChild);
     }
}

void Tree::postorder(TreeNode *CurrentNode)
{
     if (CurrentNode) {
	 postorder(CurrentNode->LeftChild);
	 postorder(CurrentNode->RightChild);
	 cout << CurrentNode->data;
     }
}

Tree::Tree(const Tree& s)
{
  root = copy(s.root);
}

TreeNode* Tree::copy(TreeNode *orignode)
{
  if (orignode) {
      TreeNode *temp = new TreeNode;
      temp->data = orignode->data;
      temp->LeftChild = copy(orignode->LeftChild);
      temp->RightChild = copy(orignode->RightChild);
      return temp;
  }
  else return 0;
}

// Driver
int operator==(const Tree& s, const Tree& t)
{
   return equal(s.root, t.root);
}

// Workhorse
int equal(TreeNode *a, TreeNode *b)
/* This function returns 0 if the subtrees at @a@ and @b@ are not
   equivalent. Otherwise, it will return 1 */
{
 if ((!a) && (!b)) return 1;  // both @a@ and @b@ are 0
 if (a && b &&                // both @a@ and @b@ are non-0
    (a->data == b->data)      // @data@ is the same
    && equal(a->LeftChild, b->LeftChild) // left subtrees are the same
    && equal(a->RightChild, b->RightChild) ) // right subtrees are the same
       return 1;
 return 0;
}

int main()
{
    Tree t;
    t.setup();
    Tree s = t;
    s.inorder();
    cout << endl;
    if (s == t) cout << 1; else cout << 0;
    cout << endl;
    cout << "The height of this tree is: " << s.height(s.getRoot()) << endl;
    cout << "The size of this tree is: " << s.size(s.getRoot())<< endl; 
    cout << "The sum of all data in tree is: " << s.sum(s.getRoot()) << endl;
    return 0;
}

