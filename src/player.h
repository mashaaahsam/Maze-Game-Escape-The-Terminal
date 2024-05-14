/****************************************************************
 * @file player.h                                               *
 * @brief Public interface fora playing character               *
 * @authors Masha, Shanil                                       *
 * @date Mar. 22, 2024                                          *
 ****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

/**
 * @brief This struct defines a player
 */
typedef struct
{
    int x;     /**< initial x cordinate of prayer */
    int y;     /**< initial y cordinate of prayer */
    int key;   /**< Key possesion value*/
    char body; /**< Player body */
} Player;

/**
 * @brief This struct defines an object
 */
typedef struct
{
    char *name; /**< Pointer to the object name */
    int key;    /**< Key requirement/possesion value*/
    int size;   /**< The size of the object word to be displayed*/
} Object;

/**
 * @brief Draw a player character on the screen.
 *
 * @param p The Player struct containing information about the player character.
 */
void drawPlayer(Player p);

/**
 * @brief Draw an object on the screen.
 *
 * @param o The Object struct containing information about the object to be drawn.
 * @param y The y-coordinate of the top-left corner of the object.
 * @param x The x-coordinate of the top-left corner of the object.
 * @param direction The direction in which to draw the object (0 for horizontal, 1 for vertical).
 */
void drawObject(Object o, int y, int x, int direction);

/**
 * @brief Move the player character by the given amount in the x and y directions.
 *
 * @param player A pointer to the Player struct representing the player character.
 * @param x The amount to move in the horizontal direction.
 * @param y The amount to move in the vertical direction.
 */
void movePlayer(Player *player, int x, int y);

/**
 * @brief Move the non-player character (NPC) based on collision handling.
 *
 * @param nPC A pointer to the Player struct representing the NPC.
 */
void moveNPC(Player *nPC);

/**
 * @brief Check for collisions at the specified position.
 *
 * This function checks for collisions with both walls and objects at the specified position.
 *
 * @param y The y-coordinate of the position to check.
 * @param x The x-coordinate of the position to check.
 * @return int Returns 1 if a collision is detected, otherwise returns 0.
 */
int collisionHandle(int y, int x);

/**
 * @brief Check for collisions with objects at the specified position.
 *
 * @param y The y-coordinate of the position to check.
 * @param x The x-coordinate of the position to check.
 * @return int Returns 1 if a collision with an object is detected, otherwise returns 0.
 */
int objectCollision(int y, int x);

/**
 * @brief Get the character type at the specified position.
 *
 * @param y The y-coordinate of the position.
 * @param x The x-coordinate of the position.
 * @return char The character type at the specified position.
 */
char typeCollision(int y, int x);

/**
 * @brief Check for collisions with the bounds of the game window.
 *
 * @param y The y-coordinate of the position to check.
 * @param x The x-coordinate of the position to check.
 * @return int Returns 1 if a collision with the bounds is detected, otherwise returns 0.
 */
int boundsCollision(int y, int x);

/**
 * @brief Set up objects for Level One including the door and key.
 *
 * This function draws the walls and creates the door and key objects for Level One.
 *
 * @param door A pointer to the Object representing the door.
 * @param key A pointer to the Object representing the key.
 * @return None.
 */
void levelOneObj(Object *door, Object *key);

/**
 * @brief Handle interaction with objects in Level One.
 *
 * This function handles interactions with objects in Level One based on the player's position.
 *
 * @param y The y-coordinate of the player's position.
 * @param x The x-coordinate of the player's position.
 * @param mC A pointer to the Player structure representing the main character.
 * @return int Returns:
 *            - 1 if the interaction is successful (e.g., talking to an NPC, picking up a key).
 *            - 2 if the player interacts with the door and has the key to proceed to the next level.
 *            - 0 if no interaction occurs.
 */
int interactObjectL1(int y, int x, Player *mC);

/**
 * @brief Set up objects for Level Two including the door, bottom button, and top button.
 *
 * This function draws the walls and creates the door, bottom button, and top button objects for Level Two.
 *
 * @param door A pointer to the Object representing the door.
 * @param BottomB A pointer to the Object representing the bottom button.
 * @param TopB A pointer to the Object representing the top button.
 * @return None.
 */
void levelTwoObj(Object *door, Object *BottomB, Object *TopB);

/**
 * @brief Handle interaction with objects in Level Two.
 *
 * This function handles interactions with objects in Level Two based on the player's position.
 *
 * @param y The y-coordinate of the player's position.
 * @param x The x-coordinate of the player's position.
 * @param mC A pointer to the Player structure representing the main character.
 * @param nPC A pointer to the Player structure representing the non-player character.
 * @return int Returns:
 *            - 1 if the interaction is successful (e.g., pressing a button, finding a key).
 *            - 2 if the player interacts with the door and has the required keys to proceed to the next level.
 *            - 0 if no interaction occurs.
 */
int interactObjectL2(int y, int x, Player *mC, Player *nPC);

#endif /* PLAYER_H */