#include<iostream>
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
    Stack(){top = NULL;}
    bool isEmpty()
    {
        if(top == NULL)
            return true;
        return false;
    }
    void push(int x)
    {
        Node *newNode = new Node;
        if(newNode == NULL)
            cout << "Stack is full" << endl;
        else
        {
            newNode->data = x;
            newNode->next = top;
            top = newNode;
        } 
    }
    int pop()
    {
        int x;
        if(top == NULL)
            cout << "Stack is empty" << endl;
        else
        {
            x = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
        }
        return x;
    }
    void display()
    {
        for(Node *temp = top; temp != NULL; temp = temp->next)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    }
private:
    Node *top;
};

class Queue
{
public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty()
    {
        if(front == NULL && rear == NULL)
            return true;
        return false;
    }
    void enqueue(int x)
    {
        Node *newNode = new Node;
        if(newNode == NULL)
            cout << "Queue is full" << endl;
        else
        {
            newNode->data = x;
            newNode->next = NULL;
            if(isEmpty())
                front = rear = newNode;
            else
            {
                rear->next = newNode;
                rear = newNode;
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
        x        = front->data;
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
    void reverseQueue()
    {
        Stack stack;
        while(!this->isEmpty())
        {
            stack.push(this->dequeue());
        }
        while(!stack.isEmpty())
        {
            this->enqueue(stack.pop());
        }
    }

    void display()
    {
        for(Node *temp = front; temp!=NULL; temp = temp->next)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    }

private:
    Node *front, *rear;
};

class twoStacksQueue
{
public:
    twoStacksQueue()
    {
    }
    void enqueue(int x)
    {
        s1.push(x);
    }
    int dequeue()
    {
        int x;
        if(s2.isEmpty())
        {
            if(s1.isEmpty())
            {
                cout << "Queue is empty" << endl;
                return x;
            }
            else
            {
                while(!s1.isEmpty())
                    s2.push(s1.pop());
            }
        }
        return s2.pop();

    }
    void display()
    {
        Stack s3;   
        if(s2.isEmpty())
        {
            if(s1.isEmpty())
                cout << "Stack is empty" <<endl;
            else
            {
                while(!s1.isEmpty())
                    s2.push(s1.pop());
            }
        }
        else//when they both have elements
        {
            Stack s3;
            s2.display();
            int x = s2.pop();//
            s2.push(x);
            while(!s1.isEmpty())
                s3.push(s1.pop());
            s3.display();
            while(!s3.isEmpty())
                s1.push(s3.pop());
        }
    
    }
private:
    Stack s1,s2; 
};

//template <class T>
void reverseQueue(Queue q){
    Stack s;
    int temp;
    // First build a stack (LIFO queue) from the (FIFO) queue.
    while (q.dequeue())
    {
        s.push(temp);
    }
    // The first item in the queue is now at the bottom of the stack.
    // The last item is at the top.
    // The queue is empty.

    // If we enqueue them again they will be reversed.
    while (s.pop())
    {
        q.enqueue(temp);
    }
} 

int main()
{
    /*Stack stack;
    stack.push(10);
    stack.push(14);
    stack.push(26);
    stack.display();
    cout << stack.pop() << " popped off the stack"<< endl;
    stack.display();*/
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.reverseQueue();
    //cout << q.dequeue() << " dequeued from Queue" << endl; 
    q.display();
    q.reverseQueue();
    q.display();
    /*twoStacksQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << q.dequeue() << "removed from Queue" << endl;
    q.display();
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.enqueue(60);
    q.display();*/
    
    return 0;
}