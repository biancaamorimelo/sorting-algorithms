all: mergeSort quickSort

mergeSort: mergeSort.c
	gcc mergeSort.c -o mergeSort
	
quickSort: quickSort.c
	gcc quickSort.c -o quickSort

clean:
	rm *.o
