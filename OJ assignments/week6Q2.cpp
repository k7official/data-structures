#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

#define SIZE 10
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class Grid
{
public:
	Grid(): Grid(0)
	{
	}
	Grid(int s)
	{
		state = s;
		dir[UP] = NULL;
		dir[DOWN] = NULL;
		dir[LEFT] = NULL;
		dir[RIGHT] = NULL;
	}
	Grid *getDir(int d) const { return dir[d]; }
	int getState() const { return state; }
	void setDir(int d, Grid *g) { dir[d] = g; }
	void setState(int s) { state = s;}
private:
	Grid *dir[4];
	int state;
};

class List
{
public:
	List()
	{
		top = 0;
	}
	/*
	Insert an element from top
	*/
	void addElement(Grid *g)
	{
	    data[top] = g;
	    top++;
	}

	Grid *removeElement()
	{
	    if(top == 0)
            return NULL;
        Grid *discard = new Grid();
        discard = data[top];
        top--;
        return discard;
	}
	void printPath() const
	{
		int j;
		for(j = 1;j < top;j ++)
		{
			if(data[j] == data[j - 1]->getDir(UP))
			{
				cout<<"UP\n";
			}
			else if(data[j] == data[j - 1]->getDir(DOWN))
			{
				cout<<"DOWN\n";
			}
			else if(data[j] == data[j - 1]->getDir(LEFT))
			{
				cout<<"LEFT\n";
			}
			else if(data[j] == data[j - 1]->getDir(RIGHT))
			{
				cout<<"RIGHT\n";
			}
		}
	}
private:
	Grid *data[SIZE * SIZE];
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
	    int total_size = s*s;
	    Grid *_maze = new Grid[total_size];
	    for(int i=0; i<0.2*total_size; i++)
        {
            int space_wall = rand() % total_size;
            while (_maze[space_wall].getState()==1 || space_wall==0 || space_wall==total_size-1)
            {
                space_wall = rand() % total_size;
            }
            _maze[space_wall].setState(1);
	    }
	    maze = _maze;

	    for(int i=0; i<total_size;i++)//link every value in grid to point its surroundings in 2D
        {
            int row = i/s;
            int col = i%s;
            if(row>0)
                maze[i].setDir(UP, &maze[(row-1)*s+col]);//point to the one above it(2D)...*s because technically they are in 1D
            if(row<s-1)
                maze[i].setDir(DOWN, &maze[(row + 1) * s + (col)]);
            if (col < s - 1)
                maze[i].setDir(RIGHT, &maze[(row)*s + (col + 1)]);
            if (col > 0)
                maze[i].setDir(LEFT, &maze[(row)*s + (col - 1)]);

        }

	}

	List *getPath()
	{
	    List *list_ = new List();
	    bool found = mazeHelp(list_, &maze[0]);
	    if(found)
            return list_;
        else
            return NULL;
	}

	bool mazeHelp(List *list_, Grid *grid)
	{
	    static bool found = false;
	    if(grid == &maze[SIZE*SIZE-1])
        {
            list_->addElement(grid);
            found = true;
            return true;
        }
        bool up, down, left, right;
        if(grid->getDir(UP))
            up = true;
        else
            up = false;

        if(grid->getDir(DOWN))
            down = true;
        else
            down = false;

        if(grid->getDir(LEFT))
            left = true;
        else
            left = false;

        if(grid->getDir(RIGHT))
            right = true;
        else
            right = false;

        grid->setState(-1);
        if(!found && down && (grid->getDir(DOWN)->getState() == 0))
        {
			list_->addElement(grid);
			mazeHelp(list_, grid->getDir(DOWN));
		}
		if (!found && right && (grid->getDir(RIGHT)->getState() == 0))
        {
			list_->addElement(grid);
			mazeHelp(list_, grid->getDir(RIGHT));
		}
		if (!found && up && (grid->getDir(UP)->getState() == 0))
        {
			list_->addElement(grid);
			mazeHelp(list_, grid->getDir(UP));
		}
		if (!found && left && (grid->getDir(LEFT)->getState() == 0))
        {
			list_->addElement(grid);
			mazeHelp(list_, grid->getDir(LEFT));
		}
        if (!found)
        {
			list_->removeElement();
        }
		return found;
	}

	void printMaze() const
	{
		Grid *j = maze, *k;
		while(j != NULL)
		{
			k = j;
			while(k != NULL)
			{
				cout<<k->getState() << " ";
				k = k->getDir(RIGHT);
			}
			cout<<endl;
			j = j->getDir(DOWN);
		}
	}
private:
	Grid *maze;
};

int main()
{
    srand(time(0));
	Maze *maze = new Maze();
	maze->printMaze();
	maze->getPath()->printPath();

}
