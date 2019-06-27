#ifndef _MAIN_H_
#define _MAIN_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_video.h>

#define GAME_WIDTH 480
#define GAME_HEIGHT 640
#define GAME_TITLE "Toaru_Fighter_No_Railgun"
#define GAME_FPS 60.0

#define SAMPLE_RESERVE_NUM 10

ALLEGRO_DISPLAY * game_display;
ALLEGRO_TIMER * game_timer;
ALLEGRO_EVENT_QUEUE * game_queue;

bool game_exit;

int refresh;

#endif
