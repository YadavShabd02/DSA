#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printArray(const vector<int>& A) {
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;
}

int maximum(const vector<int>& A) {
    int max = INT_MIN;
    for (int num : A) {
        if (max < num) {
            max = num;
        }
    }
    return max;
}

void countSort(vector<int>& A) {
    int n = A.size();
    if(n == 0) return;
    
    // Find the maximum element in A
    int max = maximum(A);
    
    // Create the count array and initialize with zeros
    vector<int> count(max + 1, 0);
    
    // Increment the corresponding index in the count array
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }
    
    // Overwrite the original array with sorted elements
    int j = 0; // counter for vector A
    for (int i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            A[j] = i;
            count[i]--;
            j++;
        }
    }
}

int main() {
    vector<int> A = {9, 1, 4, 14, 4, 15, 6};
    
    cout << "Original array: ";
    printArray(A);
    
    countSort(A);
    
    cout << "Sorted array: ";
    printArray(A);
    
    return 0;
}
