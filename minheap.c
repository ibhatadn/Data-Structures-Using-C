#include<stdio.h>
#include<stdlib.h>

struct heap{
    int *arr;
    int size;
    int capacity;
};

struct heap *createHeap(int , int*);
int extractMin(struct heap*);
void heapify(struct heap*, int);
// void insertElement(struct heap*, int);
// void insertHelper(struct heap*, int);

int main(){
    int input_Arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i, capacity = sizeof(input_Arr)/sizeof(input_Arr[0]);

    struct heap *heap = createHeap(capacity, input_Arr);
    
    for(i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");


    extractMin(heap);

    for(i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");

    return 0;
}


struct heap* createHeap(int capacity, int* input_Arr){
    int i;
    struct heap *h;
    h = (struct heap *)malloc(sizeof(struct heap));
    if(h == NULL){
        printf("\n Memory Error \n");
        return NULL;
    }
    h->size = 0;
    h->capacity = capacity;
    h->arr = (int *)malloc(capacity * sizeof(int));
    if(h->arr == NULL){
        printf("\n Memory Error \n");
        return NULL;
    }

    for(i = 0; i < h->capacity; i++){
        h->arr[i] = input_Arr[i];
    }
    h->size = i;
    i = (h->size - 2) / 2;
    while(i>=0){
        heapify(h,i);
        i--;
    }
    return h;
}

void heapify(struct heap* h,int index){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int temp, min = index;
    
    if(left >= h->capacity || left < 0)
        left = -1 ;
    
    if(right >= h->capacity || right < 0)
        right = -1;
    
    if(left != -1 && h->arr[left] < h->arr[min])
        min = left;
    
    if(right != -1 && h->arr[right] < h->arr[min])
        min = right;
    
    if(min != index){
        temp = h->arr[min];
        h->arr[min] = h->arr[index];
        h->arr[index] = temp;
        heapify(h,min);
    }
}

int extractMin(struct heap *h){
    int minimumElement;
    if(h->size == 0){
        printf("\n Heap is empty \n");
        return 999;
    }
    minimumElement = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapify(h,0);
    return minimumElement;
} 