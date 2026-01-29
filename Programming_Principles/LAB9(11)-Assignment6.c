#include<stdio.h>
#include<string.h>
#include<time.h>

#define MAXROOMS 20

struct Room {
    int roomNumber;
    int roomStatus;
    int roomType;
    char username[100];
    char lastName[100];
    char emailAdd[100];
    char address[100];
    char telephone[100];
    int checkInDay;
    int checkInMonth;
    int checkInYear;
    int checkOutDay;
    int checkOutMonth;
    int checkOutYear;
};

//functions --------------------------------------------------------------------------------------------------------------------
int findRoomIndex(struct Room *rooms, int roomNumber) {
    for (int i = 0; i < MAXROOMS; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            return i;
        }
    }
    return -1;
}

void bookRoom(struct Room *rooms) {
    int roomNumber;
    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);

    int roomType;
    printf("Normal = 0\n");
    printf("Deluxe = 1\n");
    printf("Enter Room Type: ");
    scanf("%d", &roomType);

    int index = findRoomIndex(rooms, roomNumber);

    if (index != -1) {
        if (rooms[index].roomStatus == 0) {
            if (rooms[index].roomType == roomType) {
                printf("Username: ");
                scanf("%s", rooms[index].username);
                printf("Last Name: ");
                scanf("%s", rooms[index].lastName);
                printf("Email Address: ");
                scanf("%s", rooms[index].emailAdd);
                printf("Address: ");
                scanf("%s", rooms[index].address);
                printf("Telephone Number: ");
                scanf("%s", rooms[index].telephone);

                // Input Check-in Date (Month Day Year)
                printf("Enter Check-in Date (Month Day Year): ");
                scanf("%d %d %d", &rooms[index].checkInMonth, &rooms[index].checkInDay, &rooms[index].checkInYear);

                if (rooms[index].checkInMonth < 1 || rooms[index].checkInMonth > 12 ||
                    rooms[index].checkInDay < 1 || rooms[index].checkInDay > 30) {
                    printf("Error: Invalid date. Please enter a valid date.\n");
                    return;
                }

                // Input Check-out Date (Month Day Year)
                printf("Enter Check-out Date (Month Day Year): ");
                scanf("%d %d %d", &rooms[index].checkOutMonth, &rooms[index].checkOutDay, &rooms[index].checkOutYear);

                if (rooms[index].checkOutMonth < 1 || rooms[index].checkOutMonth > 12 ||
                    rooms[index].checkOutDay < 1 || rooms[index].checkOutDay > 30 ||
                    (rooms[index].checkOutYear < rooms[index].checkInYear) ||
                    (rooms[index].checkOutYear == rooms[index].checkInYear && rooms[index].checkOutMonth < rooms[index].checkInMonth) ||
                    (rooms[index].checkOutYear == rooms[index].checkInYear && rooms[index].checkOutMonth == rooms[index].checkInMonth && rooms[index].checkOutDay <= rooms[index].checkInDay)) {
                    printf("Error: Invalid check-out date. Check-out date must be after check-in date.\n");
                    return;
                }

                rooms[index].roomStatus = 1; // Marks room as reserved
                printf("Room #%d booked successfully.\n", rooms[index].roomNumber);
            } else {
                printf("NOTICE!\n");
                printf("Normal rooms are Rooms 1-10!\n");
                printf("Deluxe rooms are Rooms 11-20!\n\n");
            }
        } else {
            printf("Room is vacant!\n");
        }
    } else {
        printf("Invalid Room #!\n");
    }
}


void viewCustomerDetails(struct Room *rooms) {
    int roomNumber;
    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);

    int index = findRoomIndex(rooms, roomNumber);

    if (index != -1) {
        if (rooms[index].roomStatus == 1) {
            printf("Customer Details:\n");
            printf("Username: %s\n", rooms[index].username);
            printf("Last Name: %s\n", rooms[index].lastName);
            printf("Email Address: %s\n", rooms[index].emailAdd);
            printf("Address: %s\n", rooms[index].address);
            printf("Telephone Number: %s\n", rooms[index].telephone);
            printf("Check-in Date: %d-%d-%d\n", rooms[index].checkInMonth, rooms[index].checkInDay, rooms[index].checkInYear);
            printf("Check-out Date: %d-%d-%d\n", rooms[index].checkOutMonth, rooms[index].checkOutDay, rooms[index].checkOutYear);

        } else {
            printf("Room is vacant!\n");
        }
    } else {
        printf("Invalid Room #!\n");
    }
}

