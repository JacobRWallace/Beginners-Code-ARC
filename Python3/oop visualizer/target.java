public class Player{
    public String name;
    private int health;

    public Player(String name, int health){
        this.name = name;
        this.health = health;
    }

    public void damage(int amount) {
        health -= amount;
    }
}