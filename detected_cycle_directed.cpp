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
class Solution {
 vector<int>v;
void DFS(int node,vector<vector<int>>&adjl,vector<bool>&visited){
 visited[node]=true;
 for(int i : adjl[node]){
    if(!visited[i]){
        DFS(i,adjl,visited);
    }
 }
   v.push_back(node);
}
public:
   /* vector<int>*/void findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<bool>visited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
            DFS(i,prerequisites,visited);
        }
        for(int i =0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
};
int main(){
    vector<vector<int>>v{{1,0},{0,1},{3,1},{3,2}};
    Solution s;s.findOrder(4,v);
}