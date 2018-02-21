// Note.h

#ifndef _NOTE_h
#define _NOTE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Utils.h"

typedef enum { END, PAUSE, BUZZER, DRUM } messageType_t;
//typedef enum {ONCE, CONTINUED} drumBeatType_t;
//typedef enum {DOUBLEBEAT, BEAT, HALFBEAT, QUARTERBEAT} drumBeatLength_t;

typedef struct {
	uint8_t octave : 4;
	uint8_t note : 4;
} musicNote_t;

// 3 bytes
struct Note {
	storageType_t storageType;
	message_t* message;
};

struct Message {
	messageType_t messageType : 2;
	//drumBeatType_t drumBeatType : 1;
	//drumBeatLength_t drumBeatTiming : 2;
	//uint8_t : 0; // byte alignment packing
	uint8_t noteLength;
	musicNote_t note;
};

typedef struct Message message_t;
typedef struct Note note_t;

#endif