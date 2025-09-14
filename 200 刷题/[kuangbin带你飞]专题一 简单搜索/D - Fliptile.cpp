//猜测：涉及最小次数，采用宽度优先搜索
//要求输出字典序最小的方案，我们先不管这个


#include <iostream>
using namespace std;
const int MAXN = 16;
int N,M;
bool map[MAXN][MAXN];
void output_map()
{
    cout<<endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cin>>N>>M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin>>map[i][j];
        }
    }
    output_map();
}