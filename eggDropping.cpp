#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 +5 ;

int eggDrop(int K,int N){  //K EGGS AND N FLOORS eggDrop(eggs,floor)
    vector<vector<int>> dp(N+1, vector<int>(K+1));
    for(int i=0;i<=K;++i){
        dp[0][i]=0;                       // 0 floors, i eggs --> 0 trails
        dp[1][i]=1;                       // 1 floor, i eggs --> 1 trail
    }
    for(int i=0; i<=N;++i){
        dp[i][1]=i;                       // you'll never have zero eggs so we ignore col 0, here if you have 1 egg --> you'll need i trails in worst case
    }

    for(int n=2; n<=N; ++n){          //for every floor
        for(int k=2; k<=K; ++k){      //for every egg
            dp[n][k] = INF;
            for(int f=1; f<=n; ++f){
                int tmp =max(dp[f-1][k-1], dp[n-f][k]) +1 ;
                dp[n][k] = min(dp[n][k], tmp);
            }
        }
    }
    for(int n=0; n<=N; ++n){          //for every floor
        for(int k=0; k<=K; ++k){
            cout<<dp[n][k]<<" ";
        }
        cout<<"\n";
    }
    return dp[N][K];
}
int main(){
    int ans = eggDrop(2,10);
    cout<<ans;
}