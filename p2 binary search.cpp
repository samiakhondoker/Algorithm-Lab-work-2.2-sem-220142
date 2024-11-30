#include <iostream>
using namespace std;
void binary_search(int arr[], int low, int high, int key){
   int mid;
   mid = (low + high) / 2;
   if (low <= high) {
      if (arr[mid] == key)
         cout << "Element found at index: " << mid << endl;
      else if(key < arr[mid])
         binary_search(arr, low, mid-1, key);
      else if (arr[mid] < key)
         binary_search(arr, mid+1, high, key);
   } else if (low > high)
      cout << "Element is not found" <<endl;
}
int main(){
   int i,low, high;
   int n;
   cout<<"enter the array size:"<<endl;
   cin>>n;
   int arr[n];
   cout<<"enter the element in sorted order:"<<endl;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   low = 0;
   high = n-1;
  int key;
  cout<<"enter the target value:"<<endl;
  cin>>key;
   binary_search(arr, low, high, key);
   return 0;
}
