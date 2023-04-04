/*
** EPITECH PROJECT, 2023
** CSFML-Menus-Scenes
** File description:
** init
*/

#include "game.h"

fonts_t *init_fonts(void)
{
    fonts_t *fonts = malloc(sizeof(fonts_t));

    fonts->arial = sfFont_createFromFile("assets/fonts/arial.ttf");
    return fonts;
}

button_t *create_button(
    sfColor color,
    sfVector2f size,
    sfVector2f pos,
    sfFont *font,
    const char *text
)
{
    button_t *button = malloc(sizeof(button_t));

    button->background = sfRectangleShape_create();
    button->text = sfText_create();
    sfRectangleShape_setFillColor(button->background, color);
    sfRectangleShape_setSize(button->background, size);
    sfRectangleShape_setPosition(button->background, pos);
    sfText_setString(button->text, text);
    sfText_setFont(button->text, font);
    sfText_setCharacterSize(button->text, 30);
    sfText_setColor(button->text, sfWhite);
    sfText_setPosition(button->text, (sfVector2f){
        pos.x + size.x / 2,
        pos.y + size.y / 2
    });
    sfText_setOrigin(button->text, (sfVector2f){
        sfText_getLocalBounds(button->text).width / 2,
        sfText_getLocalBounds(button->text).height / 2
    });
    return button;
}

navbar_t *init_navbar(sfFont *font)
{
    navbar_t *navbar = malloc(sizeof(navbar_t));

    navbar->background = sfRectangleShape_create();
    sfRectangleShape_setFillColor(navbar->background, sfBlack);
    sfRectangleShape_setSize(navbar->background, (sfVector2f){1920, 100});
    sfRectangleShape_setPosition(navbar->background, (sfVector2f){0, 0});
    navbar->button_1 = create_button(
        sfRed,
        (sfVector2f){200, 100},
        (sfVector2f){0, 0},
        font,
        "Menu 1"
    );
    navbar->button_2 = create_button(
        sfGreen,
        (sfVector2f){200, 100},
        (sfVector2f){200, 0},
        font,
        "Menu 2"
    );
    navbar->button_3 = create_button(
        sfBlue,
        (sfVector2f){200, 100},
        (sfVector2f){400, 0},
        font,
        "Menu 3"
    );
    navbar->button_4 = create_button(
        sfYellow,
        (sfVector2f){200, 100},
        (sfVector2f){600, 0},
        font,
        "Menu 4"
    );
    return navbar;
}

menu_t *init_menu(sfColor color, sfFont *font, const char *text)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->background = sfRectangleShape_create();
    sfRectangleShape_setFillColor(menu->background, color);
    sfRectangleShape_setSize(menu->background, (sfVector2f){1920, 980});
    sfRectangleShape_setPosition(menu->background, (sfVector2f){0, 100});
    menu->text = sfText_create();
    sfText_setString(menu->text, text);
    sfText_setFont(menu->text, font);
    sfText_setCharacterSize(menu->text, 30);
    sfText_setColor(menu->text, sfWhite);
    sfText_setPosition(menu->text, (sfVector2f){960, 540});
    sfText_setOrigin(menu->text, (sfVector2f){
        sfText_getLocalBounds(menu->text).width / 2,
        sfText_getLocalBounds(menu->text).height / 2
    });
    return menu;
}

menus_t *init_menus(sfFont *font)
{
    menus_t *menus = malloc(sizeof(menus_t));

    menus->menu_1 = init_menu(sfRed, font, "Menu 1");
    menus->menu_2 = init_menu(sfGreen, font, "Menu 2");
    menus->menu_3 = init_menu(sfBlue, font, "Menu 3");
    menus->menu_4 = init_menu(sfYellow, font, "Menu 4");
    return menus;
}

void init_character(game_t *game)
{
    game->character = sfRectangleShape_create();
    sfRectangleShape_setFillColor(game->character, sfGreen);
    sfRectangleShape_setSize(game->character, (sfVector2f){100, 100});
    sfRectangleShape_setPosition(game->character, (sfVector2f){160, 120});
    sfRectangleShape_setOrigin(game->character, (sfVector2f){50, 50});
    game->character_size = 50;
    game->character_speed = 50;
}

void init_hitbox(game_t *game)
{
    game->map_texture = sfTexture_createFromFile("assets/bg.png", NULL);
    game->map = sfSprite_create();
    game->map_texture_top = sfTexture_createFromFile("assets/bg_top.png", NULL);
    game->map_top = sfSprite_create();
    sfSprite_setTexture(game->map, game->map_texture, sfTrue);
    sfSprite_setTexture(game->map_top, game->map_texture_top, sfTrue);
    game->hitbox = sfImage_createFromFile("assets/hitbox.png");
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->window = sfRenderWindow_create(
        (sfVideoMode){1920, 1080, 32},
        "CSFML-Menus-Scenes",
        sfClose,
        NULL
    );
    game->event = malloc(sizeof(sfEvent));
    game->fonts = init_fonts();
    game->navbar = init_navbar(game->fonts->arial);
    game->menus = init_menus(game->fonts->arial);
    init_character(game);
    init_hitbox(game);
    game->current_menu = MENU_1;
    return game;
}
