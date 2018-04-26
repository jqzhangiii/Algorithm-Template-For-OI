

#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 2e5 + 56;
int tot,cnt,n,m,fa[MXN];
LL ans;
struct edge{
	int u,v,w;
}e[500005];
inline bool cmp(edge a,edge b){return a.w<b.w;}
inline int getfa(int x) {return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n);rd(m);rep(i,1,n) fa[i]=i; rep(i,1,m) rd(e[i].u),rd(e[i].v),rd(e[i].w);sort(e+1,e+1+m,cmp);
	rep(i,1,m) {
		#define u e[i].u 
		#define v e[i].v
		#define w e[i].w
		int fx=getfa(u),fy=getfa(v);
		if(fx!=fy) {
			fa[fx]=fy;
			ans+=w;
			if(++cnt==n-1) return printf("%lld\n",ans),0;
		}
	}
	return puts("0"),0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
