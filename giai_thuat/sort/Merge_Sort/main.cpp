// C++ program for Merge Sort
#include <iostream>

using namespace std;
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int left, int mid, int right)
{
	int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;
    // Create temp arrays
	int *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
    // Copy data to temp arrays leftArray[] and rightArray[]
	for (int i = 0; i < subArrayOne; i++)  leftArray[i] = array[left + i];
	for (int j = 0; j < subArrayTwo; j++)  rightArray[j] = array[mid + 1 + j];
    int indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo  = 0; // Initial index of second sub-array
	int indexOfMergedArray  = left; // Initial index of merged array
    // Merge the temp arrays back into array[left..right] 
	// Hợp nhất các mảng tạm thời trở lại thành mảng
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of left[], if there are any
	// Sao chép các phần tử còn lại của left[], nếu có
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of right[], if there are any
	// Sao chép các phần tử còn lại của right[], nếu có
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}
// begin is for left index and end is right index of the sub-array of arr to be sorted */
void mergeSort(int array[], int begin, int end)
{
	if (begin >= end)
		return; // Returns recursively
    int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}
// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}
// Driver code
int main()
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}

