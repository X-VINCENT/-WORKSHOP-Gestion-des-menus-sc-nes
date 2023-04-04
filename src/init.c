/*
** EPITECH PROJECT, 2023
** CSFML-Menus-Scenes
** File description:
** init
*/

#include "game.h"

sfSprite *create_sprite(sfTexture *texture, sfIntRect rect,
    sfVector2f position, sfVector2f scale)
{
    sfSprite *sprite = NULL;

    if (!texture)
        return NULL;
    if (!(sprite = sfSprite_create()))
        return NULL;
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    return sprite;
}

particle_t *create_particle_list(sfTexture *texture,
    sfIntRect rect, sfVector2f pos, sfVector2f scale)
{
    particle_t *list = malloc(sizeof(particle_t));

    list->sprite = create_sprite(texture, rect, pos, scale);
    list->next = NULL;
    list->previous = NULL;
    return list;
}

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

particle_t *add_node(particle_t *list, sfTexture *texture,
    sfIntRect rect, sfVector2f pos, sfVector2f scale)
{
    particle_t *head = list;
    particle_t *node = malloc(sizeof(particle_t));

    while (list->next != NULL)
        list = list->next;
    list->next = node;
    node->sprite = create_sprite(texture, rect, pos, scale);
    node->next = NULL;
    node->previous = list;
    return head;
}

void init_list(game_t *game)
{
    game->texture_list = sfTexture_createFromFile("assets/rain.png", NULL);
    sfIntRect rect = {0, 0, 3, 5};
    sfVector2f pos = {0, 0};
    sfVector2f scale = {5, 5};
    game->list = create_particle_list(game->texture_list, rect, pos, scale);
    for (int i = 0; i < 1000; i++) {
        pos.x = rand() % (1920);
        pos.y = rand() % (1080);
        game->list = add_node(game->list, game->texture_list, rect, pos, scale);
    }

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
    game->current_menu = MENU_1;

    game->clock_list = sfClock_create();
    init_list(game);
    return game;
}
