//https://loj.ac/submission/110695
#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_end=(b);i>=i##_end;--i)
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ull;
template <typename T> inline void rd(T &x) {
    x=0;int f=1;char CH=getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;return;
}
template <typename T> inline bool chMax(T &a,T &b) {
    return a<b?a=b,true:false;
}
template <typename T> inline bool chMin(T &a,T &b) {
    return a>b?a=b,true:false;
}
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
const int INF = 0x7fffffff, MXN = 500, MXM = 30005;
int ans1,ans2,n,m,S,T,from[MXN],dis[MXN],q[MXN],qh,qt;
bool vis[MXN];
struct km {
	int fir[MXN],edge_cnt=1;
	struct edge {
		int to,nxt,w,c;
	}e[MXM];
	inline void AE(int u,int v,int c,int w) {
		e[++edge_cnt].to=v;e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;e[edge_cnt].w=w;e[edge_cnt].c=c;
	}
	inline void Ins(int u,int v,int c,int w) {
		AE(u,v,c,w),AE(v,u,-c,0);
	}
	inline bool spfa() {
		rep(i,1,T) dis[i]=INF,vis[i]=0;
		q[qh=qt=1]=S; dis[S]=0; vis[S]=1;
		while(qh<=qt) {
			int x=q[qh++];
			rpg(i,x) {
				if(e[i].w&&dis[x]+e[i].c<dis[e[i].to]) {
					dis[e[i].to]=dis[x]+e[i].c;  from[e[i].to]=i;
					if(!vis[e[i].to]) vis[e[i].to]=1,q[++qt]=e[i].to;
				}
				vis[x]=0;
			}
		}
		return dis[T]!=INF;
	}
	inline void mcmf() {
		int MIN = INF;
		for(int i=from[T];i;i=from[e[i^1].to])
			MIN = min(MIN,e[i].w);
	//	cerr<<"yes"<<endl;
		for(int i=from[T];i;i=from[e[i^1].to])
			ans1 += e[i].c * MIN , e[i].w -= MIN , e[i^1].w += MIN;
		ans2+=MIN;
	}
	inline void solve() {
		while(spfa()) mcmf();
	}
}orz;
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	rd(n),rd(m); S=1,T=n;
	rep(i,1,m) {
		int a,b,c,d;
		rd(a),rd(b),rd(c),rd(d);
		orz.Ins(a,b,d,c);
	}
	orz.solve();
	cout<<ans2<<" "<<ans1;
}
