//Quick sort      
#include<stdio.h>
void QuickSort(int *arr, int start, int end){
    if(start<end){
        int pivat = partition(arr,start,end);
        QuickSort(arr,start,pivat-1);
        QuickSort(arr,pivat+1,end);
    }
}
int main(){
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array Elements: ");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    QuickSort(arr,0,n-1);
    printf("After sorting array elements are: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
