#include <iostream>
#include <queue>
using namespace std;
queue<int> search_que;
char map[32][32][32];
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
            }
        }
    }
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
}