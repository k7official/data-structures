#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Point
{
public:
    int x, y;
    bool flag;
    Point(int x_, int y_)
    {
        x = x_;
        y = y_;
        flag = false;
    }
    bool operator==(Point &other)
    {
        if(x==other.x && y==other.y)return true;
        else return false;
    }

};
bool find(vector<Point>points, Point p)
{
    for(int i=0; i<points.size(); i++){
        if(p == points[i])return true;
    }
    return false;
}
class Nurikabe
{
public:
  /*
  n is the size of the Nurikabe, n >= 5, n <= 20
  game is the result from some player
  here is one example
  n: 5
  game = { {'W', 'W', 'W', '1', 'W'},
           {'W', '.', 'W', 'W', 'W'},
           {'W', '2', 'W', '.', '3'},
           {'3', 'W', 'W', '.', 'W'},
           {'.', '.', 'W', 'W', 'W'} };
  W represent wall
  */
  Nurikabe(char game[20][20], int n)
  {
      size = n;
      for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
              grid[i][j] = game[i][j];
          }
      }
  }
  /*
  return 1 if result fit the rule.
  return 0 if result not fit the rule.
  */
  int isCorrect()
  {
      //looking for cells with numbers
      vector<Point> numberedCells;
      for(int i=0; i<size; i++){
          for(int j=0; j<size; j++){
              if(isdigit(grid[i][j]))
                numberedCells.push_back(Point(i, j));//constructs a point and pushes it to vector
          }
      }

      for(int i=0; i<numberedCells.size();i++){
          int x, y;
          vector<Point> formIsland;
          formIsland.push_back(numberedCells[i]);

          for(int j=0; j<formIsland.size(); j++){
              x = formIsland[j].x;
              y = formIsland[j].y;
              if(x>=1){
                  if(grid[x-1][y] == '.' || isdigit(grid[x-1][y])){
                      if(!find(formIsland, Point(x-1, y)))
                        formIsland.push_back(Point(x-1, y));
                  }
              }
              if(x<size-1){
                  if(grid[x+1][y] == '.' || isdigit(grid[x+1][y])){
                      if(!find(formIsland, Point(x+1, y)))
                        formIsland.push_back(Point(x+1, y));
                  }
              }
              if(y>=1){
                  if(grid[x][y-1] == '.' || isdigit(grid[x][y-1])){
                      if(!find(formIsland, Point(x, y-1)))
                        formIsland.push_back(Point(x, y-1));
                  }
              }
              if(y<size-1){
                  if(grid[x][y+1] == '.' || isdigit(grid[x][y+1]))
                    if(!find(formIsland, Point(x, y+1)))
                        formIsland.push_back(Point(x, y+1));
              }
          }
          if(formIsland.size() != (int(grid[numberedCells[i].x][numberedCells[i].y])-48))
            return 0;
        }
        Point firstW(-1,-1);
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(grid[i][j]=='W'){
                    firstW.x = i;
                    firstW.y = j;
                    break;
                }
            }
        }
        queue<Point> q;
        q.push(firstW);
        while(!q.empty()){
            Point f = q.front();
            q.pop();
            grid[f.x][f.y] = 'w';
            if(f.x>=1){
                if(grid[f.x-1][f.y]=='W')
                    q.push(Point(f.x-1, f.y));
            }
            if(f.x<size-1){
                if(grid[f.x+1][f.y] == 'W')
                    q.push(Point(f.x+1, f.y));
            }
            if(f.y>=1){
                if(grid[f.x][f.y-1]=='W')
                    q.push(Point(f.x, f.y-1));
            }
            if(f.y<size-1){
                if(grid[f.x][f.y+1] == 'W')
                    q.push(Point(f.x, f.y+1));
            }
        }

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++)
              if(grid[i][j]=='W')
                return 0;
        }
        for(int i=0;i<size-1;i++){
            for(int j=0;j<size-1;j++){
                if(grid[i][j]=='w' && grid[i+1][j]=='w' && grid[i+1][j+1]=='w' && grid[i][j+1]=='w')
                    return 0;
            }
        }
        return 1;
  }
private:
  //請設計你自己的資料結構來儲存遊戲的結果
  //Please design your own data structure to keet the result
  char grid[20][20];
  int size;
};
int main() {
  int n=5, j, l, k;
  char game[20][20] = { {'W', 'W', 'W', '1', 'W'},
                       {'W', '.', 'W', 'W', 'W'},
                       {'W', '2', 'W', '.', '3'},
                       {'3', 'W', 'W', '.', 'W'},
                       {'.', '.', 'W', 'W', 'W'} };
  /*std::cin>>n;
  for(j = 0;j < n;j ++)
    for(k = 0;k < n;k ++)
      std::cin>>game[j][k];*/
  Nurikabe *a = new Nurikabe(game, n);
  std::cout<<a->isCorrect() << std::endl;
  return 0;
}
