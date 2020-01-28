package ai.pkg3;

import ai.pkg3.Checker_rules.CheckersMove;
import static java.lang.Math.random;
import java.util.ArrayList;
import java.util.Random;

/**
 * @author Bishwajit Saha
 */
public class MinimaxCheckerAgent extends Agent {

    int winnerPoint;
    int ROW, COL;

    public MinimaxCheckerAgent(String name) {
        super(name);
        winnerPoint = 10000000;
    }
    int num_me_prev = 0, num_opo_prev = 0, my_k_p = 0, opo_k_p = 0;

    public void makeMove(Game game) {
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        Checker_rules firGame = (Checker_rules) game;
        ROW = firGame.ROW;
        COL = firGame.COL;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (firGame.board[i][j] == -1) {
                    num_me_prev++;
                } else if (firGame.board[i][j] == -2) {
                    my_k_p++;
                } else if (firGame.board[i][j] == 1) {
                    num_opo_prev++;
                } else if (firGame.board[i][j] == 2) {
                    opo_k_p++;
                }
            }
        }

        CellValueTuple best = maxMove(firGame, 6, Integer.MIN_VALUE, Integer.MAX_VALUE);
        int a = firGame.insertCoin(best.fromRow, best.fromCol, best.toRow, best.toCol, role);

        firGame.fg.setBoard(firGame.board);
        firGame.fg.repaint();
        System.out.println("fromRow= " + best.fromRow + " fromCol= " + best.fromCol);
        System.out.println("toRow= " + best.toRow + " toCol= " + best.toCol + " Utility= " + best.utility);
    }

    private CellValueTuple maxMove(Checker_rules game, int depth, int alpha, int beta) {
        CellValueTuple maxCVT = new CellValueTuple();
        maxCVT.utility = Integer.MIN_VALUE;

        int winner = game.checkForWin();
        if (winner == role) {
            maxCVT.utility = winnerPoint; //this agent wins
            return maxCVT;
        } else if (winner == -1 * role) {
            maxCVT.utility = -winnerPoint; //opponent wins
            return maxCVT;
        } else if (winner == 2) {
            maxCVT.utility = 0; //draw
            return maxCVT;
        }

        if (depth == 0) {
            return evaluate(game);
        }

        CheckersMove[] moveArray = game.getLegalMoves(role, game);
        if (moveArray != null) {
            for (int i = 0; i < moveArray.length; i++) {
                int value = game.board[moveArray[i].fromRow][moveArray[i].fromCol];
                int jmp_value = 0;
                if (moveArray[i].fromRow - moveArray[i].toRow == 2 || moveArray[i].fromRow - moveArray[i].toRow == -2) {
                    int jumpRow = (moveArray[i].fromRow + moveArray[i].toRow) / 2;  // Row of the jumped piece.
                    int jumpCol = (moveArray[i].fromCol + moveArray[i].toCol) / 2;
                    jmp_value = game.board[jumpRow][jumpCol];
                }

                int valid = game.insertCoin(moveArray[i].fromRow, moveArray[i].fromCol, moveArray[i].toRow, moveArray[i].toCol, role); //temporarily making a move

                int v = minMove(game, depth - 1, alpha, beta).utility;
                if (v > maxCVT.utility) {
                    maxCVT.utility = v;
                    maxCVT.fromRow = moveArray[i].fromRow;
                    maxCVT.fromCol = moveArray[i].fromCol;
                    maxCVT.toRow = moveArray[i].toRow;
                    maxCVT.toCol = moveArray[i].toCol;
                }

                if (moveArray[i].fromRow - moveArray[i].toRow == 2 || moveArray[i].fromRow - moveArray[i].toRow == -2) {
                    int jumpRow = (moveArray[i].fromRow + moveArray[i].toRow) / 2;  // Row of the jumped piece.
                    int jumpCol = (moveArray[i].fromCol + moveArray[i].toCol) / 2;
                    game.board[jumpRow][jumpCol] = jmp_value;
                }

                game.board[moveArray[i].fromRow][moveArray[i].fromCol] = value;
                game.board[moveArray[i].toRow][moveArray[i].toCol] = 0; // reverting back to original state
                if (v >= beta) {
                    return maxCVT;
                }

                alpha = Math.max(alpha, v);
            }

        } else {
            maxCVT.utility = -winnerPoint; //opponent wins
            return maxCVT;
        }
        return maxCVT;

    }

    private CellValueTuple minMove(Checker_rules game, int depth, int alpha, int beta) {
        CellValueTuple minCVT = new CellValueTuple();
        minCVT.utility = Integer.MAX_VALUE;

        int winner = game.checkForWin();
        if (winner == role) {
            minCVT.utility = winnerPoint; //max wins
            return minCVT;
        } else if (winner == -1 * role) {
            minCVT.utility = -winnerPoint; //min wins
            return minCVT;
        } else if (winner == 2) {
            minCVT.utility = 0; //draw
            return minCVT;
        }

        if (depth == 0) {
            return evaluate(game);
        }
        CheckersMove[] moveArray = game.getLegalMoves(minRole(), game);
        if (moveArray == null) {
            minCVT.utility = winnerPoint; //max wins
            return minCVT;
        } else {
            for (int i = 0; i < moveArray.length; i++) {
                int value = game.board[moveArray[i].fromRow][moveArray[i].fromCol];
                int jmp_value = 0;
                if (moveArray[i].fromRow - moveArray[i].toRow == 2 || moveArray[i].fromRow - moveArray[i].toRow == -2) {
                    int jumpRow = (moveArray[i].fromRow + moveArray[i].toRow) / 2;  // Row of the jumped piece.
                    int jumpCol = (moveArray[i].fromCol + moveArray[i].toCol) / 2;
                    jmp_value = game.board[jumpRow][jumpCol];
                }

                int valid = game.insertCoin(moveArray[i].fromRow, moveArray[i].fromCol, moveArray[i].toRow, moveArray[i].toCol, minRole()); //temporarily making a move

                int v = maxMove(game, depth - 1, alpha, beta).utility;
                if (v < minCVT.utility) {
                    minCVT.utility = v;
                    minCVT.fromRow = moveArray[i].fromRow;
                    minCVT.fromCol = moveArray[i].fromCol;
                    minCVT.toRow = moveArray[i].toRow;
                    minCVT.toCol = moveArray[i].toCol;
                }

                if (moveArray[i].fromRow - moveArray[i].toRow == 2 || moveArray[i].fromRow - moveArray[i].toRow == -2) {
                    int jumpRow = (moveArray[i].fromRow + moveArray[i].toRow) / 2;  // Row of the jumped piece.
                    int jumpCol = (moveArray[i].fromCol + moveArray[i].toCol) / 2;
                    game.board[jumpRow][jumpCol] = jmp_value;
                }

                game.board[moveArray[i].fromRow][moveArray[i].fromCol] = value;
                game.board[moveArray[i].toRow][moveArray[i].toCol] = 0;// everting back to original state
                if (v <= alpha) {
                    return minCVT;
                }
                beta = Math.min(beta, v);
            }

        }
        return minCVT;

    }

    private int minRole() {
        if (role == -1) {
            return 1;
        } else {
            return -1;
        }
    }

    class CellValueTuple {
        int fromRow, fromCol, toRow, toCol, utility;
        
        public CellValueTuple() {
            fromRow = -1;
            fromCol = -1;
            toRow = -1;
            toCol = -1;
        }

        public CellValueTuple(int r1, int c1, int r2, int c2) {
            fromRow = r1;
            fromCol = c1;
            toRow = r2;
            toCol = c2;
            utility = -1;
        }

        public CellValueTuple(int r1, int c1, int r2, int c2, int u) {
            fromRow = r1;
            fromCol = c1;
            toRow = r2;
            toCol = c2;
            utility = u;
        }
    }

    private CellValueTuple evaluate(Checker_rules game) {
        int num_me_now = 0, num_opo_now = 0, my_k_n = 0, opo_k_n = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (game.board[i][j] == -1) {
                    num_me_now++;
                } else if (game.board[i][j] == -2) {
                    my_k_n++;
                } else if (game.board[i][j] == 1) {
                    num_opo_now++;
                } else if (game.board[i][j] == 2) {
                    opo_k_n++;
                }
            }
        }

        int my_lose = num_me_prev - num_me_now;
        int opo_lose = num_opo_prev - num_opo_now;
        int my_k_l = my_k_p - my_k_n;
        int opo_k_l = opo_k_p - opo_k_n;
        int util = 10 * (opo_lose - my_lose) + 20 * (opo_k_l - my_k_l);
        return new CellValueTuple(0, 0, 0, 0, util);
    }

}
