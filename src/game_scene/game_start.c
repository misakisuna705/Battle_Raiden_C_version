#include "main.h"
#include "game_scene.h"
#include "game_scene/game_start.h"

#define TITLE_BITMAP "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/game_start/title.png"
#define GAME_START_VIDEO "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/game_start/game_start.ogv"

/*title*/

typedef struct {
    ALLEGRO_BITMAP * bitmap;
    double bitmap_width;
    double bitmap_x;
    double bitmap_y;
} Game_Start_Title;

Game_Start_Title Title;

ALLEGRO_VIDEO * game_start_video;

void game_start_init(void) {

    /*game start video init*/

    game_start_video = al_open_video(GAME_START_VIDEO);
    al_register_event_source(game_queue, al_get_video_event_source(game_start_video));
    al_set_mixer_gain(al_get_default_mixer(), 1.5);
    al_start_video(game_start_video, al_get_default_mixer());

    /*title init*/

    Title.bitmap = al_load_bitmap(TITLE_BITMAP);
    Title.bitmap_width = al_get_bitmap_width(Title.bitmap);
    Title.bitmap_x = (GAME_WIDTH - Title.bitmap_width) / 2;
    Title.bitmap_y = 30;
}

void game_start_set(void) {

    /*game start video set*/

    if (al_get_video_frame(game_start_video)) {
        al_draw_bitmap(al_get_video_frame(game_start_video), -260, 0, 0);
    }

    if (!al_is_video_playing(game_start_video)) {
        al_set_mixer_gain(al_get_default_mixer(), 1.0);
        game_scene(GAME_START, PLAY_SCENE);
    }

    /*title set*/

    al_draw_bitmap(Title.bitmap, Title.bitmap_x, Title.bitmap_y, 0);
}

void game_start_destroy(void) {

    /*game start video destroy*/

    if (game_start_video) {
        al_close_video(game_start_video);
        game_start_video = NULL;
    }

    /*title destroy*/

    if (Title.bitmap) {
        al_destroy_bitmap(Title.bitmap);
        Title.bitmap = NULL;
    }
}
