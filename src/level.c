#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>

#include "player.h"
#include "menu.h"
#include "level.h"

// Functions
int SplashScreen() // Level 0
{
    clear();

    // Declarations
    WINDOW *w;
    int max_y, max_x;

    // Get & assign max size of terminal at start
    getmaxyx(stdscr, max_y, max_x);

    // Height, Width, Start_Y, Start_x
    w = newwin(30, 80, 5, 5);

    // Draw the window boarder
    wborder(w, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(w);

    // Display the Splash Screen
    // Text Art
    drawTextArt(max_x, max_y);
    // Linux Penguin Art
    drawPenguin(max_x, max_y);

    // Selection Menu
    int choice = selectionMenu(max_x, max_y);

    // Wait for key to be entered before clearing screen
    endwin();

    return choice;
}

// Draw Functions
void drawTextArt(int max_x, int max_y)
{
    // Math to center text art
    int textWidth = 144, textHeight = 11;
    int textStartx = (max_x - textWidth) / 2;
    int textStarty = (max_y - textHeight) / 2 - 10;
    // Text Art
    mvprintw(textStarty++, textStartx, "888'Y88                                           88P'888'Y88 888               88P'888'Y88                            ,e,                 888 ");
    mvprintw(textStarty++, textStartx, "888 ,'Y  dP'Y  e88'888  ,'Y88b 888 88e   ,e e,    P'  888  'Y 888 ee   ,e e,    P'  888  'Y  ,e e,  888,8, 888 888 8e   '  888 8e,  'Y88b  888 ");
    mvprintw(textStarty++, textStartx, "888C8   C88b  d888  '8 '8' 888 888 888b d88 88b       888     888 88b d88 88b       888     d88 88b 888 '  888 888 88b 888 888 88b '8' 888 888 ");
    mvprintw(textStarty++, textStartx, "888 ',d  Y88D Y888   , ,ee 888 888 888P 888   ,       888     888 888 888   ,       888     888   , 888    888 888 888 888 888 888 ,ee 888 888 ");
    mvprintw(textStarty++, textStartx, "888,d88 d,dP   '88,e8' '88 888 888 88'   'YeeP'       888     888 888  'YeeP'       888      'YeeP' 888    888 888 888 888 888 888 '88 888 888 ");
    mvprintw(textStarty++, textStartx, "                               888                                                                                                             ");
    mvprintw(textStarty++, textStartx, "                               888                                                                                                             ");
}

void drawPenguin(int max_x, int max_y)
{
    // Math to penguin art
    int pWidth = 24, pHeight = 16;
    int pStartx = (max_x - pWidth);
    int pStarty = (max_y - pHeight);
    mvprintw(pStarty++, pStartx, "        _nnnn_");
    mvprintw(pStarty++, pStartx, "        gGGGGMMb");
    mvprintw(pStarty++, pStartx, "       @p~UU~~gNu");
    mvprintw(pStarty++, pStartx, "       M(@||@) M|");
    mvprintw(pStarty++, pStartx, "       @,----.JM|");
    mvprintw(pStarty++, pStartx, "      JS^|__/  qKL");
    mvprintw(pStarty++, pStartx, "     dZP        GNNu");
    mvprintw(pStarty++, pStartx, "    dZP          gNnu");
    mvprintw(pStarty++, pStartx, "   fZP            GNNU");
    mvprintw(pStarty++, pStartx, "   HZM            GGGGg");
    mvprintw(pStarty++, pStartx, "   FqM            NnnNn");
    mvprintw(pStarty++, pStartx, " ___gn        |V**VVnNu");
    mvprintw(pStarty++, pStartx, "V....`.        |.`'.V.V");
    mvprintw(pStarty++, pStartx, "V_......`.___.,|...../ ");
    mvprintw(pStarty++, pStartx, "V___....)GNugnu|..../");
    mvprintw(pStarty++, pStartx, "    '--'       `---'   ");
}

// Level Functions
void levelOne()
{
    clear();

    // Declarations
    WINDOW *w1;

    // Height, Width, Start_Y, Start_x
    w1 = newwin(30, 80, 5, 5);
    refresh();

    // Draw the window boarder
    wborder(w1, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(w1);

    // Add text centre below the window - (y, x , "text")
    mvprintw(29, 15, "Escape the Terminal: Level One");                      // Display Game Name & Level
    mvprintw(30, 15, "Use ARROW keys to move and the 'i' key to interact."); // Display Game Instructions
    mvprintw(31, 15, "Enter 'p' to pause, 'q' to quit.");                    // Displays pause & quit options
    refresh();

    // Player movement
    playerMenu_L1();

    // Close Window
    endwin();
}

void levelOneWalls()
{
    // Draw side walls in level one
    for (int i = 0; i < 22; i++)
    {
        mvprintw(6 + i, 26, "|");
    }
    // Draw the bottom walls in level one
    mvprintw(28, 6, ".____________________________________________________________________________.");

    // A quick instruction for the start of the game
    mvprintw(8, 7, "You are the U.");
    mvprintw(9, 7, "U must talk with");
    mvprintw(10, 7, "N first before ");
    mvprintw(11, 7, "anything else.");

    refresh();
}

void levelTwo()
{
    clear();
    // Declarations
    WINDOW *w2;

    // Height, Width, Start_Y, Start_x
    w2 = newwin(30, 80, 5, 5);
    refresh();

    // Draw the window boarder
    wborder(w2, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(w2);

    // Add text centre below the window - (y, x , "text")
    mvprintw(29, 15, "Escape the Terminal: Level Two");                      // Display Game Name & Level
    mvprintw(30, 15, "Use ARROW keys to move and the 'i' key to interact."); // Display Game Instructions
    mvprintw(31, 15, "Enter 'p' to pause, 'q' to quit.");                    // Displays pause & quit options
    refresh();

    // Player movement
    playerMenu_L2();

    // Close Window
    endwin();
}

void levelTwoWalls()
{
    // Draw side walls in level one
    for (int i = 0; i < 22; i++)
    {
        // Left Most Divide (text side)
        mvprintw(6 + i, 26, "|");
        // Top (room) Divide
        if (i < 10)
        {
            mvprintw(6 + i, 51, "|");
        }
        // Bottom (room) Divide - Skip line 16
        else if (i > 10)
        {
            mvprintw(6 + i, 48, "|");
        }
    }
    // Middle (rooms) Divide
    mvprintw(16, 27, "_________________________________________________________");
    // Draw the bottom walls in level one
    mvprintw(28, 6, "______________________________________________________________________________");

    // A quick instruction for the start of the game
    mvprintw(8, 7, "Welcome to Level 2");
    mvprintw(10, 7, "Press a button *");
    mvprintw(11, 7, "to move onto the");
    mvprintw(12, 7, "next room.");

    refresh();
}

void display_level(int i)
{

    // Selection menu loop
    while (true)
    {
        // Process user input
        if (i == '1')
        {
            levelOne(); // Call level one function
            break;
        }
        else if (i == '2')
        {
            levelTwo(); // Call level two function
            break;
        }
        else
        {
            break;
        }
    }
}

void room2Maze()
{
    // Display Text
    mvprintw(10, 7, "Time to be greedy ");
    mvprintw(11, 7, "Get the $...      ");
    mvprintw(12, 7, "                  ");

    // Display the Maze
    mvprintw(17, 53, "            |                  ");
    mvprintw(18, 53, "------------+ ------+---- -----");
    mvprintw(19, 53, "|           |       |          ");
    mvprintw(20, 53, "| --------+ |    .  |  +----- -");
    mvprintw(21, 53, "          | |       |  |       ");
    mvprintw(22, 53, "|-------  | |       |  +-----  ");
    mvprintw(23, 53, "|         | +-------+       +--");
    mvprintw(24, 53, "|  +---   |         |          ");
    mvprintw(25, 53, "|  |$     |  +---+  |---       ");
    mvprintw(26, 53, "|  +------|  |   |  |          ");
    mvprintw(27, 53, "             |      |          ");
    refresh();

    // Create the mat
    Object mat;
    mat.name = "{MAT}";
    mat.key = 1;
    mat.size = 5;
    drawObject(mat, 27, 77, 0);
}