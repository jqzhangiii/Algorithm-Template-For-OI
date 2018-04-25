struct SAM {
 	SAM(){cnt=0;last=rt=++cnt;}
	inline void extend(int x){
		p = last; np = last = ++cnt; l[np] = l[p] + 1; sz[np]=1;
		while(!c[p][x] && p) c[p][x] = np ,p = fail[p];
		if(!p) fail[np] = rt;
		else {
			q = c[p][x];
			if(l[q] == l[p] + 1) fail[np] = q;
			else {
				nq = ++cnt; l[nq] = l[p] + 1;
				memcpy(c[nq],c[q],sizeof c[q]);
				fail[nq] = fail[q] , fail[q] = fail[np] = nq;
				while(c[p][x] == q && p) c[p][x] = nq , p = fail[p];
			}
		}
	}
}sam;
