//
//  main.cpp
//  week8_question2
//
//  Created by Muhle Musa Khumalo on 2021/11/30.
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
       int j, k;
       for(j = 0;j < 20;j ++)
           for(k = 0;k < 4;k ++)
               root[j][k] = -1;
   }
   int insert(int node)
   {
       int f = 0, index = 0;
       while(root[index][0] != -1)
           index ++;
       if(index >= 20)
           return -1;
       if(index == 0)
       {
           root[0][0] = 1;
           root[0][1] = node;
           return 1;
       }
       else
       {
           root[index][0] = 1;
           root[index][1] = node;
           while(1)
           {
               if(root[f][1] < node)
               {
                   if(root[f][3] == -1)
                   {
                       root[f][3] = index;
                       return 1;
                   }
                   else
                   {
                       f = root[f][3];
                   }
               }
               else
               {
                   if(root[f][2] == -1)
                   {
                       root[f][2] = index;
                       return 1;
                   }
                   else
                   {
                       f = root[f][2];
                   }
               }
           }
       }
   }
   void inorder(int index)
   {
       if(index != -1 && root[index][0] != -1)
       {
           inorder(root[index][2]);
           cout << root[index][1] << " ";
           inorder(root[index][3]);
       }
   }
   void preorder(int index)
   {
       if(index != -1 && root[0][0] != -1)//DeMorgan's
       {
           cout << root[index][1] << " ";//root at that subtree
           preorder(root[index][2]);//visit left child at the at index passed
           preorder(root[index][3]);//visit right child
       }
   }
   void postorder(int index)
   {
       if(index != -1 && root[0][0] != -1)
       {
           postorder(root[index][2]);
           postorder(root[index][3]);
           cout << root[index][1] << " ";
       }
   }
   void levelorder()
   {
       int index = 0;
       queue<int> q;
       if(root[0][0] != -1)
       {
           q.push(index);
           while(!q.empty())
           {
               int temp = q.front();
               cout << root[temp][1] << " ";
               int left = root[temp][2];//index of left child
               int right = root[temp][3];//index of right child
               if(left != -1)
                   q.push(left);
               if(right != -1)
                   q.push(right);
               q.pop();
           }
       }
   }
private:
   int root[20][4];
};

int main()
{
   Tree *tree = new Tree();
   int j, node;
   srand(time(NULL));
   for(j = 0;j < 10;j ++)
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
