//bzoj 2049洞穴勘测cave
#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define For(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> PII;
typedef long long LL;
const int INF = 0x7fffffff;
/*const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/ 
template <typename T> inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1e5 + 5;
int fa[MXN],c[MXN][2],rev[MXN],n,q;
inline bool dir(int x) {
	return c[ fa[x] ][1] == x;
}
inline bool isrt(int x) {
	return (c[ fa[x] ][1] != x && c[ fa[x] ][0] != x);
}
inline void rot(int x) {
	int y=fa[x],z=fa[y],d=dir(x);
	if(!isrt(y)) c[z][dir(y)]=x; fa[x]=z;
	fa[y]=x; fa[c[x][d^1]]=y; c[y][d]=c[x][d^1]; c[x][d^1]=y;
}
inline void pushdown(int x) {
	if(!rev[x]) return;
	rev[x]^=1; rev[c[x][0]]^=1,rev[c[x][1]]^=1;
	swap(c[x][0],c[x][1]);
}
inline void gop(int x) {
	if(!isrt(x)) gop(fa[x]);
	pushdown(x);
}
inline void splay(int x) {
	gop(x);
	for(int y=fa[x];!isrt(x);rot(x),y=fa[x])
		if(!isrt(y)) dir(x)^dir(y)?rot(x):rot(y);
}
inline void	access(int x) {
	for(int y=0;x;x=fa[y=x])
		splay(x),c[x][1]=y;
}
inline void mkrt(int x) {
	access(x),splay(x); rev[x]^=1;
}
inline void link(int x,int y) {
	mkrt(x); fa[x]=y;
}
inline void cut(int x,int y) {
	mkrt(x); access(y); splay(y); fa[x]=c[y][0]=0;
}
inline int fdrt(int x) {
	access(x); splay(x); while(c[x][0]) x=c[x][0]; splay(x); return x;
}

int main() {
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
    scanf("%d%d",&n,&q);
    while(q--) {
        char str[10]; int x,y,fx,fy;
        scanf("%s%d%d",str,&x,&y);
        if(str[0]=='Q') {
            fx = fdrt(x), fy = fdrt(y);
            if(fx == fy) puts("Yes");
            else puts("No");
        } else if(str[0]=='C') {
            link(x,y);
        } else {
            cut(x,y);
        }
    }
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
