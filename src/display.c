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

void display_list(particle_t *list, sfRenderWindow *window)
{
    while (list != NULL) {
        sfRenderWindow_drawSprite(window, list->sprite, NULL);
        list = list->next;
    }
}

void animate_list(particle_t *list)
{
    sfVector2f pos = {0, 0};
    sfVector2f move = {-2, 4};

    while (list != NULL) {
        sfSprite_move(list->sprite, move);
        if ((sfSprite_getPosition(list->sprite).y > 1080) || sfSprite_getPosition(list->sprite).x > 1920) {
            pos.x = rand() % (1920);
            pos.y = rand() % (1080);
            sfSprite_setPosition(list->sprite, pos);
        }
        list = list->next;
    }
}

void display(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    display_navbar(game, game->navbar);
    display_menus(game, game->menus);
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->clock_list)) > 0.01) {
        animate_list(game->list);
        sfClock_restart(game->clock_list);
    }
    display_list(game->list, game->window);
    sfRenderWindow_display(game->window);
}
