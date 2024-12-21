#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 5

typedef struct {
    char *items[MAX_ITEMS];
    int count;
} Inventory;

void addItem(Inventory *inv, char *item) {
    if (inv->count < MAX_ITEMS) {
        inv->items[inv->count++] = item;
        printf("You have picked up: %s\n", item);
    } else {
        printf("Your inventory is full!\n");
    }
}

void displayInventory(Inventory *inv) {
    printf("Your inventory contains:\n");
    for (int i = 0; i < inv->count; i++) {
        printf("- %s\n", inv->items[i]);
    }
}

void TheVerandah(Inventory *inv) {
    printf("WELCOME TO THE VERANDAH\nYou see a board displaying the message.\nA fine woman approaches you and gives you a choice.\n1. A gun\n2. A lollipop.\nShe then tells you that one of the things will be important for you as you go to the desert on your way out.\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("The gun helped you fight the enemies like a true soldier. You save your way out! Hurray\n");
            addItem(inv, "Gun");
            break;
        case 2:
            printf("A lollipop? Are you serious? Pass my greeting to the dead in heaven!\n");
            addItem(inv, "Lollipop");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

void TheHall(Inventory *inv) {
    printf("After choosing the blue door, you find yourself in a big hall full of zombies.\nYou have to make a decision:\n1. Rattle the zombies and fight them all (Very little chance of success!)\n2. Run away and the zombies follow you and kill you.\n3. Sing the zombie song (Only known by soldiers)\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Oh my God! You rattled them. That was a cruel death as the zombies pile up on you and eat your brains out!\n");
            break;
        case 2:
            printf("You were almost out through the door and then you are dead.\n");
            break;
        case 3:
            printf("The zombies always give in to their song and they let you out. Their chief guides you out.\n");
            break;
        default:
            printf("Invalid choice. Enter 1, 2, or 3.\n");
            break;
    }
}

void House(Inventory *inv) {
    printf("\tWELCOME TO THE Q-HOUSE\n");
    int door;
    printf("You are faced with two doors.\n1. A blue door\n2. A red door\nChoose one door to go through. Once you go in there's no coming out through the same door. Be wise!\n");
    scanf("%d", &door);
    switch (door) {
        case 1:
            TheHall(inv);
            break;
        case 2:
            TheVerandah(inv);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

int main() {
    Inventory playerInventory = {.count = 0};

    printf("Hello there. You came here to ask for trouble didn't you!\n");
    char response[100];
    scanf("%s", response);

    printf("It doesn't matter what you say! '%s' nah nah WE have to test you!\n", response);
    
    House(&playerInventory);

    // Display inventory at the end
    displayInventory(&playerInventory);

    return 0;
}
