// Note.h

#ifndef _NOTE_h
#define _NOTE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#define TONE_C 0
#define TONE_CS 1
#define TONE_D 2
#define TONE_EB 3
#define TONE_E 4
#define TONE_F 5
#define TONE_FS 6
#define TONE_G 7
#define TONE_GS 8
#define TONE_A 9
#define TONE_BB 10
#define TONE_B 11

#define musicNoteToUint(octave, tone) ((((uint8_t)octave) << 4) | tone)

typedef enum {END, PAUSE, BUZZER, DRUM} noteType_t;

//typedef struct {
//	uint8_t octave : 4;
//	uint8_t note : 4;
//} musicNote_t;

// 3 bytes
struct Note {
	noteType_t noteType;
	uint8_t noteLength;
	uint8_t notePitch;
};

typedef struct Note note_t;

#ifdef __cplusplus
extern "C" {
#endif
	uint8_t musicNote_getOctave(uint8_t*);
	uint8_t musicNote_getTone(uint8_t*);

	noteType_t _note_getNoteType(note_t*);
	noteType_t _note_getNoteType_P(note_t*);
	uint8_t _note_getNoteLength(note_t*);
	uint8_t _note_getNoteLength_P(note_t*);
	uint8_t _note_getNotePitch(note_t*);
	uint8_t _note_getNotePitch_P(note_t*);
	void _note_setNoteType(note_t*, noteType_t);
	void _note_setNoteType_P(note_t*, noteType_t);
	void _note_setNoteLength(note_t*, uint8_t);
	void _note_setNoteLength_P(note_t*, uint8_t);
	void _note_setNotePitch(note_t*, uint8_t);
	void _note_setNotePitch_P(note_t*, uint8_t);
#ifdef __cplusplus
}
#endif

#endif