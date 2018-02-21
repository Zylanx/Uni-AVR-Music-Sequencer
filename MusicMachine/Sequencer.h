// Sequencer.h

#ifndef _SEQUENCER_h
#define _SEQUENCER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Note.h"
#include "SongStorage.h"

struct SequencerState;
typedef struct SequencerState sequencerState_t;

#ifdef __cplusplus
extern "C" {
#endif

sequencerState_t* sequencer_init();
void sequencer_startPlaying(sequencerState_t*);
songStorage_t* sequencer_getSongStorage(sequencerState_t*);
void sequencer_loop(sequencerState_t*);

#ifdef __cplusplus
}
#endif

#endif