package ai.pkg3;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Attributes:.. fg: the JFrame used as the GUI of the game.<br>
 * ROW: number of rows of the board.<br>
 * COL: number of columns of the board.<br>
 * board[][]: the state of the board. board[x][y] represents the element at xth
 * row and yth column.<br>
 * if board[x][y]==0: then it is blank<br>
 * if <b>board[x][y]==1:</b> then agent <b>a</b> has given a move here<br>
 * if <b>board[x][y]==-1</b>: agent <b>b</b> has given a move here<br>
 *
 * @author Bishwajit saha
 */

public class Checker_rules extends Game {

    FIRGUI fg;
    int[][] board;
    int ROW, COL;

    /*
     * @param a the first agent. a's role will be 1.
     * @param b the second agent. b's role will be -1.
     */
    public Checker_rules(Agent a, Agent b) {
        super(a, b);
        a.setRole(1);
        b.setRole(-1);
        name = "Checker";

        this.initialize(false);
        fg = new FIRGUI();
        java.awt.EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                fg.setVisible(true);
            }
        });
    }

    @Override
    boolean isFinished() {
        if (checkForWin() != 0) {
            return true;
        }
        return false;
    }

    public class CheckersMove {

        int fromRow, fromCol;  // Position of piece to be moved.
        int toRow, toCol;      // Square it is to move to.

        CheckersMove(int r1, int c1, int r2, int c2) {
            // Constructor.  Just set the values of the instance variables.
            fromRow = r1;
            fromCol = c1;
            toRow = r2;
            toCol = c2;
        }
    }

    CheckersMove[] getLegalMoves(int player, Checker_rules game) {
        // System.out.println("In getlegalmoves");
        if (player != 1 && player != -1) {
            return null;
        }
        int playerKing;  // The constant representing a King belonging to player.
        if (player == 1) {
            playerKing = 2;
        } else {
            playerKing = -2;
        }

        ArrayList<CheckersMove> moves = new ArrayList<CheckersMove>();  // Moves will be stored in this list.

        /*  First, check for any possible jumps.  Look at each square on the board.
          If that square contains one of the player's pieces, look at a possible
          jump in each of the four directions from that square.  If there is 
          a legal jump in that direction, put it in the moves ArrayList.
         */
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                if (game.board[row][col] == player || game.board[row][col] == playerKing) {
                    // System.out.println("1st row "+row+"  col"+col);
                    if (game.canJump(player, row, col, row + 1, col + 1, row + 2, col + 2) == 1) {
                        //System.out.println("2nd");
                        moves.add(new CheckersMove(row, col, row + 2, col + 2));
                    }

                    if (game.canJump(player, row, col, row - 1, col + 1, row - 2, col + 2) == 1) {
                        //System.out.println("3rd");
                        moves.add(new CheckersMove(row, col, row - 2, col + 2));
                    }

                    if (game.canJump(player, row, col, row + 1, col - 1, row + 2, col - 2) == 1) {
                        // System.out.println("4th");
                        moves.add(new CheckersMove(row, col, row + 2, col - 2));
                    }

                    if (game.canJump(player, row, col, row - 1, col - 1, row - 2, col - 2) == 1) {
                        //System.out.println("5th");
                        moves.add(new CheckersMove(row, col, row - 2, col - 2));
                    }

                }
            }
        }

        /*  If any jump moves were found, then the user must jump, so we don't 
          add any regular moves.  However, if no jumps were found, check for
          any legal regualar moves.  Look at each square on the board.
          If that square contains one of the player's pieces, look at a possible
          move in each of the four directions from that square.  If there is 
          a legal move in that direction, put it in the moves ArrayList.
         */
        if (moves.size() == 0) {
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col++) {
                    if (game.board[row][col] == player || game.board[row][col] == playerKing) {
                        if (game.canMove(player, row, col, row + 1, col + 1) == 1) {
                            moves.add(new CheckersMove(row, col, row + 1, col + 1));
                        }
                        if (game.canMove(player, row, col, row - 1, col + 1) == 1) {
                            moves.add(new CheckersMove(row, col, row - 1, col + 1));
                        }
                        if (game.canMove(player, row, col, row + 1, col - 1) == 1) {
                            moves.add(new CheckersMove(row, col, row + 1, col - 1));
                        }
                        if (game.canMove(player, row, col, row - 1, col - 1) == 1) {
                            moves.add(new CheckersMove(row, col, row - 1, col - 1));
                        }
                    }
                }
            }
        }

        /* If no legal moves have been found, return null.  Otherwise, create
          an array just big enough to hold all the legal moves, copy the
          legal moves from the ArrayList into the array, and return the array. */
        if (moves.size() == 0) {
            return null;
        } else {
            CheckersMove[] moveArray = new CheckersMove[moves.size()];
            for (int i = 0; i < moves.size(); i++) {
                moveArray[i] = moves.get(i);
            }
            return moveArray;
        }

    }  // end getLegalMoves

    int checkForWin() {
        int flag1 = 0, flag2 = 0;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (board[i][j] < 0) {
                    flag1 = 1;
                } else if (board[i][j] > 0) {
                    flag2 = 1;
                }
            }
        }
        if (flag1 == 1 && flag2 == 0) {
            this.winner = agent[1];
            System.out.println("Bot wins");
            return -1;
        } else if (flag1 == 0 && flag2 == 1) {
            this.winner = agent[0];
            System.out.println("Human wins");
            return 1;
        } else if (flag1 == 0 && flag2 == 0) {
            System.out.println("Draw");
            return 2;
        } else {
            return 0;
        }
    }

    @Override
    void initialize(boolean fromFile) {
        ROW = 8;
        COL = 8;
        board = new int[ROW][COL];
        for (int row = 0; row < ROW; row++) {
            for (int col = 0; col < COL; col++) {
                if (row % 2 == col % 2) {
                    if (row < 3) {
                        board[row][col] = 1;
                    } else if (row > 4) {
                        board[row][col] = -1;
                    } else {
                        board[row][col] = 0;
                    }
                } else {
                    board[row][col] = 0;
                }
            }
        }
    }

    @Override
    void showGameState() {

        System.out.println("-------------");

        for (int i = 0; i < board.length; i++) {
            System.out.print("| ");
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 0) {
                    System.out.print(" " + " | ");
                } else if (board[i][j] == -1) {
                    System.out.print("O | ");
                } else {
                    System.out.print("X | ");
                }
            }
            System.out.println();
            System.out.println("-------------");
        }
        System.out.println("finished: " + isFinished());
    }

    @Override
    void updateMessage(String msg) {
        this.fg.setLabelText(msg);
        System.out.println(msg);
    }

    int canJump(int player, int r1, int c1, int r2, int c2, int r3, int c3) {

        if (r3 < 0 || r3 >= 8 || c3 < 0 || c3 >= 8) {
            return -1;  // (r3,c3) is off the board.
        }
        if (board[r3][c3] != 0) {
            return -1;  // (r3,c3) already contains a piece.
        }
        if (player == -1) {
            if (board[r1][c1] == -1 && r3 > r1) {
                return -1;  // Regular red piece can only move  up.
            }
            if (board[r2][c2] != 1 && board[r2][c2] != 2) {
                return -1;  // There is no black piece to jump.
            }
            return 1;  // The jump is legal.
        } else {
            if (board[r1][c1] == 1 && r3 < r1) {
                return -1;  // Regular black piece can only move downn.
            }
            if (board[r2][c2] != -1 && board[r2][c2] != -2) {
                return -1;  // There is no red piece to jump.
            }
            return 1;  // The jump is legal.
        }

    }  // end canJump()

    /**
     * This is called by the getLegalMoves() method to determine whether the
     * player can legally move from (r1,c1) to (r2,c2). It is assumed that
     * (r1,r2) contains one of the player's pieces and that (r2,c2) is a
     * neighboring square.
     */
    int canMove(int player, int r1, int c1, int r2, int c2) {

        if (r2 < 0 || r2 >= 8 || c2 < 0 || c2 >= 8) {
            return -1;  // (r2,c2) is off the board.
        }
        if (board[r2][c2] != 0) {
            return -1;  // (r2,c2) already contains a piece.
        }
        if (player == -1) {
            if (board[r1][c1] == -1 && r2 > r1) {
                return -1;  // Regualr red piece can only move down.
            }
            return 1;  // The move is legal.
        } else {
            if (board[r1][c1] == 1 && r2 < r1) {
                System.out.println("baal " + board[r1][c1]);
                return -1;
            }
            // Regular black piece can only move up.
            return 1;  // The move is legal.
        }

    }  // end canMove()

    int insertCoin(int fromRow, int fromCol, int toRow, int toCol, int role) {

        if (((fromRow - toRow == 1) || (fromRow - toRow == -1)) && ((fromCol - toCol == 1) || (fromCol - toCol == -1))) {
            System.out.println(fromCol - toCol);
            if (canMove(role, fromRow, fromCol, toRow, toCol) == 1) {
                this.board[toRow][toCol] = this.board[fromRow][fromCol];
                this.board[fromRow][fromCol] = 0;
                if (toRow == 0 && role == -1) {
                    this.board[toRow][toCol] = -2;
                }
                if (toRow == 7 && role == 1) {
                    this.board[toRow][toCol] = 2;
                }
                return 1;
            }
            return -1;
        } else if (((fromRow - toRow == 2) || (fromRow - toRow == -2)) && (fromCol - toCol == 2 || fromCol - toCol == -2)) {
            int jumpRow = (fromRow + toRow) / 2;  // Row of the jumped piece.
            int jumpCol = (fromCol + toCol) / 2;
            if (canJump(role, fromRow, fromCol, jumpRow, jumpCol, toRow, toCol) == 1) {
                this.board[toRow][toCol] = this.board[fromRow][fromCol];
                this.board[fromRow][fromCol] = 0;
                this.board[jumpRow][jumpCol] = 0;
                if (toRow == 0 && role == -1) {
                    this.board[toRow][toCol] = -2;
                }
                if (toRow == 7 && role == 1) {
                    this.board[toRow][toCol] = 2;
                }
                return 1;
            }
            return -1;
        }
        return -1;

    }
}
