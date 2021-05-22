import java.awt.event.*;  
import javax.swing.*;   

public class ButtonActionListener implements ActionListener {

    private JTextField textField;

    public ButtonActionListener(JTextField tf){
        this.textField = tf;
    }

    public void actionPerformed(java.awt.event.ActionEvent arg0){
        this.textField.setText("Ciao a tutti");
    }
}