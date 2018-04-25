inline int fast_pow(int a,int b,int Mod) {
	int ret = 1;
	for(;b;b>>=1,a=a*a%Mod) if(b&1) ret = ret * a % Mod;
	return ret;
}
