#include "main.h"
#include "game_msg.h"

void allegro_init(void) {
    if (!al_init()) {
        game_err("Failed to initialize allegro!");
    }

    if (!al_init_font_addon() || !al_init_ttf_addon()) {
        game_err("Failed to initialize text!");
    }

    if (!al_init_image_addon()) {
        game_err("Failed to initialize image!");
    }

    if (!al_install_audio() || !al_init_acodec_addon() || !al_reserve_samples(SAMPLE_RESERVE_NUM)) {
        game_err("Failed to initialize audio!");
    }

    if (!al_init_video_addon()) {
        game_err("Failed to initialize video!");
    }

    if (!al_install_keyboard()) {
        game_err("Failed to install keyboard!");
    }

    game_display = al_create_display(GAME_WIDTH, GAME_HEIGHT);
    if (!game_display) {
        game_err("Failed to create display!");
    }
    al_set_window_title(game_display, GAME_TITLE);

    game_timer = al_create_timer(1.0 / GAME_FPS);
    if (!game_timer) {
        game_err("Failed to create timer!");
    }

    game_queue = al_create_event_queue();
    if (!game_queue) {
        game_err("Failed to create event queue!");
    }

    al_register_event_source(game_queue, al_get_keyboard_event_source());
    al_register_event_source(game_queue, al_get_display_event_source(game_display));
    al_register_event_source(game_queue, al_get_timer_event_source(game_timer));

    al_start_timer(game_timer);
}
