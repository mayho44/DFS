#include <iostream>
#include <iomanip>
#include <cmath>
#include <numeric>
#include<bits/stdc++.h>
#include <string>
using namespace std;
#define endl '\n'
//#define haha cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
    //int N=1e5+5,M=2e5+5;

class Solution {
   void connect(int node,vector<vector<int>>&adjl,vector<bool>&isvisited){
  isvisited[node]=true;
for(int i :adjl[node]){
   if(isvisited[i]==false)connect(i,adjl,isvisited);
}
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      vector<vector<int>>adjl(isConnected.size());
   vector<bool>isvisited(isConnected.size(),false);
        for(int i=0;i<isConnected.size();i++){
         for(int j=i+1;j<isConnected[i].size();j++){
            if(isConnected[i][j]==1){
            adjl[i].push_back(j);
            adjl[j].push_back(i);}
         }
        }
        int counter=0;
        for(int i=0;i<isConnected.size();i++){
         if(!isvisited[i]){
            counter++;
            connect(i,adjl,isvisited);
         }
        }
        return counter;
    }
};
