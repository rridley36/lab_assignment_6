#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	int median;
	while (low <= high){
		median = (low + high) / 2; // Calculates the middle index, which results in the median of the indexes
		if (numbers[median] == value){
			return median; // If the median index happened to be the value, then return the median
		}
		else if (numbers[median] > value){
			return search(numbers, low, median - 1, value); // If the median index is higher than the value, the high will adjust to one lower index than current median value
		}
		else if (numbers[median] < value){
			return search(numbers, median + 1, high, value); // If the median index is lower than the value, the low will adjust to one higher than the current median value
		}
	}
	return -1; // Return -1 if the value is not found in the list
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}