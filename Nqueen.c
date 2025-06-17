#include<stdio.h>
void nqueen(int k,int n){
    for(int i=1;i<=n;i++){
        if(safe(k,i)){
            s[k]=i;
            if(k==n){
                printf x;
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