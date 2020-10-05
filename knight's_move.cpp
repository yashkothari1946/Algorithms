#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<int,int> > vec;
bool knight_check(int x,int y,int moves[8][8],int next){
  if(next==64)return true;
  int next_x,next_y;
  for(int i=0;i<8;i++){
    next_x = x+vec[i].first;
    next_y = y+vec[i].second;
    if(next_x>=0 && next_x<8 && next_y>=0 && next_y<8 && moves[next_x][next_y]==-1){
        moves[next_x][next_y]=next;
        if(knight_check(next_x,next_y,moves,1+next)){
            return true;
        }else{
          moves[next_x][next_y]=-1;
        }
    }
  }
  return false;
}
void knight_move(int x,int y,int moves[8][8]){
    // order is important .
    vec.push_back(make_pair(2,1));
    vec.push_back(make_pair(1,2));
    vec.push_back(make_pair(-1,2));
    vec.push_back(make_pair(-2,1));
    vec.push_back(make_pair(-2,-1));
    vec.push_back(make_pair(-1,-2));
    vec.push_back(make_pair(1,-2));
    vec.push_back(make_pair(2,-1));
    moves[x][y]=0;
    if(knight_check(x,y,moves,1)){
      cout<<"Possible\n";
      for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
          cout<<moves[i][j]<<" ";
        }cout<<"\n";
      }
      cout<<"\n";
    }else{
      cout<<"Not Possible\n";
    }
}

int main() {
    int x=0,y=0;
    int moves[8][8];
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        moves[i][j]=-1;
      }
    }
    knight_move(0,0,moves);
    return 0;
}
