#include <stdio.h>

int arr[1000];
int n;
int temp[1000];

void combine(int s,int mid,int e){
    int i=s;
    int j=mid+1;
    int k=s;
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
        
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    for(int i=s;i<=e;i++){
        arr[i]=temp[i];
    }
}
void divide(int s,int e){
    if(s<e)
    {
        int mid=(s+e)/2;
        divide(s,mid);
        divide(mid+1,e);
        combine(s,mid,e);
    }    
}
void main(){
    int n;
    printf("enter the number of elements \n");
    scanf("%d",&n);
    printf("enter the elements now\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("after sorting\n");
    divide(0,n-1);
     for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
