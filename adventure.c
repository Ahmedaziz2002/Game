#include <stdio.h>
#include <stdlib.h>

void introduction() {
    printf("You wake up in a strange house. The air is thick with dust, and you can hear faint noises coming from somewhere in the house.\n");
    printf("You must make important decisions to stay alive.\n");
}

void first_choice() {
    int choice;
    printf("\nYou see two doors: one on the left and one on the right.\n");
    printf("1. Go through the left door.\n");
    printf("2. Go through the right door.\n");
    printf("What do you choose? (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou enter a room filled with old furniture. Suddenly, a ghost appears!\n");
        printf("You have two options:\n");
        printf("1. Try to communicate with the ghost.\n");
        printf("2. Run back to the hallway.\n");
        int ghost_choice;
        printf("What do you choose? (1 or 2): ");
        scanf("%d", &ghost_choice);

        if (ghost_choice == 1) {
            printf("\nThe ghost was friendly! It helps you find an exit. You are safe!\n");
        } else {
            printf("\nYou run back, but the ghost follows you! You trip and fall. Game Over.\n");
        }
    } else if (choice == 2) {
        printf("\nYou find yourself in a kitchen with a strange smell. There is a knife on the table.\n");
        printf("1. Take the knife for protection.\n");
        printf("2. Leave the kitchen quickly.\n");
        int kitchen_choice;
        printf("What do you choose? (1 or 2): ");
        scanf("%d", &kitchen_choice);

        if (kitchen_choice == 1) {
            printf("\nYou take the knife. Suddenly, a stranger enters the kitchen!\n");
            printf("1. Confront the stranger with the knife.\n");
            printf("2. Hide behind the door.\n");
            int stranger_choice;
            printf("What do you choose? (1 or 2): ");
            scanf("%d", &stranger_choice);

            if (stranger_choice == 1) {
                printf("\nThe stranger is scared of you! He tells you he was trapped here too and offers to help you escape!\n");
                printf("You both find a way out together. You are safe!\n");
            } else {
                printf("\nThe stranger finds you hiding and thinks you're a threat! He attacks you. Game Over.\n");
            }
        } else {
            printf("\nAs you leave the kitchen, you hear footsteps behind you. It's too late! Game Over.\n");
        }
    } else {
        printf("\nInvalid choice! Please restart the game and choose 1 or 2.\n");
    }
}

int main() {
    introduction();
    first_choice();
    
    return 0;
}