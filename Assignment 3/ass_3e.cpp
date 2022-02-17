#include <iostream>
using namespace std;

class TreeNode;
class Tree;

class Header
{
public:
    Header() {
        data = {};
        nextHeader = 0;
        nextOfType = 0;
    }
    int data;
    Header* nextHeader;
    TreeNode* nextOfType;
};

class TreeNode {
    friend class Tree;
    friend int equal(TreeNode*, TreeNode*);
    friend int size(TreeNode*);
    friend int height(TreeNode*);
    friend int sum(TreeNode*);
    friend void link(TreeNode*);
private:
    TreeNode* LeftChild;
    int data;
    TreeNode* RightChild;
    TreeNode* nextLikeNode;
    TreeNode() { LeftChild = RightChild = nextLikeNode = 0; data = {}; };
    TreeNode(int d, TreeNode* Lefty, TreeNode* Righty, TreeNode* nLn = 0)
    {
        data = d;
        LeftChild = Lefty;
        RightChild = Righty;
        nextLikeNode = nLn;
    }
};

class Tree {
    friend int operator==(const Tree&, const Tree&);
    friend class LinkedTree;
private:
    TreeNode* root;
    void inorder(TreeNode*);
    void preorder(TreeNode*);
    void postorder(TreeNode*);
    TreeNode* copy(TreeNode*);
    Header* header;
    void link(TreeNode*);
public:
    void setup();
    void inorder();
    void preorder();
    void postorder();
    void link();
    Tree(const Tree&);
    Tree() {
        root = 0; 
        header = 0; 
    };
    TreeNode* getRoot() { return root; }
    Header* getHeader() { return header; }

    Header* findHeader(int d) {
        if (!header) return NULL;
        Header* iter = header;              
        while (iter && iter->data != d) {
            iter = iter->nextHeader;
        }
        return iter;
    }
    TreeNode* findNextOfType(TreeNode* tN) {
        TreeNode* iter =tN;
        while (tN->nextLikeNode) {
            tN = tN->nextLikeNode;
        }
        return tN;
    }

    void printHeaders() {
        Header* h = header;
        while (h) {
            cout << h->data<<": ";
            TreeNode* iter = h->nextOfType;
            while (iter) {
                cout << h->nextOfType->data << " ";
                iter = iter->nextLikeNode;
            }
            cout << endl;
            h = h->nextHeader;
        }
        
    }
};

void Tree::setup()
{
    root = new TreeNode(10, 0, 0);
    root->LeftChild = new TreeNode(20, 0, 0);
    root->LeftChild->LeftChild = new TreeNode(30, 0, 0);
    root->LeftChild->RightChild = new TreeNode(40, 0, 0);
    root->LeftChild->LeftChild->LeftChild = new TreeNode(50, 0, 0);
    root->LeftChild->LeftChild->RightChild = new TreeNode(30, 0, 0);
    root->LeftChild->RightChild->LeftChild = new TreeNode(40, 0, 0);
    root->LeftChild->LeftChild->LeftChild->LeftChild = new TreeNode(50, 0, 0);
    root->LeftChild->RightChild->LeftChild->RightChild = new TreeNode(40, 0, 0);
    root->LeftChild->LeftChild->LeftChild->LeftChild->RightChild = new TreeNode(10, 0, 0);
    root->LeftChild->LeftChild->LeftChild->LeftChild->RightChild = new TreeNode(20, 0, 0);
    root->LeftChild->LeftChild->LeftChild->LeftChild->RightChild->LeftChild = new TreeNode(80, 0, 0);

    link();
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

void Tree::link()
{
    link(root);
}

void Tree::link(TreeNode* tN) {
    if (tN) {
        int d = tN->data;
        Header* head = findHeader(d);
        if (!head && !header) {
            header = new Header();
            header->data = d;
            header->nextOfType = tN;
            header->nextHeader = NULL;
        }
        else if (!head) {
            Header* iter = header;
            while (iter->nextHeader) {
                iter = iter->nextHeader;
            }
            head = new Header();
            head->data = d;
            head->nextOfType = tN;
            head->nextHeader = NULL;
            iter->nextHeader = head;

        }
        else {
            TreeNode* iter = head->nextOfType;
            while (iter->nextLikeNode) {
                iter = iter->nextLikeNode;
            }
            iter->nextLikeNode = tN;
        }
        link(tN->LeftChild);
        link(tN->RightChild);
    }
}



void Tree::inorder(TreeNode* CurrentNode)
{
    if (CurrentNode) {
        inorder(CurrentNode->LeftChild);
        cout << CurrentNode->data << " ";
        inorder(CurrentNode->RightChild);
    }
}

void Tree::preorder(TreeNode* CurrentNode)
{
    if (CurrentNode) {
        cout << CurrentNode->data;
        preorder(CurrentNode->LeftChild);
        preorder(CurrentNode->RightChild);
    }
}

void Tree::postorder(TreeNode* CurrentNode)
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

TreeNode* Tree::copy(TreeNode* orignode)
{
    if (orignode) {
        TreeNode* temp = new TreeNode;
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
int equal(TreeNode* a, TreeNode* b)
/* This function returns 0 if the subtrees at @a@ and @b@ are not
   equivalent. Otherwise, it will return 1 */
{
    if ((!a) && (!b)) return 1;  // both @a@ and @b@ are 0
    if (a && b &&                // both @a@ and @b@ are non-0
        (a->data == b->data)      // @data@ is the same
        && equal(a->LeftChild, b->LeftChild) // left subtrees are the same
        && equal(a->RightChild, b->RightChild)) // right subtrees are the same
        return 1;
    return 0;
}

int size(TreeNode* n) {
    static int s = 0;
    if (n) {
        size(n->LeftChild);
        s++;
        size(n->RightChild);
    }
    return s;
}

int height(TreeNode* n) {
    static int h = 0;
    //check if root exists
    if (h == 0 && n) {
        h = 1;
    }
    if (n) {
        int child = 0;
        //check if LeftChild Exists
        if (n->LeftChild) {
            child++;
            height(n->LeftChild);
        }
        //check if RightChild Exists
        if (n->RightChild) {
            child++;
            height(n->RightChild);
        }
        //If a child was found increase height
        if (child > 0)
            h++;
    }
    return h;
}

int sum(TreeNode* n) {
    static int s = 0;
    if (n) {
        s += n->data;
        sum(n->LeftChild);
        sum(n->RightChild);
    }
    return s;
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
    cout << size(t.getRoot());
    cout << endl;
    cout << height(t.getRoot());
    cout << endl;
    cout << sum(t.getRoot());
    cout << endl;
    t.printHeaders();
}



