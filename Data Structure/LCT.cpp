inline bool dir(int x) { return c[ fa[x] ][1] == x; }
 
inline bool isrt(int x) { return c[ fa[x] ][1] != x && c[ fa[x] ][0] != x;}

inline void pushdown(int x) {
	if(!rev[x]) return;
	rev[x]^=1;
	rev[c[x][0]]^=1,rev[c[x][1]]^=1;
	swap(c[x][0],c[x][1]);
}

inline void rot(int x) {
	int y = fa[x], z = fa[y], d = dir(x);
	if(!isrt(y)) c[z][dir(y)] = x; fa[x] = z;
	c[y][d] = c[x][d^1] , fa[ c[x][d^1] ] = y;
	fa[y] = x ,c[x][d^1] = y;
}

inline void gop(int x){
	if(!isrt(x)) gop(fa[x]);
	pushdown(x);
}

inline void splay(int x) {
	gop(x);
	for(int y=fa[x];!isrt(x);rot(x),y=fa[x])
		if(!isrt(y)) dir(x)^dir(y)?rot(x):rot(y);
}

inline void access(int x) {
	for(int y=0;x;x=fa[y=x])
		splay(x),c[x][1]=y;
}

inline void mkrt(int x) {
	access(x),splay(x),rev[x]^=1;
}

inline void link(int x,int y) {
	mkrt(x),fa[x]=y;
}

inline void cut(int x,int y) {
	mkrt(x),access(y),splay(y),c[y][0]=fa[x]=0;
}

inline int fdrt(int x) {
	access(x);splay(x); while(c[x][0]) x=c[x][0]; splay(x); return x;
}
