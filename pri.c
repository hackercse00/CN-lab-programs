#include<stdio.h>
#include<limits.h>
int i,j,u,v,x,count,min,ans;
void main(){
	int n;
	scanf("%d",&n);
	int visited[n],cost[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0) cost[i][j]=INT_MAX;
		}
		visited[i]=0;
	}
	scanf("%d",&x);
	visited[x]=1;
	for(count=0;count<n-1;count++){
	for(i=0,min=INT_MAX;i<n;i++){
		for(j=0;j<n;j++){
			if(cost[i][j]<min&visited[i]!=0){
				min=cost[i][j];
				u=i;
				v=j;
			}
		}
	}
	if(visited[v]==0){
		visited[v]=1;
		printf("%d to %d min is %d\n",u,v,min);
		ans+=min;
	}
	cost[u][v]=cost[v][u]=INT_MAX;
}
printf("%d",ans);
}
