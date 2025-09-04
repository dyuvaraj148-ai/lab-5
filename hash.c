#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct node{
    int data;
    struct node* next;
}node;
node* hashtable[SIZE];

int hashfunction(int data){
    return data%SIZE;
}

void insert(int d){
    int n=hashfunction(d);
    node* nw=(node*)malloc(sizeof(node));
    nw->data=d;
    nw->next=hashtable[n];
    hashtable[n]=nw;
    printf("Inserted\n");
}

int  search(int d){
    int index=hashfunction(d);
    node* ptr=hashtable[index];
    for(;ptr!=NULL;ptr=ptr->next){
        if(ptr->data==d)
        return 1;
    }
    return 0;
}

void delete(int d){
    int index=hashfunction(d);
    node* ptr=hashtable[index];
    node* prev=NULL;
    for(;ptr!=NULL;ptr=ptr->next){
        if(ptr->data==d){
            if(prev==NULL)
            hashtable[index]=ptr->next;
            else
            prev->next=ptr->next;
            free(ptr);
            printf("Deleted\n");
            return;
        }
    }
    printf("Not found\n");
}

void display(){
    for(int i=0;i<SIZE;i++){
        node* ptr=hashtable[i];
        for(;ptr!=NULL;ptr=ptr->next)
        printf("%d ",ptr->data);
    }
    printf("\n");
}

int main(){
    
    for(int i=0;i<SIZE;i++)
    hashtable[i]=NULL;
    printf("HASHFUNCTION\n****************\n");
    printf("1.insert\n2.delete\n3.search\n4.display\n5Exit\n");
    int c;
    while(1){
        printf("Enter your choice:");
        scanf("%d",&c);
        if(c==1){
            int data;
            printf("Enter data to insert:");
            scanf("%d",&data);
            insert(data);
        }
        else if(c==3){
            int data;
            printf("Enter data to search:");
            scanf("%d",&data);
            if(search(data))
            printf("present in hashtable\n");
            else
            printf("not present in hashtable\n");
        }
        else if(c==2){
            int data;
            printf("Enter data to delete:");
            scanf("%d",&data);
            delete(data);
        }
        else if(c==4)
        display();
        else if(c==5)
        break;
        else
        printf("enter correct choice\n");
    }
}