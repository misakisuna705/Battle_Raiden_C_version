#include "main.h"
#include "game_scene/allegro_exit.h"

void allegro_exit(void) {
    if (game_display) {
        al_destroy_display(game_display);
        game_display = NULL;
    }

    if (game_timer) {
        al_destroy_timer(game_timer);
        game_timer = NULL;
    }

    if (game_queue) {
        al_destroy_event_queue(game_queue);
        game_queue = NULL;
    }
}
