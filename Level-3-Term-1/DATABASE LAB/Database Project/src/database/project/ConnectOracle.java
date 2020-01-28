/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package database.project;

import java.sql.Connection;
import java.sql.DriverManager;
import javax.swing.JOptionPane;

/**
 *
 * @author Shahed
 */
public class ConnectOracle {
    public static Connection connectDb()
    {
        try
        {
            Class.forName("oracle.jdbc.driver.OracleDriver");
            Connection con= DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl","sms","sms");
            System.out.println("Connection successful");
            
            return con;
        }catch(Exception e)
        {
            System.out.println("Connection unsuccessful");
            JOptionPane.showMessageDialog(null, e);
        }
        return null;
    }
    
}
