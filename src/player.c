// Masha Antoshkina - 3104393
// Shanil Kumar - 3078389

#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>

#include "player.h"
#include "menu.h"
#include "level.h"

// Functions

// Draw
void drawPlayer(Player p)
{
    mvaddch(p.y, p.x, p.body);
    refresh();
}

void drawObject(Object o, int y, int x, int direction)
{
    // direction 0 = Horizontal
    if (direction == 0)
    {
        for (int i = 0; i < o.size; i++)
        {
            mvaddch(y, x + i, o.name[i]);
        }
    }
    // direction 1 = Vertical
    else
    {
        for (int i = 0; i < o.size; i++)
        {
            mvaddch(y + i, x, o.name[i]);
        }
    }

    refresh();
}

// Move Function
void movePlayer(Player *player, int x, int y)
{
    player->x += x;
    player->y += y;
}

void moveNPC(Player *nPC)
{
    int collide;
    // Move Up if posibile
    if ((collide = collisionHandle(nPC->y - 1, nPC->x)) == 0)
    {
        mvaddch(nPC->y, nPC->x, ' ');
        nPC->y -= 1;
        drawPlayer(*nPC);
    }
    // Move Left if possible
    else if ((collide = collisionHandle(nPC->y, nPC->x - 1)) == 0)
    {
        mvaddch(nPC->y, nPC->x, ' ');
        nPC->x -= 1;
        drawPlayer(*nPC);
    }
    // Move Down if possible
    else if ((collide = collisionHandle(nPC->y + 1, nPC->x)) == 0)
    {
        mvaddch(nPC->y, nPC->x, ' ');
        nPC->y += 1;
        drawPlayer(*nPC);
    }
    // Move Right if possible
    else if ((collide = collisionHandle(nPC->y, nPC->x + 1)) == 0)
    {
        mvaddch(nPC->y, nPC->x, ' ');
        nPC->x += 1;
        drawPlayer(*nPC);
    }
}

// Collision
int collisionHandle(int y, int x)
{
    int wallC, objC;
    //
    wallC = boundsCollision(y, x);
    // Handles Everything inside the window
    objC = objectCollision(y, x);
    if (objC || wallC)
    {
        return 1;
    }
    return 0;
}

int objectCollision(int y, int x)
{
    char character = typeCollision(y, x);

    // Collision detected. Return 1
    if (character != ' ')
    {
        // Something to collide with
        return 1;
    }
    else
    {
        // Nothing to collide with
        return 0;
    }
}

char typeCollision(int y, int x)
{
    // Get the character at position (y, x)
    chtype ch = mvinch(y, x);

    // Extract the character part from the ch
    char character = (char)ch;
    refresh();

    return character;
}

int boundsCollision(int y, int x)
{
    if ((x < 6) || (x > 83) || (y < 6) || (y > 33))
    {
        return 1;
    }
    return 0;
}

// Objects

// Level One
void levelOneObj(Object *door, Object *key)
{
    // Draw the walls in the level
    levelOneWalls();
    // Create the door
    door->name = "[DOOR]";
    door->key = 0;
    door->size = 6;
    drawObject(*door, 6, 32, 0);

    // Create the key
    key->name = "K|o";
    key->key = 1;
    key->size = 3;
    drawObject(*key, 21, 72, 1);
}

int interactObjectL1(int y, int x, Player *mC)
{
    // Extract the character part from the ch
    char character = typeCollision(y, x);

    // Check what you are colliding with
    if (character == 'N')
    {
        // NPC Interaction
        if (mC->key == 0) // First time talking to NPC
        {
            mC->key = 1;
        }
        npcMenu();
        return 1;
    }
    // Collide with key & you've talked to the NPC
    else if ((character == 'K') && (mC->key == 1))
    {
        // Key interaction
        mC->key += 1;
        for (int i = 0; i < 3; i++)
        {
            mvaddch(y + i, x, ' ');
        }
        return 1;
    }
    // Colliding with door & you have the key
    else if (((character == '[') || (character == ']') || (character == 'D') || (character == 'O') || (character == 'R')) && (mC->key > 1))
    {
        return 2;
    }
    return 0;
}

// Level Two
void levelTwoObj(Object *door, Object *BottomB, Object *TopB)
{
    // Draw the walls in the level
    levelTwoWalls();
    // Create the door
    door->name = "[DOOR]";
    door->key = 0;
    door->size = 6;
    drawObject(*door, 6, 32, 0);

    // Create the Bottom Button
    BottomB->name = "*B";
    BottomB->key = 2;
    BottomB->size = 2;
    drawObject(*BottomB, 26, 40, 1);

    // Create the Top Button
    TopB->name = "B*";
    TopB->key = 1;
    TopB->size = 2;
    drawObject(*TopB, 17, 40, 1);
}

