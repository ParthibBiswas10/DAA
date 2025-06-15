#include<stdio.h>
struct Job {
    char id[10];    
    int deadline; 
    int profit;  
};
int main(){
    int n;
    printf("Enter no of Jobs: ");
    scanf("%d", &n);
    struct Job j[n];
    for(int i=0;i<n;i++){
        printf("Enter Job id: ");
        scanf("%s", &j[i].id);

        printf("Enter Deadline: ");
        scanf("%s", &j[i].deadline);

        printf("Enter Profit : ");
        scanf("%d", &j[i].profit);
    }

    for(int i=0;i<n-1;i++){
        for(int k=0;k<n-1-i;k++){
            if(j[i].profit<j[i+1].profit){
                struct Job temp = j[i];
                j[i] = j[i+1];
                j[i+1] = temp;
            }
        }
    }
    return 0;
}