#include <iostream>
using namespace std;

class DoubleLinkedIntNode{
public:
    DoubleLinkedIntNode(){}
    DoubleLinkedIntNode(int theData, DoubleLinkedIntNode* previous, DoubleLinkedIntNode* next)
                        :data(theData), nextLink(next), previousLink(previous){}
    DoubleLinkedIntNode* getNextLink() const{return nextLink;}
    DoubleLinkedIntNode* getPreviousLink() const{return previousLink;}
    int getData()const{return data;}
    void setNextLink(DoubleLinkedIntNode* next){nextLink = next;}
    void setPreviousLink(DoubleLinkedIntNode* previous){previousLink = previous;}
    void setData(int theData){data = theData;}

private:
    int data;
    DoubleLinkedIntNode *nextLink;
    DoubleLinkedIntNode *previousLink;
};
typedef DoubleLinkedIntNode* DoubleLinkedIntNodePtr;

int main()
{
    DoubleLinkedIntNodePtr head;
    head = new DoubleLinkedIntNode;
    head->setData(2);
    head->setPreviousLink(NULL);
    head->setNextLink(NULL);
    cout << head->getData() << endl;
    //cout << head->getNextLink() << endl;
    //cout << head->getPreviousLink() << endl;
    //adding a node to the front of a double linked list
    DoubleLinkedIntNodePtr newHead;
    newHead = new DoubleLinkedIntNode(4, NULL, head);
    head->setPreviousLink(newHead);//set the previous link of the original head node
    head = newHead; //set head to newHead
    cout << head->getData() << endl;
    newHead = new DoubleLinkedIntNode(1, NULL, head);
    head->setPreviousLink(newHead);
    head = newHead;
    cout << head->getData() << endl;
    //deleting a node from a doubly linked list
    DoubleLinkedIntNodePtr discard;
    discard = head->getNextLink();
    cout << discard->getData() << endl;
    DoubleLinkedIntNodePtr prev = discard->getPreviousLink();
    cout << prev->getData() << endl;
    DoubleLinkedIntNodePtr next = discard->getNextLink();
    cout << next->getData() << endl;
    prev->setNextLink(next);//bypass discard
    next->setPreviousLink(prev);//bypass discard
    delete discard;
    cout << head->getData() << endl;
    cout << head->getNextLink()->getData() << endl;

    

    return 0;
}