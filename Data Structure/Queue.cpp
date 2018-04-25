struct Queue{
	int q[MXN],h,t;
	inline void init() {h=t=0;memset(q,0,sizeof q);}
	inline bool empty() {return h==t;}
	inline void push(int x) {q[t++]=x;}
	inline void pop_back() {t--;}
	inline void pop_front() {h++;}
	inline int front() {return q[h];}
	inline int back() {return q[t-1];}
};
