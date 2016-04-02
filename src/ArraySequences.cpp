/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int CheckAP(int *a,int start,int end)
{
	int iDiff = a[1] - a[0];
	for (int i = start; i<end - 1; i++)
	{
		if ((a[i + 1] - a[i]) != iDiff)
			return -1;
	}
	return 1;
}
int CheckGP(int *a,int len)
{
	int iRatio = a[1] / a[0];
	for (int i = 0; i<len - 1; i++)
	{
		if ((a[i + 1] / a[i]) != iRatio)
			return -1;
	}
	return 1;
}

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr==NULL||len<3)
	return NULL;
	int index = 0,templen=len;
	int AP1_S=0, AP1_E=0, AP2_S=0, AP2_E=0, GP1_S=0, GP2_E=0;
	int Apmax = 0;
	for (int i = 0; i < len-2; i++){
		int j = i + 1;
		int curr = CheckAP(arr, i, j);
		while (curr == 1){
			AP1_E = (j>Apmax) ? j : AP1_E;
			AP1_S = i;
			curr = CheckAP(arr, i, j);
			j++;
		}
	}

}