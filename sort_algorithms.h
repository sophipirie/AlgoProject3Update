#ifndef SORTING_ALGORITHMS
#define SORTING_ALGORITHMS

#include <vector>
const int MAX_SIZE = 50;
static const int MIN_SIZE  = 4; // Smallest size of an array that quicksort will sort

using namespace std;
//typedef string ItemType;
//************* Brute Force Sort Algorithms ***********
// sort an array of type T using buble sort
template<class T>
void bubbleSort(T theArray[], int n);


// sort an integer array using selection sort
void selectionSort(int arr[], int n);

// sort an array of type T using selection sort
template <typename T>
void selectionSort(T arr[], int n);

// sort a vector of type T using selection sort
template <typename T>
void selectionSort(vector<T>& v);


// sort an array of type T using insertion sort
template <typename T>
void insertionSort(T arr[], int n);

// sort a vector of type T using insertion sort
template <typename T>
void insertionSort(vector<T>& v);

// sort the elements of a vector of type T in the range
// [first, last) using insertion sort
template <typename T>
void insertionSort(vector<T>& v, int first, int last);

//*********** Divide-and-Concur Sort Algorithms ************

// merges the ordered sequences into sone in the range [first,last)
template<class T>
void merge(T theArray[], int first, int mid, int last);

// sorts v in the index range [first,last) by merging
// ordered sublists
template<class T>
void mergeSort(T theArray[], int first, int last);

// Locates and return the index of the pivot element
template<class T>
int partition(T theArray[], int first, int last);

// sort a vector using quicksort
template<class T>
void quickSort(T theArray[], int first, int last);

// Locates and return the index of the pivot element
template<class T>
int partition(vector<T>& theArray, int first, int last);

// sort a vector using quicksort
template<class T>
void quickSort(vector<T>& theArray, int first, int last);

//*********** Heap Sort Algorithms ************


// Converts a semiheap rooted at index root into a heap on an array.
template <class ItemType>
void heapRebuild(const int subTreeNodeIndex, ItemType items[], int itemCount);

// Sorts the items in an array using heapSort.
template <class ItemType>
void heapSort(ItemType anArray[], int n);


// Converts a semiheap rooted at index root into a heap on a vector.
template <class ItemType>
void heapRebuild(const int subTreeNodeIndex, vector<ItemType>& items, int itemCount);

// Sorts the items in a vector using heapSort.
template <class ItemType>
void heapSort(vector<ItemType>& vectorItems);

//************************************************************
// 					IMPLEMENTATIONS
//************************************************************
//************* Brute Force Sort Algorithms ***********

/** Sorts the items in an array into ascending order 
	using Bubble Sort Algorithm.
 @pre  None.
 @post  theArray is sorted into ascending order; n is unchanged.
 @param theArray  The given array.
 @param n  The size of theArray. */
template<class T>
void bubbleSort(T theArray[], int n)
{
   //cout << "Sorting using template bubble sort..." << endl;
   bool sorted = false; // False when swaps occur
   int pass = 1;
   while (!sorted && (pass < n))
   {
      // At this point, theArray[n+1-pass..n-1] is sorted
      // and all of its entries are > the entries in theArray[0..n-pass]
      sorted = true; // Assume sorted
      for (int index = 0; index < n - pass; index++)
      {
         // At this point, all entries in theArray[0..index-1]
         // are <= theArray[index]
         int nextIndex = index + 1;
         if (theArray[index] > theArray[nextIndex])
         {
            // Exchange entries
            std::swap(theArray[index], theArray[nextIndex]);
            sorted = false; // Signal exchange
         } // end if
      }  // end for
      // Assertion: theArray[0..n-pass-1] < theArray[n-pass]
      
      pass++;
   }  // end while
}  // end bubbleSort

/** Sorts the items in an int array into ascending order 
	using Selection Sort Algorithm.
 @pre  None.
 @post  arr is sorted into ascending order; n is unchanged.
 @param arr  The given array.
 @param n  The size of arr. */
