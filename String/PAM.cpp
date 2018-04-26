struct PAM {
	PAM(){cnt=f[0]=f[1]=1;l[1]=-1;}
	inline void extend(int x,int n) {
		int p = last; while(s[n-l[p]-1]!=s[n]) p=fail[p];
		if(!c[p][x]) {
			int now = ++cnt , k = fail[p];
			l[now] = l[p] + 2;
			while(s[n-l[k]-1]!=s[n]) k=fail[k];
			f[now] = c[k][x] , c[p][x] = now;
		}
		last = c[p][x];
		sz[last]++;
	}
};
