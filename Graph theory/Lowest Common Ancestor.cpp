inline void dfs(int x,int f) {
	for(int i = 1 ;(1<<i) <= dep[x] ;++i) {
		fa[x][i] = fa[fa[x][i-1]][i-1];
	}
	for(int i = fir[x] ; i; i = e[i].nxt) {
		int v = e[i].to;
		if(v == f) continue; 
		fa[v][0] = x;	dep[v] = dep[x] + 1;
		dfs(v,x);
	}
}

inline int LCA(int x,int y) {
	if(dep[x] > dep[y]) swap(x,y);
	for(int i = 20 ;i >= 0 ;--i) 
		if(dep[fa[y][i]] >= dep[x]) y = fa[y][i];
	if(dep[x] > dep[y]) swap(x,y);
	for(int i = 20 ;i >= 0 ;--i) {
		if(fa[x][i] != fa[y][i]) 
			x = fa[x][i] , y = fa[y][i];
	}
	return x != y ? fa[x][0] : x;
}



