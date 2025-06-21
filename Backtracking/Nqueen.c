#include<stdio.h>
#include<stdlib.h>
int x[10];
int safe(int k, int i){
    for(int j=1;j<k;j++){
        if(x[j]==i || abs(x[j]-i)==abs(j-k)) return 0;
    }
    return 1;
}
void nqueen(int k,int n){
    for(int i=1;i<=n;i++){
        if(safe(k,i)){
            x[k]=i;
            if(k==n){
                for(int i=1;i<=n;i++){
                    printf("%d",x[i]);
                }
                printf("\n");
            }
            else nqueen(k+1,n);
        }
    }
}
int main(){
    int n;
    printf("Enter Number of Queens: ");
    scanf("%d",&n);
    nqueen(1,n);

}

/*
Time Complexity: 
    Brute Force	- O(N^N)
    Backtracking- O(N!)
*/