#include<bits/stdc++.h>
using namespace std;
const int N=50011;
int n,m;
vector<int> g[N];
vector<int> bc[N];
int dfs_cnt,bcc_cnt;
int id[N];
int U[N],V[N],tp;
int dfn[N],low[N];
int isc[N];
void Dfs(int x,int fa=-1){
	int ch=0;
	dfn[x]=low[x]=++dfs_cnt;
	for(int i=0;i<g[x].size();++i){
		int v=g[x][i];
		if(!dfn[v]){
			++ch;
			U[++tp]=x,V[tp]=v;
			Dfs(v,x);
			if(low[v]>=dfn[x]){
				isc[x]=1; 
				++bcc_cnt;
				int u,o;
				do{
					u=U[tp],o=V[tp--];
					if(id[u]!=bcc_cnt)bc[bcc_cnt].push_back(u),id[u]=bcc_cnt;
					if(id[o]!=bcc_cnt)bc[bcc_cnt].push_back(o),id[o]=bcc_cnt;
				}while(u!=x&&o!=v);
			}else low[x]=min(low[x],low[v]);
		}else if(v!=fa){
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(fa==-1 && ch==1) isc[x]=0;
}
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	for(;cin>>m && m;){
		for(;n;)g[n--].clear();
		for(int i=1;i<=m;++i){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			n=max(n,max(u,v));
		}
		memset(id+1,0,4*n);
		memset(isc+1,0,4*n);
		memset(dfn+1,0,4*n);
		for(;bcc_cnt;)bc[bcc_cnt--].clear();
		dfs_cnt=0;
		for(int i=1;i<=n;++i)if(!dfn[i]){
			Dfs(i);
		}
		int t=0;long long ans=1;
		for(int i=1;i<=bcc_cnt;++i){
			int s=bc[i].size();
			int p=0;
			for(int j=0;j<s;++j){
				if(isc[bc[i][j]])++p; 
			}
			if(p==1)ans*=(s-1),++t;
		}
		if(bcc_cnt==1)t=2,ans=(long long)bc[1].size()*(bc[1].size()-1)/2;
		static int cas=0;
		printf("Case %d: %d %lld\n",++cas,t,ans);
	}
}
