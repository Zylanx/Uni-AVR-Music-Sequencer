//
//
//

#include "Note.h"

uint8_t musicNote_getOctave(uint8_t* self) {
	return (uint8_t)(*self >> 4);
}

uint8_t musicNote_getTone(uint8_t* self) {
	return (uint8_t)(*self & 0x0F);
}

noteType_t _note_getNoteType(note_t* self) {
	return self->noteType;
}

noteType_t _note_getNoteType_P(note_t* self) {
	//noteType_t returnValue = (noteType_t)pgm_read_byte(&self->noteType);
	//return returnValue;

	return pgm_read_byte(&self->noteType);
}

uint8_t _note_getNoteLength(note_t* self) {
	return self->noteLength;
}

uint8_t _note_getNoteLength_P(note_t* self) {
	return pgm_read_byte(&self->noteLength);
}

uint8_t _note_getNotePitch(note_t* self) {
	return self->notePitch;
}

uint8_t _note_getNotePitch_P(note_t* self) {
	return pgm_read_byte(&self->notePitch);
}

void _note_setNoteType(note_t* self, noteType_t newValue) {
	self->noteType = newValue;
}

void _note_setNoteType_P(note_t* self, noteType_t newValue) {
	return;
}

void _note_setNoteLength(note_t* self, uint8_t newValue) {
	self->noteLength = newValue;
}

void _note_setNoteLength_P(note_t* self, uint8_t newValue) {
	return;
}

void _note_setNotePitch(note_t* self, uint8_t newValue) {
	self->notePitch = newValue;
}

void _note_setNotePitch_P(note_t* self, uint8_t newValue) {
	return;
}