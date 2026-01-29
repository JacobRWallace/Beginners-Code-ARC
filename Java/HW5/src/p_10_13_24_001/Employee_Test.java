package p_10_13_24_001;

public class Employee_Test {
    public static void main(String[] args) {
        
        //create employee objects
        Employee employee1 = new Employee("Susan Meyers", 47899, "Accounting", "Vice President");
        Employee employee2 = new Employee("Mark Jones", 39119, "IT", "Programmer");
        Employee employee3 = new Employee("Joy Rogers", 81774, "Manufacturing", "Engineer");

        //print employee details
        System.out.println("Employee 1: " + employee1.getName() + ", " + employee1.getIdNumber() + 
                           ", " + employee1.getDepartment() + ", " + employee1.getPosition());
        
        System.out.println("Employee 2: " + employee2.getName() + ", " + employee2.getIdNumber() + 
                           ", " + employee2.getDepartment() + ", " + employee2.getPosition());
        
        System.out.println("Employee 3: " + employee3.getName() + ", " + employee3.getIdNumber() + 
                           ", " + employee3.getDepartment() + ", " + employee3.getPosition());
    }
}
