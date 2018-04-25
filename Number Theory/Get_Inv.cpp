inline int exgcd(int a,int b,int &x,int &y) {
	if( !b ) { x = 1 , y = 0 ; return a;}
	else {
		int d = exgcd(b,a%b,y,x);
		y -= a/b*x;
		return d;
	}
}

inline int get_inverse(int a,int Mod) {
	int x,y;
	if( exgcd(a,Mod,x,y) == 1) //ax+my=1;
		return (x%Mod+Mod)%Mod;
	return -1; //不存在
}

//若模数为质数，可使用费马小定理 a^(Mod-2) 则为逆元
