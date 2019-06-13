#include <iostream>
#include <cmath>

using namespace std;

/*
Remove Duplicates from Sorted Array：

    Given a sorted array, remove the duplicates in place such that each element appear only once
and return the new length.
    Do not allocate extra space for another array, you must do this in place with constant memory.
    For example, Given input array A = [1,1,2] ,
    Your function should return length = 2, and A is now [1,2] .
*/

class Solution{
    public:
        int removeDuplicates(int arr[], int n){
            if(n == 0)    return 1;
            int j = 0;
            for(int i = 1; i < n; i++)
            {
                // 1 1 1 2 3 3 
                if(arr[i] - arr[j] > 1e-9)
                {
                    arr[++j] = arr[i];                             
                }
            }
            return ++j;
        }
};

int main()
{
    Solution a;
    int arr[] = {1, 1, 3};
    int ret = a.removeDuplicates(arr, 3);
    cout << "length = " << ret <<endl;
    cout<<"A now is ["<< arr[0] <<", "<< arr[1]<< "]" <<endl;

    return 0;
}