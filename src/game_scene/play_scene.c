#include "main.h"
#include "game_scene.h"
#include "game_scene/play_scene.h"

#define BACKGROUND_BITMAP "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/play_scene/background.png"
#define BACKGROUND_SAMPLE "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/play_scene/future_gazer.ogg"

/*background*/

typedef struct {
    ALLEGRO_BITMAP * bitmap;
    ALLEGRO_SAMPLE * sample;
    ALLEGRO_SAMPLE_INSTANCE * sample_instance;
    bool sample_shown;
    double bitmap_height;
    double bitmap_x;
    double bitmap_y;
    double bitmap_y_dir;
    double bitmap_y_speed;
    unsigned sample_pos;
} Play_Scene_Background;

Play_Scene_Background Background;

void play_scene_init(void) {

    /*background init*/

    Background.bitmap = al_load_bitmap(BACKGROUND_BITMAP);
    Background.bitmap_height = al_get_bitmap_height(Background.bitmap);
    Background.bitmap_x = -260;
    Background.bitmap_y = Background.bitmap_height / 2 * (-1);
    Background.bitmap_y_dir = 1;
    Background.bitmap_y_speed = 3;
    Background.sample = al_load_sample(BACKGROUND_SAMPLE);
    Background.sample_instance = al_create_sample_instance(Background.sample);
    Background.sample_shown = true;
    Background.sample_pos = 0;
    al_set_sample_instance_playmode(Background.sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_gain(Background.sample_instance, 0.5f);
    al_attach_sample_instance_to_mixer(Background.sample_instance, al_get_default_mixer());
}

void play_scene_update(void) {
    Background.bitmap_y += Background.bitmap_y_dir * Background.bitmap_y_speed;
    if (Background.bitmap_y >= Background.bitmap_height / 2) {
        Background.bitmap_y = Background.bitmap_height / 2 * (-1);
    }
}

void play_scene_set(void) {

    /*background set*/

    al_draw_bitmap(Background.bitmap, Background.bitmap_x, Background.bitmap_y, 0);
    if (Background.bitmap_y >= 0) {
        al_draw_bitmap(Background.bitmap, Background.bitmap_x, Background.bitmap_y - Background.bitmap_height, 0);
    }
    if (Background.sample_shown) {
        al_play_sample_instance(Background.sample_instance);
    } else {
        al_stop_sample_instance(Background.sample_instance);
    }
}

void play_scene_destroy(void) {

    /*background destroy*/

    if (Background.bitmap) {
        al_destroy_bitmap(Background.bitmap);
        Background.bitmap = NULL;
    }
    if (Background.sample) {
        al_destroy_sample(Background.sample);
        Background.sample = NULL;
    }
    if (Background.sample_instance) {
        al_destroy_sample_instance(Background.sample_instance);
        Background.sample_instance = NULL;
    }
}

void play_scene_key(int keycode) {
}
