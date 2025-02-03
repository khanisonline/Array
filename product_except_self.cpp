#include <bits/stdc++.h>
using namespace std;
// Function to find Product of Array Except Itself
void findproduct(int arr[], int product[],int n)
{
    int prefix[n];
    prefix[0]=1; // since first element can have no prefix
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]*arr[i-1];
    }
    int suffixproduct=1;
    // Building Product array and maintaining suffix product
    for(int i=n-1;i>=0;i--)
    {
        product[i]=suffixproduct*prefix[i];
        suffixproduct*=arr[i];
    }
}
// Driver Code
int main()
{
    int arr[] = { 1 , 4 , 6 , 2 , 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int product[n];
    findproduct(arr,product,n);
 
    cout << "The product of array Except itself is: ";
    for(int i=0;i<n;i++)
    {
        cout<<product[i]<<", "; 
    }
    cout<<endl;
 
    return 0;
}