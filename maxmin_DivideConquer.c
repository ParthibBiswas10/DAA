#include<stdio.h>
void maxmin(int arr[], int i, int j, int *max,int *min){
    int mid, max1,min1,max2,min2;
    if(i==j){
        *max=*min=arr[i];
        return;
    }
    else if(i==j-1){
        *max=(arr[i]>arr[j])? arr[i] : arr[j];
        *min=(arr[i]<arr[j])? arr[i] : arr[j];
        return;
    }
    else{
        mid=(i+j)/2;
        maxmin(arr,i,mid,&max1,&min1);
        maxmin(arr,mid+1,j,&max2,&min2);

        *max=(max1>max2)?max1:max2;
        *min=(min1<min2)?min1:min2;
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
    int max,min;
    maxmin(arr,i,j,&max,&min);
    printf("Max element: %d\n",max);
     printf("Min element: %d\n",min);
}
