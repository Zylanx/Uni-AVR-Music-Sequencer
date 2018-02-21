// NoteLoader.h

#ifndef _NOTELOADER_h
#define _NOTELOADER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Note.h"

#ifdef __cplusplus
extern "C" {
#endif

note_t* loadNote(PGM_VOID_P);

#ifdef __cplusplus
}
#endif

#endif