int interactObjectL2(int y, int x, Player *mC, Player *nPC)
{

    // Extract the character part from the ch
    char character = typeCollision(y, x);

    // Check the object you collide with
    // Button - Room #1
    if (character == '*')
    {
        // Button was pressed - check which one
        // Bottom Button
        if ((mC->y < 27) && (mC->y > 24))
        {
            // Display the Room Specialty
            room2Maze();
            // Erase Buttons
            mvaddch(18, 40, ' ');
            mvaddch(17, 40, ' ');
            mvaddch(26, 40, ' ');
            mvaddch(27, 40, ' ');
            // Move to bottom right room (#2)
            mvaddch(mC->y, mC->x, ' ');
            mC->x = 51;
            mC->y = 18;
            drawPlayer(*mC);
            move(mC->y, mC->x);
            return 1;
        }
        // Top Button
        else if ((mC->y < 20) && (mC->y > 17))
        {
            // Open walls & Remove Buttons
            mvaddch(18, 39, ' ');
            mvaddch(18, 40, ' ');
            mvaddch(17, 40, ' ');
            mvaddch(16, 41, ' ');
            mvaddch(16, 40, ' ');
            mvaddch(16, 39, ' ');
            // Bottom Button
            mvaddch(26, 40, ' ');
            mvaddch(27, 40, ' ');
            // Wall to Room #3
            mvaddch(13, 51, ' ');
            mvaddch(14, 51, ' ');
            // Display instruction text
            mvprintw(10, 7, "I heard the NP-C  ");
            mvprintw(11, 7, "has a key for the ");
            mvprintw(12, 7, "player who solves ");
            mvprintw(13, 7, "his riddle.       ");
        }
    }
    // $ - Room #2
    else if ((character == '$'))
    {
        // Move through maze
        mvaddch(25, 57, ' ');
        mvaddch(mC->y, mC->x, ' ');
        mC->x = 70;
        mC->y = 20;
        drawPlayer(*mC);
        move(mC->y, mC->x);
        // Display Mat Text
        mvprintw(10, 7, "I heard people    ");
        mvprintw(11, 7, "hide keys under   ");
        mvprintw(12, 7, "mats...           ");
        refresh();
        return 1;
    }
    // Mat - Room #2
    else if ((character == 'M') || (character == 'A') || (character == 'T') || (character == '{') || (character == '}'))
    {
        mC->key += 1;
        mvprintw(10, 7, "You found a key   ");
        mvprintw(11, 7, "under the mat!    ");
        // Player only found one key (room 2 first)
        if (mC->key == 1)
        {
            mvprintw(12, 7, "You need 2 for the");
            mvprintw(13, 7, "final door.       ");
        }
        // Player has more than one (room 3 first)
        else
        {
            mvprintw(12, 7, "You have all the  ");
            mvprintw(13, 7, "keys to the door. ");
        }
        // Erase Mat & Open NPC room
        mvprintw(27, 77, "     ");
        mvprintw(16, 70, "        ");
        refresh();
        return 1;
    }
    // NPC - Room #3
    else if (character == 'N')
    {
        // NPC has key to give
        if (nPC->key == 1)
        {
            int guessed = npcRiddle();
            // Got the riddle right
            if (guessed == 1)
            {
                mC->key += 1;
                nPC->key -= 1;
                mvprintw(10, 7, "You got a key from");
                mvprintw(11, 7, "the NP-C.         ");
                mvprintw(12, 7, "                  ");
                mvprintw(13, 7, "                  ");
                getch();
                // Room #2 not explored
                if (mC->key < 2)
                {
                    // Display the Room Specialty
                    room2Maze();
                    // Move to bottom right room (#2)
                    mvaddch(mC->y, mC->x, ' ');
                    mC->x = 51;
                    mC->y = 18;
                    drawPlayer(*mC);
                    move(mC->y, mC->x);
                    return 1;
                }
                // Have two keys - Wall to Room #3
                mvaddch(13, 51, ' ');
                mvaddch(14, 51, ' ');
                refresh();
            }
            return 1;
        }
        // NPC already gave key
        else
        {
            mvprintw(10, 7, "NP-C doesn't have ");
            mvprintw(11, 7, "a key for you.    ");
            mvprintw(12, 7, "                  ");
            mvprintw(13, 7, "                  ");
            refresh();
        }
    }
    // Door - Room #4
    else if (((character == '[') || (character == ']') || (character == 'D') || (character == 'O') || (character == 'R')) && (mC->key >= 2))
    {
        // Level Won
        return 2;
    }
    // Did not interact with objects
    return 0;
}
