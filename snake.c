#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_LENGTH 100

typedef struct {
    int x[MAX_LENGTH];
    int y[MAX_LENGTH];
    int length;
    char direction;
} Snake;

typedef struct {
    int x;
    int y;
} Food;

void init_game(Snake *snake, Food *food) {
    snake->length = 1;
    snake->x[0] = WIDTH / 2;
    snake->y[0] = HEIGHT / 2;
    snake->direction = 'r'; // Start moving right

    food->x = rand() % WIDTH;
    food->y = rand() % HEIGHT;
}

void draw_border() {
    for (int i = 0; i < WIDTH + 2; i++) {
        mvprintw(0, i, "#");
        mvprintw(HEIGHT + 1, i, "#");
    }
    for (int i = 0; i < HEIGHT + 2; i++) {
        mvprintw(i + 1, 0, "#");
        mvprintw(i + 1, WIDTH + 1, "#");
    }
}

void draw_snake(Snake *snake) {
    for (int i = 0; i < snake->length; i++) {
        mvprintw(snake->y[i] + 1, snake->x[i], "O");
    }
}

void draw_food(Food *food) {
    mvprintw(food->y + 1, food->x, "*");
}

int kbhit() {
    int ch = getch();
    if (ch != ERR) {
        ungetch(ch);
        return 1;
    }
    return 0;
}

void update_snake(Snake *snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->x[i] = snake->x[i - 1];
        snake->y[i] = snake->y[i - 1];
    }

    switch (snake->direction) {
        case 'u': snake->y[0]--; break;
        case 'd': snake->y[0]++; break;
        case 'l': snake->x[0]--; break;
        case 'r': snake->x[0]++; break;
    }

    // Wrap around the screen
    if (snake->x[0] >= WIDTH) snake->x[0] = 0;
    if (snake->x[0] < 0) snake->x[0] = WIDTH - 1;
    if (snake->y[0] >= HEIGHT) snake->y[0] = 0;
    if (snake->y[0] < 0) snake->y[0] = HEIGHT - 1;
}

void check_collision(Snake *snake, Food *food) {
    // Check for self collision
    for (int i = 1; i < snake->length; i++) {
        if (snake->x[0] == snake->x[i] && snake->y[0] == snake->y[i]) {
            endwin();
            printf("Game Over: Snake collided with itself!\n");
            exit(0);
        }
    }

    // Check for food collision
    if (snake->x[0] == food->x && snake->y[0] == food->y) {
        if (snake->length < MAX_LENGTH) {
            snake->length++;
            food->x = rand() % WIDTH;
            food->y = rand() % HEIGHT;

            // Ensure new food position is not on the snake
            for (int i = 0; i < snake->length; i++) {
                if (food->x == snake->x[i] && food->y == snake->y[i]) {
                    food->x = rand() % WIDTH;
                    food->y = rand() % HEIGHT;
                    i = -1; // Restart checking from the beginning
                }
            }
        }
    }
}

int main() {
    srand(time(0));
    
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    
    Snake snake;
    Food food;

    init_game(&snake, &food);

    while (1) {
        clear();
        
        draw_border();
        draw_snake(&snake);
        draw_food(&food);

        if (kbhit()) {
            int ch = getch();
            switch (ch) {
                case 'w': if (snake.direction != 'd') snake.direction = 'u'; break; // up
                case 's': if (snake.direction != 'u') snake.direction = 'd'; break; // down
                case 'a': if (snake.direction != 'r') snake.direction = 'l'; break; // left
                case 'd': if (snake.direction != 'l') snake.direction = 'r'; break; // right
                case 'q': endwin(); exit(0); // quit
            }
        }

        update_snake(&snake);
        check_collision(&snake, &food);

        refresh();
        usleep(100000); // Control speed
    }

    endwin();
    return 0;
}