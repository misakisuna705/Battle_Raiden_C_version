#include "main.h"
#include "game_scene.h"
#include "game_scene/main_scene.h"

#define TITLE_BITMAP "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/title.png"
#define BACKGROUND_BITMAP "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/background.png"
#define BACKGROUND_SAMPLE "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/late_in_autumn.ogg"
#define LIGHTNING_BACK_BITMAP "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/lightning_back.png"
#define LIGHTNING_BACK_SAMPLE "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/lightning_back.ogg"
#define LIGHTNING_FRONT_BITMAP "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/lightning_front.png"
#define LIGHTNING_FRONT_SAMPLE "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/lightning_front.ogg"
#define BUTTON_BITMAP "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/button.png"
#define BUTTON_FONT "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/Genkai_Mincho.ttf"
#define SELECT_BITMAP "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/select.png"
#define SELECT_SAMPLE "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/select.ogg"
#define INFO_BOARD_BITMAP "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/info_board.png"
#define INFO_BOARD_FONT "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/Nagurigaki_Crayon.ttf"
#define INFO_BOARD_SAMPLE "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/info_board.ogg"
#define INFO_NPC_BITMAP "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/Komoe.png"
#define INFO_NPC_SAMPLE "/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/res/main_scene/Komoe.ogg"

#define LIGHTNING_NUM 2
#define BUTTON_NUM 4
#define INFO_NUM 4

//lightning count

enum {
    BACK,
    FRONT
};

//button count

enum {
    START,
    SCORE,
    INFO,
    EXIT
};

//info count

enum {
    MOVE,
    ATTACK,
    SKILL,
    PAUSE
};

//background

typedef struct {
    ALLEGRO_BITMAP * bitmap;
    ALLEGRO_SAMPLE * sample;
    ALLEGRO_SAMPLE_INSTANCE * sample_instance;
    bool sample_shown;
    double bitmap_x;
    double bitmap_y;
    unsigned sample_pos;
} Main_Scene_Background;

//lightning

typedef struct {
    ALLEGRO_BITMAP * bitmap;
    ALLEGRO_SAMPLE * sample;
    ALLEGRO_SAMPLE_INSTANCE * sample_instance;
    bool shown;
    double bitmap_x;
    double bitmap_y;
    double delay;
    double last_time;
    double this_time;
} Main_Scene_Lightning;

//button

typedef struct {
    ALLEGRO_BITMAP * bitmap;
    ALLEGRO_FONT * font;
    double bitmap_width;
    double bitmap_x;
    double bitmap_y;
    double font_x;
    double font_y;
} Main_Scene_Button;

//select

typedef struct {
    ALLEGRO_BITMAP * bitmap;
    ALLEGRO_SAMPLE * sample;
    ALLEGRO_SAMPLE_INSTANCE * sample_instance;
    bool sample_shown;
    double bitmap_x;
    double bitmap_y;
    unsigned bitmap_pos;
} Main_Scene_Select;

//title

typedef struct {
    ALLEGRO_BITMAP * bitmap;
    double bitmap_width;
    double bitmap_x;
    double bitmap_y;
} Main_Scene_Title;

//info board

typedef struct {
    ALLEGRO_BITMAP * bitmap;
    ALLEGRO_FONT * font[INFO_NUM];
    ALLEGRO_SAMPLE * sample;
    ALLEGRO_SAMPLE_INSTANCE * sample_instance;
    bool bitmap_shown;
    bool sample_shown;
    double bitmap_width;
    double bitmap_height;
    double bitmap_x;
    double bitmap_y;
    double bitmap_y_dir;
    double bitmap_y_speed;
    double font_x;
    double font_y[INFO_NUM];
} Main_Scene_Info_Board;

//info npc

typedef struct {
    ALLEGRO_BITMAP * bitmap;
    ALLEGRO_SAMPLE * sample;
    ALLEGRO_SAMPLE_INSTANCE * sample_instance;
    bool bitmap_shown;
    bool sample_shown;
    double bitmap_width;
    double bitmap_height;
    double bitmap_x;
    double bitmap_y;
    double bitmap_x_dir;
    double bitmap_x_speed;
} Main_Scene_Info_Npc;

