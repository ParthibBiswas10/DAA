#include<stdio.h>
struct Job {
    char id[10];    
    int deadline; 
    int profit;  
};
void js(int n, struct Job j[]);

int findMin(int x, int y){
    if(x<y) return x;
    else return y;
}
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

//Sort the jobs based on profit in descending order(Used Bubble Sort here)
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
    js(n, j);
    return 0;
}
void js(int n, struct Job j[]){
    int dmax=0,k;
    for(int i=0;i<n;i++){
        if(j[i].deadline>dmax){
            dmax=j[i].deadline;
        }
    }
    printf("Max Deadline : %d",dmax);
    int TimeSlot[dmax];
    for(int i = 0; i < dmax; i++) {
        TimeSlot[i] = -1;
    }
    for(int i=0;i<n;i++) //This loop denotes the job number
    {
        k=j[i].deadline;
        while(k>=1){
            if(TimeSlot[k]==-1){
                TimeSlot[k]=i;  //this line denotes : the timeslot in which i th job  will be stored
                break;
            }
            k--;
        }
    }
    for(int i=0; i<n; i++){
        printf("%s",j[TimeSlot[i]].id); 
        if(i<n) printf("->");
    }

}