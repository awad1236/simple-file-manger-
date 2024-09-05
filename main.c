
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"
#include <stdlib.h>


int main() {
    int choice;
    char path[260];

    while (1) {
        // Clear the screen before showing the menu
        system("cls");

        setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);  // Blue for menu heading
        printf("Loading File Manager Options...\n");

        loadingAnimation("", 3); // Animation when loading the menu

        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);  // Green for options
        printf("1. List files in directory\n");
        printf("2. Create a file\n");
        printf("3. Delete a file\n");
        printf("4. Exit\n");

        setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // Reset to default
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear the screen before performing any action
        system("cls");

        switch (choice) {
            case 1:
                printf("Enter directory path: ");
                scanf("%s", path);
                system("cls"); // Clear the screen before listing files
                listFiles(path);
                break;
            case 2:
                printf("Enter file path to create: ");
                scanf("%s", path);
                createFile(path);
                break;
            case 3:
                printf("Enter file path to delete: ");
                scanf("%s", path);
                deleteFile(path);
                break;
            case 4:
                setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);  // Green for exit message
                loadingAnimation("Exiting the program", 4); // Animation before exit
                return 0;
            default:
                setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);  // Red for invalid choice
                printf("Invalid choice, try again.\n");
                setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // Reset to default
                Sleep(2000); // Pause for a moment before returning to the menu
        }

        // Pause before returning to menu
        printf("\nReturning to the menu in 2 seconds...\n");
        Sleep(2000);  // Pause for 2 seconds before returning to the menu
    }

    return 0;
}
