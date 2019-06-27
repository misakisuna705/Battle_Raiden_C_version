#ifndef _GAME_KEY_H_
#define _GAME_KEY_H_

#include <allegro5/allegro.h>

bool cur_key[ALLEGRO_KEY_MAX];

void game_key(int active_scene, int keycode);

#endif
