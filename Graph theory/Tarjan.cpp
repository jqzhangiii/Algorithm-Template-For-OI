#include<bits/stdc++.h>
using namespace std;

inline void tarjan(int x) {
	dfn[x] = low[x] = ++dfs_clock; 
	inq[x] = 1; stk[++top] = x; int v;
	for(int i = fir[x] ;i ;i = e[i].nxt) {
		v = e[i].to;
		if(!dfn[x]) {
			tarjan(v);
			low[x] = min(low[x] ,low[v]);
		} else if(inq[v]) {
			low[x] = min(low[x] ,dfn[v]);
		}
	}
	if(low[x] == dfn[x]) {
		++scc;
		do {
			v = stk[top--];
			bel[v] = scc;
			hav[scc]++;
			inq[v] = 0;
		} while(x != v);
	}
}
			
  
