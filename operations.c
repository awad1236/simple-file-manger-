/*
 *  Created by : Mohamed Awad
 *  Date       : 9/5/2024.
*/

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"


// Function to set text color
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Function to create a loading animation
void loadingAnimation(const char* message, int duration) {
    printf("%s", message);
    for (int i = 0; i < duration; ++i) {
        printf(".");
        fflush(stdout); // Forces the print to appear immediately
        Sleep(500);
    }
    printf("\n");
}

void listFiles(char* directory) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(strcat(directory, "\\*"), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);  // Red for error
        printf("Invalid directory path.\n");
        setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // Reset to default
        return;
    }

    loadingAnimation("Listing files", 4);

    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);  // Green for directory list
    printf("Files in directory: %s\n", directory);
    do {
        const char* name = findFileData.cFileName;
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);  // Blue for directories
            printf("[DIR]  %s\n", name);
        } else {
            setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);  // Green for files
            printf("       %s\n", name);
        }
        Sleep(500);
    } while (FindNextFile(hFind, &findFileData) != 0);

    setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // Reset to default
    FindClose(hFind);
}

void createFile(char* filePath) {
    loadingAnimation("Creating file", 3);

    HANDLE hFile = CreateFile(
            filePath,
            GENERIC_WRITE,
            0,
            NULL,
            CREATE_NEW,
            FILE_ATTRIBUTE_NORMAL,
            NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);  // Red for error
        printf("Could not create file (error %d)\n", GetLastError());
    } else {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);  // Green for success
        printf("File created successfully: %s\n", filePath);
        CloseHandle(hFile);
    }
    setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // Reset to default
}

void deleteFile(char* filePath) {
    loadingAnimation("Deleting file", 3);

    if (DeleteFile(filePath)) {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);  // Green for success
        printf("File deleted successfully: %s\n", filePath);
    } else {
        setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);  // Red for error
        printf("Could not delete file (error %d)\n", GetLastError());
    }
    setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // Reset to default
}