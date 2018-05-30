//xor
const int mod=10007,inv2=5004;
struct FastWalshTransform {
	int n;
	void init(int n) {
		this->n=n;
	}
	void transform(int *a,int len,int mul) {
		if(len==1)return;
		int mid=len>>1;
		transform(a,mid,mul);
		transform(a+mid,mid,mul);
		for(int i=0; i<mid; i++) {
			LL x=a[i],y=a[mid+i];
			a[i]=(x+y)*mul%mod;
			a[mid+i]=(x-y+mod)*mul%mod;
		}
	}
	void fwt(int *a) {
		transform(a,n,1);
	}
	void ufwt(int *a) {
		transform(a,n,inv2);
	}
} ;

//iterator 
const int mod=10007,inv2=5004;
struct FastWalshTransform {
	int n;
	void init(int n) {
		this->n=n;
	}
	void transform(int *a,int mul) {
		for(int len=2; len<=n; len<<=1) {
			int mid=len>>1;
			for(int *p=a; p!=a+n; p+=len)
				for(int i=0; i<mid; i++) {
					LL x=p[i],y=p[mid+i];
					p[i]=(x+y)*mul%mod;
					p[mid+i]=(x-y+mod)*mul%mod;
				}
		}
	}
	void fwt(int *a) {
		transform(a,1);
	}
	void ufwt(int *a) {
		transform(a,inv2);
	}
} ;
