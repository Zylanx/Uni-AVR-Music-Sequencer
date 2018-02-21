/*
 Name:		MusicMachine.ino
 Created:	9/19/2017 12:21:04 PM
 Author:	Zylanx
*/

#include "SongStorage.h"
#include "NoteLoader.h"
#include "Sequencer.h"
#include "Note.h"
#include "TestSong.h"

sequencerState_t* globalSequencer;

// the setup function runs once when you press reset or power the board
void setup() {
	globalSequencer = sequencer_init();
	songStorage_setNoteArray(sequencer_getSongStorage(globalSequencer), &FalloutSong, FLASH);
	sequencer_startPlaying(globalSequencer);
}

// the loop function runs over and over again until power down or reset
void loop() {
	sequencer_loop(globalSequencer);
}