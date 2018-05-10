//https://www.luogu.org/problemnew/show/P4238
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register
const int Mod = 998244353 , MXN = 4e5 + 5 , g = 3;

int A[MXN],B[MXN],C[MXN],n,M,tmd,rev[MXN];

inline int qpow(int x,int y) {
	int ret=1;
	for(;y;y>>=1,x=1LL*x*x%Mod) if(y&1) ret=1LL*ret*x%Mod;
	return ret;
}

inline void NTT(int *A,int f) {
	int wn,w0,i,j,k; for(int i=0;i<M;++i) if(rev[i]>i) swap(A[rev[i]],A[i]);
	for(int i=1;i<M;i<<=1) {
		wn=qpow(g,(Mod-1)/(i<<1));
		if(f==-1) wn=qpow(wn,Mod-2);
		for(j=0;j<M;j+=i<<1) {
			w0=1;
			for(k=0;k<i;++k) {
				int x=A[j+k],y=1LL*w0*A[j+k+i]%Mod;
				A[j+k]=(x+y)%Mod;
				A[j+k+i]=(x-y+Mod)%Mod;
				w0=1LL*w0*wn%Mod;
			}
		}
	}
	if(f==-1) {
		int inv=qpow(M,Mod-2);
		for(i=0;i<M;++i) A[i]=1LL*A[i]*inv%Mod;
	}
}

inline void get_inv(int *A,int *B,int deg) {
	if(deg == 1) {B[0]=qpow(A[0],Mod-2);return;}
	get_inv(A,B,(deg+1)>>1);
	for(tmd=0,M=1;M<(deg<<1);M<<=1,++tmd);
	for(RG int i=0;i<M;++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(tmd-1));
	for(RG int i=0;i<deg;++i) C[i]=A[i];
	for(RG int i=deg;i<M;++i) C[i]=0;
	NTT(C,1),NTT(B,1);
	for(RG int i=0;i<M;++i) {
		B[i]=1LL*(2-1LL*C[i]*B[i]%Mod+Mod)%Mod*B[i]%Mod;
	}
	NTT(B,-1);
	for(RG int i=deg;i<M;++i) B[i]=0;
}

int main() {
	ios::sync_with_stdio(false);
	cin>>n;for(RG int i=0;i<n;++i) cin>>A[i];
	get_inv(A,B,n);
	for(RG int i=0;i<n;++i) cout<<B[i]<<" ";
	return 0;
}
