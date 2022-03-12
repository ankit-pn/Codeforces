#include <bits/stdc++.h>
using namespace std;
bool modifed_bst_1(int arr[], int l, int r, int key)
{
    if (l <= r)
    {
        int pos = l + (r-l) / 3;
        if (arr[pos] == key)
            return true;
        else
        {
            if (key < arr[pos])
                return modifed_bst_1(arr, l, pos - 1, key);
            else
                return modifed_bst_1(arr, pos + 1, r, key);
        }
    }
    else
    return false;
}
int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cout << "Enter the key you want to search\n";
    int key;
    cin >> key;
    bool res = modifed_bst_1(arr, 0, n-1, key);
    if (res)
        cout << "Key Found\n";
    else
        cout << "Key Not Found\n";
    return 0;
}