#include<stdio.h>
void heapsort(int a, int i){
    

}
int main(){
    int n;
    scanf("%d",&n);
    printf("Enter Heap Size: ");
    int a[n];
    printf("\nEnter Numbers: ");
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    printf("Array Before sort: ");
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    heapsort(a,1);
    printf("Array after sort: ");
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    return 0;
}