//
//  main.cpp
//  week8_question3
//
//  Created by Muhle Musa Khumalo on 2021/11/29.
//

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<queue>

using namespace std;

class Tree
{
public:
    Tree()
    {
        int j;
        for(j = 0;j < 2000;j ++)
            root[j] = -1;
    }
    int insert(int node)
    {
        int index = 0;
        while(index < 2000 && root[index] != -1)
        {
            if(root[index] < node)
                index = index * 2 + 2;
            else
                index = index * 2 + 1;
        }
        root[index] = node;
        return true;
    }
    void inorder(int index)
    {
        if(root[index] != -1 && index < 2000)//so you dont check at more than 2000..causes segmentation fault
        {
            inorder(index*2 + 1);
            cout << root[index] << " ";
            inorder(index*2 + 2);
        }
        
    }
    void preorder(int index)
    {
        if(root[index] != -1 && index < 2000)
        {
            cout << root[index] << " ";
            preorder(index*2 + 1);
            preorder(index*2 + 2);
        }
        
    }
    void postorder(int index)
    {
        if(root[index] != -1 && index < 2000)
        {
            postorder(index*2 + 1);
            postorder(index*2 + 2);
            cout << root[index] << " ";
        }
    }
    void levelorder()
    {
        int index = 0;
        queue<int> q;
        if(root[0] != -1)
        {
            q.push(index);
            while(!q.empty())
            {
                int temp = q.front();
                if(temp > 2000)
                    break;
                cout << root[temp] << " ";
                int left = temp*2+1;
                int right = temp*2+2;
                if(root[left] != -1)
                    q.push(left);
                if(root[right] != -1)
                    q.push(right);
                q.pop();
            }
        }
    }
private:
    int root[2000];
};

int main()
{
    Tree *tree = new Tree();
    int j, node;
    srand(time(NULL));
    for(j = 0;j < 10;j++)
    {
        node = j;
        tree->insert(node);
    }
    int index = 0;
    tree->inorder(index);
    printf("\n");
    tree->preorder(index);
    printf("\n");
    tree->postorder(index);
    printf("\n");
    tree->levelorder();
    printf("\n");
}
