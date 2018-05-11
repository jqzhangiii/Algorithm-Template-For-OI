//https://www.luogu.org/problemnew/show/P3834
#include<bits/stdc++.h>
using namespace std;
const int MXN = 2e5 + 5;
struct tree {
	int ls,rs; int sum;
}tr[MXN*23];
int rt[MXN],a[MXN],num[MXN],cnt,n,m,len;

inline void Ins(int &y,int x,int l,int r,int xx) {
	tr[y=++cnt]=tr[x]; tr[y].sum++;
	if(l==r) return;
	int mid = l+r>>1;
	if(xx<=mid) {
		Ins(tr[y].ls,tr[x].ls,l,mid,xx);
	} else {
		Ins(tr[y].rs,tr[x].rs,mid+1,r,xx);
	}
}

inline int Query(int l,int r,int k,int ll,int rr) {
	if(ll==rr) return ll;
	int tmp=tr[tr[r].ls].sum-tr[tr[l].ls].sum;
	if(k<=tmp) return Query(tr[l].ls,tr[r].ls,k,ll,(ll+rr)/2);
	else return Query(tr[l].rs,tr[r].rs,k-tmp,(ll+rr)/2+1,rr);
}


int main() {
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	memcpy(num,a,sizeof a);
	sort(a+1,a+1+n); len=unique(a+1,a+1+n)-a;
	for(int i=1;i<=n;++i) {
		num[i]=lower_bound(a+1,a+1+len,num[i])-a;
	}
	for(int i=1;i<=n;++i) {
		printf(" a[%d] = %d , num[%d] = %d\n",i,a[i],i,num[i]);
	}

	for(int i=1;i<=n;++i) {
		Ins(rt[i],rt[i-1],1,n,num[i]);
	}
	while(m--) {
		int l,r,k;
		cin>>l>>r>>k;
		cout<<a[Query(rt[l-1],rt[r],k,1,n)]<<endl;
	}
}
