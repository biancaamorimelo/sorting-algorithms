all: selectionSort insertionSort mergeSort quickSort countingSort

selectionSort: selectionSort.c
	gcc selectionSort.c -o selectionSort

insertionSort: insertionSort.c
	gcc insertionSort.c -o insertionSort
	
mergeSort: mergeSort.c
	gcc mergeSort.c -o mergeSort
	
quickSort: quickSort.c
	gcc quickSort.c -o quickSort

countingSort: countingSort.c
	gcc countingSort.c -o countingSort	

clean:
	rm *.o
