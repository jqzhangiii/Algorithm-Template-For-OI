struct Queue{
	int q[N],h,t;
	inline void init() {h=t=0;memset(q,0,sizeof q);}
	inline bool empty() {return h==t;}
	inline void push(int x) {q[t++]=x;}
	inline void pop_back() {t--;}
	inline void pop_front() {h++;}
	inline int front() {return q[h];}
	inline int back() {return q[t-1];}
};
inline bool spfa() {
	rep(i,0,TT)	d[i]=INF;
	Queue q; q.init();
	q.push(S); mark[S]=1; d[S]=0;
	while(!q.empty()) {
		int now=q.front(); q.pop_front();
		rpg(i,now) {
			if(e[i].w&&d[now]+e[i].c<d[e[i].to]) {
				d[e[i].to]=d[now]+e[i].c; from[e[i].to]=i;
				if(!mark[e[i].to]) {
					q.push(e[i].to); mark[e[i].to]=1; 
				}
			}
		}
		mark[now]=0;
	}
	return d[TT]!=INF;
}
inline void mcf() {
	int minn=INF;
	for(int i=from[TT];i;i=from[e[i].from])
		minn=min(minn,e[i].w);
	for(int i=from[TT];i;i=from[e[i].from]) {
		ans+=e[i].c*minn;
		e[i].w-=minn;e[i^1].w+=minn;
	}
	ans1+=minn;
}
