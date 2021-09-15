#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//utility function
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap{
    int *harr;//Heap Array
    int capacity;
    int heap_size;
    public :
    MinHeap(int capacity){
        this->heap_size = 0;
        this->capacity = capacity;
        this->harr = new int[capacity];
    }
    //Get Indices in Array Representation
    int parent(int i) {return (i-1)/2;}
    int left(int i) {return (2*i+1);}
    int right(int i) {return (2*i+2);}

    int getMin(){return harr[0];}

    void insertKey(int k){
        if (heap_size == capacity){
            cout << "Overflow : key cannot be inserted\n";
            return;
        }
        //Inserting new key at end
        int i = heap_size++;
        harr[i] = k;
        //Fix Min Heap Property
        while (i!=0 && harr[parent(i)] > harr[i]){
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }
    void decreaseKey(int i,int new_val){
        //assuming new_val<harr[i]
        harr[i] = new_val;
        while (i!=0 && harr[parent(i)]>harr[i]){
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i){
        decreaseKey(i,INT_MIN);
        extractMin();
    }

    void MinHeapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i){
            swap(&harr[i],&harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int extractMin(){
        if (heap_size <=0)
            return INT_MAX;
        if (heap_size == 1){
            heap_size--;
            return harr[0];
        }
        //Store the minimum value
        int root = harr[0];
        harr[0] = harr[--heap_size];
        MinHeapify(0);
        return root;
    }

};