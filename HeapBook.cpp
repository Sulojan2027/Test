#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int> arr,int i) {
    int size = arr.size();
    int left = 2*i;
    int right = 2*i+1;
    int largest;
    if (left <= size && arr[left] > arr[i]) {
        largest = left;
    }
    else {
        largest = i;
    }
    if (right <= size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest);
    }
}

void minHeapify(vector<int> arr,int i) {
    int size = arr.size();
    int left = 2*i;
    int right = 2*i+1;
    int smallest;
    if (left <= size && arr[left] < arr[i]) {
        smallest = left;
    }
    else {
        smallest = i;
    }
    if (right <= size && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, smallest);
    }
}

void buildMaxHeap(vector<int> arr) {
    int size = arr.size();
    for (int i = size/2; i >= 1; i--) {
        maxHeapify(arr, i);
    }
}

void buildMinHeap(vector<int> arr) {
    int size = arr.size();
    for (int i = size/2; i >= 1; i--) {
        minHeapify(arr, i);
    }
}

void heapSort(vector<int>& arr) {
    buildMaxHeap(arr);
    int size = arr.size();
    for (int i = size; i >= 2; i--) {
        swap(arr[0], arr[i-1]);
        size--;
        maxHeapify(arr, size);
    }
}
