#include <cstdio>
#include <iostream>
#include <vector> 
using namespace std;

//int main()
//{￼
    //変数の定義。
    int V; 					//頂点数
    vector<int> G[MAX_V]; 	//グラフの隣接リスト表現  http://vivi.dyndns.org/tech/cpp/vector.html にイテレータについての記述あり。
    int match[MAX_V]; 		//マッチングペア
    bool used[MAX_V];		//DFSですでにしらべたかのフラグ DFS=深さ優先探索。
    
    //uとvを結ぶ辺をグラフに追加する。
    void add_edge(int u, int v){
        G[u].push_back(v);//push.backがなにを示しているかわかってない。 p92?
        G[v].push_back(u);//G[v]がなにを表しているかわからない。定義がまだだ。
    }
    
    //増加パスをDFSで探す。このアルゴリズムがなにをしているかをまだ理解していない。　プログラミングチャレンジコンテストブック　p33参照。
    bool dfs(int v){
        used[v] = true;
        for ( int i = 0; i < G[v].size(); i++){
            int u = G[v][i], w = match[u];
            if (w<0 || !used[w] && dfs(w)){//分岐がこれでよいか調べる。
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    
    //二部グラフの最大マッチングを求める
    int bipartite_matching(){
        int res = 0;
        memset(match, -1, sizeof(match));//この変数がちゃんと定義されてない。sizeof//memsetが定義されてない。
        for ( int v = 0; v < V; v++){
            if(match[v]<0){
                memset(used, 0, sizeof(used));
                if (dfs(v)){//dfs(v)が頂点数個の値を持っていて、この値だけチェックしているので、あとはこの関数をmain関数で包めば終わり。
                    res++;
                }
            }
        }
        return res;
    }
    //出力
//}