#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Defining the linked list node structure
typedef struct Node {
    int guess;
    struct Node* next;
} Node;

// Implementing functions
//creating new node
Node* createNode(int guess) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->guess = guess;
    newNode->next = NULL;
    return newNode;
}

// Adding guess to the linked list
void addGuess(Node** head, int guess) {
    Node* newNode = createNode(guess);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Displaying the guess
void displayGuesses(Node* head) {
    if (head == NULL) {
        printf("No guesses yet.\n");
        return;
    }
    Node* temp = head;
    printf("Your guesses:\n");
    while (temp != NULL) {
        printf("%d\n", temp->guess);
        temp = temp->next;
    }
}
//Main function
int main() {
    Node* guesses = NULL;
    int numberToGuess = 92; // Number to guess(can be changed)
    int guess;
    char command[50];

    printf("Welcome to the No. Guessing Game!\n");
    printf("Guess the number b/w 1 & 100\n");

    while (1) {
        printf("Enter your guess OR type 'show' to see all guesses / 'exit' to quit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the game Sayonara!\n");
            break;
        } else if (strcmp(command, "show") == 0) {
            displayGuesses(guesses);
        } else {
            guess = atoi(command);
            addGuess(&guesses, guess);
            if (guess < numberToGuess) {
                printf("Oops!Too low Try again\n");
            } else if (guess > numberToGuess) {
                printf("Oops!Too high Try again\n");
            } else {
                printf("Congrats! You guessed the number\n");
                break;
            }
        }
    }


    return 0;
}
