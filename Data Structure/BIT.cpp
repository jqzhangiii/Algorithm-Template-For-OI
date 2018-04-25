#define lowbit(x) (x&(-x))
struct BIT {
	int c[MXN];
	inline void Add(int x,int val) {
		for(int i=x;i<=n;i+=lowbit(i)) c[x]+=val;
	}
	inline int Ask(int x) {
		int ret = 0;
		for(int i=x;i;i-=lowbit(i)) ret += c[x];
		return ret;
	}
}
  
