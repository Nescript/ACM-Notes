#include <bits/stdc++.h>
const int MAXN = 100 + 10;
using namespace std;
int dp[1010];
int info[MAXN][2];

int item;
int solve(int time)
{
    cout << "for now item is " << item << " ans time is " << time <<endl;
    if(item == 0) return 0;
    //if(dp[time] != -1) return dp[time];
    
    if(time >= info[item][0]) 
    {
        item--;
        return dp[time] = max(solve(time), 
                              solve(time - info[item + 1][0]) + info[item + 1][1]);
    }
    else 
    {
        item--;
        return dp[time] = solve(time);
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));    
    int T, M;
    cin >> T >> M;
    int time, val;
    //cout << "wtf" << endl;
    for (int i = 1; i <= M; i++)
    {
        cin >> info[i][0] >> info[i][1];
    }
    item = M;
    dp[0] = 0;
    //cout << "wtf" << endl;
    cout << solve(T) << endl;
    //cout << dp[M][T] << endl;
    cout << dp[100] << " " << dp[70] << " " << dp[1];
}