#include<stdio.h>
#include<string.h>
#include<math.h>
 void main()
{
   int u,v,num,i,j,l,k,s[10],min,cost[10][10],dist[10],path[10],n;
   printf("\n enter the no of vertices:");
   scanf("%d",&n);
   printf("\n enter the adjacency matrix:\n");
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
     scanf("%d",&cost[i][j]);
     }
   }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
     if(i==j)
     {
       cost[i][j]=0;
     }
     else if(cost[i][j]==-1)
     {
      cost[i][j]=999;
     }
    }
  }
   printf("\nenter source vertex:");
   scanf("%d",&v);
  for(i=1;i<=n;i++)
  {
   s[i]=0;
   path[i]=v;
   dist[i]=cost[v][i];
  }
  dist[v]=0;
  for(num=2;num<=n;num++)
 {
   min=999;
   u=0;
  for(i=1;i<=n;i++)
  {
   if(s[i]!=1)
   {
    if(min>dist[i])
    {
     u=i;
     min=dist[i];
    }
   }
  }
  s[u]=1;
 for(i=1;i<=n;i++)
 {
   if(s[i]!=1)
   {
    if(dist[i]>(min+cost[u][i]))
    {
     dist[i]=min+cost[u][i];
     path[i]=u;
    }
   }
 }
}
  printf("\n");
  printf("\ndistance node path\n");
 for(i=1;i<=n;i++)
 {
   printf("\n %d",dist[i]);
   printf(" %d ",i);
   j=i;
  do
  {
  printf(" --> %d ",path[j]);
  u=path[j];
  j=u;
  }while(u!=v);
 }
}
