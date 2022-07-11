#include<stdio.h>
#include<limits.h>
int i,j,u,v,mincost,count,min ;
void main(){
	int n;
	scanf("%d",&n);
	int visited[n];
	int cost[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0) cost[i][j]=999;
		}
		visited[i]=0;
	}
	visited[0]=1;
	for(count=0;count<n-1;count++){
		for(i=0,min=999;i<n;i++)
		for(j=0;j<n;j++){
			if(cost[i][j]<min){
				if(visited[i]!=0){
					min=cost[i][j];
					u=i;
					v=j;
				}	
			} 
		}
		if(visited[v]==0){ 
			 printf("%d to %d cost= %d\n",u,v,min);
			 mincost+=min;
		visited[v]=1;
		}
		cost[u][v]=cost[v][u]=999;
	}
	printf("%d",mincost);
}
