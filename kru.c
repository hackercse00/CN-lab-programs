#include<stdio.h>
#include<limits.h>
int i,j,u,v,mincost,count,min,visited[100];
void main(){
	int n;
	scanf("%d",&n);
	int cost[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0) cost[i][j]=999;
		}
		visited[i]=0;
	}
	for(count=0;count<n-1;count++){   
		for(i=0,min=999;i<n;i++)
		for(j=0;j<n;j++){
			if(cost[i][j]<min){
				
					min=cost[i][j];
					u=i;
					v=j;
				
			} 
		}
	u=find(u);
	v=find(v);
	if(alc(u,v)){
		printf("%d to %d cost= %d\n",u,v,min);
			 mincost+=min;
	}
	cost[u][v]=cost[v][u]=999;
}
printf("%d",mincost);
}
int find(int i){
	while(visited[i]) i=visited[i];
	return i;
}
int alc(int i,int j){
	if(i!=j){
		visited[j]=i;
		return 1;
	}
	return 0;
}
