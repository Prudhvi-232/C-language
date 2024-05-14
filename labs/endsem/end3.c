#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 5
#define MAX_THEATERS 6
#define MAX_SEATS 4

void displayMovies(char movies[][50], int numMovies) {
    printf("\nAvailable Movies:\n");
    for (int i = 0; i < numMovies; ++i) {
        printf("%d. %s\n", i + 1, movies[i]);
    }
    printf("0. Exit\n");
}

void displayTheaters(char theaters[][50], int numTheaters) {
    printf("\nAvailable Theaters:\n");
    for (int i = 0; i < numTheaters; ++i) {
        printf("%d. %s\n", i + 1, theaters[i]);
    }
    printf("0. Go back\n");
}

int main() {
    FILE *file;
    char movies[MAX_MOVIES][50];
    char theaters[MAX_THEATERS][50];
    int seatRates[MAX_SEATS];
    int totalAmount = 0;

    // Read movies from CSV
    file = fopen("movies.csv", "r");
    if (file == NULL) {
        printf("Error opening movies file.\n");
        return 1;
    }
    for (int i = 0; i < MAX_MOVIES; ++i) {
        if (fscanf(file, " \"%[^\"]\"", movies[i]) != 1) {
            printf("Error reading movies file.\n");
            return 1;
        }
    }
    fclose(file);

    // Read theaters from CSV
    file = fopen("theaters.csv", "r");
    if (file == NULL) {
        printf("Error opening theaters file.\n");
        return 1;
    }
    for (int i = 0; i < MAX_THEATERS; ++i) {
        if (fscanf(file, " \"%[^\"]\"", theaters[i]) != 1) {
            printf("Error reading theaters file.\n");
            return 1;
        }
    }
    fclose(file);

    // Seat rates
    seatRates[0] = 400;
    seatRates[1] = 230;
    seatRates[2] = 200;
    seatRates[3] = 180;

    char selectedMovie[50], selectedTheater[50], selectedSeat[20];

    int movieChoice, theaterChoice, numSeats, seatChoice;
    int seatCounts[MAX_SEATS] = {0};

    printf("Welcome to the CineBooking System!\n");

    do {
        // Select movie
        displayMovies(movies, MAX_MOVIES);
        printf("Enter the number corresponding to your desired movie: ");
        scanf("%d", &movieChoice);

        if (movieChoice == 0) {
            printf("Movies bring us together, and your choice is our delight. Thank you!\n");
            break; 
        } else if (movieChoice < 0 || movieChoice > MAX_MOVIES) {
            printf("Invalid movie selection.\n");
            continue;
        }

        strcpy(selectedMovie, movies[movieChoice - 1]);

        do {
            // Select theater
            displayTheaters(theaters, MAX_THEATERS);
            printf("Enter the number corresponding to your desired theater: ");
            scanf("%d", &theaterChoice);

            if (theaterChoice == 0) {
                break; // Go back to movie selection
            } else if (theaterChoice < 0 || theaterChoice > MAX_THEATERS) {
                printf("Invalid theater selection.\n");
                continue;
            }

            strcpy(selectedTheater, theaters[theaterChoice - 1]);

            printf("Available Seat Types:\n");
            printf("1. Gold - Recliner (400)\n");
            printf("2. Premium (230)\n");
            printf("3. Classic (200)\n");
            printf("4. Silver (180)\n");
            printf("0. Go back\n");

            do {
                printf("Enter the number corresponding to your desired seat type (1-4): ");
                scanf("%d", &seatChoice);

                if (seatChoice == 0) {
                    break; // Go back to theater selection
                } else if (seatChoice < 0 || seatChoice > MAX_SEATS) {
                    printf("Invalid seat selection.\n");
                    continue;
                }

                if (seatChoice > 0 && seatChoice <= MAX_SEATS) {
                    printf("Enter the number of seats you want to book: ");
                    scanf("%d", &numSeats);

                    seatCounts[seatChoice - 1] += numSeats;
                }

            } while (1);

        } while (1);

        // Calculate total amount
        totalAmount = 0;
        for (int i = 0; i < MAX_SEATS; ++i) {
            if (seatCounts[i] > 0) {
                totalAmount += seatRates[i] * seatCounts[i];
            }
        }

        // Display final booking details
        printf("\n===========================\n");
        printf("      Booking Details\n");
        printf("===========================\n");
        printf("Movie: %s\n", selectedMovie);
        printf("Theater: %s\n", selectedTheater);
        for (int i = 0; i < MAX_SEATS; ++i) {
            if (seatCounts[i] > 0) {
                printf("Number of %s Seats: %d\n", (i == 0) ? "Gold - Recliner" : (i == 1) ? "Premium" : (i == 2) ? "Classic" : "Silver", seatCounts[i]);
            }
        }
        printf("Total Amount: %d\n", totalAmount);
        printf("===========================\n");

    } while (1);

    return 0;
}
