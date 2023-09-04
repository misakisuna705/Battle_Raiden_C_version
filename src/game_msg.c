#include "main.h"
#include "game_msg.h"

void game_msg(const char * msg, va_list arg);

void game_log(const char * log_msg, ...) {
#ifdef GAME_LOG

    va_list arg;

    va_start(arg, log_msg);
    game_msg(log_msg, arg);
    va_end(arg);

#endif
}

void game_err(const char * err_msg, ...) {
    va_list arg;

    va_start(arg, err_msg);
    game_msg(err_msg, arg);
    va_end(arg);

    fprintf(stderr, "\nError occured!\n");

    exit(EXIT_FAILURE);
}

void game_msg(const char * msg, va_list arg) {
#ifdef GAME_LOG

    static bool clear_file = true;

    vprintf(msg, arg);
    printf("\n");

    FILE * pFile = fopen("/Volumes/misakisuna/Google_Drive/程式/Toaru_Fighter_No_Railgun/test/game_msg.log", clear_file ? "w" : "a");

    vfprintf(pFile, msg, arg);
    fprintf(pFile, "\n");

    fclose(pFile);

    clear_file = false;

#endif
}
