#include<stdio.h>
int sen[50],sen1[50],rec[50],gp[]={1,1,0,0,0,0,0,0,0,1,1,1,1},cs[20];
int lgp=13,lsen,i,j;
void main(){
 printf("The generator polynomial is:");
 for(i=0;i<lgp;i++)
    printf("%d",gp[i]);
 printf("\nEnter the size of information to be sent:");
 scanf("%d",&lsen);
 printf("Enter the information:");
 for(i=0;i<lsen;i++){
   scanf("%d",&sen[i]);
   sen1[i]=sen[i];
 }
 for(i=lsen;i<lsen+lgp-1;i++)                
    sen1[i]=0;
 printf("The data after adding renundant bits is :\n");
 for(i=0;i<lsen+lgp-1;i++){
    printf("%d",sen1[i]);
 }
	 i=j=0;
	int k=0;
	while(i<lsen){
		for(j=0;j<lgp;j++){
			if(sen1[i]==0){
          sen1[i]=0^gp[j];
          i++;
       }
       else{
         sen1[i]=sen1[i]^gp[j];
         i++;
       }
		}
		if(sen1[k]==0){
			k++;
			i=k;
		}
		else i=k;
	}
 for(i=lsen;i<lsen+lgp-1;i++) sen[i]=sen1[i];
  printf("\nThe data to be sent is:\n");
	 for(i=0;i<lsen+lgp-1;i++){
	    printf("%d",sen[i]);
	 }
	printf("\nEnter the data to be received:\n");
 for(i=0;i<lsen+lgp-1;i++)
    scanf("%d",&rec[i]);
i=0,j=0,k=0;
 while(i<lsen){
    for(j=0;j<lgp;j++){
          if(rec[i]==0){
          rec[i]=0^gp[j];
          i++;
       }
       else{
          rec[i]=rec[i]^gp[j];
          i++;
       }
    }
    if(rec[k]==0){
       k++;
       i=k;
    }
    else
      i=k;
 }
 int flag=0;
 for(i=lsen;i<lsen+lgp-1;i++){
    if(rec[i]==1){
       flag=1;
       break;
    }
 }
 if(flag==0)
   printf("No error\n");
 else
   printf("Error is present!!\n");
}
