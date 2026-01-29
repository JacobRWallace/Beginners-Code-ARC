package package1;

import java.util.Scanner;

public class WiFiConnection {

    public static void main(String[] args) {
        
        String[] text = {
            "Did that fix the problem? ",  // Question to check if the problem is fixed
            "Reboot the computer and try to connect.",  // Step 1
            "Reboot the router and try to connect.",    // Step 2
            "Make sure the cables between the router & modem are plugged in firmly.", // Step 3
            "Move the router to a new location and try to connect.",  // Step 4
            "Get a new router.",  // Step 5
            "Computer is fixed."  // Success message
        };

        Scanner scanner = new Scanner(System.in);

        // Step 1: Reboot computer
        System.out.println(text[1]);
        System.out.print(text[0]);
        if (scanner.next().equalsIgnoreCase("no")) {
            
            // Step 2: Reboot router
            System.out.println(text[2]);
            System.out.print(text[0]);
            if (scanner.next().equalsIgnoreCase("no")) {
                
                // Step 3: Check cables
                System.out.println(text[3]);
                System.out.print(text[0]);
                if (scanner.next().equalsIgnoreCase("no")) {
                    
                    // Step 4: Move the router
                    System.out.println(text[4]);
                    System.out.print(text[0]);
                    if (scanner.next().equalsIgnoreCase("no")) {
                        
                        // Step 5: Get a new router
                        System.out.println(text[5]);
                    } else {
                        System.out.println(text[6]);  // Computer is fixed at step 4
                    }
                } else {
                    System.out.println(text[6]);  // Computer is fixed at step 3
                }
            } else {
                System.out.println(text[6]);  // Computer is fixed at step 2
            }
        } else {
            System.out.println(text[6]);  // Computer is fixed at step 1
        }

        scanner.close();  // Close scanner to prevent resource leaks
    }
}
