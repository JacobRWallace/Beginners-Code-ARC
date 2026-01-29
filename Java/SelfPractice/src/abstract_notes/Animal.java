package abstract_notes;

abstract class Animal {
    String name;

    // Constructor
    public Animal(String name) {
        this.name = name;
    }

    // Abstract method (must be implemented by subclasses)
    abstract void makeSound();

    // Concrete method (can be used by subclasses as-is)
    public void sleep() {
        System.out.println(name + " is sleeping.");
    }
}

class Dog extends Animal {
    public Dog(String name) {
        super(name);
    }

    @Override
    void makeSound() {
        System.out.println(name + " barks.");
    }
}

class Cat extends Animal {
    public Cat(String name) {
        super(name);
    }

    @Override
    void makeSound() {
        System.out.println(name + " meows.");
    }
}
