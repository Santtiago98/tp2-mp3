#include <stdlib.h>
#include <string.h>
#include "mp3.h"

char * genres[MAX_GENRES]=
        {
                "Blues",
                "Classic Rock",
                "Country",
                "Dance",
                "Disco",
                "Funk",
                "Grunge",
                "Hip-Hop",
                "Jazz",
                "Metal",
                "New Age",
                "Oldies",
                "Other",
                "Pop",
                "R&B",
                "Rap",
                "Reggae",
                "Rock",
                "Techno",
                "Industrial",
                "Alternative",
                "Ska",
                "Death Metal",
                "Pranks",
                "Soundtrack",
                "Euro-Techno",
                "Ambient",
                "Trip-Hop",
                "Vocal",
                "Jazz+Funk",
                "Fusion",
                "Trance",
                "Classical",
                "Instrumental",
                "Acid",
                "House",
                "Game",
                "Sound Clip",
                "Gospel",
                "Noise",
                "AlternRock",
                "Bass",
                "Soul",
                "Punk",
                "Space",
                "Meditative",
                "Instrumental Pop",
                "Instrumental Rock",
                "Ethnic",
                "Gothic",
                "Darkwave",
                "Techno-Industrial",
                "Electronic",
                "Pop-Folk",
                "Eurodance",
                "Dream",
                "Southern Rock",
                "Comedy",
                "Cult",
                "Gangsta",
                "Top 40",
                "hristian Rap",
                "Pop/Funk",
                "Jungle",
                "Native American",
                "Cabaret",
                "New Wave",
                "Psychadelic",
                "Rave",
                "Showtunes",
                "Trailer",
                "Lo-Fi",
                "Tribal",
                "Acid Punk",
                "Acid Jazz",
                "Polka",
                "Retro",
                "Musical",
                "Rock & Roll",
                "Hard Rock",
                "Folk",
                "Folk-Rock",
                "National Folk",
                "Swing",
                "Fast Fusion",
                "Bebob",
                "Latin",
                "Revival",
                "Celtic",
                "Bluegrass",
                "Avantgarde",
                "Gothic Rock",
                "Progressive Rock",
                "Psychedelic Rock",
                "Symphonic Rock",
                "Slow Rock",
                "Big Band",
                "Chorus",
                "Easy Listening",
                "Acoustic",
                "Humour",
                "Speech",
                "Chanson",
                "Opera",
                "Chamber Music",
                "Sonata",
                "Symphony",
                "Booty Brass",
                "Primus",
                "Porn Groove",
                "Satire",
                "Slow Jam",
                "Club",
                "Tango",
                "Samba",
                "Folklore",
                "Ballad",
                "Poweer Ballad",
                "Rhytmic Soul",
                "Freestyle",
                "Duet",
                "Punk Rock",
                "Drum Solo",
                "A Capela",
                "Euro-House",
                "Dance Hall",
        };

status_t ADT_Track_new_from_binary_file (FILE * f, ADT_Track_t ** track) /*debería dividir en ADT..New y ADT..load?*/
{
    status_t st;
    char buf[MP3_HEADER_SIZE];
    char *temp;
    char header[MP3_HEADER_SIZE + 1];

    if (track == NULL || f == NULL)
        return ERROR_NULL_POINTER;
    if ((*track = (ADT_Track_t *) malloc(sizeof(ADT_Track_t))) == NULL)
        return ERROR_OUT_OF_MEMORY;
    if ((st = ADT_Track_read_header(f, &header)) != OK) /*no recuerdo como se hace esto jeje*/
        return st;
    memcpy((*track)->tag, header + LEXEM_START_TAG, LEXEM_SPAN_TAG);
    ((*track)->tag)[LEXEM_SPAN_TAG] = '\0';
    memcpy((*track)->title,header + LEXEM_START_TITLE, LEXEM_SPAN_TITLE);
    ((*track)->title)[LEXEM_SPAN_TITLE] = '\0';
    memcpy((*track)->artist, header + LEXEM_START_ARTIST, LEXEM_SPAN_ARTIST);
    ((*track)->artist)[LEXEM_SPAN_ARTIST] = '\0';
    memcpy((*track)->album, header + LEXEM_START_ALBUM, LEXEM_SPAN_ALBUM);
    ((*track)->album)[LEXEM_SPAN_ALBUM] = '\0';
    memcpy(buf, header + LEXEM_START_YEAR, LEXEM_SPAN_YEAR);
    buf[LEXEM_SPAN_YEAR] = '\0';
    (*track)->year = strtol(buf, &temp, 10); /*fulero*/
    if(*temp)
        return ERROR_INVALID_ARGUMENTS; /*cambiar */
    memcpy(buf, header + LEXEM_START_GENRE, LEXEM_SPAN_GENRE);
    buf[LEXEM_SPAN_GENRE] = '\0';
    /*strcmp para 127 cosas?? zarpado.*/
    return OK;
}

status_t ADT_Track_read_header(FILE * f, char ** header) /*ya necesito memoria reservada para no usar mem din*/
{
    long int length;

    if (header == NULL || f == NULL)
        return ERROR_NULL_POINTER;
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f,length-MP3_HEADER_SIZE,SEEK_SET);
    fread(*header, sizeof(char), MP3_HEADER_SIZE, f);
    return OK;
}

