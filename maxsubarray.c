#include<stdio.h>
#include<limits.h>
typedef struct result{
    int low,high,sum;
}result;

result maximum(int arr[], int s1,int e1,int s2,int e2){

    int min=e1;
    int minsum=INT_MIN;
    int sum=0;
    for(int i=e1;i>=s1;i--){
        sum+=arr[i];
        if(sum>minsum){
            minsum=sum;
            min=i;
        }
    }

    int max=s2;
    int maxsum=INT_MIN;
    sum=0;
    for(int i=s2;i<=e2;i++){
        sum+=arr[i];
        if(sum>maxsum){
            maxsum=sum;
            max=i;
        }
    }
    
    result res;
    res.low=min;
    res.high=max;
    res.sum=minsum+maxsum;
    return res;

}

result maxsub(int arr[],int s,int e){
    
    if(s==e){
        result res;
        res.low=s;
        res.high=s;
        res.sum=arr[s];
        return res;
    }

    int mid=(s+e)/2;
    result leftres=maxsub(arr,s,mid);
    result rightres=maxsub(arr,mid+1,e);
    result crossres=maximum(arr,s,mid,mid+1,e);
    
    if(leftres.sum>rightres.sum)
    return leftres.sum>crossres.sum?leftres:crossres;
    else
    return rightres.sum>crossres.sum?rightres:crossres;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    result r=maxsub(arr,0,n-1);
    printf("Start index:%d\nEnd index:%d\nSum:%d",r.low,r.high,r.sum);
}