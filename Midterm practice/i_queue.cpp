#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        counter = 0;
    }
    bool isEmpty()
    {
        if(front == NULL && rear == NULL)
            return true;
        return false;
    }
    void enqueue(int x, int i)
    {
        Node *newNode = new Node;
        if(i>counter)
            cout << "i_val greater than elements in list"<<endl;
        else if(newNode == NULL)
            cout << "Queue is full" << endl;
        else
        {
            counter++;
            newNode->data = x;
            newNode->next = NULL;
            if(isEmpty())
                front = rear = newNode;
            else if(i==0)
            {
                newNode->next = front;
                front = newNode;
            }
            else
            {
                int j = 0;
                Node *temp = front;
                while(j<i-1)
                {
                    temp = temp->next;
                    j++;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        } 
    }
    int dequeue()
    {
        int x;
        Node *temp;
        if(isEmpty())
        {
             cout << "Queue is empty" << endl;
        }
        x = front->data;
        if(front == rear)//one element in the queue
            front = rear = NULL;
        else
        {
            temp = front;
            front = front->next;
            delete temp;
        }
        return x;
    }
    void display()
    {
        for(Node *temp = front; temp != NULL; temp = temp->next)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    }
private:
    Node *front, *rear;
    int counter;
};

int main()
{
    Queue q;
    q.enqueue(1, 0);
    q.enqueue(2, 1);
    q.enqueue(3, 2);
    q.enqueue(5, 0);
    q.enqueue(6, 1);
    q.display();
    return 0;
}