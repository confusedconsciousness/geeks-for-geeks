#include<iostream>
#include<cmath>
using namespace std;
/*
    In this problem we'll be finding the kth largest element in a stream
    I/P: A = {5, 15, 6, 3, 10, 20, ...}
    O/P: {_, _, 5, 5, 6, 10, ...} for k = 3
    // the idea is to maintain a min heap having size of k and replace the root if the coming stream has value greater than the root
 */
// following is the implementation of min heap natively
// ******************************* MIN HEAP *****************************************
int find_left_child(int parent){
    return (2 * parent + 1);
}
int find_right_child(int parent){
    return (2 * parent + 2);
}
int find_parent(int index){
    return floor((index - 1) / 2);
}
void heapify(int* A, int parent, int n){
    // A is the array, n is the size of it
    // this function assumes that the whole array follows the min heap property only this particular index of the
    // parent doesn't follow
    int left = find_left_child(parent);
    int right = find_right_child(parent);
    int smallest;
    if(left < n && A[parent] > A[left]){
        smallest = left;
    }else{
        smallest = parent;
    }
    if(right < n && A[smallest] > A[right]){
        smallest = right;
    }

    if(smallest != parent){
        // if the min heap property is violated
        swap(A[smallest], A[parent]);
    }
}

void build_heap(int *A, int n){
    for(int i = n / 2; i > -1; --i){
        heapify(A, i, n);
    }
}

void delete_element(int* A, int index){
    //*** it is an auxilary function ***
    // it takes the heap and the index of the element to be deleted
    // we replace the value of the element to be - INF and run heapify
    // after that it will moved to the root
    // so first set the element to _INF
    A[index] = -65536;
    int parent = find_parent(index);
    while(parent > -1 && A[parent] > A[index]){
        // violated
        swap(A[parent], A[index]);
        index = parent;
        parent = find_parent(index);
    }
    // now the element to be deleted is present at the top
    // we can simply replace it with the last element and decrement the size of the total size of heap
}


void insert_element(int *A, int element, int n){
    // so we will be given an element that we need to insert into the heap
    // in our scenario we will replace our root with the element based on the condition
    // so we need to heapify down in order to find the location of the current element in the min heap
    A[0] = element;
    int parent = 0;
    int left = find_left_child(parent);
    int right = find_right_child(parent);
    int smallest;
    while(true){
        left = find_left_child(parent);
        right = find_right_child(parent);
        if(left >= n || right >= n){
            break;
        }
        if(left < n && A[parent] > A[left]){
            smallest = left;
        }else{
            smallest = parent;
        }
        if(right < n && A[smallest] > A[right]){
            smallest = right;
        }
        if(smallest != parent){
            // we need to swap it
            swap(A[smallest], A[parent]);
            parent = smallest;
        }else{
            break;
        }
    }
}

void find_k_largest(int *A, int k, int n){
    // A is an unsorted array and k is the parameter i.e. k largest element
    // first step is to build a min heap of k size
    int B[k];
    for(int i = 0; i < k; ++i){
        B[i] = A[i];
    }
    // now build min heap
    build_heap(B, k);
    for(int i = k; i < n; ++i){
        if(B[0] < A[i]){
            // insert A[i]
            insert_element(B, A[i], k);
        }
        cout<<B[0]<<",";
    }

}

int main(){
    int A[] = {10, 5, 15, 20, 8, 32, 24, 90, 1};
    int k = 3;
    for(int i = 0; i < k; ++i){
        cout<<"_,";
    }
    find_k_largest(A, k, sizeof(A) / sizeof(int));
    
}