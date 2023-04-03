// On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].

// Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.



// We may make the following moves:

// 'U' moves our position up one row, if the position exists on the board;
// 'D' moves our position down one row, if the position exists on the board;
// 'L' moves our position left one column, if the position exists on the board;
// 'R' moves our position right one column, if the position exists on the board;
// '!' adds the character board[r][c] at our current position (r, c) to the answer.
// (Here, the only positions that exist on the board are positions with letters on them.)

// Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.

 

// Example 1:

// Input: target = "leet"
// Output: "DDR!UURRR!!DDD!"

class Solution {
public:
  
	string alphabetBoardPath(string target) {
		int curr_row =0;
		int curr_col=0;
		string res="";
		for(int i=0;i<target.length();i++){
			char a = target[i];
			int loc = a - 'a';
			int row = loc/5;
			int col = (loc%5);
			int diff_row = row-curr_row;
			int diff_col = col-curr_col;
			res += string(max(0, -diff_row), 'U') + string(max(0, diff_col), 'R') +
			string(max(0, -diff_col), 'L') + string(max(0, diff_row), 'D') + "!";
			curr_row=row;
			curr_col=col;
		}
		return res;
	}
    };
