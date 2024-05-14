/****************************************************************
 * @file menu.h                                                 *
 * @brief Public interface for menus                            *
 * @authors Masha, Shanil                                       *
 * @date Mar. 22, 2023                                          *
 ****************************************************************/

#ifndef MENU_H
#define MENU_H

/**
 * @brief Display a selection menu and get user input for menu selection.
 *
 * @param max_x The maximum x-coordinate of the screen.
 * @param max_y The maximum y-coordinate of the screen.
 * @return An integer representing the user's menu selection.
 */
int selectionMenu(int max_x, int max_y);

/**
 * @brief Display a pause menu and get user input for pausing or quitting the game.
 *
 * @return A character representing the user's choice ('p' to resume or 'q' to quit).
 */
char pauseMenu();

/**
 * @brief Display a quit confirmation menu and handle user input.
 *
 * @return An integer indicating the user's choice (1 to quit, 0 otherwise).
 */
int quitMenu();

/**
 * @brief Display an NPC interaction menu and handle user input.
 *
 * Allows the player to interact with non-player characters.
 */
void npcMenu();

/**
 * @brief Display the player menu for Level 1 gameplay.
 *
 * Allows the player to navigate, interact with objects, pause the game, and quit.
 */
void playerMenu_L1();

/**
 * @brief Display the player menu for Level 2 gameplay.
 *
 * Allows the player to navigate, interact with objects, pause the game, and quit.
 */
void playerMenu_L2();

/**
 * @brief Convert a string to lowercase.
 *
 * @param string A pointer to the string to be converted to lowercase.
 */
void strLower(char *string);

/**
 * @brief Display a riddle for the player to guess and handle user input.
 *
 * @return An integer indicating the result of the riddle guessing:
 *         - 1 if the player guessed the correct answer.
 *         - 0 if the player did not guess the correct answer or chose to quit.
 */
int npcRiddle();

#endif /* MENU_H */
