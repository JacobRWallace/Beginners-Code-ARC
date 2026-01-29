package snake;

import java.awt.Point;
import java.util.LinkedList;
import java.util.List;

public class Snake {
    private LinkedList<Point> body = new LinkedList<>();
    private Direction dir = Direction.RIGHT;
    private boolean grow = false;

    public Snake(int startX, int startY) {
        body.add(new Point(startX, startY));
        body.add(new Point(startX - 1, startY));
        body.add(new Point(startX - 2, startY));
    }

    public void setDirection(Direction d) {
        // Prevent reversing direction
        if ((dir == Direction.LEFT && d == Direction.RIGHT) || (dir == Direction.RIGHT && d == Direction.LEFT)
                || (dir == Direction.UP && d == Direction.DOWN) || (dir == Direction.DOWN && d == Direction.UP))
            return;
        dir = d;
    }

    public void move() {
        Point head = body.getFirst();
        Point newHead = new Point(head);
        switch (dir) {
            case UP:
                newHead.y -= 1;
                break;
            case DOWN:
                newHead.y += 1;
                break;
            case LEFT:
                newHead.x -= 1;
                break;
            case RIGHT:
                newHead.x += 1;
                break;
        }
        body.addFirst(newHead);
        if (!grow)
            body.removeLast();
        else
            grow = false;
    }

    public void grow() {
        grow = true;
    }

    public boolean isCollidingWithSelf() {
        Point head = body.getFirst();
        for (int i = 1; i < body.size(); i++) {
            if (head.equals(body.get(i)))
                return true;
        }
        return false;
    }

    public Point getHead() {
        return body.getFirst();
    }

    public List<Point> getBody() {
        return body;
    }
}
