#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    int i = 0, j = n - 1;
    bool found = false;

    while(i < j)
    {
        if(arr[i] + arr[j] == target)
        {
            cout << "Target found at indices: " << i << " " << j << endl;
            found = true;
            break;
        }
        else if(arr[i] + arr[j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    if(!found)
    {
        cout << "Target not found";
    }

    return 0;
}