void selectionSort(int arr[], int n)
{
	//cout << "Sorting using int array selectionSort..." << endl;
	int smallIndex; // index of smallest element in the sublist
	int pass, j;
	int temp;
	// pass has the range 0 to n-2
	for (pass = 0; pass < n-1; pass++)
	{
		// scan the sublist starting at index pass
		smallIndex = pass;
		// j traverses the sublist arr[pass+1] to arr[n-1]
		for (j = pass+1; j < n; j++)
				 // update if smaller element found
			if (arr[j] < arr[smallIndex])
				smallIndex = j;
		// if smallIndex and pass are not the same location,
		// exchange the smallest item in the sublist with arr[pass]
		if (smallIndex != pass)
		{
			temp = arr[pass];
			arr[pass] = arr[smallIndex];
			arr[smallIndex] = temp;
		}
	}
}

/** Sorts the items in an array of any data type  
	into ascending order using Selection Sort Algorithm .
 @pre  None.
 @post  arr is sorted into ascending order; n is unchanged.
 @param arr  The given array.
 @param n  The size of arr. */
template <typename T>
void selectionSort(T arr[], int n)
{
	//cout << "Sorting using template array selectionSort..." << endl;
	int smallIndex; // index of smallest element in the sublist
	int pass, j;
	T temp;
	// pass has the range 0 to n-2
	for (pass = 0; pass < n-1; pass++)
	{
		// scan the sublist starting at index pass
		smallIndex = pass;
		// j traverses the sublist arr[pass+1] to arr[n-1]
		for (j = pass+1; j < n; j++)
				 // update if smaller element found
			if (arr[j] < arr[smallIndex])
				smallIndex = j;
		// if smallIndex and pass are not the same location,
		// exchange the smallest item in the sublist with arr[pass]
		if (smallIndex != pass)
		{
			temp = arr[pass];
			arr[pass] = arr[smallIndex];
			arr[smallIndex] = temp;
		}
	}
}

/** Sorts the items in vector template of any data type  
	into ascending order using Selection Sort Algorithm .
 @pre  None.
 @post  v is sorted into ascending order.
 @param v  The given vector. */
template <typename T>
void selectionSort(vector<T>& v)
{
	//cout << "Sorting using vector template selectionSort..." << endl;
	// index of smallest item in each pass
	int smallIndex;
	// save the vector size in n
	int pass, j, n = v.size();
	T temp;
	// sort v[0]..v[n-2], and arr[n-1] is in place
	for (pass = 0; pass < n-1; pass++)
	{
		// start the scan at index pass; set smallIndex to pass
		smallIndex = pass;
		// j scans the sublist v[pass+1]..v[n-1]
		for (j = pass+1; j < n; j++)
			 // update smallIndex if smaller element is found
			if (v[j] < v[smallIndex])
				smallIndex = j;
			// when finished, place smallest item in arr[pass]
			if (smallIndex != pass)
		{
			temp = v[pass];
			v[pass] = v[smallIndex];
			v[smallIndex] = temp;
		}
   }
}

/** Sorts an array of type T 
	into ascending order using Insertion Sort Algorithm .
 @pre  None.
 @post  arr is sorted into ascending order; n is unchanged.
 @param arr  The given array.
 @param n  The size of arr. */
// sort an array of type T using insertion sort
template <typename T>
void insertionSort(T arr[], int n)
{
	//cout << "Sorting using array template insertionSort..." << endl;
	int i, j;
	T target;
	// place arr[i] into the sublist
	//   arr[0] ... arr[i-1], 1 <= i < n,
	// so it is in the correct position
	for (i = 1; i < n; i++)
	{
		// index j scans down list from arr[i] looking for
		// correct position to locate target. assigns it to
		// arr[j]
		j = i;
		target = arr[i];
		// locate insertion point by scanning downward as long
		// as target < arr[j-1] and we have not encountered the
		// beginning of the list
		while (j > 0 && target < arr[j-1])
		{
			// shift elements up list to make room for insertion
			arr[j] = arr[j-1];
			j--;
		}
		// the location is found; insert target
		arr[j] = target;
	}
}

/** Sorts the items in vector template of any data type  
	into ascending order using Insertion Sort Algorithm .
 @pre  None.
 @post  v is sorted into ascending order.
 @param v  The given vector. */
