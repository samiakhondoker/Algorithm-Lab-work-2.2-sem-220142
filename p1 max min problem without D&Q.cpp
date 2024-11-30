#include <iostream>
using namespace std;

int main()
{

    int n;
    cout<<"enter the array size"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the array element :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max=arr[0];
    int min=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    cout<<"maximum value is :"<<max<<endl;
    cout<<"minimum value is :"<<min<<endl;

}
