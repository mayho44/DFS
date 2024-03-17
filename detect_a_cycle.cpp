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
const int N=1e5+5;
class Graph {
bool cyclic(int node,int p,vector<int> adj[],vector<bool>visited){
visited[node]=true;
for(int i :adj[node]){
    if(visited[i] && i != p){
        return true;
    }
    else if(!visited[i])
    {
      if(cyclic(i,node,adj,visited)) return true;
    }
}
return false;
}
public:
    bool detectCycle(int V, vector<int> adj[]) {
      vector<bool>visited(,false);
       for(int i=0;i<V;i++){
        if(!visited[i]){
      if(cyclic(i,-1,adj,visited)){
        return true;
      } 
        }
      }
      return false;
    }
};