/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ai.pkg3;

/**
 *
 * @author amlansaha
 */
public class MinimaxFIRAgent extends Agent{
    int winnerPoint;
    int ROW,COL;
    public MinimaxFIRAgent(String name) {
        super(name);
        winnerPoint=10000000;
    }

    
    @Override
    public void makeMove(Game game) {
        // TODO Auto-generated method stub

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        FourInARow firGame = (FourInARow) game;
        ROW=firGame.ROW;
        COL=firGame.COL;
        CellValueTuple best = maxMove(firGame,8,Integer.MIN_VALUE,Integer.MAX_VALUE);
        if (best.col != -1) {
//            firGame.board[best.row][best.col] = role;
            firGame.insertCoin(best.col, role);
        }
        else    {
            for(int col=2;col!=2; col=(col+1)%firGame.COL)   {
                if(firGame.insertCoin(col, role)>=0)    break;
            }
        }
        firGame.fg.setBoard(firGame.board);
        firGame.fg.repaint();
        System.out.println(best.col+" "+best.utility);

    }

    private CellValueTuple maxMove(FourInARow game, int depth,int alpha,int beta) {
        CellValueTuple maxCVT = new CellValueTuple();
        maxCVT.utility = Integer.MIN_VALUE;

        int winner = game.checkForWin();
        

        //terminal check
        if (winner == role) {
            maxCVT.utility = winnerPoint; //this agent wins
            return maxCVT;
        } else if (winner == -1*role) {
            maxCVT.utility = -winnerPoint; //opponent wins
            return maxCVT;
        } else if (game.isBoardFull()) {
            maxCVT.utility = 0; //draw
            return maxCVT;
        }
//        if(depth<2) System.out.println("max... depth: "+depth);

        if(depth==0)    {
            return evaluate(game);
        }
//        for (int i = 0; i < game.board.length; i++) {
        for (int col=1; col!=0; col = (col+1)%game.board[0].length)    {
//            for (int row = 0; row < game.board.length; row++) {
//                if (game.board[row][col] != 0) {
//                    continue;
//                }

                int row = game.insertCoin(col, role); //temporarily making a move
                if(row<0)   continue;
                int v = minMove(game,depth-1,alpha,beta).utility;
                if (v > maxCVT.utility) {
                    maxCVT.utility = v;
                    maxCVT.row = row;
                    maxCVT.col = col;
                }
                game.board[row][col] = 0; // reverting back to original state
                if (v>=beta)    {
//                    System.out.println("pruning on depth"+depth);
                    return maxCVT;
                }
                alpha = Math.max(alpha, v);
//                break;
//            }
        }
        return maxCVT;

    }
    
    
    private CellValueTuple minMove(FourInARow game,int depth,int alpha,int beta) {
        CellValueTuple minCVT = new CellValueTuple();
        minCVT.utility = Integer.MAX_VALUE;

        int winner = game.checkForWin();
//        System.out.println("depth: "+depth);
        //terminal check
        if (winner == role) {
            minCVT.utility = winnerPoint; //max wins
            return minCVT;
        } else if (winner == -1*role) {
            minCVT.utility = -winnerPoint; //min wins
            return minCVT;
        } else if (game.isBoardFull()) {
            minCVT.utility = 0; //draw
            return minCVT;
        }

        if(depth==0)    {
            return evaluate(game);
        }
        for (int col=0; col<game.board[0].length; col++)    {
//            for (int row = 0; row < game.board.length; row++) {
//                if (game.board[row][col] != 0) {
//                    continue;
//                }

                int row = game.insertCoin(col, minRole()); //temporarily making a move
                if(row<0)   continue;
                int v = maxMove(game,depth-1,alpha,beta).utility;
                if (v < minCVT.utility) {
                    minCVT.utility = v;
                    minCVT.row = row;
                    minCVT.col = col;
                }
                game.board[row][col] = 0;
                if(v<=alpha)    return minCVT;
                beta = Math.min(beta, v);
//            }
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

        int row, col, utility;

        public CellValueTuple() {
            // TODO Auto-generated constructor stub
            row = -1;
            col = -1;
        }
        public CellValueTuple(int r,int c)  {
            row=r;
            col=c;
            utility=-1;
        }
        public CellValueTuple(int r,int c,int u)    {
            row=r;
            col=c;
            utility=u;
        }
    }
    
    private CellValueTuple evaluate(FourInARow game)    {
        int ret=0;
        int used=0;
        
        for(int i=0;i<game.board.length;i++)    {
            for(int j=0;j<game.board[0].length;j++) {
                if(game.board[i][j]!=0) used++;
            }
        }
        int tempRole=1;
        if(used%2!=0)   tempRole=-1;
        
        for(int col=0;col<game.board[0].length;col++)   {
            int row=game.insertCoin(col, tempRole);
            if(row<0)   continue;
            int tempWinner = game.checkForWin();
            game.board[row][col]=0;
            if(tempWinner==this.role)    return new CellValueTuple(row, col, winnerPoint);
            else if(tempWinner==minRole())  return new CellValueTuple(row, col, -winnerPoint);
        }
        
        int board[][] = game.board;
        
        for(int i=0;i<ROW;i++)  {
            int temp=0;
            int conseq=0;
            int zero=0;
            for(int j=0;j<COL;j++)  {
                if(board[i][j]==0)  {
                    zero++;
                    if(zero>1)  conseq=0;
                    continue;
                }
                if(board[i][j]>0)   {
                    if(conseq<0)    {
                        conseq=0;
                    }
                    conseq++;
                    temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
                else    {
                    if(conseq>0)    {
                        conseq=0;
                    }
                    conseq--;
                    temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
            }
        }
        
        for(int j=0;j<COL;j++)  {
            int conseq=0;
            int zero=0;
            for(int i=0;i<ROW;i++)  {
                if(board[i][j]==0)  {
                    zero++;
                    if(zero>1)  conseq=0;
                    continue;
                }
                if(board[i][j]>0)   {
                    if(conseq<0)    {
                        conseq=0;
                    }
                    conseq++;
                    int temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
                else    {
                    if(conseq>0)    {
                        conseq=0;
                    }
                    conseq--;
                    int temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
            }
        }
        
        for(int i=0;i<ROW;i++)  {
            int conseq=0;
            int zero=0;
            for(int j=0;j+i<ROW && j<COL;j++)   {
                if(board[i+j][j]==0)  {
                    zero++;
                    if(zero>1)  conseq=0;
                    continue;
                }
                else if(board[i+j][j]>0)  {
                    if(conseq<0)    conseq=0;
                    conseq++;
                    int temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
                else    {
                    if(conseq>0)    conseq=0;
                    conseq--;
                    int temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
            }
        }
        
        for(int i=0;i<ROW;i++)  {
            int conseq=0;
            int zero=0;
            for(int j=0; i+j<ROW && COL-j-1>=0; j++)  {
//            for(int j=COL;j-i>=0 && j>=0; j--)   {
                if(board[i+j][COL-j-1]==0)  {
                    zero++;
                    if(zero>1)  conseq=0;
                    continue;
                }
                else if(board[i+j][COL-j-1]>0)  {
                    if(conseq<0)    conseq=0;
                    conseq++;
                    int temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
                else    {
                    if(conseq>0)    conseq=0;
                    conseq--;
                    int temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
            }
        }        
        
        for(int j=0;j<COL;j++)  {
            int conseq=0;
            int zero=0;
            for(int i=0;j+i<COL && i<ROW;i++)   {
                if(board[i][i+j]==0)  {
                    zero++;
                    if(zero>1)  conseq=0;
                    continue;
                }
                else if(board[i][i+j]>0)  {
                    if(conseq<0)    conseq=0;
                    conseq++;
                    int temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
                else    {
                    if(conseq>0)    conseq=0;
                    conseq--;
                    int temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
            }
        }
        
        
//        for(int j=COL-1;j>=0;j--)  {
        for(int j=0; j<COL; j++)  {
            int conseq=0;
            int zero=0;
            for(int i=0; COL-1-j-i>=0 && i<ROW;i++)   {
                if(board[i][COL-1-j-i]==0)  {
                    zero++;
                    if(zero>1)  conseq=0;
                    continue;
                }
                else if(board[i][COL-1-j-i]>0)  {
                    if(conseq<0)    conseq=0;
                    conseq++;
                    int temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
                else    {
                    if(conseq>0)    conseq=0;
                    conseq--;
                    int temp=100;
                    if(conseq>=2)   temp*=10;
                    else if(conseq>=3)  temp*=10;
                    if(board[i][j]==minRole())  temp*=-1;
                    ret+=temp;
                }
            }
        }
        
        return new CellValueTuple(0,0,ret);
    }
    boolean isValid(int r,int c)    {
        return r>=0 && c>=0 && r<ROW && c<COL;
    }
}
