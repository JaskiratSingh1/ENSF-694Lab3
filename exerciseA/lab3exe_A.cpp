// lab3exe_A.cpp
// ENSF 694 Fall - Lab 3 Exercise A

#include <iostream>
using namespace std;

void moon(int& arg1, int* arg2);

void mars(const int& arg1, int*& arg2);

void jupiter(int& x);

int main()
{
    int arr[] = { 1500, 1100, 1600 };
    int& ref = arr[2];
    
    moon(ref, arr);
    ref++;
    cout << endl << arr[0] << "   " << arr[1] << endl;
    int* p = &arr[0];
    
    mars(arr[1] + 300, p);
    cout << endl << arr[0] << "   " << arr[1] << endl;
    
    return 0;
}

void moon(int& arg1, int* arg2)
{
    arg1++;
    (*arg2)++;
    
    // point one
    
    return;
}

void mars(const int& arg1, int*& arg2)
{
    *arg2 = arg1 + 200;
    cout << "arg2 is " << *arg2 << endl;
    
    cout << "\nin mars: "<< arg1 << "   " << *arg2;
    jupiter(*arg2);
    cout << "\nin mars: "<< arg1 << "   " << *arg2;
    return;
}

void jupiter(int& x)
{
    cout << "\nin jupiter: "<< x;
    x += 100;
    cout << "\nin jupiter: "<< x;
    // point two
    
    return;
}



/*

int main()
{
    int arr[] = { 1500, 1100, 1600 };
    int& ref = arr[2];
    
     
    ref++;
    cout << endl << arr[0] << "   " << arr[1] << endl;
    int* p = &arr[0];
    
    mars(arr[1] + 300, p);
    cout << endl << arr[0] << "   " << arr[1] << endl;
    
    return 0;
}

void moon(int& arg1, int* arg2)
{
    cout << arg1 << endl;
    arg1++;
    cout << arg1 << endl;
    
    cout << (*arg2) << endl;
    cout << &arg2 << endl;
    (*arg2)++;
    *arg2 += 1;
    cout << arg2 << endl;
    
    // point one
    
    return;
}

void mars(const int& arg1, int*& arg2)
{
    *arg2 = arg1 + 200;
    cout << "\nin mars: "<< arg1 << "   " << *arg2;
    jupiter(*arg2);
    cout << "\nin mars: "<< arg1 << "   " << *arg2;
    return;
}

void jupiter(int& x)
{
    cout << "\nin jupiter: "<< x;
    x += 100;
    cout << "\nin jupiter: "<< x;
    // point two
    
    return;
}
*/
