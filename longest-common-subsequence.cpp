#include<bits/stdc++.h>
using namespace std;
int dp[500][500]={0};
void lcs(string a,string b){
	int i,j;
	for( i=1;i<=a.length();i++){
		for( j=1;j<=b.length();j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[a.length()][b.length()]<<"\n";
	string ans="";
	while(i>0 && j>0){
		if(dp[i-1][j]<dp[i][j] && dp[i][j-1]<dp[i][j]){
			ans+=a[i-1];
			i--;j--;
		}else{
			if(dp[i-1][j]>dp[i][j-1]){
				i--;
			}else{
				j--;
			}
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string a,b;
	cin>>a>>b;
	lcs(a,b);
    return 0;
}