template <typename T>
void insertionSort(vector<T>& v)
{
	//cout << "Sorting using vector template insertionSort..." << endl;
	int i, j, n = v.size();
	T target;
	// place v[i] into the sublist
	//   v[0] ... v[i-1], 1 <= i < n,
	// so it is in the correct position
	for (i = 1; i < n; i++)
	{
		// index j scans down list from v[i] looking for
		// correct position to locate target. assigns it to
		// v[j]
		j = i;
		target = v[i];
		// locate insertion point by scanning downward as long
		// as target < v[j-1] and we have not encountered the
		// beginning of the list
		while (j > 0 && target < v[j-1])
		{
			// shift elements up list to make room for insertion
			v[j] = v[j-1];
			j--;
		}
		// the location is found; insert target
		v[j] = target;
	}
}

/** Sorts the items in vector template of any data type  
	into ascending order using Insertion Sort Algorithm .
 @pre  None.
 @post  v is sorted into ascending order.
 @param v  The given vector. 
 @param first  The index of first element.
 @param last  The index of last element. */
template <typename T>
void insertionSort(vector<T>& v, int first, int last)
{
	//cout << "Sorting using vector template insertionSort [0.. n-1]..." << endl;
	int i, j, n = last+1;
	T target;
	// place v[i] into the sublist
	//   v[first] ... v[i-1], first <= i < last,
	// so it is in the correct position
	for (i = first+1; i < n; i++)
	{
		// index j scans down list from v[i] looking for
		// correct position to locate target. assigns it to
		// v[j]
		j = i;
		target = v[i];
		// locate insertion point by scanning downward as long
		// as target < v[j-1] and we have not encountered the
		// beginning of the range
		while (j > first && target < v[j-1])
		{
			// shift elements up list to make room for insertion
			v[j] = v[j-1];
			j--;
		}
		// the location is found; insert target
		v[j] = target;
	}
}
//**********************************************************************
//			DIVIDE-AND-CONCUR SORT ALGORITHMS
//**********************************************************************

/** Merges two sorted array segments theArray[first..mid] and
    theArray[mid+1..last] into one sorted array.
 @pre  first <= mid <= last. The subarrays theArray[first..mid] and
    theArray[mid+1..last] are each sorted in increasing order.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the beginning of the first segment in theArray.
 @param mid  The index of the end of the first segment in theArray;
    mid + 1 marks the beginning of the second segment.
 @param last  The index of the last element in the second segment in theArray.
 @note  This function merges the two subarrays into a temporary
    array and copies the result into the original array theArray. */
template<class T>
void merge(T theArray[], int first, int mid, int last)
{
   T tempArray[MAX_SIZE];  // Temporary array
   
   // Initialize the local indices to indicate the subarrays
   int first1 = first;            // Beginning of first subarray
   int last1 = mid;               // End of first subarray
   int first2 = mid + 1;          // Beginning of second subarray
   int last2 = last;              // End of second subarray
   
   // While both subarrays are not empty, copy the
   // smaller item into the temporary array
   int index = first1;            // Next available location in tempArray
   while ((first1 <= last1) && (first2 <= last2))
   {
      // At this point, tempArray[first..index-1] is in order
      if (theArray[first1] <= theArray[first2])
      {
         tempArray[index] = theArray[first1];
         first1++;
      }
      else
      {
         tempArray[index] = theArray[first2];
         first2++;
      }  // end if
      index++;
   }  // end while
   
   // Finish off the first subarray, if necessary
   while (first1 <= last1)
   {
      // At this point, tempArray[first..index-1] is in order
      tempArray[index] = theArray[first1];
      first1++;
      index++;
   }  // end while
   
   // Finish off the second subarray, if necessary
   while (first2 <= last2)
   {
      // At this point, tempArray[first..index-1] is in order
      tempArray[index] = theArray[first2];
      first2++;
      index++;
   }  // end for
   
   // Copy the result back into the original array
   for (index = first; index <= last; index++)
      theArray[index] = tempArray[index];
}  // end merge

/** Sorts the items in an array into ascending order.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted in ascending order.
 @param theArray  The given array.
 @param first  The index of the first element to consider in theArray.
 @param last  The index of the last element to consider in theArray. */
