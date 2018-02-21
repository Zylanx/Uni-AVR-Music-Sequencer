// SongStorage.h

#ifndef _SONGSTORAGE_h
#define _SONGSTORAGE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Utils.h"
#include "Note.h"

struct SongStorage;
typedef struct SongStorage songStorage_t;

#ifdef __cplusplus
extern "C" {
#endif

	songStorage_t* songStorage_init();
	void songStorage_setNoteArray(songStorage_t*, void*, storageType_t);
	note_t* songStorage_getNote(songStorage_t*);

	noteType_t note_getNoteType(note_t*, songStorage_t*);
	uint8_t note_getNoteLength(note_t*, songStorage_t*);
	uint8_t note_getNotePitch(note_t*, songStorage_t*);
	void note_setNoteType(note_t*, noteType_t, songStorage_t*);
	void note_setNoteLength(note_t*, uint8_t, songStorage_t*);
	void note_setNotePitch(note_t*, uint8_t, songStorage_t*);

#ifdef __cplusplus
}
#endif

#endif

