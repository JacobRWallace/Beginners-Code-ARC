package snake;

import java.awt.Point;
import java.util.Random;

public class Food {
    private Point loc;
    private int w, h;
    private Random rnd = new Random();

    public Food(int w, int h) {
        this.w = w;
        this.h = h;
    }

    public void respawn(Snake snake) {
        while (true) {
            int x = rnd.nextInt(w);
            int y = rnd.nextInt(h);
            Point p = new Point(x, y);
            boolean onSnake = false;
            for (Point s : snake.getBody()) {
                if (s.equals(p)) {
                    onSnake = true;
                    break;
                }
            }
            if (!onSnake) {
                loc = p;
                return;
            }
        }
    }

    public Point getLocation() {
        return loc;
    }
}
