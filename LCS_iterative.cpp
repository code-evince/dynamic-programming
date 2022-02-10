#include <bits/stdc++.h>
using namespace std;

int LCS_iterative(string a, string b){
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int i =0; i<n;++i){
        for(int j=0; j<m;++j){
            if(a[i] == b[j]){
                dp[i+1][j+1] = 1 + dp[i][j];
                
            }

            else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    //just for printing the dp table 
     for(int i =0; i<n+1;++i){
        for(int j=0; j<m+1;++j){
            
            cout<<dp[i][j]<<" ";
            if(j==m){
                cout<<"\n";
            }

        }
     }

    return dp[n][m];
    
}

int main() {
    int ans;
    string a = "ABCBDAB";
    string b = "BDCABA";
    ans = LCS_iterative(a,b);
    cout<<ans;
    
};