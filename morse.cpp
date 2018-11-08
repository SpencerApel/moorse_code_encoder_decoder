#include "morse.h"

Morse::Morse(const char *file_path)
{
    
}

Morse::~Morse()
{

}
    
void Morse::build_tree(const char *file_path)
{
        
}
    
std::string Morse::encode()
{

}
    
std::string Morse::decode()
{

}

void Morse::merge(std::string arr[], int left, int middle, int right)
{
    int i, j, k; 
    int left_subarray_size = middle - left + 1; //size of left subarray
    int right_subarray_size =  right - middle; //size of right subarray
  
    //Create temp arrays
    std::string Left_subarray[left_subarray_size], Right_subarray[right_subarray_size]; 
  
    //Copy data to temp arrays
    for (i = 0; i < left_subarray_size; i++) 
        Left_subarray[i] = arr[left + i]; 
    for (j = 0; j < right_subarray_size; j++) 
        Right_subarray[j] = arr[middle + 1+ j]; 
  
    //Merge the temp arrays back into arr[l..r]
    i = 0; //Initial index of first subarray 
    j = 0; //Initial index of second subarray 
    k = left; //Initial index of merged subarray 
    while (i < left_subarray_size && j < right_subarray_size) //bounds checking
    { 
        if (Left_subarray[i].length() <= Right_subarray[j].length()) //if left[index] is less than right
        { 
            arr[k] = Left_subarray[i]; //put left[index] into array
            i++; 
        } 
        else
        { 
            arr[k] = Right_subarray[j]; //put right[index] into array
            j++; 
        } 
        k++; //increment index in new sorted array
    } 
  
    //Copy the remaining elements of L[], if there are any
    while (i < left_subarray_size) 
    { 
        arr[k] = Left_subarray[i]; 
        i++; 
        k++; 
    } 
  
    //Copy the remaining elements of R[], if there are any
    while (j < right_subarray_size) 
    { 
        arr[k] = Right_subarray[j]; 
        j++; 
        k++; 
    } 
}

void Morse::merge_sort(std::string arr[], int left, int right)
{
    if (left < right) 
    {
        int m = left + (right - left) / 2; //finding mid point 
  
        // Sort first and second halves 
        merge_sort(arr, left, m); 
        merge_sort(arr, m + 1, right); 
  
        merge(arr, left, m, right); 
    } 
}
