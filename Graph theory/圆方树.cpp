template <typename T> inline bool chmax(T &a,const T &b) {
    return a<b?a=b,true:false;
}
template <typename T> inline bool chmin(T &a,const T &b) {
    return a>b?a=b,true:false;
}
struct graph {
    int fir[MXN<<1],edge_cnt;
    graph(){cls(fir,0),edge_cnt=1;}
    struct edge {
        int to,nxt;
    }e[MXN<<2];
    inline void AE(int u,int v) {
        e[++edge_cnt].to=v;e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;
    }
}g1,g2;
inline void tarjan(int x,int fro) {
    dfn[x]=low[x]=++dfs_clock;
    rpg1(i,x) {
        if(i==(fro^1)) continue;
        if(!dfn[g1.e[i].to]) {
            stk[++top]=i;
            tarjan(g1.e[i].to,i);
            chmin(low[x],low[g1.e[i].to]);
            if(low[g1.e[i].to]>=dfn[x]) {
                ++sz; int v=0;
                while(v!=i) {
                    v=stk[top--]; ++val[sz+n];
                    g2.AE(sz+n,g1.e[v].to); g2.AE(g1.e[v].to,sz+n);
                }g2.AE(sz+n,x);g2.AE(x,sz+n); ++val[sz+n];
            }
        } else chmin(low[x],dfn[g1.e[i].to]);
    }
}
