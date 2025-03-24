
#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

// Structure to represent the parking garage
typedef struct {
    bool slots[ROWS][COLS];  
} ParkingGarage;

// Function to initialize the parking garage
void initializeParkingGarage(ParkingGarage *garage) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            garage->slots[i][j] = false;  
        }
    }
}

// Function to allocate a parking slot
int allocateParkingSlot(ParkingGarage *garage) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!garage->slots[i][j]) {  
                garage->slots[i][j] = true; 
                return i * COLS + j;  
            }
        }
    }
    return -1;  
}

// Function to update the status of a parking slot
void updateParkingSlot(ParkingGarage *garage, int slotIndex, bool status) {
    if (slotIndex >= 0 && slotIndex < ROWS * COLS) { 
        int row = slotIndex / COLS;  
        int col = slotIndex % COLS;  
        garage->slots[row][col] = status;  
    } else {
        printf("Invalid slot index!\n");
    }
}

// Function to display available parking slots
void getAvailableParkingSlots(ParkingGarage *garage) {
    printf("Available Slots:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!garage->slots[i][j]) {  
                printf("Slot (%d, %d) is available.\n", i, j);
            }
        }
    }
}

// Function to visually display the parking garage
void displayParkingGarage(ParkingGarage *garage) {
    printf("\nParking Garage Layout:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", garage->slots[i][j] ? 'X' : 'O'); 
        }
        printf("\n");
    }
}

// Main function with a menu-driven approach
int main() {
    ParkingGarage garage;
    initializeParkingGarage(&garage);  

    int choice;
    while (1) {
        printf("\nSmart Parking System\n");
        printf("1. View Available Slots\n");
        printf("2. Allocate Parking Slot\n");
        printf("3. Free a Parking Slot\n");
        printf("4. Display Parking Garage\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            getAvailableParkingSlots(&garage);
        } else if (choice == 2) {
            int allocatedSlot = allocateParkingSlot(&garage);
            if (allocatedSlot != -1) {
                printf("Allocated Slot: (%d, %d)\n", allocatedSlot / COLS, allocatedSlot % COLS);
            } else {
                printf("No available slots.\n");
            }
        } else if (choice == 3) {
            int slotRow, slotCol;
            printf("Enter row and column of the slot to free (e.g., 1 2): ");
            scanf("%d %d", &slotRow, &slotCol);
            int slotIndex = slotRow * COLS + slotCol;
            updateParkingSlot(&garage, slotIndex, false);
            printf("Slot (%d, %d) is now available.\n", slotRow, slotCol);
        } else if (choice == 4) {
            displayParkingGarage(&garage);
        } else if (choice == 5) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
