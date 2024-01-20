#define SIZE 100

void main()
{
	unsigned int size, i;
	int arr[SIZE];
	int ** pointers;
	int ascend_flag;

	printf("Please enter the number of items:\n");
	scanf("%u", &size);
	for (i = 0; i<size; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &ascend_flag);
	pointerSort(arr, size, ascend_flag, &pointers);
	printf("The sorted array:\n"); //Print the sorted array
	printPointers(pointers, size);
	free(pointers);
}