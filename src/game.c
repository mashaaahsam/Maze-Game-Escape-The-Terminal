#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>

#include "player.h"
#include "menu.h"
#include "level.h"

int main()
{
    // Inits ncurses
    initscr();

    // Displays the Splash/Home screen
    int choice = SplashScreen();
    display_level(choice);

    return 0;
}