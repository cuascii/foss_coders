import java.util.Scanner;

class TicTacToe {
    public static void printBoard(char[][] board) 
    {
        for (int row = 0; row < board.length; row++) 
        {
          for (int col = 0; col < board[row].length; col++) 
          {
            System.out.print("[ "+board[row][col]  +" ]");
          }
          System.out.println();
        }
      }
      public static boolean haveWon(char[][] board, char player) {
        // checking for rows
        for (int row = 0; row < board.length; row++) 
        {
          if (board[row][0] == player && board[row][1] == player && board[row][2] == player) 
          {
            return true;
          }
        }
    
        // checking in Column wise
        for (int col = 0; col < board[0].length; col++) 
        {
          if (board[0][col] == player && board[1][col] == player && board[2][col] == player) 
          {
            return true;
          }
        }
    
        // diagonal
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) 
        {
          return true;
        }
    
        else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
         {
          return true;
        }
        return false;
      }
  public static void main(String[] args) {
    char[][] board = new char[3][3];
    for (int row = 0; row < board.length; row++) {
      for (int col = 0; col < board[row].length; col++) {
        board[row][col] = ' ';
      }
    }

    char player = 'X';
    boolean gameOver = false;
    Scanner input = new Scanner(System.in);
    System.out.println("place the x or y using x and y coordinates ");
    //reading element

    while (!gameOver) {
      printBoard(board);
      System.out.println("Player " + player + " enter: ");
      System.out.print("x coordinate(1-3):");
      int row = input.nextInt()-1;
      System.out.println("");
    System.out.print("y coordinate(1-3):");
      int col = input.nextInt()-1;
      System.out.println();
    

      if (board[row][col] == ' ') 
      {
        

        board[row][col] = player; 
        gameOver = haveWon(board, player);
        if (gameOver) {
          System.out.println("Player " + player + " has won!!: ");
        } else 
        {
         
          player = (player == 'X') ? 'O' : 'X';
        }
      } else {
        System.out.println("Invalid move. Try again!");
        
      }
    }
    
    printBoard(board);
  }



 
}