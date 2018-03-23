#include "stdafx.h"
#include <string.h>


int smallest(int x, int y, int z) {

	return (x < y) ? ((x < z) ? x : z) : (y < z) ? y : z;
}

int goal(int x1, int y1, int x2, int y2) {

	if ((x1 == 45 && y1 == 49) && (x2 == 45 && y2 == 49)) {
		return 1;
	}
	return 0;
}

int compareFirstChar(char x, char y) {
	
	if (x == y) {
		return 0;
	}
	else {
		return 1;
	}
}

void editDistance(char *string1, char *string2) {
	
	int len1, len2, i, j, low = 0;
	int distance[101][101] = { { 0 } };
	len1 = strlen(string1);
	len2 = strlen(string2);

	// Initialize 1st row
	for (j = 0; j <= len2; j++) {
		distance[0][j] = j;
	}

	// Initialize 1st column
	for (j = 0; j <= len1; j++) {
		distance[j][0] = j;
	}

	
	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {

			if (( string1[i-1] == string2[j-1])) {
				distance[i][j] = distance[i-1][j-1];
			}
			else {
				low = smallest(distance[i - 1][j - 1], distance[i][j - 1], distance[i - 1][j]);
				distance[i][j] = low + 1;
			}


		}
	}
	printf("\n");

		printf("\t   |     |");
		for (j = 0; j < len2; j++) {
			printf("  %c  |", string2[j]);
		}
		printf("\n\t");
		for (j = 0; j <= len2; j++) {
			printf("----");
		}
		printf("\n");

	
	for (i = 0; i <= len1; i++) {

		if (i != 0) {
			printf("\t%c  |  ", string1[i - 1]);
		}

		if (i == 0) {
			printf("\t   |  ", string1[i - 1]);
		}

		for (j = 0; j <= len2; j++) {
			printf("%d  |  ", distance[i][j]);
		}
		printf("\n\t");
		for (j = 0; j <= len2; j++) {
			printf("-----");
		}
		printf("\n");
	}

	printf("Edit Distance: %d \n", distance[len1][len2]);

}


int main()
{
	int var;
	char string1[100], string2[100];

	//	var = smallest(7, 5, 6);
	//	printf("the smallest value is: %d\n", var);
	
	while (1) {

		gets(string1);
		gets(string2);

		if (goal(string1[0], string1[1], string2[0], string2[1])) {
			break;
		}
		else {
			printf("first: %s\n", string1);
			printf("second: %s\n\n", string2);

			editDistance(string1, string2);
			printf("\n===========================================================================================\n");
			
		}
	}
	
	return 0;
}

