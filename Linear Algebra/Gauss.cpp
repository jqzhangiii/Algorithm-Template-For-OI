#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double A[110][110];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i) {
		for(int j=0;j<=n;++j) 
			cin>>A[i][j];
	}
	for(int i=0;i<n;++i) {
		int tmp=i;
		for(int j=i;j<n;++j) 
			if(fabs(A[j][i]-A[tmp][i])<=eps) tmp=j;
		for(int j=0;j<=n;++j) {
			swap(A[i][j],A[tmp][j]);
		}
		if(fabs(A[i][i])<=eps) {
			puts("No Solution\n");
			return 0;
		}
		for(int j=i+1;j<=n;++j) A[i][j]/=A[i][i];
		for(int j=0;j<n;++j) {
			if(i!=j) 
				for(int k=i+1;k<=n;++k) 
					A[j][k]-=A[j][i]*A[i][k];
		}
	}
	for(int i=0;i<n;++i) printf("%.2lf\n",A[i][n]);
	return 0;
}
