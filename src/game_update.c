#include "game_scene.h"
#include "game_update.h"
#include "game_scene/main_scene.h"
#include "game_scene/play_scene.h"

void game_update(void) {
    switch (active_scene) {
    case MAIN_SCENE:
        main_scene_update();
        break;

    case PLAY_SCENE:
        play_scene_update();
        break;
    }
}
