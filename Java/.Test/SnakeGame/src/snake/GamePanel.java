package snake;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.List;

public class GamePanel extends JPanel implements ActionListener, KeyListener {
    static final int CELL_SIZE = 20;
    static final int GRID_W = 30;
    static final int GRID_H = 20;
    static final int PREF_W = CELL_SIZE * GRID_W;
    static final int PREF_H = CELL_SIZE * GRID_H;

    private Snake snake;
    private Food food;
    private Timer timer;
    private boolean running = false;
    private int score = 0;

    public GamePanel() {
        setPreferredSize(new Dimension(PREF_W, PREF_H));
        setBackground(Color.BLACK);
        setFocusable(true);
        addKeyListener(this);
        snake = new Snake(GRID_W / 2, GRID_H / 2);
        food = new Food(GRID_W, GRID_H);
        food.respawn(snake);
        timer = new Timer(120, this);
    }

    public void startGame() {
        running = true;
        timer.start();
        requestFocusInWindow();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (running) {
            snake.move();
            if (snake.getHead().equals(food.getLocation())) {
                snake.grow();
                score++;
                food.respawn(snake);
            }
            if (!inBounds(snake.getHead()) || snake.isCollidingWithSelf()) {
                running = false;
                timer.stop();
            }
        }
        repaint();
    }

    private boolean inBounds(Point p) {
        return p.x >= 0 && p.x < GRID_W && p.y >= 0 && p.y < GRID_H;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        // draw grid
        g.setColor(Color.DARK_GRAY);
        for (int x = 0; x <= PREF_W; x += CELL_SIZE)
            g.drawLine(x, 0, x, PREF_H);
        for (int y = 0; y <= PREF_H; y += CELL_SIZE)
            g.drawLine(0, y, PREF_W, y);

        // draw food
        g.setColor(Color.RED);
        g.fillOval(food.getLocation().x * CELL_SIZE, food.getLocation().y * CELL_SIZE, CELL_SIZE, CELL_SIZE);

        // draw snake
        g.setColor(Color.GREEN);
        for (Point p : snake.getBody()) {
            g.fillRect(p.x * CELL_SIZE, p.y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
        }

        // score and status
        g.setColor(Color.WHITE);
        g.drawString("Score: " + score, 5, 15);
        if (!running) {
            g.setFont(g.getFont().deriveFont(24f));
            g.drawString("Game Over - Press R to restart", PREF_W / 2 - 150, PREF_H / 2);
        }
    }

    // KeyListener methods
    @Override
    public void keyPressed(KeyEvent e) {
        int k = e.getKeyCode();
        if (k == KeyEvent.VK_R && !running) {
            reset();
        } else if (k == KeyEvent.VK_UP) {
            snake.setDirection(Direction.UP);
        } else if (k == KeyEvent.VK_DOWN) {
            snake.setDirection(Direction.DOWN);
        } else if (k == KeyEvent.VK_LEFT) {
            snake.setDirection(Direction.LEFT);
        } else if (k == KeyEvent.VK_RIGHT) {
            snake.setDirection(Direction.RIGHT);
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
    }

    @Override
    public void keyTyped(KeyEvent e) {
    }

    private void reset() {
        snake = new Snake(GRID_W / 2, GRID_H / 2);
        food.respawn(snake);
        score = 0;
        running = true;
        timer.start();
        requestFocusInWindow();
    }
}
