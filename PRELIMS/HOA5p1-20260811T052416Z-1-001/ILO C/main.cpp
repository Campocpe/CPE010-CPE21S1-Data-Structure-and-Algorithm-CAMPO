#include <iostream>
#include <string>
#include "PrinterSystem.h"

// Helper function to safely read integers without extra library headers
int getValidInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        } else {
            std::cout << "Invalid input! Please enter a numeric value.\n";
            std::cin.clear(); // Reset cin error flag
            while (std::cin.get() != '\n'); // Loop to read and discard bad characters until newline
        }
    }
}

int main() {
    int capInput = getValidInt("Enter Printer Queue Capacity: ");
    while (capInput <= 0) {
        std::cout << "Capacity must be greater than 0.\n";
        capInput = getValidInt("Enter Printer Queue Capacity: ");
    }

    Printer officePrinter(static_cast<size_t>(capInput));

    int choice = 0;
    do {
        std::cout << "\n========== PRINTER SYSTEM MENU ==========\n";
        std::cout << "1. Add Print Job\n";
        std::cout << "2. Process Next Job\n";
        std::cout << "3. Process All Jobs\n";
        std::cout << "4. View Queue Status\n";
        std::cout << "5. Exit\n";

        choice = getValidInt("Enter choice (1-5): ");

        switch (choice) {
            case 1: {
                int id = getValidInt("\nEnter Job ID: ");

                std::string userName;
                std::cout << "Enter User Name: ";
                while (std::cin.get() != '\n'); // Clear trailing newline left by integer input
                std::getline(std::cin, userName);

                int pages = getValidInt("Enter Number of Pages: ");

                officePrinter.addJob(Job(id, userName, pages));
                break;
            }
            case 2:
                officePrinter.processNextJob();
                break;
            case 3:
                officePrinter.processAllJobs();
                break;
            case 4:
                std::cout << "\nQueue Status: " << officePrinter.getPendingCount()
                          << " / " << officePrinter.getCapacity() << " jobs pending.\n";
                break;
            case 5:
                std::cout << "\nExiting Printer Simulation.\n";
                break;
            default:
                std::cout << "\nInvalid choice! Please enter a number from 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}