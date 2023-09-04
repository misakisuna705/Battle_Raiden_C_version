#include "game_scene.h"
#include "game_key.h"
#include "game_scene/main_scene.h"

void game_key(int active_scene, int keycode) {
    switch(active_scene) {
    case MAIN_SCENE:
        main_scene_key(keycode);
        break;
    }
}
