#include <iostream>
using namespace std;

int main()
{
        int a[] ={1,2,3,4,5};
        int size = sizeof(a)/sizeof(a[0]);
        cout<<"Original"<<endl;
        for(int i =0; i< size; i++)
                cout<<a[i]<<"-";
        cout<<endl;
        int isize = size;
        for(int i =0; i< isize; i++)
        {
                int ival = a[i];
                a[i]=a[isize-1];
                a[isize-1]= ival;
                isize--;
        }
        cout<<"Reversed"<<endl;
        for(int i =0; i< size; i++)
                cout<<a[i]<<"-";
        cout<<endl;
}
