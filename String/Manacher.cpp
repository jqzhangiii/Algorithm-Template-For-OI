void manacher() {
	for(int i=0;i<n;i++) {
		a[i*2]=ch[i];
		a[i*2+1]='#';
	}
	pos=0,MR=-1;
	for(int i=0;i<2*n-1;i++) {
		if(i<MR)R[i]=min(R[2*pos-i],MR-i);
		else R[i]=1;
		while(i-R[i]+1>=0&&i+R[i]-1<=2*n-2&&a[i+R[i]-1]==a[i-R[i]+1])R[i]++;
		R[i]--;
		if(R[i]+i-1>MR)	pos=i;MR=i+R[i]-1;
	}
}
