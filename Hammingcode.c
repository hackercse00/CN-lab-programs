/*AUTHOR:ARLI A SASI VARDHAN
Created on:02-06-2022 10:07A.M
*/
#include<stdio.h>
#include<math.h>
void sender();
void reciever();
int i,n,j,r=1,x,t=0,count=0;
void main(){
        char s;
        printf("Choose S to send the data and R to recieve:\n");
        scanf("%c",&s);
        if(s=='s'||s=='S') sender();
        else if(s=='R'||s=='r') reciever();
        else printf("Choose correct option\n");
        printf("\n");
}
void sender(){
        printf("Enter data set size:\n");
        scanf("%d",&n);
        int a[n+1];
        while(pow(2,r)-r<n+1) r++;
        printf("Redundant bits are %d\n",r);
        int b[n+r+1],d[r],c[n+r+1][r+1];
        printf("Enter senders data\n");
        for(i=1;i<=n;i++)
                scanf("%d",&a[i]);
        for(i=1;i<=n+r;i++){
                if(i==pow(2,t)){
                        t++;
                        d[t]=i;
                        continue;
                }
                b[i]=a[i-t];
        }
        for(i=1;i<=n+r;i++){
                x=i;
                for(j=1;j<=r;j++){
                        c[i][j]=x%2;
                        x/=2;
                }
        }
        for(j=1;j<=r;j++){
        count=0;
        for(i=1;i<=n+r;i++){
                if(c[i][j]==1){
                      if(b[i]==1) count++;
                }
        }
        if(count%2==0) b[d[j]]=0;
        else b[d[j]]=1;
        }
        printf("Code word is:\n");
        for(i=1;i<=n+r;i++)
                printf("%d ",b[i]);
}
void reciever(){
        printf("Enter data set size:\n");
        scanf("%d",&n);
        int b[n];
        while(n>pow(2,r)) r++;
        printf("Redundant bits are %d\n",r);
        int a[n-r];
        printf("Enter Code Word:\n");
        for(i=1;i<=n;i++){
                scanf("%d",&b[i]);
                if(i==pow(2,t)){
                        t++;
                        continue;
                }
                a[i-t]=b[i];
        }
        printf("Recievers data is\n");
        for(i=1;i<=n-r;i++)
                printf("%d ",a[i]);
}                                                               
