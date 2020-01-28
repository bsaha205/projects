/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package database.project;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author Shahed
 */
public class DatabaseProject {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        // TODO code application logic here\
        Connection con= null;
        Statement stmt = null;
        ResultSet rs = null;
        ConnectOracle co = new ConnectOracle();
        con= co.connectDb();
        String a= "D";
        int i= a.charAt(0)-'A'+1;
        System.out.println(i);
        
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
    }
    
}
