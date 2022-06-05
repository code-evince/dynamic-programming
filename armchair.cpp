#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x;
vector<ll> filled,empty1;

ll dp[5005][5005];


#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (ll)((x).size())
#define fr                first
#define sc                second
#define pii               pair<ll,ll>
#define rep(i,a,b)        for(ll i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

ll solve(ll idx1,ll idx2){

    if(idx1==sz(filled)) return 0;
    if(idx2==sz(empty1)) return INT_MAX;
    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    ll ans;
    ans = min(abs(filled[idx1]-empty1[idx2]) + solve(idx1+1,idx2+1)  , solve(idx1,idx2+1));
    return dp[idx1][idx2]=ans;



}


int main(){
  ll t=1;           // t=1 in case of no testcases
  // cin>>t;           // comment out in case of no test cases
  while(t--){
    cin>>n;
    mem1(dp);
    rep(i,1,n+1){
      cin>>x;
      if(x==1) filled.pb(i);
      else empty1.pb(i);
    }

    cout<<solve(0,0)<<endl;
  }


}
