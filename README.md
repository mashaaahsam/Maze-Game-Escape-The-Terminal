# CMPT201_A2
Creating a game for the final Lab project. Theme: Maze

Terminal-Based Game
Terminal-based game developed using C and ncurses, offering an engaging text-based adventure and puzzle-solving experience. Navigate through various levels, interact with characters, and uncover the mysteries within.

Features
Multiple levels with unique challenges.
Dynamic splash screen with ASCII art.
Penguin mascot for a friendly guide.
Simplified and full art adaptability based on terminal size.
Pause functionality allowing you to take a break whenever needed.

Prerequisites
To compile and run this game, you'll need:
    - GCC (GNU Compiler Collection)
    - ncurses library


GAME PLAN
Goal for each level:
    Level 1 - Interact with NPC, get the key and open the door. This is the premis for most of the game
    Level 2 - As in level 1 you need to find the NPC however theres multiple rooms you have to get out of to get to the final door


Overall Goal   
Reach the doors in each level, assuming you've found the corresponding key(s) for each level.

What do the levels look like
    Level 1 - Has a simple border, with the NPC and key out in the open. 
    Level 2 - Has multiple rooms, with some choices to get to the other rooms. Room 1 has two buttons. Room 2 spawns in a maze when entered. Room 3 has the NPC. Room 4 has the final door.

What are items in the game
    - Keys (K|o)
    - Doors ((DOOR))
    - NPC (N)
    - MC (U)
    - Money ($)
    - Mat ({MAT})