template<class T>
void mergeSort(T theArray[], int first, int last)
{
   if (first < last)
   {
      // Find the mid point index
      int mid = first + (last - first) / 2; // Index of midpoint
      
      // Sort left half theArray[first..mid]
      mergeSort(theArray, first, mid);
      
      // Sort right half theArray[mid+1..last]
      mergeSort(theArray, mid + 1, last);
      
      // Merge the two halves
      merge(theArray, first, mid, last);
   }  // end if
}  // end mergeSort

/** Arranges the first, middle, and last entry in an array in sorted order.
 @pre  theArray[first..last] is an array; first <= last.
 @post  theArray[first..last] is is arranged so that its
 first, middle, and last entries are in sorted order.
 @param theArray  The given array.
 @param first  The first entry to consider in theArray.
 @param last  The last entry to consider in theArray.
 @return  The index of the middle entry. */
template<class T>
int sortFirstMiddleLast(T theArray[], int first, int last)
{
   int mid = first + (last - first) / 2;
   if (theArray[first] > theArray[mid])		// Make theArray[first] <= theArray[mid]
		std::swap(theArray[first], theArray[mid]); // Exchange entries
   if (theArray[mid] > theArray[last])		// Make theArray[mid] <= theArray[last]
		std::swap(theArray[mid], theArray[last]); // Exchange entries	
   if (theArray[first] > theArray[mid])		// Make theArray[first] <= theArray[mid]
		std::swap(theArray[first], theArray[mid]); // Exchange entries
   
   return mid;
}  // end sortFirstMiddleLast


/** Partitions the entries in an array about a pivot entry for quicksort.
 @pre  theArray[first..last] is an array; first <= last.
 @post  theArray[first..last] is partitioned such that:
 S1 = theArray[first..pivotIndex-1] <= pivot
 theArray[pivotIndex]          == pivot
 S2 = theArray[pivotIndex+1..last]  >= pivot
 @param theArray  The given array.
 @param first  The first entry to consider in theArray.
 @param last  The last entry to consider in theArray.
 @return  The index of the pivot. */
template<class T>
int partition(T theArray[], int first, int last)
{
   // Choose pivot using median-of-three selection
   int pivotIndex = sortFirstMiddleLast(theArray, first, last);
   
   // Reposition pivot so it is last in the array
   std::swap(theArray[pivotIndex], theArray[last - 1]);
   pivotIndex = last - 1;
   T pivot = theArray[pivotIndex];
   
   // Determine the regions S1 and S2
   int indexFromLeft = first + 1;
   int indexFromRight = last - 2;
   
   bool done = false;
   while (!done)
   {
      // Locate first entry on left that is >= pivot
      while (theArray[indexFromLeft] < pivot)
         indexFromLeft = indexFromLeft + 1;
      
      // Locate first entry on right that is <= pivot
      while (theArray[indexFromRight] > pivot)
         indexFromRight = indexFromRight - 1;
      
      if (indexFromLeft < indexFromRight)
      {
         std::swap(theArray[indexFromLeft], theArray[indexFromRight]);
         indexFromLeft = indexFromLeft + 1;
         indexFromRight = indexFromRight - 1;
      }
      else
         done = true;
   }  // end while
   
   // Place pivot in proper position between S1 and S2, and mark its new location
   std::swap(theArray[pivotIndex], theArray[indexFromLeft]);
   pivotIndex = indexFromLeft;
   
   return pivotIndex;
}  // end partition

// Listing 11-5.
/** Sorts an array into ascending order. Uses the quick sort with
 median-of-three pivot selection for arrays of at least MIN_SIZE
 entries, and uses the insertion sort for other arrays.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The first element to consider in theArray.
 @param last  The last element to consider in theArray. */
template<class T>
void quickSort(T theArray[], int first, int last)
{
   if (last - first + 1 < MIN_SIZE)
   {
	  insertionSort(theArray, last+1);
   }
   else
   {
      // Create the partition: S1 | Pivot | S2
      int pivotIndex = partition(theArray, first, last);
      
      // Sort subarrays S1 and S2
      quickSort(theArray, first, pivotIndex - 1);
      quickSort(theArray, pivotIndex + 1, last);
   }  // end if
}  // end quickSort

//****************QUICK SORT VECTOR ************************

/** Arranges the first, middle, and last entry in an array in sorted order.
 @pre  theArray[first..last] is an array; first <= last.
 @post  theArray[first..last] is is arranged so that its
 first, middle, and last entries are in sorted order.
 @param theArray  The given array.
 @param first  The first entry to consider in theArray.
 @param last  The last entry to consider in theArray.
 @return  The index of the middle entry. */
