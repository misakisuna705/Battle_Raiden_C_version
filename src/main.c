#include "main.h"
#include "game_scene.h"
#include "game_init.h"
#include "game_process.h"
#include "game_run.h"
#include "game_destroy.h"
#include "game_msg.h"

int main(void) {
    srand((unsigned)time(NULL));

    game_log("Game start...");
    game_init(ALLEGRO_INIT);
    game_log("Succeeded to start game!");

    game_scene(ALLEGRO_INIT, MAIN_SCENE);

    game_log("Game run...\n");
    while (!game_exit) {
        game_process();

        game_run();
    }
    game_log("\nSucceeded to run game!\n");

    game_log("Game exit...");
    game_destroy(ALLEGRO_EXIT);
    game_log("Succeeded to exit game!");

    return 0;
}
