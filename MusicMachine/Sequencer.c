// 
// 
// 

#include "Sequencer.h"

#define NOTE_STORAGE_MAX 5

const uint8_t initalBeatCount = 0;

//typedef struct BeatTime {
//	uint8_t subBeat : 2;
//	uint8_t beat : 6;
//} beatTime_t;
//
//typedef union {
//	beatTime_t;
//	uint8_t asUint8;
//} beatTimeUnion_t;

typedef uint8_t beatTime_t;

// Should be about 5 bytes in length
// (Including the note it is 8 bytes)
typedef struct PlayingNote {
	note_t* note;
	noteType_t noteType : 2;
	uint8_t notePlaying : 1;
	uint8_t : 0;
	beatTime_t startBeat;
	beatTime_t endBeat;
} playingNote_t;

typedef struct PauseNote {
	note_t* note;
	boolean active : 1;
	beatTime_t endBeat;
} pauseNote_t;

typedef struct NoteStorage {
	playingNote_t playingNotes[NOTE_STORAGE_MAX];
	playingNote_t* freeNotes[NOTE_STORAGE_MAX];
	uint8_t numFreeNotes;
} noteStorage_t;

typedef struct SequencerState {
	songStorage_t* songStorage;
	noteStorage_t playingNoteList;
	pauseNote_t pauseNote;
	boolean playingSong;
	beatTime_t curBeat;
} sequencerState_t;

void soundPlayer_addSound(songStorage_t* self, note_t* note) {
	PORTB = (uint8_t)note_getNotePitch(note, self) | 0x0F;
	PORTB = (uint8_t)note_getNotePitch(note, self) >> 4;
}

noteStorage_t* noteStorage_init(noteStorage_t* self) {
	self->numFreeNotes = NOTE_STORAGE_MAX;
	for (int i = 0; i < NOTE_STORAGE_MAX; i++) {
		self->freeNotes[i] = &(self->playingNotes[i]);
	}
	return self;
}

playingNote_t* noteStorage_getUnassignedNote(noteStorage_t* self) {
	if (self->numFreeNotes > 0) {
		for (int i = 0; i < NOTE_STORAGE_MAX; i++) {
			if (self->freeNotes[i] != NULL) {
				self->numFreeNotes -= 1;
				playingNote_t* returnNote = self->freeNotes[i];
				self->freeNotes[i] = NULL;
				return returnNote;
			}
		}
	} else {
		return NULL;
	}
}

void noteStorage_removeNote(noteStorage_t* self, playingNote_t* noteToRemove) {
	for (int i = 0; i < NOTE_STORAGE_MAX; i++) {
		if (self->freeNotes[i] == NULL) {
			self->freeNotes[i] = noteToRemove;
			self->numFreeNotes += 1;
			return;
		}
	}
}

sequencerState_t* sequencer_init() {
	sequencerState_t* tempContainer = calloc(1, sizeof(sequencerState_t));
	tempContainer->songStorage = songStorage_init();
	tempContainer->pauseNote.note = NULL;
	tempContainer->pauseNote.active = 0;
	//memcpy(&(tempContainer->pauseNote.endBeat), &initalBeatCount, 1);
	//memcpy(&(tempContainer->curBeat), &initalBeatCount, 1);
	tempContainer->pauseNote.endBeat = initalBeatCount;
	tempContainer->curBeat = initalBeatCount;
	noteStorage_init(&tempContainer->playingNoteList);
	return tempContainer;
}

void sequencer_startPlaying(sequencerState_t* self) {
	self->playingSong = 1;
}

songStorage_t* sequencer_getSongStorage(sequencerState_t* self) {
	return self->songStorage;
}

playingNote_t* sequencer_setupPlayingNote(sequencerState_t* self, playingNote_t* container, note_t* note) {
	container->notePlaying = 1;
	container->note = note;
	container->noteType = note_getNoteType(note, self->songStorage);
	container->startBeat = self->curBeat;
	container->endBeat = self->curBeat + note_getNoteLength(note, self->songStorage);
	return container;
}

int sequencer_sequenceNote(sequencerState_t* self) {
	note_t* note = songStorage_getNote(self->songStorage);
	if (note_getNoteType(note, self->songStorage) == END) {
		return 1;
	} else if (note_getNoteType(note, self->songStorage) == PAUSE) {
		self->pauseNote.note = note;
		self->pauseNote.endBeat = self->curBeat + note_getNoteLength(note, self->songStorage);
		self->pauseNote.active = 1;
		return 1;
	} else {
		// TODO: possibly start notes playing in here
		playingNote_t* playingNotePtr = noteStorage_getUnassignedNote(&self->playingNoteList);
		sequencer_setupPlayingNote(self, playingNotePtr, note);
		return 0;
	}
}

void sequencer_removeNote(sequencerState_t* self, playingNote_t* noteToRemove) {
	noteToRemove->notePlaying = 0;
	noteToRemove->note = NULL;
	noteStorage_removeNote(&self->playingNoteList, noteToRemove);
}

void sequencer_updatePlayingNotes(sequencerState_t* self) {
	// Update playingNote's in playingNoteList
	for (int i = 0; i < NOTE_STORAGE_MAX; i++) {
		if (self->playingNoteList.playingNotes[i].notePlaying == 1) {
			// Update the note
			if (self->playingNoteList.playingNotes[i].endBeat > self->curBeat) {
				soundPlayer_addSound(self->playingNoteList.playingNotes[i].note, self->songStorage);
			} else {
				sequencer_removeNote(self, &self->playingNoteList.playingNotes[i]);
			}
		}
	}

	// Update PauseNote
	if (self->pauseNote.endBeat <= self->curBeat) {
		self->pauseNote.active = 0;
		self->pauseNote.note = NULL;
	}
}

void sequencer_incrementCurBeat(sequencerState_t* self) {
	self->curBeat += 1;
}

void sequencer_loop(sequencerState_t* self) {
	if (self->playingSong) {
		if (self->pauseNote.active == 0) {
			// Sequence notes until next pause or end note
			while (!sequencer_sequenceNote(self)) {
				;
			}
		}

		sequencer_updatePlayingNotes(self);

		sequencer_incrementCurBeat(self);
	}
}