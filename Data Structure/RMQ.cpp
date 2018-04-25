inline void chmax(int &x,int y) { x = x > y ? x : y;}
inline void chmin(int &x,int y) { x = x < y ? x : y;}
void init_rmq() {
	for(int i = 1 ; i <= n ; i++)
		mn[i][0] = mx[i][0] = a[i];
	for(int i = 1 ; i <= 20 ; i++)
		for(int j = 1 ; j <= n ; j++) {
			if(j+(1<<i)-1<=n) {
					chmax(mx[j][i-1],mx[j+(1<<(i-1))][i-1]) , 
					chmin(mn[j][i-1],mn[j+(1<<(i-1))][i-1]) ;
			}
		}
}
inline int query_rmq_mx(int l,int r) {
	int k = log(r-l+1) / log(2);
	return max(mx[l][k],mx[r-(1<<k)+1][k]);	
}
inline int query_rmq_mn(int l,int r) {
	int k = log(r-l+1) / log(2);
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