template<class T>
int sortFirstMiddleLast(vector<T>& theArray, int first, int last)
{
   int mid = first + (last - first) / 2;
   if (theArray[first] > theArray[mid])		// Make theArray[first] <= theArray[mid]
		std::swap(theArray[first], theArray[mid]); // Exchange entries
   if (theArray[mid] > theArray[last])		// Make theArray[mid] <= theArray[last]
		std::swap(theArray[mid], theArray[last]); // Exchange entries	
   if (theArray[first] > theArray[mid])		// Make theArray[first] <= theArray[mid]
		std::swap(theArray[first], theArray[mid]); // Exchange entries
   
   return mid;
}  // end sortFirstMiddleLast


/** Partitions the entries in an array about a pivot entry for quicksort.
 @pre  theArray[first..last] is an array; first <= last.
 @post  theArray[first..last] is partitioned such that:
 S1 = theArray[first..pivotIndex-1] <= pivot
 theArray[pivotIndex]          == pivot
 S2 = theArray[pivotIndex+1..last]  >= pivot
 @param theArray  The given array.
 @param first  The first entry to consider in theArray.
 @param last  The last entry to consider in theArray.
 @return  The index of the pivot. */
template<class T>
int partition(vector<T>& theArray, int first, int last)
{
   // Choose pivot using median-of-three selection
   int pivotIndex = sortFirstMiddleLast(theArray, first, last);
   
   // Reposition pivot so it is last in the array
   std::swap(theArray[pivotIndex], theArray[last - 1]);
   pivotIndex = last - 1;
   T pivot = theArray[pivotIndex];
   
   // Determine the regions S1 and S2
   int indexFromLeft = first + 1;
   int indexFromRight = last - 2;
   
   bool done = false;
   while (!done)
   {
      // Locate first entry on left that is >= pivot
      while (theArray[indexFromLeft] < pivot)
         indexFromLeft = indexFromLeft + 1;
      
      // Locate first entry on right that is <= pivot
      while (theArray[indexFromRight] > pivot)
         indexFromRight = indexFromRight - 1;
      
      if (indexFromLeft < indexFromRight)
      {
         std::swap(theArray[indexFromLeft], theArray[indexFromRight]);
         indexFromLeft = indexFromLeft + 1;
         indexFromRight = indexFromRight - 1;
      }
      else
         done = true;
   }  // end while
   
   // Place pivot in proper position between S1 and S2, and mark its new location
   std::swap(theArray[pivotIndex], theArray[indexFromLeft]);
   pivotIndex = indexFromLeft;
   
   return pivotIndex;
}  // end partition

// Listing 11-5.
/** Sorts an array into ascending order. Uses the quick sort with
 median-of-three pivot selection for arrays of at least MIN_SIZE
 entries, and uses the insertion sort for other arrays.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The first element to consider in theArray.
 @param last  The last element to consider in theArray. */
template<class T>
void quickSort(vector<T>& theArray, int first, int last)
{
   if (last - first + 1 < MIN_SIZE)
   {
	  insertionSort(theArray, first, last);
   }
   else
   {
      // Create the partition: S1 | Pivot | S2
      int pivotIndex = partition(theArray, first, last);
      
      // Sort subarrays S1 and S2
      quickSort(theArray, first, pivotIndex - 1);
      quickSort(theArray, pivotIndex + 1, last);
   }  // end if
}  // end quickSort
//*********************** HEAP SORT *******************************

// Converts a semiheap rooted at index root into a heap.
template <class ItemType>
void heapRebuild(const int subTreeNodeIndex, ItemType items[], int itemCount)
{
   bool leaf = (((2 * subTreeNodeIndex) + 1) >= itemCount);
   if (!leaf) // if not a leaf
   {
      // Find larger child
      int largerChildIndex = (2 * subTreeNodeIndex) + 1; // A left child must exist
											// Make assumption about larger child
      int rightChildIndex = (2 * subTreeNodeIndex) + 2; // A right child might not exist
      
      // Check to see whether a right child exists
      if (rightChildIndex < itemCount)
      {
         // A right child exists; check whether it is larger
         if (items[rightChildIndex] > items[largerChildIndex])
            largerChildIndex = rightChildIndex; // Asssumption was wrong
      }  // end if
      
      // If root value is smaller that the value in the larger child, swap values
      if (items[subTreeNodeIndex] < items[largerChildIndex])
      {
         swap(items[largerChildIndex], items[subTreeNodeIndex]);
         
         // Continue with the recursion at that child
         heapRebuild(largerChildIndex, items, itemCount);
      }  // end if
   }  // end if
}  // end heapRebuild


