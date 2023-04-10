#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include<bits/stdc++.h>
using namespace std;
class testbed{
private :

    int *arr;
public:

    testbed(){

    }
    int  generate_random(int min,int max,int len){

        for (int i = 0; i < len; i++) {
            int no = rand() % (max+1-min) + min;
            arr[i]=no;
        }
        return *arr ;
    }
    int  generate_reverse(int min,int max,int len){
        int re_arr[len];
int j=0;
        for (int i = len-1; i>=0; i--) {
            re_arr[j]=arr[i];
            j++;
        }
        return *re_arr;
    }
};


class sorter{
 private:
   int *arr;
  int len;
public:
    sorter(){

    }
    void set_arr(int *Arr){
        arr=Arr;
    }
    void set_len(int l){
        len=l;
    }
    virtual void sort(int arr[],int len){
//        int i,j,tmp;
//    for ( i = 1 ; i < len; i++){
//        tmp = arr [i];
//
//        for (j = i; j > 0 && tmp < arr [j-1]; j--)
//            arr [j] = arr [j - 1];
//        arr[j] = tmp;
//    }
    }
};



class selectionSorter  : public sorter{
public:
    virtual void sort(int arr[], int len){
        int j,min,i;
        for ( i = 0; i < len-1; i++) {

            for (j = i+1, min = i; j < len; j++)
                if (arr [j] < arr [min])
                    min = j;

            swap (arr [min], arr [i]);
        }
    }
};




class quickSorter  : public sorter{
public:
    int partition(int array[], int low, int high) {
        int pivot = array[high];

        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;

                swap(array[i], array[j]);
            }
        }

        swap(array[i + 1], array[high]);

        return (i + 1);
    }

     void quicksort(int array[], int low, int high) {
        if (low < high) {
            int pi = partition(array, low, high);

            quicksort(array, low, pi - 1);

            quicksort(array, pi + 1, high);
        }
    }
    virtual void sort (int arr[],int len){
        quicksort(arr,0,len-1);
    }
};


    int main() {
       /* int arr[10];
          for(int i=0;i<10;i++)
          cin>>arr[i];
          int n;
        //  cin>>n;
        // cout<< BinarySearch(arr,1,10,n);
        quickSort(arr,0,9);
         for(int i=0;i<10;i++)
           cout<<arr[i]<<" ";*/
//sorter* s=new selectionSorter();
testbed t;
for(int i=0;i<5;i++)
cout<<t. generate_random(10,15,5)<<" ";
        for(int i=0;i<5;i++)
cout<<t.generate_reverse(10,15,5)<<" ";
        return 0;
    }