#include<iostream>
using namespace std;

#define SIZE 26

struct trieNode
{
    struct trieNode *child[SIZE];
    bool isEndOfWord;
};
struct trieNode* getNode()
{
    struct trieNode *node = new trieNode;
    node->isEndOfWord = false;
    for(int j=0;j<26;j++)
    {
        node->child[j] = 0;
    }
    return node;
}
void insert(struct trieNode *root, string key)
{
    struct trieNode *pCrawl = root;
    for(int i=0;i<key.length();i++)
    {
        int index = key[i] -'a';    
        if(!pCrawl->child[index])//if input key does not exist
            pCrawl->child[index] = getNode();//every character is stored as a trie node data structure

        pCrawl = pCrawl->child[index];//move pointer until end of word
    }
    pCrawl->isEndOfWord = true;//mark the last character's trie node as leaf node/end of key 
}
bool search(struct trieNode *root, string key)
{
    struct trieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)//i is the level in the trie
    {
        int index = key[i] - 'a';
        if (!pCrawl->child[index])//if the required node does not exist
            return false;
        pCrawl = pCrawl->child[index];
    }
    return (pCrawl->isEndOfWord);
}


int main()
{
    int n, tries;
    cin >> n >> tries;
    string keys[tries];
    struct trieNode *root = getNode();
    for(int i=0;i<n;i++)//construct a trie                      
    {
        string word;
        cin >> word;
        insert(root, word);
    }
    for(int j=0;j<tries;j++)
    {
        cin >> keys[j];
    }
    for(int j=0;j<tries;j++)
    {
        search(root, keys[j]) ? cout << 1 << endl : cout << 0 << endl;
    }
    return 0;
}