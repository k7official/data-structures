#include<iostream>
#include<cstdlib>
#include<ctime>
#include<random>

#define SIZE 10

using namespace std;

class Node
{
public:
	Node(): Node(0, 0)
	{
	}
	Node(int r, int c)
	{
		row = r;
		col = c;
	}
	int getRow() const { return row; }
	int getCol() const { return col; }
	void setRow(int r)
	{
		if(r >= 0 && r < SIZE)
			row = r;
	}
	void setCol(int c)
	{
		if(c >= 0 && c < SIZE)
			col = c;
	}
private:
	int col, row, data;
};

class List
{
public:
	List()
	{
		top = 0;
	}

	void addElement(int r, int c)
	{
	    Node newNode(r, c);
	    //data[top].setRow(r);
	    //data[top].setCol(c);
	    data[top] = newNode;
	    top++;
	}

	Node *removeElement()
	{
	    if (top == 0)
        {
            return NULL;
        }
        Node *discard = new Node();
	    discard = &data[top];
	    top--;
	    return discard;
	}
	void printList()
	{
		int j;
		for(j = 0;j <= top;j ++)
		{
			cout<<"("<<data[j].getRow()<<", "<<data[j].getCol()<<")"<<endl;
		}
	}
	int get_top(){return top;}
	Node* get_data(){return data;}
private:
	Node data[SIZE * SIZE];
	int top;
};

class Maze
{
public:
	Maze()
	{
		initMaze(SIZE);
	}
	void initMaze(int s)
    {
        int **_maze = new int *[s];
        for (int i = 0; i < s; i++)
        {
            _maze[i] = new int[s];
        }
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < s; j++)
            {
                _maze[i][j] = 0;
            }
        }
        int row, col, counter = 0;
        while (counter < 20)
        {
            row = rand() % s;
            col = rand() % s;

            if ((row != 0 && col != 0) || (row != 9 && col != 9))
            {
                if (_maze[row][col] == 0)
                {
                    _maze[row][col] = 1;
                    counter++;
                }
            }
        }
        maze = _maze;
    }

	void mazeHelp(List *list,  int x, int y)
    {
        if(x == SIZE-1 && y == SIZE-1)
        {
            list->addElement(x, y);
            end_ = true;
            return;
        }
        //if(x>=n || x<0 || y>=n || y<0 || maze[x][y]==1 || solution[x][y] == 0)
          //  return solution;
        maze[x][y]=-1;
        if(!end_ && y+1 < SIZE && maze[x][y+1] == 0)
            mazeHelp(list, x, y+1);

        if(!end_ && (x+1) < SIZE &&maze[x+1][y] == 0){
            mazeHelp(list, x+1, y);
        }
        if(!end_ && (y-1) >= 0 && maze[x][y-1] == 0){
            mazeHelp(list, x, y-1);
        }
        if(!end_ && (x-1) >= 0 && maze[x-1][y] == 0){
            mazeHelp(list, x-1, y);
        }
        if(maze[x][y] == -1){
            maze[x][y] = 0;
        }
        if(end_)
            list->addElement(x,y);
    }

	List *getPath()
	{
        List *list = new List();
        mazeHelp(list, 0, 0);
        if(list->removeElement()==NULL){
            return NULL;
        }
        return list;
	}
	void printMaze()
	{
		int j, k;
        int **temp[10];
        //temp = &maze;
		for(j = 0;j < SIZE;j ++)
		{
			for(k = 0;k < SIZE;k ++)
			{
				if(maze[j][k] == 0)
					cout<<" ";
				else if(maze[j][k] == 1)
					cout<<"*";
			}
			cout<<"\n";
		}
	}
private:
	int **maze;
	bool end_ = false;
};

int main()
{
    srand(time(0));
	Maze *maze = new Maze();
	maze->printMaze();
	maze->getPath()->printList();
}
