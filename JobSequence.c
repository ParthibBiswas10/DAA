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

}