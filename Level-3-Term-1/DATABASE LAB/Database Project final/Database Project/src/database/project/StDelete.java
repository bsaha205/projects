/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package database.project;

/**
 *
 * @author Shahed
 */
public class StDelete extends javax.swing.JFrame {

    /**
     * Creates new form StDelete
     */
    public StDelete() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        DelResult = new javax.swing.JPanel();
        success = new javax.swing.JLabel();
        DelOk = new javax.swing.JButton();
        fail = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new java.awt.CardLayout());

        success.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        success.setText("Delete Successful");

        DelOk.setText("Ok");
        DelOk.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                DelOkActionPerformed(evt);
            }
        });

        fail.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        fail.setText("Delete Failed");

        javax.swing.GroupLayout DelResultLayout = new javax.swing.GroupLayout(DelResult);
        DelResult.setLayout(DelResultLayout);
        DelResultLayout.setHorizontalGroup(
            DelResultLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(DelResultLayout.createSequentialGroup()
                .addGroup(DelResultLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(DelResultLayout.createSequentialGroup()
                        .addGap(96, 96, 96)
                        .addComponent(DelOk))
                    .addGroup(DelResultLayout.createSequentialGroup()
                        .addGap(63, 63, 63)
                        .addGroup(DelResultLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(success, javax.swing.GroupLayout.PREFERRED_SIZE, 189, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(fail, javax.swing.GroupLayout.PREFERRED_SIZE, 108, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addContainerGap(70, Short.MAX_VALUE))
        );
        DelResultLayout.setVerticalGroup(
            DelResultLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(DelResultLayout.createSequentialGroup()
                .addGap(26, 26, 26)
                .addComponent(fail)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(success)
                .addGap(18, 18, 18)
                .addComponent(DelOk)
                .addContainerGap(112, Short.MAX_VALUE))
        );

        getContentPane().add(DelResult, "card3");

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void DelOkActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_DelOkActionPerformed
        // TODO add your handling code here:
        this.setVisible(false);
        this.dispose();
    }//GEN-LAST:event_DelOkActionPerformed

    /**
     * @param args the command line arguments
     */
    public void DelSuc()
    {
        DelResult.setVisible(true);
        success.setVisible(true);
        fail.setVisible(false);
    }
    public void DelFail()
    {
        DelResult.setVisible(true);
        success.setVisible(false);
        fail.setVisible(true);
    }
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(StDelete.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(StDelete.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(StDelete.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(StDelete.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new StDelete().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton DelOk;
    private javax.swing.JPanel DelResult;
    private javax.swing.JLabel fail;
    private javax.swing.JLabel success;
    // End of variables declaration//GEN-END:variables
}
