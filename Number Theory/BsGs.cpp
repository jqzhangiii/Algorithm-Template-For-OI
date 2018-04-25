#define ll long long
inline void exgcd(LL a,LL b,LL &g,LL &x,LL &y)
{
	if(!b)	g = a , x = 1 , y = 0;
	else exgcd(b,a%b,g,y,x),y-=x*(a/b);
}
inline LL inv(LL x,LL p)
{
	LL g,res,tmp;
	exgcd(x,p,g,res,tmp);
	return (res%p+p)%p;
}
inline LL bsgs(LL a,LL b,LL p)
{
	a %= p ,b %= p;
	map<LL,LL> mp;
	LL m = ceil(sqrt(p)) , t = 1;
	for(int i = 0 ; i < m ; i++)
	{
		if(!mp.count(t)) mp[t] = i;
		t = t * a % p;
	}
	LL k = inv(t,p) , w = b;
	for(int i = 0 ; i < m ; i++)
	{
		if(mp.count(w)) return i * m + mp[w];
		w = w * k % p; 
	}
	return -1;
}
