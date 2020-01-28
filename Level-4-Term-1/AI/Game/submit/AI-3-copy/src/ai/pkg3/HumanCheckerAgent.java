package ai.pkg3;

import ai.pkg3.Checker_rules.CheckersMove;
import java.util.Scanner;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.util.Pair;

public class HumanCheckerAgent extends Agent {

    public HumanCheckerAgent(String name) {
        super(name);
    }
    

    @Override
    public void makeMove(Game game) {
        Checker_rules cr = (Checker_rules) game;
        FIRGUI fg = cr.fg;
        fg.humanTurn = true;

        fg.setBoard(cr.board);
        fg.repaint();
        
        Vector<Integer> rows = new Vector<>();
        Vector<Integer> cols = new Vector<>();
        CheckersMove[] moveArray = cr.getLegalMoves(role, (Checker_rules) game);
        if (moveArray==null)
        {
            System.out.println("Machine wins!!!");
            updateMessage("Machine wins!!!");
        }
        while (fg.humanTurn) {
            try {
                Thread.sleep(500);
                if (fg.humanTurn) {
                    continue;
                }
                Pair cell = fg.clickedCell;
                rows.add((int) cell.getKey());
                cols.add((int) cell.getValue());
                System.out.println("bbb");

                fg.humanTurn = true;
                while (fg.humanTurn) {
                    try {
                        Thread.sleep(500);
                        if (fg.humanTurn) {
                            continue;
                        }

                        System.out.println(rows.size());
                       
                        cell = fg.clickedCell;
                        rows.add((int) cell.getKey());
                        cols.add((int) cell.getValue());
                        //System.out.println("aaa");
                        int fromRow = rows.get(0);
                        int fromCol = cols.get(0);
                        int toRow = rows.get(1);
                        int toCol = cols.get(1);
                        rows.clear();
                        cols.clear();

                        System.out.println("fromrow=" + fromRow + " and fromcol=" + fromCol);

                        System.out.println("torow=" + toRow + " and tocol=" + toCol);
                        int valid = cr.insertCoin(fromRow, fromCol, toRow, toCol, this.role);
                        if (valid < 0) {
                            cr.updateMessage("Please give a valid move : "+name +"'s turn");
                            //fir.updateMessage(name +"'s turn");
                            fg.humanTurn = true;
                            break;
                        }
                    } catch (InterruptedException ex) {
                        Logger.getLogger(HumanCheckerAgent.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            } catch (InterruptedException ex) {
                Logger.getLogger(HumanCheckerAgent.class.getName()).log(Level.SEVERE, null, ex);
            }
            System.out.println(fg.humanTurn);
            System.out.println("boken");
            fg.repaint();
        }

    }

    private void updateMessage(String machine_wins) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
}

