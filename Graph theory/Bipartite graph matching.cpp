#include<bits/stdc++.h>
using namespace std;
const int MXN = 505;
const int MXM = MXN * MXN;
int lk[MXN],vis[MXN],tot,ans[MXN],cnt,fir[MXN];
#define rpg(i,x) for(int i=fir[x];i;i=e[i].nxt)
struct edge{
	int to,nxt;
}e[MXM<<1];
inline void AE(int u,int v) {
	e[++cnt].to = v ; e[cnt].nxt=fir[u];fir[u] = cnt;
}
inline bool dfs(int x) {
	rpg(i,x) {
		int v = e[i].to;
		if(!vis[v]) {
			vis[v] = 1;
			if(!lk[v] || dfs(lk[v])) {
				lk[v] = x;
				return 1;
			}
		}
	}
	return false;
}
int n1,n2,m;
int main() {
	ios::sync_with_stdio(false);
	cin>>n1>>n2>>m;
	for(int i=1;i<=m;++i) {
		int x,y; cin>>x>>y;
		AE(x,y);
	}
	for(int i=1;i<=n1;++i) {
		memset(vis,0,sizeof vis);
		if(dfs(i)) ++tot;
	}
	cout<<tot<<endl;
	for(int i=1;i<=n2;++i) {
		ans[lk[i]]=i;
	}
	for(int i=1;i<=n1;++i) {
		cout<<ans[i]<<" ";
	}
}
