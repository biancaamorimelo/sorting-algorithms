all: mergeSort 

mergeSort: mergeSort.c
	gcc mergeSort.c -o mergeSort

clean:
	rm *.o