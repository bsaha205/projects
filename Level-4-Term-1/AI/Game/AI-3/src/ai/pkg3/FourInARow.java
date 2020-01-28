package ai.pkg3;

import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Attributes:..
 * fg: the JFrame used as the GUI of the game.<br>
 * ROW: number of rows of the board.<br>
 * COL: number of columns of the board.<br>
 * board[][]: the state of the board. board[x][y] represents the element at xth row and yth column.<br>
 * if board[x][y]==0: then it is blank<br>
 * if <b>board[x][y]==1:</b> then agent <b>a</b> has given a move here<br>
 * if <b>board[x][y]==-1</b>: agent <b>b</b> has given a move here<br>
 * 
 * @author amlansaha
 */
public class FourInARow extends Game{
    FIRGUI fg;
    int[][] board;
    int ROW,COL;
    
    /**
     * 
     * 
     * @param a the first agent. a's role will be 1.
     * @param b the second agent. b's role will be -1.
     */
    public FourInARow(Agent a, Agent b) {
        super(a, b);
        a.setRole(1);
        b.setRole(-1);
        name="Four In A Row";
        
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
//        Scanner sc=new Scanner(System.in);
//        for(int i=0;i<ROW;i++)  for(int j=0;j<COL;j++)  board[i][j]=sc.nextInt();
        if(checkForWin()!=0)    return true;
        return isBoardFull();
    }
    
    /**
     * Returns role of the winner (1 or -1), if no winner/ still game is going on 0.
     *
     * @return role of the winner (1 or -1), if no winner/ still game is going on 0.
     */
    int checkForWin()   {
        
        for(int i=0;i<ROW;i++)  {
            int conseq=0;
            for(int j=0;j<COL;j++)  {
                if(board[i][j]==0)  {
                    conseq=0;
                    continue;
                }
                if(board[i][j]>0)   {
                    if(conseq<0)    {
                        conseq=0;
                    }
                    conseq++;
                }
                else    {
                    if(conseq>0)    {
                        conseq=0;
                    }
                    conseq--;
                }
                if(conseq==4)   {
                    winner=agent[0];
                    return 1;
                }
                else if(conseq==-4) {
                    winner=agent[1];
                    return -1;
                }
            }
        }
        
        for(int j=0;j<COL;j++)  {
            int conseq=0;
            for(int i=0;i<ROW;i++)  {
                if(board[i][j]==0)  {
                    conseq=0;
                    continue;
                }
                if(board[i][j]>0)   {
                    if(conseq<0)    {
                        conseq=0;
                    }
                    conseq++;
                }
                else    {
                    if(conseq>0)    {
                        conseq=0;
                    }
                    conseq--;
                }
                if(conseq==4)   {
                    winner=agent[0];
                    return 1;
                }
                else if(conseq==-4) {
                    winner=agent[1];
                    return -1;
                }
            }
        }
        
        for(int i=0;i<ROW;i++)  {
            int conseq=0;
            for(int j=0;j+i<ROW && j<COL;j++)   {
                if(board[i+j][j]==0)  conseq=0;
                else if(board[i+j][j]>0)  {
                    if(conseq<0)    conseq=0;
                    conseq++;
                }
                else    {
                    if(conseq>0)    conseq=0;
                    conseq--;
                }
                if(conseq==4)   {
                    winner=agent[0];
                    return 1;
                }
                else if(conseq==-4) {
                    winner=agent[1];
                    return -1;
                }
            }
        }
        
        for(int i=0;i<ROW;i++)  {
            int conseq=0;
            for(int j=0; i+j<ROW && COL-j-1>=0; j++)  {
//            for(int j=COL;j-i>=0 && j>=0; j--)   {
                if(board[i+j][COL-j-1]==0)  conseq=0;
                else if(board[i+j][COL-j-1]>0)  {
                    if(conseq<0)    conseq=0;
                    conseq++;
                }
                else    {
                    if(conseq>0)    conseq=0;
                    conseq--;
                }
                if(conseq==4)   {
                    winner=agent[0];
                    return 1;
                }
                else if(conseq==-4) {
                    winner=agent[1];
                    return -1;
                }
            }
        }        
        
        for(int j=0;j<COL;j++)  {
            int conseq=0;
            for(int i=0;j+i<COL && i<ROW;i++)   {
                if(board[i][i+j]==0)  conseq=0;
                else if(board[i][i+j]>0)  {
                    if(conseq<0)    conseq=0;
                    conseq++;
                }
                else    {
                    if(conseq>0)    conseq=0;
                    conseq--;
                }
                if(conseq==4)   {
                    winner=agent[0];
                    return 1;
                }
                else if(conseq==-4) {
                    winner=agent[1];
                    return -1;
                }
            }
        }
        
        
//        for(int j=COL-1;j>=0;j--)  {
        for(int j=0; j<COL; j++)  {
            int conseq=0;
            for(int i=0; COL-1-j-i>=0 && i<ROW;i++)   {
                if(board[i][COL-1-j-i]==0)  conseq=0;
                else if(board[i][COL-1-j-i]>0)  {
                    if(conseq<0)    conseq=0;
                    conseq++;
                }
                else    {
                    if(conseq>0)    conseq=0;
                    conseq--;
                }
                if(conseq==4)   {
                    winner=agent[0];
                    return 1;
                }
                else if(conseq==-4) {
                    winner=agent[1];
                    return -1;
                }
            }
        }
        
        return 0;
    }
    
    
    boolean isBoardFull()   {
        for(int i=0;i<ROW;i++)  {
            for(int j=0;j<COL;j++)  if(board[i][j]==0)  return false;
        }
        return true;
    }
    
    
    @Override
    void initialize(boolean fromFile) {
        ROW=6;
        COL=7;
        board = new int[ROW][COL];
    }

    @Override
    void showGameState() {
//        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.


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
        System.out.println("finished: "+isFinished());
    }

    @Override
    void updateMessage(String msg) {
        this.fg.setLabelText(msg);
        System.out.println(msg);
    }
    
    int insertCoin(int column, int role) {
        int row = this.board.length - 1;
        while (row >= 0) {
            if (this.board[row][column] == 0) {
                break;
            }
            row--;
        }
        if (row >= 0) {
            this.board[row][column] = role;
//            fg.humanTurn = false;
        }
        return row;
    }
    
//    public static void main(String[] st)    {
//        Game fir=new FourInARow(new HumanFIRAgent("Human"), new MinimaxFIRAgent("AI BOT"));
////        while(true) {
////            boolean result = fir.isFinished();
////            System.out.println(result);
////        }
//        fir.play();
//    }
}
