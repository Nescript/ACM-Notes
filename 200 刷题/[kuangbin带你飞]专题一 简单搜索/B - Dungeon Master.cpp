#include <iostream>
#include <queue>
using namespace std;
const int MAX_D = 40000;
char map[32][32][32];

typedef pair<int, int> RC;
typedef pair<int, RC> LRC;

int dx[6] ={-1, 0, 1, 0, 0, 0}; 
int dy[6] ={0, -1, 0, 1, 0 ,0};
int dz[6] ={0, 0, 0, 0, 1, -1};
LRC end_point;
LRC start_point;
LRC current;
int d[32][32][32];

queue<LRC> search_que;
int L,R,C;

void solve()
{
    int x,y,z;
    //压进队列的要求：不超过边界，没有访问过，
    while(!search_que.empty())
    {
        cout<<"Now we go into the while loop"<<endl;
        current = search_que.front();
        search_que.pop();
        for(int i = 0; i < 6; i++)
        {
            z = current.first + dz[i];
            x = current.second.first + dx[i];
            y = current.second.second + dy[i];
            if(z >= 0 && z < L &&
               x >= 0 && x < R &&
               y >= 0 && y < C &&
               map[x][y][z] == '.' &&
               d[x][y][z] == MAX_D)
            {
                d[z][x][y] = d[current.first][current.second.first][current.second.second] + 1;
                if(end_point == LRC(z, RC(x, y)))
                {
                    return;
                }
                search_que.push(LRC(z, RC(x, y)));
                //跳出条件，遇到终点，否则队列跑完还没出来就是trapped
            }
        }
    }
}
//宽度优先搜索
//需要用到队列
int main()
{
    cin>>L>>R>>C;
    for(int k = 0; k < L; k++)
    {
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                cin>>map[k][i][j];
                d[k][i][j] = MAX_D; 
                if(map[k][i][j] == 'S')
                {
                    start_point = LRC(k,RC(i,j));
                    search_que.push(start_point);
                }
                if(map[k][i][j] == 'E')
                {
                    end_point = LRC(k,RC(i,j));
                }
            }
        }
    }
    solve();
    if(d[end_point.first][end_point.second.first][end_point.second.first] != MAX_D)
    {
        cout<<"Escaped in ";
        cout<<d[end_point.first][end_point.second.first][end_point.second.first]<<endl;
        cout<<" minute(s)."<<endl;
    }
    else 
    {
        cout<<"Trapped!"<<endl;
    }
    /*
    for(int k = 0; k < L; k++)
    {
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                cout<<map[k][i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    */
}