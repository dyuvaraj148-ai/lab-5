#include<stdio.h>

typedef struct com{
    int max;
    int min;
}com;

com maxmin(int arr[], int s,int e){
    com res;
    if(s==e){
        res.min=arr[s];
        res.max=arr[s];
        return res;
    }
    int mid=(s+e)/2;
    com r1=maxmin(arr,s,mid);
    com r2=maxmin(arr,mid+1,e);
    res.max=r1.max>r2.max?r1.max:r2.max;
    res.min=r1.min<r2.min?r1.min:r2.min;
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    com res=maxmin(arr,0,n-1);
    printf("Maximum:%d\nMinmum:%d",res.max,res.min);
}