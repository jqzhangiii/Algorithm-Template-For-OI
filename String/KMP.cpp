inline void Get_Next(char *s) {
	int len = strlen(s);
	int i,j; nxt[0] = -1;
	for(i=0,j=0;i<len;++i) {
		if(j == -1 || s[i] == s[j]) nxt[++i] = ++j;
		else j = nxt[j];
	}
}
