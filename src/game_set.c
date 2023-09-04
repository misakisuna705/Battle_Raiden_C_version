#include "game_scene.h"
#include "game_set.h"
#include "game_scene/main_scene.h"
#include "game_scene/game_start.h"
#include "game_scene/play_scene.h"

void game_set(void) {
    switch (active_scene) {
    case MAIN_SCENE:
        main_scene_set();
        break;

    case GAME_START:
        game_start_set();
        break;

    case PLAY_SCENE:
        play_scene_set();
        break;
    }
}