template <class ItemType>
void display(ItemType anArray[], int n)
{
   for (int i = 0; i < n; i++)
      cout << anArray[i] << " ";
}  // end display

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  anArray is sorted into ascending order; n is
 unchanged.
 @param anArray  The given array.
 @param n  The size of theArray. */
template <class ItemType>
void heapSort(ItemType anArray[], int n)
{
   // Build initial heap
   for (int index = n / 2 - 1; index >= 0; index--)
      heapRebuild(index, anArray, n);
   // The heap is anArray[0..n-1]
   // Assertion: anArray[0] is the largest entry in the array
   
   // Move the largest item to the sorted region of array
   swap (anArray[0], anArray[n - 1]);
   
   int heapSize = n - 1;  // Heap region size decreases by 1
   while (heapSize > 1)
   {
	   // Make the Heap region a heap again
      heapRebuild(0, anArray, heapSize);
      
      // Move the largest item to the sorted region of array
      swap(anArray[0], anArray[heapSize-1]);
	  heapSize--;		// Decrease the size of the Heap region
   }  // end while
}  // end heapSort

//************************** VECTOR HEAP SORT**************
// Converts a semiheap rooted at index root into a heap.
template <class ItemType>
void heapRebuild(const int subTreeNodeIndex, vector<ItemType>& items, int itemCount)
{
   bool leaf = (((2 * subTreeNodeIndex) + 1) >= itemCount);
   if (!leaf) // if not a leaf
   {
      // Find larger child
      int largerChildIndex = (2 * subTreeNodeIndex) + 1; // A left child must exist
																	// Make assumption about larger child
      int rightChildIndex = (2 * subTreeNodeIndex) + 2; // A right child might not exist
      
      // Check to see whether a right child exists
      if (rightChildIndex < itemCount)
      {
         // A right child exists; check whether it is larger
         if (items[rightChildIndex] > items[largerChildIndex])
            largerChildIndex = rightChildIndex; // Asssumption was wrong
      }  // end if
      
      // If root value is smaller that the value in the larger child, swap values
      if (items[subTreeNodeIndex] < items[largerChildIndex])
      {
         swap(items[largerChildIndex], items[subTreeNodeIndex]);
         
         // Continue with the recursion at that child
         heapRebuild(largerChildIndex, items, itemCount);
      }  // end if
   }  // end if
}  // end heapRebuild

template <class ItemType>
void display(vector<ItemType>& vectorItems, int n)
{
   for (int i = 0; i < n; i++)
      cout << vectorItems[i] << " ";
}  // end display

/** Sorts the items in a vector into ascending order.
 @pre  None.
 @post  vectorItems is sorted into ascending order; n is
 unchanged.
 @param vectorItems  The given vector.
 @param n  The size of vectorItems. */
template <class ItemType> 
void heapSort(vector<ItemType>& vectorItems)
{
	int n = vectorItems.size();
   // Build initial heap
   for (int index = n / 2 - 1; index >= 0; index--)
      heapRebuild(index, vectorItems, n);
   // The heap is vectorItems[0..n-1]
   // Assertion: vectorItems[0] is the largest entry in the array
   
   // Move the largest item to the sorted region of array
   swap (vectorItems[0], vectorItems[n - 1]);
   
   int heapSize = n - 1;  // Heap region size decreases by 1
   while (heapSize > 1)
   {
	   // Make the Heap region a heap again
      heapRebuild(0, vectorItems, heapSize);
      
      // Move the largest item to the sorted region of array
      swap(vectorItems[0], vectorItems[heapSize-1]);
	  heapSize--;		// Decrease the size of the Heap region
   }  // end while
}  // end heapSort

#endif   // SORTING_ALGORITHMS