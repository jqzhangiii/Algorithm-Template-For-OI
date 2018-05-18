struct Hash{
	int base,P;
	int bin[MXN],hash[MXN];
	Hash(){}
	void prepare(int _base,int _P,char *s){
		base=_base;
		P=_P;
		int n=strlen(s+1);
		bin[0]=1;hash[0]=0;
		for (int i=1;i<=n;++i){
			hash[i]=(1LL*hash[i-1]*base%P+s[i])%P;
			bin[i]=1LL*bin[i-1]*base%P;
		}
	}
	int get_hash(int l,int r){
		return (hash[r]-1LL*hash[l-1]*bin[r-l+1]%P+P)%P;
	}
}h;
