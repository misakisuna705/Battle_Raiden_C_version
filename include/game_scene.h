#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

enum {
    ALLEGRO_INIT,
    MAIN_SCENE,
    GAME_START,
    PLAY_SCENE,
    ALLEGRO_EXIT
};

int active_scene;

void game_scene(int cur_scene, int next_scene);

#endif
