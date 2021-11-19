#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class Dequeue
{
public:
    Dequeue()
    {
        front = NULL;
        rear  = NULL;
    }
    void frontInsert(int x)//like push in stack
    {
        Node *newNode = new Node;
         if(newNode == NULL)
            cout << "Queue is full" << endl;
        else
        {
            newNode->data = x;
            newNode->next = NULL;
            if(front == NULL)
            {
                front = rear = newNode;
            }
            else
            {
                newNode->next = front;
                front = newNode;
            }
        }
    }
    int frontDelete()//similar to dequeue in Queue
    {
        int x;
        Node *temp;
        if(front == NULL)
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
    void rearInsert(int x)//like enqueue in Queue   
    {
        Node *newNode = new Node;
        if(newNode == NULL)
            cout << "Queue is full" << endl;
        else
        {
            newNode->data = x;
            newNode->next = NULL;
            if(front == NULL)
                front = rear = newNode;
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
        } 
    }
    int rearDelete()//like pop in stack
    {
        Node *temp = front;
        int x;
        if(front == NULL)
            cout << "Deque is empty" << endl;
        else if(front->next == NULL)    
        {
            x = front->data;
            delete front;
            front = rear = NULL;
        } 
        else//need to traverse to rear
        {
            for(temp = front; temp->next!=rear; temp = temp->next);//will run by itself, will terminate with the semi-colon
            x = temp->data;
            delete rear;
            temp->next = NULL;
            rear = temp;
        }
        return x;
    }
    void display()
    {
        if(front == NULL)
            cout<<"Deque is empty"<<endl;
        else
        {
            for(Node *t=front; t!=NULL; t=t->next)
            {
                cout << t->data << " ";
            }
            cout << "NULL";
            cout << endl;
        }
    }

private:
    Node *front, *rear;
};

int main()
{
    Dequeue dq;
    dq.frontInsert(10);
    dq.frontInsert(5);
    dq.rearInsert(15);
    dq.rearInsert(20);
    dq.display();
    cout << dq.rearDelete()<< " deleted from rear"<<endl;
    cout << dq.frontDelete() << " deleted from front"<<endl;
    dq.display();
    return 0;
}