#include<stdio.h>
int main(){
      int n;
    printf("Enter number of objects : ");
    scanf("%d",&n);
    int weight[n], profit[n];
    float ratio[n];
  
    for(int i=0;i<n;i++){
        printf("wight of item %d: ",i+1);
        scanf("%d",&weight[i]);
        printf("profit of item %d: ",i+1);
        scanf("%d",&profit[i]);
    }

    for(int i=0;i<n;i++){
        ratio[i]=profit[i]/weight[i];
    }

    
}