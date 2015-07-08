//
//  main.cpp
//  Funatomi-Kadai
//
//  Created by 高橋 克郎 on 2015/06/04.
//  Copyright (c) 2015年 高橋 克郎. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//int main()
//{￼
    
    //辺を表す構造体
    struct edge { int to, cap, rev;};
    
    
    vector<edge> G[MAX_V]; //グラフの隣接リスト表現
    int level[MAX_V]; //sからの距離
    int iter[MAX_V]; //どこまで調べ終わったか　これはイテレータということか？

    //fromからtoに向かう容量capの辺をグラフに追加する。
    void add_edge(int from, int to, int cap){
        G[from].push_back((edge){to, cap, G[to].size()});//sizeが定義されていない。
        G[to].push_bakc((edge){from, 0, G[from].size() - 1});
    }
    
    // sからの最短距離をBFSで計算する。　BFSは幅優先探索。
    void bfs( int s ){
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] =0;
        que.push(s);
        while (!que.empty()){
            int v = que.front(); que.pop();
            for ( int i = 0; i < G[v].size(); i++){
                edge &e = G[v][i];
                if ( e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
            
        }
    }
    
    //増加パスをDFSで探す。
    int dfs(int v, int t, int f){
        if ( v == t) return f;
        for ( int &i = iter[v]; i < G[v].size(); i++){
            edge &e = G[v][i];
            if ( e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
    }
    //出力
//}