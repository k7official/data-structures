//Template class for a single linked list

#include<iostream>
using namespace std;

template <class Type> 
class Node
{
public:
    Type data;
    Node<Type>* next;
    Node(Type d)
    {
        data = d;
        next = NULL;
    }
};

template <class Type> 
class List
{
public:
    List()
    {
        first = NULL;
    }
    void Insertion(Type element)
    {
        Node<Type>* temp = new Node(element);
        if(!first){
            first = temp;
            return;
        }
        Node<Type>* t = first;
        while(t){
            if(t->next == NULL){
                t->next = temp;
                return;
            }
            t = t->next;
        }

    }

    void insertNth(int n, Type k)
    {
        int size = this->Length();
        if (n < 0 || n > size) {
            cerr << "Illegal insert position" << endl;
            return;
        }

        Node<Type> *newnode = new Node<Type>(k);
        Node<Type> *p = first;
        Node<Type> *prev = 0;
        int i = 0;
        while (i != n) {
            prev = p;
            p = p->next;
            i++;
        }
        newnode->next = p;
        if (prev)
            prev->next = newnode;
        else
            first = newnode;//maybe at the beginning when prev is nulls
    }


    void Delete(Type k)
    {
        Node<Type> *previous = NULL;
        Node<Type> *current;
        for (current = first; current && current->data != k;
        previous = current, current = current->link);//this loop will run and teminate on its own
        if (current)
        {
            if (previous) previous->next = current->next;
            else first = first->next;
            delete current;
        }
    }
    void Display()
    {
        for(Node<Type> *t = first; t!=NULL; t=t->next){
            cout << t->data << " ";
        }
        cout<<endl;
    }
    int Length()
    {
        int counter=0;
        Node<Type> *t = first;
        while(t!=NULL){
            counter++;
            t = t->next;
        }
        return counter;
    }

    void Invert()
    {
        Node<Type> *p = first, *q = 0; // q trails p
        while (p) {
            Node<Type> *r = q;
            q = p; 
            p = p->next; // p moves to next node
            q->next = r; // link q to preceding node
        }
        first = q;
    }

    void Concatenate(List<Type> b)
    {
        if (!first)//if this list is empty
        {
            first = b.first; 
            return;
        }
        if (b.first) {
        Node<Type> *p;
        for (p = first; p->next; p = p->next); // no body
        p->next = b.first;
        }
    }

    void deleteAll(Type k)
{
    //need two pointers 
    Node<Type> *previous = 0;
    Node<Type> *current = first;

    while (current) {
        for ( ; current && current->data != k; previous = current, current = current->next);
        if (current)
        {
            if (previous)//always check that it is not null
                previous->next = current->next;
            else 
                first = first->next;
            Node<Type> *temp = current;
            current = current->next;
            delete temp;
        }
    }
}


    Type atNth(int n)
    {
        if(Length() && n <= Length()){
            Node<Type> *t = first;
            int i=1;
            while(i<n){
                t=t->next;
                i++;
            }
            return t->data;
        }
        return -1;
    }
    int occurances(Type x)//computes the occurances of x in list
    {
        int occ = 0;
		Node<Type> *p = first;
		int count = 1;
		while (p && count <= Length()) {
			if (p->data == x) {
				occ++;
			}
			p = p->next;
			count++;
		}
		return occ;
    }
    
private:
    Node<Type> *first;
};

int main()
{
    List<int> *list = new List<int>();
    list->Insertion(1);
    list->Insertion(2);
    list->Insertion(2);
    list->Insertion(3);
    list->Display();
    cout << "Length of list: " << list->Length() << endl;
    cout << "Data at Nth position of list: " << list->atNth(4) << endl;
    list->deleteAll(2);
    list->Display();
    return 0;
}