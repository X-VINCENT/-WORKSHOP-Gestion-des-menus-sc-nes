/*
** EPITECH PROJECT, 2023
** CSFML-Menus-Scenes
** File description:
** destroy
*/

#include "game.h"

void destroy_fonts(fonts_t *fonts)
{
    sfFont_destroy(fonts->arial);
    free(fonts);
}

void destroy_button(button_t *button)
{
    sfRectangleShape_destroy(button->background);
    sfText_destroy(button->text);
    free(button);
}

void destroy_menu(menu_t *menu)
{
    sfRectangleShape_destroy(menu->background);
    sfText_destroy(menu->text);
    free(menu);
}

void destroy_menus(menus_t *menus)
{
    destroy_menu(menus->menu_1);
    destroy_menu(menus->menu_2);
    destroy_menu(menus->menu_3);
    destroy_menu(menus->menu_4);
    free(menus);
}

void destroy_navbar(navbar_t *navbar)
{
    sfRectangleShape_destroy(navbar->background);
    destroy_button(navbar->button_1);
    destroy_button(navbar->button_2);
    destroy_button(navbar->button_3);
    destroy_button(navbar->button_4);
    free(navbar);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    free(game->event);
    destroy_fonts(game->fonts);
    destroy_navbar(game->navbar);
    destroy_menus(game->menus);
    free(game);
}
