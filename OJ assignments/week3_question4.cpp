#include <iostream>
#include <string>

#define SIZE 3

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
        top = NULL;
        bot = NULL;
        counter = 0;
	}
	int enqueue(int data)
	{
        if(counter >= SIZE)
            return -1;
        counter++;
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if(top == NULL && bot == NULL){
            top = bot = newNode;
            return 1;
        }
        else
        {
            bot->next = newNode;
            bot = newNode;
            return 1;
        }

	}
	int *dequeue()
	{
        Node *temp = top;
        if(top == NULL)return NULL;
        if(top == bot)
        {
            top = bot = NULL;
        }
        else
        {
            top = top->next;
        }
        return &temp->data;
	}
private:
	Node *top, *bot;
    int counter;
};

int main()
{
	int data, *temp;
	string command;
	Queue *queue = new Queue();
	while(1)
	{
		cin>>command;
		if(command.compare("exit") == 0)
		{
			break;
		}
		else if(command.compare("enqueue") == 0)
		{
			cout<<"Please input a integer data:";
			cin>>data;
			if(queue->enqueue(data) == 1)
			{
				cout<<"Successfully enqueue data "<<data<<" into queue."<<endl;
			}
			else
			{
				cout<<"Failed to enqueue data into queue."<<endl;
			}
		}
		else if(command.compare("dequeue") == 0) 
		{
			temp = queue->dequeue();
			if(temp == NULL)
			{
				cout<<"Failed to dequeue a data from queue.\n";
			}
			else
			{
				cout<<"Dequeue data "<<*temp<<" from queue."<<endl;
			}
		}
	}
}
