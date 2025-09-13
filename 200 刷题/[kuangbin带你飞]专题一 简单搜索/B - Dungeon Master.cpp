#include <iostream>
#include <queue>
using namespace std;
queue<int> search_que;
char map[32][32][32];

typedef pair<int, int> RC;
typedef pair<int, RC> LRC;

int dx[6] ={-1, 0, 1, 0, 0, 0}; 
int dy[6] ={0, -1, 0, 1, 0 ,0};
int dz[6] ={0, 0, 0, 0, 1, -1};
LRC end_point;
LRC start_point;
int L,R,C;
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
                if(map[k][i][j] == 'S')
                {
                    start_point = LRC(k,RC(i,j));
                }
                if(map[k][i][j] == 'E')
                {
                    end_point = LRC(k,RC(i,j));
                }
            }
        }
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