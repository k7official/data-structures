//triple ended queue
#include<iostream>
using namespace std;

#define SIZE 5

template <class Type> 
class Node
{
public:
    Type data;
    Node<Type>* left_link, *right_link;
    Node() 
    { 
        left_link = right_link = 0; 
    }
    Node(Type d)
    {
        data = d;
        left_link = right_link = NULL;
    }
    Node(Type d, Node<Type> *l, Node<Type> *r) :
        data(d), left_link(l), right_link(r) {};
};

template<class Type>
class TreQueue
{
public:
    TreQueue() 
    { 
        front = rear = middle = 0; 
        size = 0; 
    }
    int length()
    {
        return size;
    }
    Node<Type>*first()
    {
        return front;
    }
    void addFront(const Type k)
    {
        Node<Type> *newnode = new Node<Type>(k);
        if(isFull())
            cout << "Queue is full, could not add node" << endl;
        else if(front == 0)
        {
            front = rear = middle = newnode;
        }
        else
        {
            newnode->right_link = front;
            front->left_link = newnode;
            front = newnode;
        }
        if(size%2 == 1)
            middle = middle->left_link;
        size++;
    }
    void addRear(const Type k)
    {
        Node<Type> *newnode = new Node<Type>(k);
        if(isFull())
            cout << "Queue is full, could not add node" << endl;
        else if(rear == 0)
        {
            front = rear = middle = newnode;
        }
        else
        {
            newnode->left_link = rear;
            rear->right_link = newnode;
            rear = newnode;
        }
        if(size%2 == 0)
            middle = middle->right_link;
        size++;
    }
    void addMiddle(const Type k)
    {
        Node<Type> *newnode = new Node<Type>(k);
        if(isFull())
            cout << "Queue is full, could not add node" << endl;
        else if (middle == 0) 
        {
            front = rear = middle = newnode;
        }
        else if(size%2 == 0)
        {
            newnode->left_link = middle;
            newnode->right_link = middle->right_link;
            middle->right_link->left_link = newnode;
            middle->right_link = newnode;
            middle = newnode;
        }
        else
        {
            newnode->right_link = middle;
            newnode->left_link = middle->left_link;
            middle->left_link->right_link = newnode;
            middle->left_link = newnode;
            middle = newnode; // some thoughts here
        }
        size++;
    }
    Type deleteFront()
    {
        Node<Type> *t = front;
        Type val = t->data;
        if(front == 0) 
            cout << "Queue is empty, unable to delete." <<endl;
        else if(size == 1)
        {
            front = rear = middle = 0;
        }
        else
        {
            front->right_link->left_link = 0;
            front = front->right_link;
            if(size %2 == 0)
                middle = middle->right_link;
            delete t;
        }
        size--;
        return val;
    }
    Type deleteRear()
    {
        Node<Type> *t = rear;
        Type val = t->data;
        if(rear==0)
            cout << "Queue is empty, unable to delete." <<endl;
        else if(size == 1)
        {
            front = rear = middle = 0;
        }
        else
        {
            rear->left_link->right_link = 0;
            rear = rear->left_link;
            if(size%2 == 1)
                middle = middle->left_link;
            delete t;
        }
        size--;
        return val;
    }
    Type deleteMiddle()
    {
        Node<Type> *t = middle;
        Type val = t->data;
        if(middle==0)
            cout << "Queue is empty, unable to delete." <<endl;
        else if(size == 1)
        {
            front = rear = middle = 0;
        }
        else
        {
            middle->right_link->left_link = middle->left_link;
            middle->left_link->right_link = middle->right_link;
            if(size%2 == 0)
                middle = middle->right_link;
            else
                middle = middle->left_link;
            delete t;
        }
        size--;
        return val;
    }
    bool isFull()
    {
        if(size == SIZE)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if(size == 0)
            return true;
        else
            return false;
    }
    void Display()
    {
        Node<Type> *node = front;
        while(node && node->right_link){
            cout << node->data << "->";
            node = node->right_link;
        }
        if(node){
            cout << node->data << endl;
        }
        else{
            cout << "Empty Queue." << endl;
        }
    }
    Type getMiddle()
    {
        return middle->data;
    }
private:
    Node<Type> *front, *middle, *rear;
    int size;
};
int main()
{
    TreQueue<int>* q = new TreQueue<int>();
    q->addFront(1);
    cout << "Middle: " << q->getMiddle() << endl;
    q->addFront(2);
    cout << "Middle: " << q->getMiddle() << endl;
    q->addFront(3);
    cout << "Middle: " << q->getMiddle() << endl;
    q->addRear(5);
    cout << "Middle: " << q->getMiddle() << endl;
    q->addMiddle(4);
    cout << "Middle: " << q->getMiddle() << endl;
    //q->addFront(7);//full
    q->Display();
    cout << "Middle: " << q->getMiddle() << endl;
    cout << "Deleted from front: " << q->deleteFront() << endl;
    cout << "Middle: " << q->getMiddle() << endl;
    cout << "Deleted from rear: " << q->deleteRear() << endl;
    cout << "Middle: " << q->getMiddle() << endl;
    cout << "Deleted from middle: " << q->deleteMiddle() << endl;
    cout << "Middle: " << q->getMiddle() << endl;
    q->Display();
    q->addRear(3);
    cout << "Middle: " << q->getMiddle() << endl;
    q->Display();

    return 0;
}