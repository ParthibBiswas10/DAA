#include<stdio.h>
void maxheapify(int a[], int i, int size){
    int l=2*i;
    int r=(2*i)+1;
    int largest=i;
    if(l<=size && a[l]>a[largest]) swap(a[l], a[largest]);
    if(r<=size && a[r]>a[largest]) swap(a[r], a[largest]);

    if(largest!=i){
        swap(a[i],a[largest]);
        maxheapify(a,largest,size);
    }


}
void heapsort(int a, int n){
    //MaxHeap Creation Start :(
    for(int i=n/2; i>=1; i--){
        maxheapify(a,i,n);
    }
     //MaxHeap Creation Ends :)
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
    heapsort(a,n);
    printf("Array after sort: ");
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    return 0;
}