/*
** EPITECH PROJECT, 2023
** CSFML-Menus-Scenes
** File description:
** events
*/

#include "game.h"

void handle_change_menu(game_t *game, int direction)
{
    if (direction == 1)
        game->current_menu += 1;
    else if (direction == -1)
        game->current_menu -= 1;
    if (game->current_menu < 0)
        game->current_menu = 0;
    else if (game->current_menu > 2)
        game->current_menu = 2;
}

void handle_key_pressed_events(game_t *game)
{
    switch(game->event->key.code) {
        case sfKeyEscape:
            sfRenderWindow_close(game->window);
            break;
        case sfKeyLeft:
            handle_change_menu(game, -1);
            break;
        case sfKeyRight:
            handle_change_menu(game, 1);
            break;
        default:
            break;
    }
}

void handle_click_navbar(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f coords = sfRenderWindow_mapPixelToCoords(
        game->window, mouse, NULL);
    sfFloatRect menu_1 = sfRectangleShape_getGlobalBounds(game->navbar->button_1->background);
    sfFloatRect menu_2 = sfRectangleShape_getGlobalBounds(game->navbar->button_2->background);
    sfFloatRect menu_3 = sfRectangleShape_getGlobalBounds(game->navbar->button_3->background);
    sfFloatRect menu_4 = sfRectangleShape_getGlobalBounds(game->navbar->button_4->background);

    if (sfFloatRect_contains(&menu_1, coords.x, coords.y))
        game->current_menu = MENU_1;
    else if (sfFloatRect_contains(&menu_2, coords.x, coords.y))
        game->current_menu = MENU_2;
    else if (sfFloatRect_contains(&menu_3, coords.x, coords.y))
        game->current_menu = MENU_3;
    else if (sfFloatRect_contains(&menu_4, coords.x, coords.y))
        game->current_menu = MENU_4;
}

void handle_mouse_pressed_events(game_t *game)
{
    switch(game->event->mouseButton.button) {
        case sfMouseLeft:
            handle_click_navbar(game);
            break;
        default:
            break;
    }
}

void handle_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, game->event)) {
        switch (game->event->type) {
            case sfEvtClosed:
                sfRenderWindow_close(game->window);
                break;
            case sfEvtKeyPressed:
                handle_key_pressed_events(game);
                break;
            case sfEvtMouseButtonPressed:
                handle_mouse_pressed_events(game);
                break;
            default:
                break;
        }
    }
}
