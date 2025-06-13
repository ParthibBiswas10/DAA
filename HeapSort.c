#include<stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void maxheapify(int a[], int i, int size){
    int l=2*i;
    int r=(2*i)+1;
    int largest=i;
    if(l<=size && a[l]>a[largest]) {
        largest=l;
        swap(&a[l], &a[largest]);}

    if(r<=size && a[r]>a[largest]) {
        largest= r;
        swap(&a[r], &a[largest]);}

    if(largest!=i){
        swap(&a[i],&a[largest]);
        maxheapify(a,largest,size);
    }


}
void heapsort(int a[], int n){
    //MaxHeap Creation Start :(
    for(int i=n/2; i>=1; i--){    // O(n)
        maxheapify(a,i,n);
    }
     //MaxHeap Creation Ends :)

     for(int i=n;i>=2;i--){    //n times
        swap(&a[i],&a[1]);         
        n--;
        maxheapify(a,1,n);    //O(logn)
     }
}
//total time complexity for heapsort: O(nlogn)//

int main(){
    int n;
    printf("Enter Heap Size: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter Numbers: ");
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    printf("Array Before sort: ");
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    heapsort(a,n);

    printf("Array after sort: ");
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
// at line 33 We stop at 2 because when only one element remains (at index 1), it's already in its correct place.
