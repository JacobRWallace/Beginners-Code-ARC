package snake;

import javax.swing.JFrame;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Snake - .Test Demo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GamePanel panel = new GamePanel();
        frame.add(panel);
        frame.pack();
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        panel.startGame();
    }
}
