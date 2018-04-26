inline int dfs(int x,int flow) {
	if(x == T) return flow;
	int used = 0 , tmp;
	rpg(i,x) {
		if(e[i].w && dep[e[i].to] == dep[x] + 1) {
			tmp = flow - used , tmp = dfs(e[i].to , min(tmp,e[i].w));
			e[i].w -= tmp , e[i^1].w += tmp;
			used += tmp ; if(used == flow) return used;
		}
	}
	if(!used) dep[x] = -1;
	return used;
}

inline bool bfs() {
	memset(dep,-1,sizeof dep);
	static int q[MXN];
	int hd = 1 , tl = 1 , x;
	q[tl++] = S; dep[S] = 0;
	while(hd!=tl) {
		x = q[hd++];
		rpg(i,x) {
			int v = e[i].to;
			if(dep[v] == -1 && e[i].w) {
				dep[v] = dep[x] + 1;
				q[tl++] = v;
			}
		}
	}
	return dep[T] != -1;
}

inline int dinic() {
	int ret = 0 ;
	while(bfs()) ret += dfs(S,INF);
	return ret;
}
