inline void FFT(Cp *A,int f) {
	int i,j,k;
	for(i=0,j=0;i<M;i++) {
		if(i>j)swap(A[i],A[j]);
		for(k=M>>1;(j^=k)<k;k>>=1);
	}
	for(i=1;i<M;i<<=1) {
		w.x=cos(pi/i),w.y=sin(pi/i)*f;
		for(j=0;j<M;j+=i<<1) {
			w0.x=1,w0.y=0;
			for(k=0;k<i;++k) {
				x=A[j+k],y=A[i+j+k]*w0;
				A[j+k]=x+y;
				A[i+j+k]=x-y;
				w0=w0*w;
			}
		}
	}
	if(f==-1) for(i=0;i<M;++i) A[i].x/=M;
}
