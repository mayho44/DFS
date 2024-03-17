#include <iostream>
#include <iomanip>
#include <cmath>
#include <numeric>
#include<bits/stdc++.h>
#include <string>
using namespace std;
#define endl '\n'
//#define haha cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
/*
still needs to be completed
*/
#define ll long long
const int N=1e5+5;
int indx=-1,maxi=1000000,counter=0,lol=0;
deque<vector<string>>dq;
class Solution {
    void DFS(int node, vector<vector<int>>& adjl,vector<bool>&visited){
        visited[node]=true;
        for(int i : adjl[node]){
            if(!visited[i]){
                if(i==indx)
                    maxi=min(maxi,counter),counter=0;
                else {
                    counter++;
                    }
                      DFS(i,adjl,visited);
            }
        }

    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<pair<int,string>>>adjl(wordList.size()+1);
        vector<bool>visited(wordList.size()+1,false);
          for(int i=0;i<wordList.size();i++){
            int counter=0;
            for(int j=0;j<beginWord.length();j++){
                if(beginWord[j]!=wordList[i][j])counter++;
                if(counter>1)break;
            }
            if(counter==1)adjl[0].push_back({i+1,wordList[i+1]}),adjl[i+1].push_back({0,beginWord});
          }
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==endWord)indx=i;
          for(int j=i+1;j<wordList.size();j++){
            int counter=0;
            for(int k=0;k<wordList[i].length();k++){
if(wordList[i][k]!=wordList[j][k])counter++;
if(counter>1)break;
            }
            if(counter==1){
adjl[i+1].push_back({j+1,wordList[j+1]});
adjl[j+1].push_back({i+1,wordList[i+1]});
            }
          }    
        }
     
        DFS(0,adjl,visited);
    
    }

};