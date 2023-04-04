/*
** EPITECH PROJECT, 2023
** CSFML-Menus-Scenes
** File description:
** display
*/

#include "game.h"

void display_button(game_t *game, button_t *button)
{
    sfRenderWindow_drawRectangleShape(game->window, button->background, NULL);
    sfRenderWindow_drawText(game->window, button->text, NULL);
}

void display_menu(game_t *game, menu_t *menu)
{
    sfRenderWindow_drawRectangleShape(game->window, menu->background, NULL);
    sfRenderWindow_drawText(game->window, menu->text, NULL);
}

void display_menus(game_t *game, menus_t *menus)
{
    switch (game->current_menu) {
        case MENU_1:
            display_menu(game, menus->menu_1);
            break;
        case MENU_2:
            display_menu(game, menus->menu_2);
            break;
        case MENU_3:
            display_menu(game, menus->menu_3);
            break;
        case MENU_4:
            display_menu(game, menus->menu_4);
            break;
        default:
            break;
    }
}

void display_navbar(game_t *game, navbar_t *navbar)
{
    sfRenderWindow_drawRectangleShape(game->window, navbar->background, NULL);
    display_button(game, navbar->button_1);
    display_button(game, navbar->button_2);
    display_button(game, navbar->button_3);
    display_button(game, navbar->button_4);
}

void display(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    display_navbar(game, game->navbar);
    display_menus(game, game->menus);
    sfRenderWindow_display(game->window);
}
