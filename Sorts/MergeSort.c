#include<stdio.h>
void merge(int arr[],int start , int mid, int end){
    int n1=mid-start+1;
    int n2=end-mid;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++) left[i]=arr[i];
    for(int i=0;i<n2;i++) right[i]=arr[mid+1+i];

    while()
}
void mergesort(int arr[],int i, int j){
    if(i<j){
        int mid=(i+j)/2;
        mergesort(arr,i,mid);
        mergesort(arr,mid+1,j);
        merge(arr,i,mid,j);
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
    mergesort(arr,i,j);

}