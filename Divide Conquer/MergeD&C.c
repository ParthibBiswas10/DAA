#include<stdio.h>
void merge(int arr[],int start , int mid, int end){
    int i=0,j=0,k=0;
    int sortedArr[end+1];
    int n1=mid-start+1;
    int n2=end-mid;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++) left[i]=arr[start+i];
    for(int i=0;i<n2;i++) right[i]=arr[mid+1+i]; //remember this step(mid+1+i)

    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            sortedArr[k]=left[i];
            i++;
        }
        else{
            sortedArr[k]=right[j];
            j++;
        }
        k++;

    }
    //if(i>n1){
        while(j<n2){
            sortedArr[k]=right[j];
            j++;
            k++;
        }
    //}
    //else if(j>n2){
        while(i<n1){
            sortedArr[k]=left[i];
            i++;
            k++;
        }
    //}
    for(int i=start,m=0;i<=end;i++,m++){
        arr[i]=sortedArr[m];
    }
    
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
    printf("Unsorted Array: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    mergesort(arr,i,j);
    printf("\nSorted Array: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
