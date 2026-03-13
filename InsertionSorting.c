#include<stdio.h>
void InsertionSorting(int a[],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        temp=a[i];
        j=i-1;
        while(temp<a[j] && j>=0){
        a[j+1]=a[j];
        j--;
        }
        a[j+1]=temp;
    }
    
}
int main(){
        int a[100],n;
        printf("Enter the number of items to enter: ");
        scanf("%d",&n);
        printf("Enter the %d items:\t",n);
        for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
        }
        printf("\nItems before sorting:\n");
        for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
        }
        InsertionSorting(a,n);
        printf("\nItems after sorting:\n");
        for(int i=0;i<n;i++){
            printf("%d\t",a[i]);
        }
        return 0;
    }