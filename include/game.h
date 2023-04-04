/*
** EPITECH PROJECT, 2023
** CSFML-Menus-Scenes
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_



    // C
    #include <stdlib.h>
    #include <stdio.h>



    // CSFML
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>



    // Data
    enum menus {
        NO_MENU = -1,
        MENU_1,
        MENU_2,
        MENU_3,
        MENU_4
    };

    typedef struct particle {
        sfSprite *sprite;
        struct particle *next;
        struct particle *previous;
    } particle_t;

    typedef struct button_s {
        sfRectangleShape *background;
        sfText *text;
    } button_t;

    typedef struct navbar_s {
        sfRectangleShape *background;
        button_t *button_1;
        button_t *button_2;
        button_t *button_3;
        button_t *button_4;
    } navbar_t;

    typedef struct menu_s {
        sfRectangleShape *background;
        sfText *text;
    } menu_t;

    typedef struct menus_s {
        menu_t *menu_1;
        menu_t *menu_2;
        menu_t *menu_3;
        menu_t *menu_4;
    } menus_t;

    typedef struct fonts_s {
        sfFont *arial;
    } fonts_t;

    typedef struct game_s {
        sfRenderWindow *window;
        sfEvent *event;
        fonts_t *fonts;
        navbar_t *navbar;
        menus_t *menus;
        enum menus current_menu;
        particle_t *list;
        sfTexture *texture_list;
        sfClock *clock_list;
    } game_t;



    /* FUNCTIONS */
        // destroy.c
        void destroy_game(game_t *game);

        // display.c
        void display(game_t *game);

        // events.c
        void handle_events(game_t *game);

        // game.c
        int game(void);

        // init.c
        game_t *init_game(void);

#endif /* !GAME_H_ */
