// There are n bricks initially. You have to find number of staircases you can make using these bricks with atleast 2 columns.
// Also previous colum must be smaller than the current one.
// Example:
// input
// 10
// output
// 9

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
int dp[10005][10005];
int stairs(int bricks_rem,int height){
  if(dp[bricks_rem][height]!=-1){return dp[bricks_rem][height];}
  if(bricks_rem==0)return 1;
  if(bricks_rem>height){
    int sum=0;
    for(int i=height+1;i<=bricks_rem;i++){
      sum+=stairs(bricks_rem-i,i);
    }
    return dp[bricks_rem][height]=sum;
  }else{
    return dp[bricks_rem][height]=0;
  }
}

int main() {
	fast;
  int n,bricks;
  cin>>n;
  while(n--){
    cin>>bricks;
    memset(dp,-1,sizeof(dp));
    cout<<stairs(bricks,0)-1<<"\n";
  }
	return 0;
}
