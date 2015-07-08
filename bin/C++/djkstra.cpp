#include <cstdio>
#include <iostream>
#include <vector> 
using namespace std;

//int main()
//{￼
    //変数の定義。
    int MAX_V;
    int cost[MAX_V][MAX_V];
    int d[MAX_V];
    bool used[MAX_V];
    int V;
    int INF = 十分大きな定数;
    
    //上記の代入
    //MAX_V;
    //cost[Max_V][MAX_V];
    //d[MAX_V];
    //used[MAX_V];
    //V=;
    
    
    //始点から拡張店への最短距離を求める。
    void dijkstra(int s) {
        fill(d, d + V, INF);
        fill(used, used + V, false);
        d[s] = 0;
        
        
        while(true){
            int v = -1;
            //まだ使われていない頂点のうち距離が最小のものを探す。
            for (int u = 0; u < V; u++){
                if (!used[u] && (v == -1 || d[u] < d[v])) v = u; //この分岐をしっかりとする。
            }
            
            if ( v == -1) break;
            
            used[v] = true;
            
            //最小距離の更新する。
            for ( int u = 0; u < V; u++){
                d[u] = min(d[u], d[v] + cost[v][u]);
            }
            
        }
        
    }
    //出力（最小距離）
    
//}