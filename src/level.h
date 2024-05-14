/****************************************************************
 * @file level.h                                                *
 * @brief Public interface for levels                           *
 * @authors Masha, Shanil                                       *
 * @date Mar. 22, 2023                                          *
 ****************************************************************/

#ifndef LEVEL_H
#define LEVEL_H

/**
 * @brief Displays the Splash/Home Screen and a Selection Menu with level choices or to Quit.
 *
 * @return Integer value of the user choice (level selection or quit).
 */
int SplashScreen();

/**
 * @brief Display a text art design centered on the screen.
 *
 * @param max_x The maximum x-coordinate of the screen.
 * @param max_y The maximum y-coordinate of the screen.
 */
void drawTextArt(int max_x, int max_y);

/**
 * @brief Display a penguin art design on the screen.
 *
 * @param max_x The maximum x-coordinate of the screen.
 * @param max_y The maximum y-coordinate of the screen.
 */
void drawPenguin(int max_x, int max_y);

/**
 * @brief Display level one of the game.
 */
void levelOne();

/**
 * @brief Draw the walls & text for level one.
 */
void levelOneWalls();

/**
 * @brief Display and manage Level Two of the game.
 */
void levelTwo();

/**
 * @brief Draw walls, text, and layout for Level Two of the game.
 */
void levelTwoWalls();

/**
 * @brief Display the specified level based on the input parameter.
 *
 * @param i The level number (1 for Level One, 2 for Level Two).
 */
void display_level(int i);

/**
 * @brief Display the layout of the maze in room 2 and provide instructions to the player.
 */
void room2Maze();

#endif /* LEVEL_H */