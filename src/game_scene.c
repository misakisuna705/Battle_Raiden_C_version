#include "main.h"
#include "game_scene.h"
#include "game_init.h"
#include "game_destroy.h"
#include "game_msg.h"

void game_scene(int cur_scene, int next_scene) {
    if (cur_scene == ALLEGRO_INIT && next_scene == MAIN_SCENE) {
        game_log("\n\tChange scene to main scene...");
        game_init(MAIN_SCENE);
    } else if (cur_scene == MAIN_SCENE && next_scene == GAME_START) {
        game_log("\n\tChange scene from main scene to game start...");
        game_init(GAME_START);
        game_init(PLAY_SCENE);
    }

    active_scene = next_scene;
    game_log("\tSucceeded to change scene!\n");
}
