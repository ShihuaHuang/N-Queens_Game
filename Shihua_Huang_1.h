#ifndef Shihua_Huang_1
#define Shihua_Huang_1
using namespace std;
class Board
{

	// private data member: size of the board
	int size;

	// pointer-to-pointer initialization of the board
	int **chess_board;

	// private member function:  returns 'false' if
	// the (row, col) position is not safe.
	bool is_this_position_safe(int row, int col)
	{	
		//returns "true" if the (row,col) position is safe.  If it is
		// unsafe (i.e. some other queen can threaten this position) return "false"
		int qRow, qCol;
		for (qCol = 0; qCol < col; qCol++)
		{
			for (qRow = 0; qRow < size; qRow++)
			{
				if (chess_board[qRow][qCol] == 1 && (qRow == row || abs(qCol - col) == abs(qRow - row)))
						return false;
			}		
		}
		return true;
	}

	// private member function: initializes the (n x n) chessboard
	void initialize(int n)
	{
		// code that uses the pointer - to - pointer
		// method to initialize the (n x n) chessboard.  Once initialized,
		// put zeros in all entries.  Later on, if you placed a queen in
		// the (i,j)-th position, then chessboard[i][j] will be 1.
		size = n;
		chess_board = new int*[size];
		for (int i = 0; i < size; i++)
			chess_board[i] = new int[size];
		//memset(chess_board, 0, sizeof(chess_board));
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				chess_board[i][j] = 0;
	}

	// private member function: prints the board position
	void print_board()
	{
		// print out the solved board
		std::cout << size << "-Queens Problem Solution" << std::endl;
		int i, j;
		for (i = 0; i < size; i++)
		{
			cout << " " << " ";
			for (j = 0; j < size; j++)
				cout << chess_board[i][j] << " ";
			cout << endl;
		}
	}

	// private member function: recursive backtracking
	bool solve(int col)
	{
		// implement the recursive backtracking procedure described in
		// pseudocode format in figure 1 of the description of the first
		// programming assignment
		if (col >= size)
			return true;
		else
		{
			for (int row = 0; row <= size - 1; row++)
			{
				if (is_this_position_safe(row, col))
				{
					chess_board[row][col] = 1;
					if (solve(col + 1))
						return true;
					else
						chess_board[row][col] = 0;
				}
			}
		}
		return false;
	}

public:
	// Solves the n-Queens problem by (recursive) backtracking
	void nQueens(int n)
	{
		initialize(n);

		if (solve(0))
			print_board();
		else
			std::cout << "There is no solution to the " << n << "-Queens Problem" << std::endl;
	}
};
#endif
