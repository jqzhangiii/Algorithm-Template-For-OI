//https://www.luogu.org/problemnew/show/P3371
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define RG register
#define rpg(i,x) for(RG int i=fir[x];i;i=e[i].nxt)
typedef pair<int,int> PII;
const int MXN = 1e4 + 5;
int dis[MXN],fir[MXN],edge_cnt,n,m,S,vis[MXN];
priority_queue<PII,vector<PII>,greater<PII> > q;

struct edge{
	int to,nxt,w;
}e[MXN * 50];
inline void AE(int u,int v,int w) {
	e[++edge_cnt].to=v,e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;e[edge_cnt].w=w;
}

inline void dijkstra() {
	for(int i=0;i<=n;++i) dis[i]=2147483647;
	q.push(mp(0,S)); dis[S]=0;
//	fprintf(stderr,"S = %d dis[S] = %d\n",S,dis[S]);
	while(!q.empty()) {
		int now = q.top().se; q.pop();
		rpg(i,now) {
//			fprintf(stderr," e[i].to = %d , e[i].w = %d\n",e[i].to,e[i].w);
			int v = e[i].to , w = e[i].w;
			if(dis[v]>dis[now]+w) {
				dis[v]=dis[now]+w;
				if(!vis[v]) {
					vis[v]=1;
					q.push(mp(dis[v],v));
				}
			}
		}
		vis[now]=0;
	}
}

int main() {
	ios::sync_with_stdio(false);
		cin>>n>>m>>S;
	for(int i=1;i<=m;++i) {
		int x,y,z;
		cin>>x>>y>>z;
		AE(x,y,z);
	}
	dijkstra();
	for(int i=1;i<=n;++i) {
		if(i!=n) {
			cout<<dis[i]<<" ";
		} else {
			cout<<dis[i];
		}
	}
}
