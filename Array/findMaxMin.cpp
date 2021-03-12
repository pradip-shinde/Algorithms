 #include <iostream>
 #include <chrono>
 using namespace std::chrono;
 using namespace std;

 int main()
 {
         int a[] = {89,45,12,45,56,76,10,6,4,12,12,12};
         auto start = high_resolution_clock::now();
         int size = sizeof(a)/sizeof(a[0]);
         int min =a[0];
         int max =a[1];
         int isize =size;
         if(min > max)
         {
                 max = min;
                 min = a[1];
         }
         for(int i=2; i< isize; i++)
         {
                 if(min > a[i])
                         min =a[i];
                 else if(max < a[i])
                         max = a[i];
                 isize--;
         }
         auto stop = high_resolution_clock::now();
         cout<< endl;
         cout <<"Min:"<< min <<" Max:"<< max <<" Duration:"<< (stop-start).count()<< " ms"<<endl;

         return 0;
 }

