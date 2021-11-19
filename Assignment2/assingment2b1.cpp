#include<iostream>
#define SIZE 10
using namespace std;

class Stack
{
public:
    Stack()
    {
        top=-1;
    }
    int push(char data)
    {
        if(top == -1){
            top++;
        }
        else if(top >= SIZE-1)
        {
            return -1;
        }
        else{
            top++;
        }
        this->data[top] = data;
        return 1;
    }

    char *pop()
    {
        char *item = NULL;
        item = new char;
        if(top == -1)
            return NULL;
        else
        {
            item = &data[top];
            top = top - 1;
            return item;
        }
    }
    int isEmpty()
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }
    char get_top(){return data[top];}
private:
    char data[SIZE];
    int top;
};

int isBalanced(char *exp)
{
    Stack *st = new Stack();
    for(int i=0; exp[i]!= '\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            st->push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(st->isEmpty())
                return false;
            else if(exp[i]==')' && (st->get_top()=='{' || st->get_top()=='['))
                return false;
            else if(exp[i]=='}' && (st->get_top()=='(' || st->get_top()=='['))
                return false;
            else if(exp[i]=='[' && (st->get_top()=='(' || st->get_top()=='{'))
                return false;
            else st->pop();
        }
    }
    return st->isEmpty() ? true : false;
}

int main()
{
    char exp[] = "{((a+b)*(c-d))[]}";
    cout << isBalanced(exp) << endl;
    return 0;
}
/*
Write a program that reads in a sequence of characters,
and determines whether its parentheses, brackets, and braces are balanced and properly nested.
*/
