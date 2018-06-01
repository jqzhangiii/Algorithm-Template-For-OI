#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef double ld;
typedef long long L;
typedef long double lf;
typedef unsigned int uint;
typedef unsigned long long uL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f,mo=1e9+7;
template<typename A,typename B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<typename A,typename B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
template<typename T>inline T gcd(T x,T y){for(;y;swap(x,y))x%=y;return x;}
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
char *TT,*tmo,but[(1<<15)+2];
#define grc ((TT==tmo&&(tmo=((TT=but)+fread(but,1,1<<15,stdin)),TT==tmo))?-1:*TT++)
inline int rd(){
	int x,f=1,c;for(;!isdigit(c=grc);)f=c!='-';x=c-'0';
	for(;isdigit(c=grc);)x=x*10+c-'0';return f?x:-x;
}
const int N=1e6+11,K=2;
int cpk;
struct P{
	int x[K];
	inline int&operator[](int i){
		return x[i];
	}
	inline bool operator<(const P&t)const{
		return x[cpk]<t.x[cpk];
	}
} a[N>>1];
struct T{
	int x[K],y[K],z[K],d;
	T*ls,*rs;
} pool[N],*cur=pool-1,*rt;
inline void pu(T*o,T*x){
	if(!x)return;
	For(i,0,K){
		upmn(o->y[i],x->y[i]);
		upmx(o->z[i],x->z[i]);
	}
}
inline void B(T*&o,int l,int r){
	if(l>=r)return;
	o=++cur;
	int m=l+r>>1;
	int d=0;ld mn=0;
	For(i,0,K){
		ld sum=0,ave=0;
		For(j,l,r){
			sum+=a[j][i];
		}
		sum/=(r-l);
		For(j,l,r){
			ave+=(a[j][i]-sum)*(a[j][i]-sum);
		}
		if(ave>mn)mn=ave,d=i;
	}
	cpk=o->d=d;
	nth_element(a+l,a+m,a+r);
	For(i,0,K)o->x[i]=o->y[i]=o->z[i]=a[m][i];
	B(o->ls,l,m),pu(o,o->ls);
	B(o->rs,m+1,r),pu(o,o->rs);
}
int x[K];
int n;
inline int ins(T*o){
	int d;T *t;
	for(;o;){
		For(i,0,K)upmn(o->y[i],x[i]),upmx(o->z[i],x[i]);
		d=o->d,t=o;
		o=x[d]<o->x[d]?o->ls:o->rs;
	}
	if(x[d]<t->x[d])o=t->ls=++cur;
	else o=t->rs=++cur;
	o->d=d+1==K?0:d+1;
	For(i,0,K)o->x[i]=o->y[i]=o->z[i]=x[i];
}
int ans;
inline int dist(int*x,int*y,int*z){	
	int res=0;
	For(i,0,K)if(x[i]<y[i])res+=y[i]-x[i];
	else if(x[i]>z[i])res+=x[i]-z[i];
	return res;
}
inline int dist(int*x,int*y){
	int res=0;
	For(i,0,K)res+=abs(x[i]-y[i]);
	return res;
}
inline void ask(T*o){
	if(!o||dist(x,o->y,o->z)>=ans)return;
	upmn(ans,dist(x,o->x));
	int d=o->d;
	if(x[d]<o->x[d])ask(o->ls),ask(o->rs);
	else ask(o->rs),ask(o->ls);
}

char butt[(1<<15)+2],*bp=butt,*bq=butt+(1<<15);
inline void pr(char x){
    *bp=x;(++bp==bq)?fwrite(butt,1,1<<15,stdout),bp=butt:0;
}
inline void Wr(int x){
    if(!x)pr('0');
    else{
        if(x<0)pr('-'),x=-x;
        static int s[12];
        int p=0;
        while(x)s[p++]=x%10,x/=10;
        per(i,0,p-1)pr(s[i]+'0');
    }
		pr('\n');
}
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
	freopen("g.out","w",stdout);
#endif
	n=rd();int m=rd();
	For(i,0,n)a[i].x[0]=rd(),a[i].x[1]=rd();
	B(rt,0,n);
	for(;m--;){
		int op=rd();
		For(i,0,K)x[i]=rd();
		if(op==1)ins(rt);
		else{
			ans=1<<30;
			ask(rt);
			Wr(ans);
		}
	}
	fwrite(butt,1,bp-butt,stdout);
}
