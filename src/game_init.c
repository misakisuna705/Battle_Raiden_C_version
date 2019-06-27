#include "main.h"
#include "game_scene.h"
#include "game_init.h"
#include "game_msg.h"
#include "game_scene/allegro_init.h"
#include "game_scene/main_scene.h"
#include "game_scene/game_start.h"
#include "game_scene/play_scene.h"

void game_init(int obj_scene) {
    switch (obj_scene) {
    case MAIN_SCENE:
        game_log("\n\t\tInitialize main scene...");
        main_scene_init();
        game_log("\t\tSucceeded to initialize main scene!\n");
        break;

    case GAME_START:
        game_log("\n\t\tInitialize game start...");
        game_start_init();
        game_log("\t\tSucceeded to initialize game start!\n");
        break;

    case PLAY_SCENE:
        game_log("\n\t\tInitialize play scene...");
        play_scene_init();
        game_log("\t\tSucceeded to initialize play scene!\n");
        break;

    case ALLEGRO_INIT:
        game_log("\n\t\tInitialize allegro...");
        allegro_init();
        game_log("\t\tSucceeded to initialize allegro!\n");
        break;
    }
}
