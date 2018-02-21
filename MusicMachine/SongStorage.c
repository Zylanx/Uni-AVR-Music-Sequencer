// 
// 
// 

#include "SongStorage.h"

typedef struct SongStorage {
	storageType_t storageType;
	uint16_t noteArrayIndex;
	uint16_t noteArrayLength;
	note_t* noteArray;
} songStorage_t;

songStorage_t* songStorage_init() {
	songStorage_t* tempContainer = calloc(1, sizeof(songStorage_t));
	return tempContainer;
}

note_t* songStorage_getNote(songStorage_t* self) {
	note_t* notePtr;

	notePtr = &(self->noteArray[self->noteArrayIndex]);

	//TODO: check if end
	//if so, reset index
	// else just increment it
	self->noteArrayIndex += 1;

	if (self->noteArrayIndex >= self->noteArrayLength) {
		self->noteArrayIndex = 0;
	}
	return notePtr;
}

void songStorage_setNoteArray(songStorage_t* self, void* arrayPtr, storageType_t storageLoc) {
	self->noteArray = arrayPtr;
	self->storageType = storageLoc;
	self->noteArrayIndex = 0;
	self->noteArrayLength = 65535;

	while (1) {
		if (note_getNoteType(songStorage_getNote(self), self) == END) {
			break;
		}
	}

	self->noteArrayLength = self->noteArrayIndex;
	self->noteArrayIndex = 0;
}

noteType_t note_getNoteType(note_t* self, songStorage_t* songStorage) {
	if (songStorage->storageType == FLASH) {
		return _note_getNoteType_P(self);
	} else {
		return _note_getNoteType(self);
	}
}

uint8_t note_getNoteLength(note_t* self, songStorage_t* songStorage) {
	if (songStorage->storageType == FLASH) {
		return _note_getNoteLength_P(self);
	} else {
		return _note_getNoteLength(self);
	}
}

uint8_t note_getNotePitch(note_t* self, songStorage_t* songStorage) {
	if (songStorage->storageType == FLASH) {
		return _note_getNotePitch_P(self);
	} else {
		return _note_getNotePitch(self);
	}
}

void note_setNoteType(note_t* self, noteType_t newValue, songStorage_t* songStorage) {
	if (songStorage->storageType == FLASH) {
		_note_setNoteType_P(self, newValue);
	} else {
		return _note_setNoteType(self, newValue);
	}
}

void note_setNoteLength(note_t* self, uint8_t newValue, songStorage_t* songStorage) {
	if (songStorage->storageType == FLASH) {
		_note_setNoteLength_P(self, newValue);
	} else {
		return _note_setNoteLength(self, newValue);
	}
}

void note_setNotePitch(note_t* self, uint8_t newValue, songStorage_t* songStorage) {
	if (songStorage->storageType == FLASH) {
		_note_setNotePitch_P(self, newValue);
	} else {
		return _note_setNotePitch(self, newValue);
	}
}