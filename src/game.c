/*
** EPITECH PROJECT, 2023
** CSFML-Menus-Scenes
** File description:
** game
*/

#include "game.h"

int loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        handle_events(game);
        display(game);
    }
    return 0;
}

int game(void)
{
    game_t *game = init_game();

    if (!game)
        return 84;
    loop(game);
    destroy_game(game);
    return 0;
}
