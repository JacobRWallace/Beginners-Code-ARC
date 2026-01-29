package abstract_notes;

public class some {

	interface Movable {
	    void move(); // Abstract method
	}

	interface SoundMaker {
	    void makeSound(); // Abstract method
	}

	class Car implements Movable {
	    @Override
	    public void move() {
	        System.out.println("The car is moving.");
	    }
	}

	class Dog implements Movable, SoundMaker {
	    @Override
	    public void move() {
	        System.out.println("The dog is running.");
	    }

	    @Override
	    public void makeSound() {
	        System.out.println("The dog barks.");
	    }
	}

}
