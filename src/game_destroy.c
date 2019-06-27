#include "main.h"
#include "game_scene.h"
#include "game_destroy.h"
#include "game_msg.h"
#include "game_scene/allegro_exit.h"
#include "game_scene/main_scene.h"
#include "game_scene/game_start.h"
#include "game_scene/play_scene.h"

void game_destroy(int obj_scene) {
    switch (obj_scene) {
    case MAIN_SCENE:
        game_log("\n\t\tDestroy main scene...");
        main_scene_destroy();
        game_log("\t\tSucceeded to destroy main scene!\n");
        break;

    case GAME_START:
        game_log("\n\t\tDestroy game start...");
        game_start_destroy();
        game_log("\t\tSucceeded to destroy gaem start!\n");
        break;

    case PLAY_SCENE:
        game_log("\n\t\tDestroy play scene...");
        play_scene_destroy();
        game_log("\t\tSucceeded to destroy play scene...\n");
        break;

    case ALLEGRO_EXIT:
        game_log("\n\t\tDestroy main scene...");
        main_scene_destroy();
        game_log("\t\tSucceeded to destroy main scene!\n");

        game_log("\t\tDestroy game start...");
        game_start_destroy();
        game_log("\t\tSucceeded to destroy gaem start!\n");

        game_log("\n\t\tDestroy play scene...");
        play_scene_destroy();
        game_log("\t\tSucceeded to destroy play scene...\n");

        game_log("\t\tDestroy allegro...");
        allegro_exit();
        game_log("\t\tSucceeded to destroy allegro!\n");
        break;
    }
}
