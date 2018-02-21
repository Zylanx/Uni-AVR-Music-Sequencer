// TestSong.h

#ifndef TEST_SONG_H
#define TEST_SONG_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Note.h"

static const note_t FalloutSong[] PROGMEM = {
		{BUZZER, 4, musicNoteToUint(7, TONE_E)},
		{BUZZER, 4, musicNoteToUint(6, TONE_E)},
		{BUZZER, 4, musicNoteToUint(4, TONE_G)},
		{BUZZER, 2, musicNoteToUint(3, TONE_A)},
		{BUZZER, 2, musicNoteToUint(2, TONE_A)},
		{PAUSE, 2, 0},
		{BUZZER, 2, musicNoteToUint(4, TONE_E)},
		{END, 2, 0}
	};

#endif