inline int fpw(int x,int y) {
	int ret = 1;
	for(;y;y>>=1,x=1LL*x*x%Mod) if(y&1) ret=1LL*ret*x%Mod;
	return ret;
}

inline void NTT(int *A,int f) {
	int wn,w0,i,j,k; for(int i=0;i<M;++i) if(rev[i]>i) swap(A[rev[i]],A[i]);
	for(i=1;i<M;i<<=1) {
		wn=fpw(g,(Mod-1)/(i<<1));
		if(f==-1) wn=fpw(wn,Mod-2);
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
		int inv = fpw(M,Mod-2);
		for(int i=0;i<M;++i) A[i]=1LL*A[i]*inv%Mod;
	}
}
