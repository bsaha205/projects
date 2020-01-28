package ai.pkg3;

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.util.Pair;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author amlansaha
 */
public class HumanFIRAgent extends Agent{

    public HumanFIRAgent(String name) {
        super(name);
    }

    @Override
    public void makeMove(Game game) {
        FourInARow fir = (FourInARow) game;
        FIRGUI fg = fir.fg;
        fg.humanTurn = true;
//        System.out.println(this.name+" "+fg.humanTurn);
//        fir.board[4][4]=1;
//        fir.board[2][2]=-1;
//        fg.setLabelText("eee");
//        fg.setBoard(fir.board);
        while(fg.humanTurn) {
            try {
                Thread.sleep(1000);
                if(fg.humanTurn)    continue;
                Pair cell=fg.clickedCell;
                int row=(int)cell.getKey();
                int col = (int)cell.getValue();
//                fir.board[(int)cell.getKey()][(int)cell.getValue()] = this.role;
//            fg.setLabelText("habijabi henten");
//            Scanner sc=new Scanner(System.in);
//            int col=sc.nextInt();
                int valid = fir.insertCoin(col, this.role);
                if(valid<0)  {
                    fir.updateMessage("Invalid move");
                    fg.humanTurn=true;
                    continue;
                }
                break;
            } catch (InterruptedException ex) {
                Logger.getLogger(HumanFIRAgent.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        System.out.println(fg.humanTurn);
        System.out.println("boken");
        fg.repaint();
//        System.out.println("clicked on "+x+" "+y);
    }
    
}
