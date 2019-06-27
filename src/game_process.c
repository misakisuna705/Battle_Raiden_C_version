#include "main.h"
#include "game_scene.h"
#include "game_process.h"
#include "game_key.h"
#include "game_msg.h"

void game_process(void) {
    ALLEGRO_EVENT game_event;

    al_wait_for_event(game_queue, &game_event);

    switch (game_event.type) {
    case ALLEGRO_EVENT_TIMER:
        refresh++;
        break;

    case ALLEGRO_EVENT_KEY_DOWN:
        game_log("Key %d down.", game_event.keyboard.keycode);
        cur_key[game_event.keyboard.keycode] = true;
        game_key(active_scene, game_event.keyboard.keycode);
        break;

    case ALLEGRO_EVENT_KEY_UP:
        game_log("Key %d up.", game_event.keyboard.keycode);
        cur_key[game_event.keyboard.keycode] = false;
        break;

    case ALLEGRO_EVENT_VIDEO_FRAME_SHOW:
        refresh++;
        break;

    case ALLEGRO_EVENT_DISPLAY_CLOSE:
        game_exit = true;
        break;
    }
}