Main_Scene_Background Background;
Main_Scene_Lightning Lightning[LIGHTNING_NUM];
Main_Scene_Button Button[BUTTON_NUM];
Main_Scene_Select Select;
Main_Scene_Title Title;
Main_Scene_Info_Board Info_Board;
Main_Scene_Info_Npc Info_Npc;

void main_scene_init(void) {
    int i;

    /*background init*/

    Background.bitmap = al_load_bitmap(BACKGROUND_BITMAP);
    Background.bitmap_x = -260;
    Background.bitmap_y = 0;
    Background.sample = al_load_sample(BACKGROUND_SAMPLE);
    Background.sample_instance = al_create_sample_instance(Background.sample);
    Background.sample_shown = true;
    Background.sample_pos = 0;
    al_set_sample_instance_playmode(Background.sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_gain(Background.sample_instance, 0.5f);
    al_attach_sample_instance_to_mixer(Background.sample_instance, al_get_default_mixer());

    /*lightning init*/

    Lightning[BACK].bitmap = al_load_bitmap(LIGHTNING_BACK_BITMAP);
    Lightning[BACK].bitmap_x = 0;
    Lightning[BACK].bitmap_y = 0;
    Lightning[BACK].sample = al_load_sample(LIGHTNING_BACK_SAMPLE);
    Lightning[BACK].sample_instance = al_create_sample_instance(Lightning[BACK].sample);
    Lightning[BACK].delay = 3;
    Lightning[BACK].last_time = 0;
    Lightning[BACK].this_time = 0;
    Lightning[BACK].shown = false;
    al_set_sample_instance_gain(Lightning[BACK].sample_instance, 0.3f);
    al_attach_sample_instance_to_mixer(Lightning[BACK].sample_instance, al_get_default_mixer());

    Lightning[FRONT].bitmap = al_load_bitmap(LIGHTNING_FRONT_BITMAP);
    Lightning[FRONT].bitmap_x = 0;
    Lightning[FRONT].bitmap_y = 0;
    Lightning[FRONT].sample = al_load_sample(LIGHTNING_FRONT_SAMPLE);
    Lightning[FRONT].sample_instance = al_create_sample_instance(Lightning[FRONT].sample);
    Lightning[FRONT].delay = 2;
    Lightning[FRONT].last_time = 0;
    Lightning[FRONT].this_time = 0;
    Lightning[FRONT].shown = false;
    al_set_sample_instance_gain(Lightning[FRONT].sample_instance, 0.3f);
    al_attach_sample_instance_to_mixer(Lightning[FRONT].sample_instance, al_get_default_mixer());

    /*button init*/

    for (i = 0; i < BUTTON_NUM; i++) {
        Button[i].bitmap = al_load_bitmap(BUTTON_BITMAP);
        Button[i].bitmap_width = al_get_bitmap_width(Button[i].bitmap);
        Button[i].bitmap_x = (GAME_WIDTH - Button[i].bitmap_width) / 2;
        Button[i].bitmap_y = 395 + i * 64;
        Button[i].font = al_load_font(BUTTON_FONT, 24, 0);
        Button[i].font_x = GAME_WIDTH / 2;
        Button[i].font_y = 405 + i * 64;
    }

    /*select init*/

    Select.bitmap = al_load_bitmap(SELECT_BITMAP);
    Select.bitmap_x = Button[START].bitmap_x - 28;
    Select.bitmap_y = Button[START].bitmap_y - 8;
    Select.bitmap_pos = 0;
    Select.sample = al_load_sample(SELECT_SAMPLE);
    Select.sample_instance = al_create_sample_instance(Select.sample);
    Select.sample_shown = false;
    al_attach_sample_instance_to_mixer(Select.sample_instance, al_get_default_mixer());

    /*title init*/

    Title.bitmap = al_load_bitmap(TITLE_BITMAP);
    Title.bitmap_width = al_get_bitmap_width(Title.bitmap);
    Title.bitmap_x = (GAME_WIDTH - Title.bitmap_width) / 2;
    Title.bitmap_y = 30;

    /*info board init*/

    Info_Board.bitmap = al_load_bitmap(INFO_BOARD_BITMAP);
    Info_Board.bitmap_width = al_get_bitmap_width(Info_Board.bitmap);
    Info_Board.bitmap_height = al_get_bitmap_height(Info_Board.bitmap);
    Info_Board.bitmap_x = (GAME_WIDTH - Info_Board.bitmap_width) / 2;
    Info_Board.bitmap_y = Info_Board.bitmap_height * (-1);
    Info_Board.bitmap_y_dir = 0;
    Info_Board.bitmap_y_speed = 40;
    Info_Board.bitmap_shown = false;
    for (i = 0; i < INFO_NUM; i++) {
        Info_Board.font[i] = al_load_font(INFO_BOARD_FONT, 32, 0);
        Info_Board.font_x = GAME_WIDTH / 2;
        Info_Board.font_y[i] = Info_Board.bitmap_y + 100 + i * 50;
    }
    Info_Board.sample = al_load_sample(INFO_BOARD_SAMPLE);
    Info_Board.sample_instance = al_create_sample_instance(Info_Board.sample);
    al_set_sample_instance_gain(Info_Board.sample_instance, 2.0f);
    al_attach_sample_instance_to_mixer(Info_Board.sample_instance, al_get_default_mixer());

    /*info npm init*/

    Info_Npc.bitmap = al_load_bitmap(INFO_NPC_BITMAP);
    Info_Npc.bitmap_width = al_get_bitmap_width(Info_Npc.bitmap);
    Info_Npc.bitmap_height = al_get_bitmap_height(Info_Npc.bitmap);
    Info_Npc.bitmap_x = GAME_WIDTH;
    Info_Npc.bitmap_y = GAME_HEIGHT - Info_Npc.bitmap_height;
    Info_Npc.bitmap_x_dir = 0;
    Info_Npc.bitmap_x_speed = 20;
    Info_Npc.bitmap_shown = false;
    Info_Npc.sample = al_load_sample(INFO_NPC_SAMPLE);
    Info_Npc.sample_instance = al_create_sample_instance(Info_Npc.sample);
    Info_Npc.sample_shown = false;
    al_attach_sample_instance_to_mixer(Info_Npc.sample_instance, al_get_default_mixer());
}

void main_scene_update(void) {
    int i;

    /*lightning update*/

    for (i = 0; i < LIGHTNING_NUM; i++) {
        Lightning[i].this_time = al_get_time();

        if (Lightning[i].this_time - Lightning[i].last_time > Lightning[i].delay) {
            Lightning[i].shown ^= true;

            Lightning[i].last_time = Lightning[i].this_time;
        }
    }

    /*select update*/

    Select.bitmap_y = Button[Select.bitmap_pos % 4].bitmap_y - 8;

    /*info board update*/

    if (Info_Board.bitmap_shown) {
        if (Info_Board.bitmap_y < 0) {
            Info_Board.bitmap_y_dir = 1;
            Info_Board.bitmap_y += Info_Board.bitmap_y_dir * Info_Board.bitmap_y_speed;
        }
    } else {
        if (Info_Board.bitmap_y > Info_Board.bitmap_height * (-1)) {
            Info_Board.bitmap_y_dir = -1;
            Info_Board.bitmap_y += Info_Board.bitmap_y_dir * Info_Board.bitmap_y_speed;
        }
    }
    for (i = 0; i < INFO_NUM; i++) {
        Info_Board.font_y[i] = Info_Board.bitmap_y + 100 + i * 50;
    }

    /*info npc update*/

    if (Info_Npc.bitmap_shown) {
        if (Info_Npc.bitmap_x + Info_Npc.bitmap_width > GAME_WIDTH) {
            Info_Npc.bitmap_x_dir = -1;
            Info_Npc.bitmap_x += Info_Npc.bitmap_x_dir * Info_Npc.bitmap_x_speed;
        }
    } else {
        if (Info_Npc.bitmap_x < GAME_WIDTH) {
            Info_Npc.bitmap_x_dir = 1;
            Info_Npc.bitmap_x += Info_Npc.bitmap_x_dir * Info_Npc.bitmap_x_speed;
        }
    }
}

void main_scene_set(void) {
    int i;

    /*background set*/

    al_draw_bitmap(Background.bitmap, Background.bitmap_x, Background.bitmap_y, 0);
    if (Background.sample_shown) {
        al_play_sample_instance(Background.sample_instance);
    } else {
        al_stop_sample_instance(Background.sample_instance);
    }

    /*lightning set*/

    for (i = 0; i < LIGHTNING_NUM; i++) {
        if (Lightning[i].shown) {
            al_draw_bitmap(Lightning[i].bitmap, Lightning[i].bitmap_x, Lightning[i].bitmap_y, 0);
            al_play_sample_instance(Lightning[i].sample_instance);
            Lightning[i].shown = false;
        }
    }

    /*button set*/

    for (i = 0; i < BUTTON_NUM; i++) {
        al_draw_bitmap(Button[i].bitmap, Button[i].bitmap_x, Button[i].bitmap_y, 0);
    }
    al_draw_text(Button[START].font, al_map_rgb(0, 0, 255), Button[START].font_x, Button[START].font_y, ALLEGRO_ALIGN_CENTER, "ゲーム始");
    al_draw_text(Button[SCORE].font, al_map_rgb(0, 0, 255), Button[SCORE].font_x, Button[SCORE].font_y, ALLEGRO_ALIGN_CENTER, "スコア");
    al_draw_text(Button[INFO].font, al_map_rgb(0, 0, 255), Button[INFO].font_x, Button[INFO].font_y, ALLEGRO_ALIGN_CENTER, "ヘルプ");
    al_draw_text(Button[EXIT].font, al_map_rgb(0, 0, 255), Button[EXIT].font_x, Button[EXIT].font_y, ALLEGRO_ALIGN_CENTER, "ゲーム終");

    /*select set*/

    al_draw_bitmap(Select.bitmap, Select.bitmap_x, Select.bitmap_y, 0);
    if (Select.sample_shown) {
        al_play_sample_instance(Select.sample_instance);
        Select.sample_shown = false;
    }

    /*title set*/

    al_draw_bitmap(Title.bitmap, Title.bitmap_x, Title.bitmap_y, 0);

    /*info board set*/

    al_draw_bitmap(Info_Board.bitmap, Info_Board.bitmap_x, Info_Board.bitmap_y, 0);
    al_draw_text(Info_Board.font[MOVE], al_map_rgb(255, 255, 255), Info_Board.font_x, Info_Board.font_y[MOVE], ALLEGRO_ALIGN_CENTER, "移動：方向キー");
    al_draw_text(Info_Board.font[ATTACK], al_map_rgb(255, 255, 255), Info_Board.font_x, Info_Board.font_y[ATTACK], ALLEGRO_ALIGN_CENTER, "攻撃：z");
    al_draw_text(Info_Board.font[SKILL], al_map_rgb(255, 255, 255), Info_Board.font_x, Info_Board.font_y[SKILL], ALLEGRO_ALIGN_CENTER, "スキル：x");
    al_draw_text(Info_Board.font[SKILL], al_map_rgb(255, 255, 255), Info_Board.font_x, Info_Board.font_y[PAUSE], ALLEGRO_ALIGN_CENTER, "タイム：space");
    if (Info_Board.sample_shown) {
        al_play_sample_instance(Info_Board.sample_instance);
        Info_Board.sample_shown = false;
    }

    /*info npc set*/

    al_draw_bitmap(Info_Npc.bitmap, Info_Npc.bitmap_x, Info_Npc.bitmap_y, 0);
    if (Info_Npc.sample_shown) {
        al_play_sample_instance(Info_Npc.sample_instance);
        Info_Npc.sample_shown = false;
    }
}

void main_scene_destroy(void) {
    int i;

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

    /*lightning destroy*/

    for (i = 0; i < LIGHTNING_NUM; i++) {
        if (Lightning[i].bitmap) {
            al_destroy_bitmap(Lightning[i].bitmap);
            Lightning[i].bitmap = NULL;
        }
        if (Lightning[i].sample) {
            al_destroy_sample(Lightning[i].sample);
            Lightning[i].sample = NULL;
        }
        if (Lightning[i].sample_instance) {
            al_destroy_sample_instance(Lightning[i].sample_instance);
            Lightning[i].sample_instance = NULL;
        }
    }

    /*button destroy*/

    for (i = 0; i < BUTTON_NUM; i++) {
        if (Button[i].bitmap) {
            al_destroy_bitmap(Button[i].bitmap);
            Button[i].bitmap = NULL;
        }
        if (Button[i].font) {
            al_destroy_font(Button[i].font);
            Button[i].font = NULL;
        }
    }

    /*select destroy*/

    if (Select.bitmap) {
        al_destroy_bitmap(Select.bitmap);
        Select.bitmap = NULL;
    }
    if (Select.sample) {
        al_destroy_sample(Select.sample);
        Select.sample = NULL;
    }
    if (Select.sample_instance) {
        al_destroy_sample_instance(Select.sample_instance);
        Select.sample_instance = NULL;
    }

    /*title destroy*/

    if (Title.bitmap) {
        al_destroy_bitmap(Title.bitmap);
        Title.bitmap = NULL;
    }

    /*info board destroy*/

    if (Info_Board.bitmap) {
        al_destroy_bitmap(Info_Board.bitmap);
        Info_Board.bitmap = NULL;
    }
    for (i = 0; i < INFO_NUM; i++) {
        if (Info_Board.font[i]) {
            al_destroy_font(Info_Board.font[i]);
            Info_Board.font[i] = NULL;
        }
    }
    if (Info_Board.sample) {
        al_destroy_sample(Info_Board.sample);
        Info_Board.sample = NULL;
    }
    if (Info_Board.sample_instance) {
        al_destroy_sample_instance(Info_Board.sample_instance);
        Info_Board.sample_instance = NULL;
    }

    /*info npc destroy*/

    if (Info_Npc.bitmap) {
        al_destroy_bitmap(Info_Npc.bitmap);
        Info_Npc.bitmap = NULL;
    }
    if (Info_Npc.sample) {
        al_destroy_sample(Info_Npc.sample);
        Info_Npc.sample = NULL;
    }
    if (Info_Npc.sample_instance) {
        al_destroy_sample_instance(Info_Npc.sample_instance);
        Info_Npc.sample_instance = NULL;
    }
}

void main_scene_key(int keycode) {
    switch (keycode) {
    case ALLEGRO_KEY_UP:
        Select.bitmap_pos += 3;
        Select.sample_shown = true;
        break;

    case ALLEGRO_KEY_DOWN:
        Select.bitmap_pos++;
        Select.sample_shown = true;
        break;

    case ALLEGRO_KEY_ENTER:
        if (Select.bitmap_y == Button[START].bitmap_y - 8) {
            al_stop_sample_instance(Background.sample_instance);

            game_scene(MAIN_SCENE, GAME_START);
        } else if (Select.bitmap_y == Button[SCORE].bitmap_y - 8) {
        } else if (Select.bitmap_y == Button[INFO].bitmap_y - 8) {
            if (Background.sample_shown) {
                Background.sample_pos = al_get_sample_instance_position(Background.sample_instance);
                Background.sample_shown = false;
            } else {
                al_set_sample_instance_position(Background.sample_instance, Background.sample_pos);
                Background.sample_shown = true;
            }

            if (Info_Board.bitmap_shown) {
                Info_Board.bitmap_shown = false;
                Info_Board.sample_shown = true;
            } else {
                Info_Board.bitmap_shown = true;
                Info_Board.sample_shown = true;
            }

            if (Info_Npc.bitmap_shown) {
                Info_Npc.bitmap_shown = false;
            } else {
                Info_Npc.bitmap_shown = true;
                Info_Npc.sample_shown = true;
            }
        } else if (Select.bitmap_y == Button[EXIT].bitmap_y - 8) {
            game_exit = true;
        }
        break;
    }
}
