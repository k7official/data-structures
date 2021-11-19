#include <iostream>
using namespace std;

class IntNode
{
public:
    IntNode(){}
    IntNode(int theData, IntNode* theLink):data(theData), link(theLink){}
    IntNode* getLink()const{return link;}
    int getData()const{return data;}
    void setData(int theData){data = theData;}
    void setLink(IntNode* pointer) {link = pointer;}

    void display(IntNode *head)
    {
        IntNode *tmp = head;
        while(tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->link;
        }
        cout << endl;
    }

    void addNode(IntNode *head, int data)
    {
        IntNode *newNode = new IntNode;
        newNode->data = data;
        newNode->link = NULL;

        IntNode *cur = head;
        while(cur)
        {
            if(cur->link == NULL)
            {
                cur->link = newNode;
                return;
            }
            cur = cur->link; // keep following the next node
        }
    }

private:
    int data;
    IntNode *link;
};
typedef IntNode* IntNodePtr; //explicitly defines that its pointer and called IntNodePtr in main 

IntNodePtr search(IntNodePtr head, int target)
{
    IntNodePtr here = head;
    while(here->getData() != target && here->getLink() != NULL)
    {
        here = here->getLink();
    }
    if(here->getData() == target)
        return here;
    else
        return NULL;
}
//must make special case for empty list, not done here though

void Reverse(IntNodePtr head)
{
    IntNodePtr current, prev, next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->getLink();
        current->setLink(prev);
        prev = current;
        current = next;
    }
    head = prev;
}

int main(){

    IntNodePtr head; //pointer to node
    head = new IntNode;//our first node in list
    head->setData(3);
    head->setLink(NULL);
    //head->display(head);
    head->addNode(head, 7);
    //head->display(head);
    head = new IntNode(10, head); // simply adding a node to the head of a linked list
    head->display(head);
    //inserting in the middle of a linked list
    IntNodePtr afterMe; //need a tempoarary pointer variable to store the link of the node we want to insert after
    afterMe = head->getLink()->getLink(); //store link in temparary pointer
    cout << afterMe->getData() << endl;
    afterMe->setLink(new IntNode(5, afterMe->getLink()));
    cout << afterMe->getData() << endl;
    head->display(head);
    Reverse(head);
    head->display(head);

    //removing a node
    //IntNodePtr before = head->getLink(); // 3
    //cout << before->getData() << endl;
    //IntNodePtr discard = head->getLink()->getLink();//7
    //cout << discard->getData() << endl;
    //before->setLink(discard->getLink());
    //head->display(head); 
   // delete discard; // free memory

    //IntNodePtr target = search(head, 5);
    //if (target != NULL)
    //{
        //cout << target->getData() << endl;
   // }
    //else
      //  cout << "Target not found!";
    

    return 0;
}

//Notes

//Traversing means visiting each node of the list once in order to perform some operation on that