#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
// average O(n), with a worst case of O(n2)
int kthSmallest(vector<int> &arr, int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) {
        int index = partition(arr, l, r);
        if (index - l == k - 1)
            return arr[index];
        if (index - l > k - 1)
            return kthSmallest(arr, l, index - 1, k);
        return kthSmallest(arr, index + 1, r,
                            k - index + l - 1);
    }
    return INT_MAX;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
void printArray(vector<int> arr)
{
    int i;
    for (i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
int main()
{
    vector<int> arr = { 10, 4, 5, 8, 6, 11, 26 };
    int n = arr.size();
    int k = 3;
    cout << "K-th smallest element is "
        << kthSmallest(arr, 0, n - 1, k);


    vector<int> b = {10, 7, 8, 9, 1, 5};
    n = b.size();
    quickSort(b, 0, n - 1);
    cout << "\nSorted array: \n";
    printArray(b);
    return 0;
}