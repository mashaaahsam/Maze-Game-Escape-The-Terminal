#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "player.h"
#include "menu.h"
#include "level.h"

// Functions
int selectionMenu(int max_x, int max_y)
{
    int mWidth = 20, mHeight = 4;
    int mStartx = (max_x - mWidth) / 2;
    int mStarty = ((max_y - mHeight) / 2) + 1;
    // Selection Menu
    mvprintw(mStarty, mStartx, "(1) Level 1");
    mvprintw(mStarty + 1, mStartx, "(2) Level 2");
    mvprintw(mStarty + 2, mStartx, "(3) Quit");
    mvprintw(mStarty + 3, mStartx, "Your Choice: ");
    refresh();

    // Get valid user choice
    int choice;
    while (true)
    {
        // Read user input
        choice = getch();

        // Process user input
        if (choice == '1' || choice == '2' || choice == '3')
        {
            break; // Exit loop if valid choice
        }
        else
        {
            mvprintw(mStarty + 4, mStartx, "Invalid choice.");
            mvprintw(mStarty + 3, mStartx, "Your Choice: ");
            refresh();
        }
    }
    return choice;
}

char pauseMenu()
{
    // Declarations
    char choice;

    // Enable echoing temporarily
    echo();

    mvprintw(32, 15, "Game Paused. Press 'p' to resume, 'q' to quit: ");
    refresh();
    do
    {
        choice = getch();
        mvprintw(32, 15, "Game Paused. Press 'p' to resume, 'q' to quit: ");
        refresh();
    } while ((choice != 'p') && (choice != 'q'));

    // Disable echoing
    noecho();

    // Clear the line
    mvprintw(32, 15, "                                                  ");
    refresh();

    return choice;
}

int quitMenu()
{
    // Enable echoing temporarily
    echo();
    char quit;
    do
    {
        // Clear and write confirmation message
        mvprintw(32, 15, "                                               ");
        mvprintw(32, 15, "Are you sure you want to quit (y/n): ");
        refresh();

        if ((quit = getch()) == 'y')
        {
            mvprintw(32, 15, "                                               ");
            refresh();
            return 1;
        }
        mvprintw(32, 15, "                                               ");
        refresh();

    } while (quit != 'n');
    // Disable echoing
    noecho();
    return 0;
}

// Level One
void npcMenu()
{
    // Declarations
    char choice;

    echo();
    // Menu
    do
    {
        mvprintw(8, 7, "Hi, I'm NP-C!");
        mvprintw(9, 7, "What'd you need?");
        mvprintw(10, 7, "1. Ask about key");
        mvprintw(11, 7, "2. Ask about door");
        mvprintw(12, 7, "3. Leave");
        mvprintw(13, 7, "You: ");
        refresh();

        choice = getch();

        if (choice == '1')
        {
            noecho();
            mvprintw(8, 7, "Ah the key!      ");
            mvprintw(9, 7, "The trick is     ");
            mvprintw(10, 7, "Grabbing it by   ");
            mvprintw(11, 7, "the K-end (use i)");
            mvprintw(12, 7, "                 ");
            mvprintw(13, 7, "See ya!          ");
            refresh();
            getch();
            break;
        }
        else if (choice == '2')
        {
            noecho();
            mvprintw(8, 7, "The door can be  ");
            mvprintw(9, 7, "opened using the ");
            mvprintw(10, 7, "key. It looks    ");
            mvprintw(11, 7, "like:     K      ");
            mvprintw(12, 7, "          |      ");
            mvprintw(13, 7, "          o      ");
            refresh();
            getch();
            break;
        }
    } while (choice != '3');

    // Disable echoing
    noecho();

    // Clear the line
    mvprintw(8, 7, "                 ");
    mvprintw(9, 7, "                 ");
    mvprintw(10, 7, "                 ");
    mvprintw(11, 7, "                 ");
    mvprintw(12, 7, "                 ");
    mvprintw(13, 7, "                 ");
    refresh();
}

