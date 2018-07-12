//https://zh.wikipedia.org/wiki/%E5%8E%9F%E6%A0%B9

inline LL fpw(LL x,LL y,LL Mod) {
	LL ret=1;
	for(;y;y>>=1,x=x*x%Mod) if(y&1) ret=ret*x%Mod;
	return ret;
}

inline int get(LL x) {
	if(x==2) return 1;
	for(int i=2;;++i) {
		bool flag=1;
		for(int j=2;j*j<x;++j) 
			if(fpw(i,(x-1)/j,x)==1) {
				flag=0;
				break;
			}
		if(flag) return i;
	}
}
