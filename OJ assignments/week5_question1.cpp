#include<iostream>
#include<cstdlib>

using namespace std;

struct Node
{
	Node()
	{
		data = 0;
		next = NULL;
	}
	int data;
	Node *next;
};

class Set
{
public:
	Set()
	{
        element = NULL;
	}

	int addElement(int e)
	{
        Node *cur = element;
        while(cur)
        {
            if(cur->data == e)
                return false;
            cur = cur->next;
        }
        Node *new_element = new Node;
        new_element->data = e;
        new_element->next = element;
        element = new_element;
        return true;
	}

	Set *unions(const Set *b) const
	{
        Set *union_set = new Set();
        union_set->element = this->element;
        Node *temp = b->element;
        while(temp)
        {
            union_set->addElement(temp->data);
            temp = temp->next;
        }
        return union_set;
	}

	Set *intersetcions(const Set *b) const
	{
        Set *intersect_set = new Set();
        Set *this_set = new Set();
        this_set->element = this->element; 
        Node *temp = b->element;
        while (temp)
        {
            int check = this_set->addElement(temp->data);
            if(check == 0)
            {
                intersect_set->addElement(temp->data);
            }
            temp = temp->next;
        }
        return intersect_set;
	}

	bool equivalent(const Set *b) const
	{
        int found = 0;
        int count = 0;
        for(Node *temp = b->element; temp != NULL; temp = temp->next)
        {
            count++;
            for(Node *temp2 = this->element; temp2 != NULL; temp2 = temp2->next)
            {
                if(temp->data == temp2->data)
                    found++;
            }
        }
        if(found == count)
            return true;
        else return false;
	}
	
	void listAll() const
	{
		Node *cur = element;
		while(cur != NULL)
		{
			cout<<cur->data<<" ";
			cur = cur->next;
		}
	}
private:
	Node *element;
};

int main()
{
	Set *a = new Set();
	Set *b = new Set();
	Set *c;
	Node *cur;
	
	a->addElement(1);
	a->addElement(2);
	a->addElement(3);
	b->addElement(4);
	b->addElement(1);
	b->addElement(1);
	b->addElement(2);
	
	c = a->unions(b);
	c->listAll();
    cout << endl;
	
	c = a->intersetcions(b);
	c->listAll();
    cout << endl;
	
	if(a->equivalent(b) == 0)
		cout<<"Not equivalent.\n";
	else
		cout<<"Equivalent!\n";
}
