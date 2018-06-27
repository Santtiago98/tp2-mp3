#ifndef MP3__H
#define MP3__H

#include <stdio.h>

#include "main.h"
#include "errors.h"
#include "types.h"
#include "vector.h"
#include "utils.h"


#define MP3_HEADER_SIZE		128

#define LEXEM_START_TAG     0
#define LEXEM_SPAN_TAG      3

#define LEXEM_START_TITLE   3
#define LEXEM_SPAN_TITLE   30

#define LEXEM_START_ARTIST 33
#define LEXEM_SPAN_ARTIST  30

#define LEXEM_START_ALBUM  63
#define LEXEM_SPAN_ALBUM   30

#define LEXEM_START_YEAR   93
#define LEXEM_SPAN_YEAR     4

#define LEXEM_START_COMMENT 97
#define LEXEM_SPAN_COMMENT  30

#define LEXEM_START_GENRE  127
#define LEXEM_SPAN_GENRE     1
#define MAX_GENRES 126


typedef enum
{
    GENRE_BLUES,
    GENRE_CLASSIC_ROCK,
    GENRE_COUNTRY,
    GENRE_DANCE,
    GENRE_DISCO,
    GENRE_FUNK,
    GENRE_GRUNGE,
    GENRE_HIP_HOP,
    GENRE_JAZZ,
    GENRE_METAL,
    GENRE_NEW_AGE,
    GENRE_OLDIES,
    GENRE_OTHER,
    GENRE_POP,
    GENRE_R_N_B,
    GENRE_RAP,
    GENRE_REGGAE,
    GENRE_ROCK,
    GENRE_TECHNO,
    GENRE_INDUSTRIAL,
    GENRE_ALTERNATIVE,
    GENRE_SKA,
    GENRE_DEATH_METAL,
    GENRE_PRANKS,
    GENRE_SOUNDTRACK,
    GENRE_EURO_TECHNO,
    GENRE_AMBIENT,
    GENRE_TRIP_HOP,
    GENRE_VOCAL,
    GENRE_JAZZ_PLUS_FUNK,
    GENRE_FUSION,
    GENRE_TRANCE,
    GENRE_CLASSICAL,
    GENRE_INSTRUMENTAL,
    GENRE_ACID,
    GENRE_HOUSE,
    GENRE_GAME,
    GENRE_SOUND_CLIP,
    GENRE_GOSPEL,
    GENRE_NOISE,
    GENRE_ALTERNROCK,
    GENRE_BASS,
    GENRE_SOUL,
    GENRE_PUNK,
    GENRE_SPACE,
    GENRE_MEDITATIVE,
    GENRE_INSTRUMENTAL_POP,
    GENRE_INSTRUMENTAL_ROCK,
    GENRE_ETHNIC,
    GENRE_GOTHIC,
    GENRE_DARKWAVE,
    GENRE_TECHNO_INDUSTRIAL,
    GENRE_ELECTRONIC,
    GENRE_POP_FOLK,
    GENRE_EURODANCE,
    GENRE_DREAM,
    GENRE_SOUTHERN_ROCK,
    GENRE_COMEDY,
    GENRE_CULT,
    GENRE_GANGSTA,
    GENRE_TOP_40,
    GENRE_CHRISTIAN_RAP,
    GENRE_POP_FUNK,
    GENRE_JUNGLE,
    GENRE_NATIVE_AMERICAN,
    GENRE_CABARET,
    GENRE_NEW_WAVE,
    GENRE_PSYCHADELIC,
    GENRE_RAVE,
    GENRE_SHOWTUNES,
    GENRE_TRAILER,
    GENRE_LO_FI,
    GENRE_TRIBAL,
    GENRE_ACID_PUNK,
    GENRE_ACID_JAZZ,
    GENRE_POLKA,
    GENRE_RETRO,
    GENRE_MUSICAL,
    GENRE_ROCK_N_ROLL,
    GENRE_HARD_ROCK,
    GENRE_FOLK,
    GENRE_FOLK_ROCK,
    GENRE_NATIONAL_FOLK,
    GENRE_SWING,
    GENRE_FAST_FUSION,
    GENRE_BEBOB,
    GENRE_LATIN,
    GENRE_REVIVAL,
    GENRE_CELTIC,
    GENRE_BLUEGRASS,
    GENRE_AVANTGARDE,
    GENRE_GOTHIC_ROCK,
    GENRE_PROGRESSIVE_ROCK,
    GENRE_PSYCHEDELIC_ROCK,
    GENRE_SYMPHONIC_ROCK,
    GENRE_SLOW_ROCK,
    GENRE_BIG_BAND,
    GENRE_CHORUS,
    GENRE_EASY_LISTENING,
    GENRE_ACOUSTIC,
    GENRE_HUMOUR,
    GENRE_SPEECH,
    GENRE_CHANSON,
    GENRE_OPERA,
    GENRE_CHAMBER_MUSIC,
    GENRE_SONATA,
    GENRE_SYMPHONY,
    GENRE_BOOTY_BRASS,
    GENRE_PRIMUS,
    GENRE_PORN_GROOVE,
    GENRE_SATIRE,
    GENRE_SLOW_JAM,
    GENRE_CLUB,
    GENRE_TANGO,
    GENRE_SAMBA,
    GENRE_FOLKLORE,
    GENRE_BALLAD,
    GENRE_POWEER_BALLAD,
    GENRE_RHYTMIC_SOUL,
    GENRE_FREESTYLE,
    GENRE_DUET,
    GENRE_PUNK_ROCK,
    GENRE_DRUM_SOLO,
    GENRE_A_CAPELA,
    GENRE_EURO_HOUSE,
    GENRE_DANCE_HALL

}genre_t;

typedef struct
{
    char tag[LEXEM_SPAN_TAG +1];
    char title[LEXEM_SPAN_TITLE + 1];
    char artist[LEXEM_SPAN_ARTIST +1];
    char album[LEXEM_SPAN_ALBUM +1];
    char genre[LEXEM_SPAN_GENRE +1];
    short year;

}ADT_Track_t;

status_t ADT_Track_new_from_binary_file (FILE *, ADT_Track_t **);
status_t ADT_Track_delete(void **);
status_t ADT_Track_compare(ADT_Track_t *, ADT_Track_t *);
status_t read_header (FILE *, char []); /*cambiar de lugar a utils?? */
status_t ADT_Track_print_to_csv(FILE*,void *);
status_t ADT_Track_print_to_xml(FILE*,void *);
status_t ADT_Track_print_to_html(FILE *, void *);
int compare_strings(const char *,const char *);
int compare_by_title(const void *, const void *);
int compare_by_artist(const void *, const void *);
int compare_by_genre(const void*, const void *);


#endif
