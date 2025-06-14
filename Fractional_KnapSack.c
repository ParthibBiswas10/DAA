#include<stdio.h>
void knapsack(int n, float w[], float p[], float r[]){
    int cap;
    float tp=0;
    printf("Enter Capacity of KnapSack: ");
    scanf("%d",&cap);
    int u=cap;
    float x[n];
    for(int j=0; j<n; j++) x[j] = 0;
    int i;
   
    for(i=0;i<n;i++){
        if(w[i]<u){
            tp=tp+p[i];
            x[i]=1;
            u=u-w[i];
        }
        else{
            break;
        }

    }
    if(i<n && u>0){
        x[i]=u/w[i];
        tp=tp+(x[i]*p[i]);
        u=0;
    }

    printf("Weight  Profit    ResultVector\n");
    for(int i=0;i<n;i++){
        printf("%.1f      ",w[i]);
        printf("%.1f      ",p[i]);
        printf("%.2f      ",x[i]);
        printf("\n");
    }
    printf("Total Profit: %.2f",tp);
}


int main(){
    int n;
    float temp;
    printf("Enter number of objects : ");
    scanf("%d",&n);
    float weight[n], profit[n];
    float ratio[n];
  
    for(int i=0;i<n;i++){
        printf("wight of item %d: ",i+1);
        scanf("%f",&weight[i]);
        printf("profit of item %d: ",i+1);
        scanf("%f",&profit[i]);
    }

    for(int i=0;i<n;i++){
        ratio[i]=profit[i]/weight[i];
    }

    //Sort items acc to decending order of pw ratio: 

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                temp=ratio[j];
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
    printf("Weight  Profit    Ratio");
     printf("\n");
    for(int i=0;i<n;i++){
        printf("%.1f      ",weight[i]);
        printf("%.1f      ",profit[i]);
        printf("%.2f      ",ratio[i]);
        printf("\n");
    }
    knapsack(n,weight,profit,ratio);
}