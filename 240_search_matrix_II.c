#ifndef bool
#define bool int
#endif

bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize,
		int target)
{
	int row = 0;
	int col = matrixColSize - 1;
	while (row < matrixRowSize && col >= 0) {
		if (matrix[row][col] == target)
			return(1);
		else if (matrix[row][col] < target)
			row++;
		else
			col--;
	}
	return(0);
}
main(){}
