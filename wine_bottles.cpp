//Wine and max price
// Imagine you have a collection of wine bottles kept in a particular order.
// At atime you can pick a bottle from front or back and sell it.
// Selling price will be price*years_kept. You want to make max profit.
// Example :
// 5
// 2 3 5 1 4
// Ans : 50

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
int dp[10005][10005];
int check(int bottle[],int yr,int l,int r){
  if(dp[l][r]!=-1)return dp[l][r];
  if(l>r)return 0;
  return dp[l][r]=max(bottle[l]*yr+check(bottle,yr+1,l+1,r),bottle[r]*yr+check(bottle,yr+1,l,r-1));
}

int main() {
	fast;
  int n;
  cin>>n;
  int bottle[n+1];
  bottle[0]=0;
  for(int i=1;i<=n;i++){
    cin>>bottle[i];
  }
  int yr=1;
  memset(dp,-1,sizeof(dp));
  cout<<check(bottle,yr,1,n)<<"\n";
	return 0;
}
