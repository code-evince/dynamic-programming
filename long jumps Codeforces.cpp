#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

void solve(){

  ll n;
  cin>>n;
  ll arr[n+1];

  rep(i,1,n+1){
    cin>>arr[i];
  }

vector<ll> dp(n+1,0);
for(ll i=n;i>0;i--){
  dp[i]=arr[i];
  int j = arr[i]+i;
  if(j<n+1){
    dp[i]+=dp[j];
  }
  for(int x:dp){
    cout<<x<<" ";
  }
  cout<<endl;

}
  cout << *max_element(dp.begin(), dp.end()) << endl;

}


int main(){
  ll t;           // t=1 in case of no testcases
  cin>>t;           // comment out in case of no test cases
  while(t--){
    solve();
  }
}
