#include <iostream>
#include <vector>

std::vector<int> mergeTwoSortedArrays(std::vector<int> &a, std::vector<int> &b) {
    /**
     * Time: O(m+n)
     * Space: O(m+n) if we consider output array space otherwise constant
    */
    int n = a.size();
    int m = b.size();
    std::vector<int> c (n + m);
    int i = 0, j = 0, k = 0;
    while(i < n and j < m) {
        if(a[i] <= b[j]) {
            c[k] = a[i];
            i++;
            k++;
        } else {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    // if array b has been exhausted -> j == m but i < n
    while(i < n) {
        c[k] = a[i];
        i++;
        k++;
    }
    // or if array a has been exhausted -> i == n but j < m
    while(j < m) {
        c[k] = b[j];
        j++;
        k++;
    }
    return c;
}

std::vector<int> f(std::vector<int> &arr, int i, int j) { // this returns a sorted array
    if(i == j) {
        // single length array
        return std::vector<int> {arr[i]};
    }
    int mid = (i + j) / 2;
    std::vector<int> left = f(arr, i, mid);
    std::vector<int> right = f(arr, mid+1, j);
    std::vector<int> result = mergeTwoSortedArrays(left, right);
    return result;
}

void merge_sort(std::vector<int> &arr) {
    arr = f(arr, 0, arr.size() - 1);
}

int main() {
    std::vector<int> arr {6,5,4,3,2,1, 10};
    merge_sort(arr);
    for(int i = 0; i < arr.size(); i++) {
        std::cout<<arr[i]<<" ";
    }
    return 0;
}