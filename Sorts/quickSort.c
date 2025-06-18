#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


int partition(int arr[],int s, int e){
    int pivot=arr[s];
    int i=s;
    int j;
    for(j=s+1;j<=e;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
   swap(&arr[s],&arr[i]);
    return pivot;
}
void quicksort(int arr[], int i, int j){
    if(i<j){
        int m=partition(arr,i,j);
        quicksort(arr,i,m);
        quicksort(arr,m+1,j);
    }
}
int main(){
    int n;
    printf("Enter Array Size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int i=0;
    int j=n-1; //as array range 0 - (n-1)
    printf("Unsorted Array: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    quicksort(arr,i,j);

    printf("\nSorted Array: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}