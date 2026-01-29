package ClassWork103024;

public class TTU_StudentDemo {
    public static void main(String[] args) {
        
        // Create a TTU_Student object
        TTU_Student student1 = new TTU_Student();
        
        // Setting properties for the student object
        student1.setName("John Doe");
        student1.setScore(88.5);
        student1.setPassFail(true);
        student1.setCollege("Texas Tech University");
        student1.setID(123456);

        // Display student1's information
        System.out.println("Details of student1:");
        student1.display();
        System.out.println();

        // Using polymorphism: create reference variables for TTU_st, TTU_st1, TTU_st2
        TTU_st student2 = new TTU_Student();
        TTU_st1 student3 = new TTU_Student();
        TTU_st2 student4 = new TTU_Student();

        // Assigning values to student2 using TTU_st reference
        student2.setName("Jane Smith");
        student2.setScore(92.0);

        // Displaying information using the TTU_st reference
        System.out.println("Details of student2 (TTU_st reference):");
        System.out.println("Name: " + ((TTU_Student) student2).getName());
        System.out.println("Score: " + student2.getScore());
        System.out.println();

        // Assigning values to student3 using TTU_st1 reference
        student3.setName("Alice Brown");
        student3.setScore(75.5);

        // Displaying information using the TTU_st1 reference
        System.out.println("Details of student3 (TTU_st1 reference):");
        System.out.println("Name: " + ((TTU_Student) student3).getName());
        System.out.println("Score: " + student3.getScore());
        System.out.println();

        // Assigning values to student4 using TTU_st2 reference
        student4.setID(654321);

        // Displaying information using the TTU_st2 reference
        System.out.println("Details of student4 (TTU_st2 reference):");
        System.out.println("ID: " + student4.getID());
        student4.display(); // Calls default display method from TTU_st2 interface
    }
}
