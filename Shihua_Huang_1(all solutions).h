#ifndef Shihua_Huang_1
#define Shihua_Huang_1

using namespace std;
class Board
{
	// private data member: size of the board
	int size;
	// pointer-to-pointer initialization of the board
	int **chess_board;
	//private data member: number of solutions
	int solutions;

	// private member function:  returns 'false' if
	// the (row, col) position is not safe.
	bool is_this_position_safe(int row, int col)
	{
		int qRow, qCol;
		for (qCol = 0; qCol < col; qCol++)
		{
			// Returns "true" if the (row,col) position is safe.  If it is
			// unsafe (i.e. some other queen can threaten this position), return "false"
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
			// the code that uses the pointer-to-pointer
			// method to initialize the (n x n) chessboard.  Once initialized,
			// put zeros in all entries.  Later on, if you placed a queen in
			// the (i,j)-th position, then chessboard[i][j] will be 1.
			size = n;
			solutions = 0;
			chess_board = new int*[size];
			for (int i = 0; i < size; i++)
				chess_board[i] = new int[size];
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					chess_board[i][j] = 0;
		}

		// private member function: prints the board position
		void print_board()
		{
			// print out the solved board as
			// shown in the assignment description
			std::cout << size << "-Queens Problem Solution" << std::endl;
			int i, j;
			cout << size << "*" << size << "#:" << solutions+1 << endl;
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
			bool t = false;
			if (col >= size)
			{
				print_board(),
				solutions++;
				return true;
			}    
			else
			{
				for (int row = 0; row <= size - 1; row++)
				{
					if (is_this_position_safe(row, col))
					{
						chess_board[row][col] = 1;
						if (solve(col + 1)) {
							t = true;
							chess_board[row][col] = 0;
						}
					    else
					        chess_board[row][col] = 0;
					}
				}
			}
			return t;
		}

	public:
		// Solves the n-Queens problem by (recursive) backtracking
		void nQueens(int n)
		{
			initialize(n);

			if (solve(0))
				cout << "There are " << solutions << " solutions to the " << size << "-Queens Problem" << endl;
			else
				std::cout << "There is no solution to the " << n << "-Queens Problem" << std::endl;
		}
};
#endif