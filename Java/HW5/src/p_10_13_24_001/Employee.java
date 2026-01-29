package p_10_13_24_001;

/**
 * The Employee class represents an employee with a name, ID number, department, and job position.
 * Contains constructors to initialize fields along with accessor and mutator methods to get and set their values.
 * 
 * @author Jacob Wallace
 * @date 10/13/2024
 */
public class Employee {
    
    //variable store employee's name
    private String name;
    
    //variable store employee's ID number
    private int idNumber;
    
    //variable store employee's department
    private String department;
    
    //variable store employee's position
    private String position;

    /**
     * Constructor that initializes the employee object with name, ID, department, and position.
     * @param name - employee's name
     * @param idNumber - employee's ID number
     * @param department - employee's department
     * @param position - employee's job position
     */
    public Employee(String name, int idNumber, String department, String position) {
        this.name = name; //Set name to the object's field
        this.idNumber = idNumber; //Set idNumber to the object's field
        this.department = department; //Set department to the object's field
        this.position = position; //Set position to the object's field
    }

    /**
     * Constructor that initializes the employee object with name and ID.
     * Also setting department and position to an empty string.
     * @param name - employee's name
     * @param idNumber - employee's ID number
     */
    public Employee(String name, int idNumber) {
        this.name = name; //Set name to the object's field
        this.idNumber = idNumber; //Set idNumber to the object's field
        this.department = ""; //Set department to the object's field
        this.position = ""; //Set position to the object's field
    }

    /**
     * No argument constructor. Initializes all fields with default values.
     * Sets name, department, and position to a empty string along with idNumber to 0.
     */
    public Employee() {
        this.name = ""; //Set name to the object's field
        this.idNumber = 0; //Set idNumber to the object's field
        this.department = ""; //Set department to the object's field
        this.position = ""; //Set position to the object's field
    }

    //Mutator setter method
    public void setName(String name) {
        this.name = name;
    }

    //Accessor getter method
    public String getName() {
        return this.name;
    }

    //Mutator setter method
    public void setIdNumber(int idNumber) {
        this.idNumber = idNumber;
    }

    //Accessor getter method
    public int getIdNumber() {
        return this.idNumber;
    }

    //Mutator setter method
    public void setDepartment(String department) {
        this.department = department;
    }

    //Accessor getter method
    public String getDepartment() {
        return this.department;
    }

    //Mutator setter method
    public void setPosition(String position) {
        this.position = position;
    }

    //Accessor getter method
    public String getPosition() {
        return this.position;
    }
}