void playerMenu_L1()
{
    // Declarations
    int choice;
    int collide;
    int movesRatio = 0;

    // Don't display user input on the screen
    noecho();

    // Enable keypad mode
    keypad(stdscr, TRUE);

    // Create and initialize the main character
    Player mC = {45, 20, 0, 'U'};
    // Create and initialize the NPC
    Player nPC = {78, 8, 0, 'N'};

    // Creates & draws objects onto screen
    // Declare pointers to Object
    Object *doorptr = malloc(sizeof(Object));
    Object *keyptr = malloc(sizeof(Object));
    levelOneObj(doorptr, keyptr);

    // Draw characters & objects onto screen
    drawPlayer(nPC);
    drawPlayer(mC);

    // Move cursor to Main Character
    move(mC.y, mC.x);

    do
    {
        // Get user input
        choice = getch();
        // Pause Game
        if (choice == 'p')
        {
            // Pause Menu
            char play = pauseMenu();
            // Player wants to quit
            if (play == 'q')
            {
                int quit = quitMenu();
                // Set the choice to quit
                if (quit == 1)
                {
                    break;
                }
            }
            else
            {
                // Reset the cursor location
                move(mC.y, mC.x);
            }
        }
        // Move Up
        else if (choice == KEY_UP)
        {

            if ((collide = collisionHandle(mC.y - 1, mC.x)) == 0)
            {
                mvaddch(mC.y, mC.x, ' ');
                movePlayer(&mC, 0, -1);
                drawPlayer(mC);
                move(mC.y, mC.x);
                movesRatio++;
            }
        }
        // Move Left
        else if (choice == KEY_LEFT)
        {
            if ((collide = collisionHandle(mC.y, mC.x - 1)) == 0)
            {
                mvaddch(mC.y, mC.x, ' ');
                movePlayer(&mC, -1, 0);
                drawPlayer(mC);
                move(mC.y, mC.x);
                movesRatio++;
            }
        }
        // Move Down
        else if (choice == KEY_DOWN)
        {
            if ((collide = collisionHandle(mC.y + 1, mC.x)) == 0)
            {
                mvaddch(mC.y, mC.x, ' ');
                movePlayer(&mC, 0, 1);
                drawPlayer(mC);
                move(mC.y, mC.x);
                movesRatio++;
            }
        }
        // Moves Right
        else if (choice == KEY_RIGHT)
        {
            if ((collide = collisionHandle(mC.y, mC.x + 1)) == 0)
            {
                mvaddch(mC.y, mC.x, ' ');
                movePlayer(&mC, 1, 0);
                drawPlayer(mC);
                move(mC.y, mC.x);
                movesRatio++;
            }
        }
        // Player Chooses to Interact
        else if (choice == 'i')
        {
            // Set/reset interaction value
            int interaction = 0;
            // Check above
            interaction = interactObjectL1(mC.y - 1, mC.x, &mC);
            // Nothing above: Check Left
            if (interaction == 0)
            {
                interaction = interactObjectL1(mC.y, mC.x - 1, &mC);

                // Nothing left: Check Below
                if (interaction == 0)
                {
                    interaction = interactObjectL1(mC.y + 1, mC.x, &mC);
                    // Nothing below: Check Right
                    if (interaction == 0)
                    {
                        interaction = interactObjectL1(mC.y, mC.x + 1, &mC);
                    }
                }
            }
            // You've beat the level
            else if (interaction == 2)
            {
                mvprintw(15, 38, "You Won! Next Level :)");
                refresh();
                sleep(3);
                levelTwo();
                break;
            }
            move(mC.y, mC.x);
        }
        // Quit Confirm
        else if (choice == 'q')
        {
            int quit = quitMenu();
            if (quit == 1)
            {
                break;
            }
            move(mC.y, mC.x);
        }
        // Move NPC after player moves 3 times
        if (movesRatio > 3)
        {
            moveNPC(&nPC);
            movesRatio = 0;
        }

        // Reset Cursor
        move(mC.y, mC.x);

    } while (true);

    // Clean up
    free(doorptr);
    free(keyptr);
}

