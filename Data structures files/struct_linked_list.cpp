#include<iostream>
using namespace std;

struct ListNode {
    string item;
    int data;
    ListNode *link;
};typedef ListNode *ListNodePtr;

void initNode(ListNodePtr head, string item, int n){
    ListNode *newNode = new ListNode;
    newNode->item = item;
    newNode->data = n;
    newNode->link = NULL;
    head = newNode;
}

void addNode(ListNodePtr head, string item, int n){
    ListNode *newNode = new ListNode; // need to allocate some memory 
    newNode->item = item;
    newNode->data = n;
    newNode->link = NULL;
    newNode->link = head;
    head = newNode;
}

void display(ListNodePtr head){
    ListNodePtr list = head;
    while(list!=NULL){
        cout << list->item << ": "<< list->data << " ";
        list = list->link;
    }
    cout << endl;
    cout << endl;
}

int main(){
    ListNodePtr head;

        initNode(head, "A1", 10);
        display(head);

        addNode(head, "B1", 12);
        display(head);

        addNode(head, "C1", 14);
        display(head);
    return 0;
}