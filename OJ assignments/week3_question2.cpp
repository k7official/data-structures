#include <iostream>
#include <cstring>

#define SIZE 3

using namespace std;

class Queue
{
public:
    Queue()
    {
        head = -1;
        tail = -1;
    }
    int enqueue(int d)
    {
        if((tail+1)%SIZE == head)//
        {
            return -1;
        }
        
        else if(IsEmpty())
        {
            tail++;
            head++;
        } 
        else{
            tail = (tail+1)%SIZE;//if size if full, this will evaluate to 0
        }
        data[tail] = d;
        return 1;
    }
    int *dequeue()
    {
        int *item  = NULL;
        item = new int;
        if(IsEmpty())
            return NULL;
        else if(head == tail)
        {
            item = &data[tail];
            head = -1;
            tail = -1;
            return item;
        }

        else{
            item = &data[head];
            head = (head+1)%SIZE;//so that it in circular manner
            return item;
        }
    }
    bool IsFull()
    {
        bool full = false;
        if(head >= SIZE - 1)
            full = true;
        return full;
    }
    bool IsEmpty()
    {
        bool empty = false;
        if(head == -1 && tail == -1)
            empty = true;
        return empty;
    }
private:
    int data[SIZE];
    int head;
    int tail;
};

int main()
{
    int data, *temp;
    char command[50];
    Queue *queue = new Queue();
    while(1)
    {
        cin>>command;
        if(strcmp(command, "exit") == 0)
        {
            break;
        }
        else if(strcmp(command, "enqueue") == 0)
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
        else if(strcmp(command, "dequeue") == 0) 
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