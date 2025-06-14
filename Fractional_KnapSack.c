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
    //Sort items acc to decending order of pw ratio: 

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                int temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;
            }
        }
    }
    printf("Weight  Profit  Ratio");
     printf("\n");
    for(int i=0;i<n;i++){
        printf("%d  ",weight[i]);
        printf("%d  ",profit[i]);
        printf("%d  ",ratio[i]);
        printf("\n");
    }

}