/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package database.project;

import static database.project.user_interface.con;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Calendar;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;

/**
 *
 * @author Shahed
 */
public class DatabaseProject {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        try {
            // TODO code application logic here\
            Connection con= null;
            Statement stmt = null;
            ResultSet rs = null;
            ConnectOracle co = new ConnectOracle();
            con= co.connectDb();
            user_interface fr= new user_interface();
                fr.setVisible(true);
                fr.setBounds(200, 30, 1000, 650);
                fr.con=con;
            String a= "D";
            int i= a.charAt(0)-'A'+1;
            stmt = con.createStatement();

            rs=stmt.executeQuery("select max(student_id) from students");
            int in=0;
            while(rs.next())
            {
                in=rs.getInt(1);
            }
            System.out.println(in);
            Calendar now = Calendar.getInstance();
    // 
            
            // stmt = con.createStatement();
//        rs = stmt.executeQuery("SELECT * FROM employees");
//            while(rs.next()) {
//                System.out.print(rs.getInt(1) + "\t\t");
//                System.out.print(rs.getString(2)+ "\t\t");
//                System.out.print(rs.getString(3)+ "\t\t");
//                System.out.print(rs.getString(4)+ "\t\t");
//                System.out.println();
//            }
//        }catch(Exception e){
//            
//        }finally {
//            try {
//                rs.close();
//                stmt.close();
//                con.close();
//            } catch (SQLException e) {
//                e.printStackTrace();
//            }
//        }
        } catch (SQLException ex) {
            Logger.getLogger(DatabaseProject.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
