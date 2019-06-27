#include "main.h"
#include "game_run.h"
#include "game_update.h"
#include "game_set.h"
#include "game_msg.h"

void game_run(void) {
    if (refresh > 0 && al_event_queue_is_empty(game_queue)) {
        if (refresh > 1) {
            game_log("%d frame(s) dropped", refresh - 1);
        }

        game_update();

        game_set();

        al_flip_display();

        refresh = 0;
    }
}
