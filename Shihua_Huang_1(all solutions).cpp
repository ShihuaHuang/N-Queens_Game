// N Queens Problem via (Backtracking, which is implemented by) Recursion 
#include <iostream>
#include "Shihua_Huang_1(all solutions).h"

int main(int argc, char * const argv[])
{
	Board x;
	int board_size;
	sscanf_s(argv[1], "%d", &board_size);

	x.nQueens(board_size);
	system("pause");

	return 0;
}