inline void floyd()
{
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++) 
			cin>>dis[i][j],mindis[i][j]=dis[i][j];
	 
	memset(dis,127,sizeof dis);
	for(int k=1;k<=n;k++) {
		for(int i=1;i<k;i++) {
			for(int j=i+1;j<k;j++) {
				if(mincir>dis[i][k]+dis[j][k]+mindis[i][j]) {
					mincir=dis[i][k]+dis[j][k]+mindis[i][j];
					circnt=1;
				}
				else if(mincir==dis[i][k]+dis[j][k]+mindis[i][j])
					circnt++;
				}
			}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				mindis[i][j]=min(dis[i][j],mindis[i][k]+mindis[k][j]);
			}
		}
	}
	if(circnt==0) 	return cout<<"-1"<<endl,0;
	else cout<<circnt<<" "<<mincir<<endl;
}
