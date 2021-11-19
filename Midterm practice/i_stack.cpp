#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class Stack
{
public:
    Stack()
    {
        data = NULL;//stack is empty
        counter = 0;
    }
    int push(int d)
    {
        if(counter > SIZE)
            return -1;
        Node *newNode = new Node;
        newNode->data = d;//push new node at the top
        newNode->next = data;
        data = newNode;//the first element wei  
        counter++;
        return 1;
    }

    int *pop()
    { 
        Node *temp;
        if(data == NULL)return NULL;//stack is empty
        temp = data;
        data = data->next;
        int *p = new int;
        p = &temp->data;
        return p;

    }
private:
    Node *data;//data is the top of the linked list
    int counter;
};

int main()
{
    int data, *temp;
    string command;
    Stack *stack = new Stack();
    while(1)
    {
        cin>>command;
        if(command.compare("exit") == 0)
        {
            break;
        }
        else if(command.compare("push") == 0)
        {
            cout<<"Please input a integer data:";
            cin>>data;
            if(stack->push(data) == 1)
            {
                cout<<"Successfully push data %d into stack.\n";
            }
            else
            {
                cout<<"Failed to push data into stack.\n";
            }
        }
        else if(command.compare("pop") == 0) 
        {
            temp = stack->pop();
            if(temp == NULL)
            {
                cout<<"Failed to pop a data from stack.\n";
            }
            else
            {
                cout<<"Pop data " <<*temp <<" from stack.\n";
            }
        }
    }
}