#include<bits/stdc++.h>
using namespace std;  
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
namespace SplayTree {
	
	int sz,i,n,root;  
	int f[100003],ch[100003][5],size[100003],cnt[100003],key[100003];  
	void clear(int x)  
	{  
	    f[x]=ch[x][0]=ch[x][1]=size[x]=cnt[x]=key[x]=0;  
	}  
	int get(int x)  
	{  
	    return ch[f[x]][1]==x;  
	}  
	void update(int x)  
	{  
	    if (x)  
	     {  
	        size[x]=cnt[x];  
	        if (ch[x][0])  size[x]+=size[ch[x][0]];  
	        if (ch[x][1])  size[x]+=size[ch[x][1]];  
	     }  
	}  
	void rotate(int x)  
	{  
	    int fa=f[x],oldfa=f[f[x]],which=get(x);  
	    ch[fa][which]=ch[x][which^1];f[ch[fa][which]]=fa;
	    f[fa]=x;ch[x][which^1]=fa;  
	    f[x]=oldfa;  
	    if (oldfa)  
	      ch[oldfa][ch[oldfa][1]==fa]=x;  
	    update(fa);update(x);  
	}  
	void splay(int x)  
	{  
	    for (int fa;(fa=f[x]);rotate(x))  
	     if (f[fa])  
	      rotate((get(x)==get(fa))?fa:x);  
	    root=x;  
	}  
	void insert(int x)  
	{  
	    if (root==0)  
	     {  
	        sz++;f[1]=ch[1][0]=ch[1][1]=0;size[1]=1;key[1]=x;cnt[1]=1;root=sz; return;  
	     }  
	    int now=root,fa=0;  
	    while (true)  
	     {  
	        if (key[now]==x)  
	         {  
	            cnt[now]++; update(now); update(fa); splay(now); return ;  
	         }  
	        fa=now;  
	        now=ch[now][key[now]<x];
	        if (now==0) 
	         {  
	            sz++; size[sz]=1; key[sz]=x; cnt[sz]=1;  
	            ch[sz][0]=ch[sz][1]=0; f[sz]=fa; ch[fa][key[fa]<x]=sz;  
	            update(sz); update(fa); splay(sz);  
	            return;  
	         }   
	     }  
	}  
	int find(int x)  
	{  
	  int ans=0,now=root;  
	  while (true)  
	  {  
	    if (x<key[now])  
	     {  
	        now=ch[now][0];  
	     }  
	    else  
	     {  
	        if (ch[now][0])  
	         ans+=size[ch[now][0]];  
	        if (key[now]==x)  { splay(now);return ans+1;}  
	        ans+=cnt[now];  
	        now=ch[now][1];  
	     }  
	  }   
	  //return -1;  
	}  
	int findx(int x)  
	{  
	    int ans=0,now=root;  
	    while (true)  
	     {  
	        if (ch[now][0]&&x<=size[ch[now][0]])  
	         now=ch[now][0];  
	        else  
	         {  
	            ans=(ch[now][0]?size[ch[now][0]]:0)+cnt[now];  
	            if (x<=ans) return key[now];//进入else,就说明该点要么在子树的根节点要么在右子树，如果x<左子树的大小+该点的个数,那么编号x的点必在子树的根节点无疑   
	            x-=ans; now=ch[now][1];  
	         }  
	     }  
	}  
	int pre()  
	{  
	    int now=ch[root][0];  
	    while (ch[now][1]) now=ch[now][1];  
	    return  now;  
	}  
	int next()  
	{  
	    int now=ch[root][1];  
	    while(ch[now][0]) now=ch[now][0];  
	    return now;   
	}  
	bool del(int x)  
	{  
	    if (find(x)==-1) return false;//find操作中已经把x转的根的位置   
	    if (cnt[root]>1)   
	     {  
	        cnt[root]--; return true;  
	     }   
	    if (!ch[root][0]&&!ch[root][1])  
	     {  
	        clear(root); root=0; return true;  
	     }  
	    if (!ch[root][0])  
	     {  
	        int ordr=root; root=ch[root][1]; f[root]=0; clear(ordr); return true;  
	     }  
	    if (!ch[root][1])  
	     {  
	        int ordr=root; root=ch[root][0]; f[root]=0; clear(ordr); return true;  
	     }  
	    int leftbig=pre(),oldr=root;  
	    splay(leftbig);  f[ch[oldr][1]]=root;  ch[root][1]=ch[oldr][1]; clear(oldr); update(root);  
	    return true;  
	}   
}
using namespace SplayTree;
int main()  
{  
//	FO(input);
    scanf("%d",&n);  
    for (i=1;i<=n;i++)  
     {  
        int order,x;  
        scanf("%d%d",&order,&x);  
        switch(order)  
         {  
            case 1:insert(x);break;  
            case 2:del(x); break;  
            case 3:printf("%d\n",find(x));break;  
            case 4:printf("%d\n",findx(x));break;  
            case 5:insert(x); printf("%d\n",key[pre()]); del(x); break;  
            case 6:insert(x); printf("%d\n",key[next()]); del(x); break;  
         }  
     }  
} 