// Level Two
void playerMenu_L2()
{
    // Declarations
    int choice;
    int collide;
    int movesRatio = 0;

    // Don't display user input on the screen
    noecho();

    // Enable keypad mode
    keypad(stdscr, TRUE);

    // Create and initialize the main character
    Player mC = {28, 22, 0, 'U'};
    // Create and initialize the NPC
    Player nPC = {78, 8, 1, 'N'};

    // Creates & draws objects onto screen
    // Declare pointers to Object
    Object *doorptr = malloc(sizeof(Object));
    Object *buttonTptr = malloc(sizeof(Object));
    Object *buttonBptr = malloc(sizeof(Object));
    levelTwoObj(doorptr, buttonBptr, buttonTptr);

    // Draw characters & objects onto screen
    drawPlayer(nPC);
    drawPlayer(mC);

    // Move cursor to Main Character
    move(mC.y, mC.x);

    do
    {
        // Get user input
        choice = getch();
        // Pause Game
        if (choice == 'p')
        {
            // Pause Menu
            char play = pauseMenu();
            // Player wants to quit
            if (play == 'q')
            {
                int quit = quitMenu();
                // Set the choice to quit
                if (quit == 1)
                {
                    break;
                }
            }
            else
            {
                // Reset the cursor location
                move(mC.y, mC.x);
            }
        }
        // Move Up
        else if (choice == KEY_UP)
        {

            if ((collide = collisionHandle(mC.y - 1, mC.x)) == 0)
            {
                mvaddch(mC.y, mC.x, ' ');
                movePlayer(&mC, 0, -1);
                drawPlayer(mC);
                move(mC.y, mC.x);
                movesRatio++;
            }
        }
        // Move Left
        else if (choice == KEY_LEFT)
        {
            if ((collide = collisionHandle(mC.y, mC.x - 1)) == 0)
            {
                mvaddch(mC.y, mC.x, ' ');
                movePlayer(&mC, -1, 0);
                drawPlayer(mC);
                move(mC.y, mC.x);
                movesRatio++;
            }
        }
        // Move Down
        else if (choice == KEY_DOWN)
        {
            if ((collide = collisionHandle(mC.y + 1, mC.x)) == 0)
            {
                mvaddch(mC.y, mC.x, ' ');
                movePlayer(&mC, 0, 1);
                drawPlayer(mC);
                move(mC.y, mC.x);
                movesRatio++;
            }
        }
        // Moves Right
        else if (choice == KEY_RIGHT)
        {
            if ((collide = collisionHandle(mC.y, mC.x + 1)) == 0)
            {
                mvaddch(mC.y, mC.x, ' ');
                movePlayer(&mC, 1, 0);
                drawPlayer(mC);
                move(mC.y, mC.x);
                movesRatio++;
            }
        }
        // Player Chooses to Interact
        else if (choice == 'i')
        {
            // Set/reset interaction value
            int interaction = 0;
            // Check above
            interaction = interactObjectL2(mC.y - 1, mC.x, &mC, &nPC);
            // Nothing above: Check Left
            if (interaction == 0)
            {
                interaction = interactObjectL2(mC.y, mC.x - 1, &mC, &nPC);
                // Nothing left: Check Below
                if (interaction == 0)
                {
                    interaction = interactObjectL2(mC.y + 1, mC.x, &mC, &nPC);
                    // Nothing below: Check Right
                    if (interaction == 0)
                    {
                        interaction = interactObjectL2(mC.y, mC.x + 1, &mC, &nPC);
                    }
                }
            }
            // You've beat the level
            else if (interaction == 2)
            {
                clear();
                mvprintw(15, 48, "You Won!");
                refresh();
                sleep(5);
                break;
            }
            move(mC.y, mC.x);
        }
        // Quit Confirm
        else if (choice == 'q')
        {
            int quit = quitMenu();
            if (quit == 1)
            {
                break;
            }
            move(mC.y, mC.x);
        }
        // Move NPC after player moves 3 times
        if (movesRatio > 3)
        {
            moveNPC(&nPC);
            movesRatio = 0;
        }

        // Reset Cursor
        move(mC.y, mC.x);

    } while (true);

    // Clean up
    free(doorptr);
    free(buttonBptr);
    free(buttonTptr);
}

void strLower(char *string)
{
    for (int i = 0; string[i] != '\0'; ++i)
    {
        string[i] = tolower(string[i]);
    }
}

int npcRiddle()
{
    // In C's domain, I link and connect,
    // I reference memory, with intellect.
    // ANS: Pointer
    char guess[10];

    do
    {
        echo();
        mvprintw(8, 7, "Riddle for key:   ");
        mvprintw(9, 7, "In C's domain, I  ");
        mvprintw(10, 7, "link and connect, ");
        mvprintw(11, 7, "reference memory  ");
        mvprintw(12, 7, "with intellect.   ");
        mvprintw(13, 7, "What am I?        ");
        mvprintw(14, 7, "P------:          ");
        move(14, 15);
        refresh();

        getnstr(guess, 10); // Wait for user input

        // Convert user input to lower-case
        strLower(guess);

        if (strcmp(guess, "pointer") == 0)
        {
            noecho();
            mvprintw(8, 7, "                  ");
            mvprintw(9, 7, "                  ");
            mvprintw(10, 7, "                  ");
            mvprintw(11, 7, "                  ");
            mvprintw(12, 7, "                  ");
            mvprintw(13, 7, "                  ");
            mvprintw(14, 7, "                  ");
            refresh();
            return 1;
        }
        else if (strcmp(guess, "quit") != 0)
        {
            noecho();
            mvprintw(14, 7, "Try again or type ");
            mvprintw(15, 7, "'quit' to exit.   ");
            refresh();
            sleep(2);
            // Clear text
            mvprintw(14, 7, "                  ");
            mvprintw(15, 7, "                  ");
            refresh();
        }

    } while (strcmp(guess, "quit") != 0);
    noecho();
    mvprintw(8, 7, "                  ");
    mvprintw(9, 7, "                  ");
    mvprintw(10, 7, "                  ");
    mvprintw(11, 7, "                  ");
    mvprintw(12, 7, "                  ");
    mvprintw(13, 7, "                  ");
    mvprintw(14, 7, "                  ");
    refresh();
    // Did not guess the riddle
    return 0;
}
