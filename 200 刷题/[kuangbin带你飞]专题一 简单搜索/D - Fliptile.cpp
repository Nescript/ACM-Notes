//一个想法：可以研究哈希，不一定与题有关，但是和这种类型，每个位置是0或者1的情况相关
//题解只看了一点，说是一层层搜

//断言：在同一个位置进行两次反转是没有意义的（指以之为中心的反转操作）
#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 20;
int N,M;
bool map[MAXN][MAXN];
bool ans[MAXN][MAXN];
int dx[3] = {-1, 0, 1};
void output_map()
{
    //cout<<endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool reverse(int a)
{
    if(a) return 0;
    else return 1;
}
void flip(int depth, int k)
{
    int nx;
    for(int i = 0; i <= 2; i++)
    {
        nx = dx[i] + k;
        if(nx >= 0 && nx < M)
        {
            map[depth][nx] = reverse(map[depth][nx]);
        }
    }
    if(depth + 1 < N)
    {
        map[depth + 1][k] = reverse(map[depth + 1][k]);
    }
    return;
}

void solve(int depth)
{
    if(depth == M-1)
    {
        for(int i = 0; i <= N; i++)
        {
            if(map[depth][i])
            {
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
            else
            {
                output_map();
                return;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        if(map[depth - 1][i])
        {
            ans[depth][i] = true;
            flip(depth, i);
        }
    }
    solve(depth + 1);
    return;
}
int main()
{
    cin>>N>>M;
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin>>map[i][j];
        }
    }
    solve(1);
    //output_map();
}

//猜测：涉及最小次数，采用宽度优先搜索
//要求输出字典序最小的方案，我们先不管这个
//猜测：我们把全是0的情况反转成题目给定样子
//对任两次反转，要么相互影响，要么相互无关
//我们需要的是1的位置有奇数次翻转，0的位置有偶数次反转
//猜测：对一个1，我们不要翻转它自己，
//因为那样的话要么只反转它，要么周围还需要反转1两个
//猜测：就搜呗，下一个反转的位置不能和上一个重叠
//猜测，将每个1周围的格子加入搜索队列