all: selectionSort insertionSort mergeSort quickSort

selectionSort: selectionSort.c
	gcc selectionSort.c -o selectionSort

insertionSort: insertionSort.c
	gcc insertionSort.c -o insertionSort
	
mergeSort: mergeSort.c
	gcc mergeSort.c -o mergeSort
	
quickSort: quickSort.c
	gcc quickSort.c -o quickSort

clean:
	rm *.o
