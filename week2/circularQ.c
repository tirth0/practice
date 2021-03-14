#include<stdio.h>
#include<stdlib.h>
# define SIZE 10




int cqOverflow(int count){
    return (count == SIZE)?1:0;
}

int cqEmpty(int count){
    return (count == 0)?1:0;
}

void insert_rear(int item, int cq[],int * r,int *f, int * count){
    if (cqOverflow(*count)){
        printf("Queue OVerflow\n");
        return;
    }
    *r = (*r+1)%SIZE;
    cq[*r] = item;
    *count+=1;
}

void delete_front(int cq[],int *f,int *count){
    if (cqEmpty(*count)){
        printf("Circular Queue Underflow\n");
        return;
    }
    printf("The deleted element is %d\n",cq[*f]);
    
    *f = (*f+1)%SIZE;
    
    *count-=1;
}

void display(int cq[],int f,int count){
    int i;
    if (cqEmpty(count)){
        printf("Queue is Empty\n");
        return;
    }
    if (f == -1) f++;
    printf("Contents of Circular Queue are\n");
    for (i=f;count!=0;i =(i+1)%SIZE){
        printf("%d ",cq[i]);
        count--;
    }
    printf("\n");
}

int main(){
    int cqueue[SIZE];
    int front = -1;
    int rear = -1;
    int count = 0;
    while(1){
        printf("\n1.Enter Element\n2.Delete Element\n3.Display Queue\n4.Exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1 : printf("\nEnter Item : \n");
                     int item;
                     scanf("%d",&item);
                     insert_rear(item,cqueue,&rear,&front, &count);
                     break;
            case 2 : delete_front(cqueue,&front,&count);
                     break;
            case 3 : display(cqueue,front,count);
                     break;
            default : break;   
        }
    }
}

