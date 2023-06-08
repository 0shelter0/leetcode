#include<iostream>
#include<vector>

using namespace std;
int graph[100000][100000]={0}; //graph
int tag[100000];

void dfs(int src, int dst, int sum){
    
}

int main(){
    int n;
    cin >> n;

    vector<int> edges;
    for(int i = 0; i < n-1; i ++){
        int j;
        cin >> j;
        edges.push_back(j);
    }

    for(int i = 0; i < n; i ++){
        int val;
        cin >> val;
        graph[i+1][edges[i]] = val;
        graph[edges[i]][i+1] = val;
    }

    //用dfs 寻找最短路径，采用递归写法


    return 0;
}