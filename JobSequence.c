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
        scanf(" %s", j[i].id);

        printf("Enter Deadline: ");
        scanf("%d", &j[i].deadline);

        printf("Enter Profit : ");
        scanf("%d", &j[i].profit);
    }
    printf("\n\n");
//Sort the jobs based on profit in descending order

    for(int i=0;i<n-1;i++){
        for(int k=0;k<n-1-i;k++){
            if(j[k].profit<j[k+1].profit){
                struct Job temp = j[k];
                j[k] = j[k+1];
                j[k+1] = temp;
            }
        }
    }
    printf("Job id    Deadline    Profit\n");
    for(int i=0;i<n;i++){
        printf("%s   %d   %d\n", j[i].id, j[i].deadline, j[i].profit);
    }
    return 0;
}