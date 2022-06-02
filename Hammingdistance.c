/*Author:ARLI A SASI VARDHAN
Created On:02-06-2022 10:13A.M
*/
#include<stdio.h>
void main(){
        int n,i,ans=0;
        printf("Enter data ser size:\n");
        scanf("%d",&n);
        int a[n],b[n];
        printf("Enter senders data\n");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        printf("Enter recievers data\n");
        for(i=0;i<n;i++)
                scanf("%d",&b[i]);
        for(i=0;i<n;i++)
                if(a[i]^b[i]==1) ans++;
        printf("Hamming distance is: %d\n",ans);
}