void editCustomerDetails(struct Room *rooms){
    int roomNumber;
    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);

    int index = findRoomIndex(rooms, roomNumber);

    if (index != -1) {
        if (rooms[index].roomStatus == 1) {
            printf("Enter new customer details for Room %d:\n", rooms[index].roomNumber);
            printf("Username: ");
            scanf("%s", rooms[index].username);
            printf("Last Name: ");
            scanf("%s", rooms[index].lastName);
            printf("Email Address: ");
            scanf("%s", rooms[index].emailAdd);
            printf("Address: ");
            scanf("%s", rooms[index].address);
            printf("Telephone Number: ");
            scanf("%s", rooms[index].telephone);

            printf("Customer details updated successfully.\n");
        } else {
            printf("Room is vacant!\n");
        }
    } else {
        printf("Invalid Room #!\n\n");
    }
}

void checkOutf(struct Room *rooms) {
    int roomNumber;
    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);

    int index = findRoomIndex(rooms, roomNumber);

    if (index != -1) {
        if (rooms[index].roomStatus == 1) {
            int dayRate = (rooms[index].roomType == 0) ? 50 : 80;

            // Calculate the number of days stayed
            int checkInDays = rooms[index].checkInYear * 365 + rooms[index].checkInMonth * 30 + rooms[index].checkInDay;
            int checkOutDays = rooms[index].checkOutYear * 365 + rooms[index].checkOutMonth * 30 + rooms[index].checkOutDay;
            int daysStayed = checkOutDays - checkInDays;

            int totalBill = daysStayed * dayRate;

            printf("Bill for Room %d:\n", rooms[index].roomNumber);
            printf("Number of days stayed: %d\n", daysStayed);
            printf("Room type: %s\n", (rooms[index].roomType == 0) ? "Normal" : "Deluxe");
            printf("Day rate: $%d\n", dayRate);
            printf("Total bill: $%d\n", totalBill);

            rooms[index].roomStatus = 0; // Mark room as vacant
            printf("Check-out successful!\n");
        } else {
            printf("Room is vacant!\n");
        }
    } else {
        printf("Invalid Room #!\n");
    }
}

void viewReport(struct Room *rooms){
    printf("Room Report:\n");
    printf("%-15s %-15s %-15s %-15s %-15s\n", "Room Number", "Status", "Room Type", "Customer Name", "Last Name");
    //%-15s formats the print with space.
    //'-' means it will specify left justification.
    //'15' is the minimal field width.
    //'s' is string; the type of value to be printed.

    for (int i = 0; i < 20; i++) {
        printf("%-15d %-15s %-15s %-15s %-15s\n", rooms[i].roomNumber,
               (rooms[i].roomStatus == 1) ? "Reserved" : "Vacant",
               (rooms[i].roomType == 0) ? "Normal" : "Deluxe",
               (rooms[i].roomStatus == 1) ? rooms[i].username : "-",
               (rooms[i].roomStatus == 1) ? rooms[i].lastName : "-");
    }
}


void main(){

//initialize 20 rooms with info
struct Room rooms[MAXROOMS];//creates array of 20 elements with all data structure entities of struct Room but empty.
for (int i = 0; i<MAXROOMS; i++){
    rooms[i].roomNumber = i + 1;
    rooms[i].roomStatus = 0;
    rooms[i].roomType = i<10 ? 0 : 1;
}

char menuoption;

printf("Menu Options:\n");
printf("[B] = Book a Room\n");
printf("[V] = View Customer Details\n");
printf("[E] = Edit Customer Details\n");
printf("[C] = Check-out and Print Bill\n");
printf("[A] = View Room Report\n");
printf("[X] = Exit Program\n\n");

while(1){
    printf("Enter Option:");
    scanf(" %c",&menuoption);

    switch(menuoption){
    case('B'):
    case('b'):
        bookRoom(rooms);
    break;
    case('V'):
    case('v'):
        viewCustomerDetails(rooms);
    break;
    case('E'):
    case('e'):
        editCustomerDetails(rooms);
    break;
    case('C'):
    case('c'):
        checkOutf(rooms);
    break;
    case('A'):
    case('a'):
        viewReport(rooms);
    break;
    case('X'):
    case('x'):
        printf("Exiting program.\n");
        return;
    break;
    default:
        printf("Error: Invalid Option!");

    }//switch
    }//while

}//main
