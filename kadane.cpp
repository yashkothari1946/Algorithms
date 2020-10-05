//Largest Sum Contiguous Subarray

#include<bits/stdc++.h>
using namespace std;
int n;
void kadane(int arr[]){
    int sum=0,maxx=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum<0)sum=0;
        else{
            maxx = max(sum,maxx);
        }
    }
    cout<<maxx<<"\n";
}

int main(){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    kadane(arr);
}
