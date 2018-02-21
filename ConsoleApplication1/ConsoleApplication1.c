// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>
#include <stdlib.h>

//typedef struct BeatTime {
//	uint8_t subBeat : 2;
//	uint8_t beat : 6;
//} beatTime_t;
//
//typedef union {
//	beatTime_t;
////	uint8_t;
//} beatTimeUnion_t;

//typedef struct PauseNote {
//	uint8_t active;
//	beatTime_t endBeat;
//} pauseNote_t;
//
//typedef struct SequencerState {
//	pauseNote_t* pauseNote;
//	uint8_t playingSong;
//	beatTime_t curBeat;
//} sequencerState_t;
//
//sequencerState_t* sequencer;
//pauseNote_t* pause;

typedef struct {
	uint8_t* intArray;
} tester_t;

uint8_t intArray[] = {1, 20, 3, 16, 4, 28};

int main() {
	/*sequencer = calloc(1, sizeof(sequencerState_t));
	pause = calloc(1, sizeof(pauseNote_t));

	printf("%p\n", sequencer->pauseNote);
	sequencer->pauseNote = pause;
	printf("%p\n", sequencer->pauseNote);

	printf("%i\n", sequencer->pauseNote->active);

	sequencer->pauseNote->active = 1;
	sequencer->pauseNote->endBeat.subBeat = 2;
	sequencer->pauseNote->endBeat.beat = 3;

	printf("%i\n", sequencer->pauseNote->active);

	free(sequencer);
	free(pause);*/

	/*beatTime_t test = {.subBeat = 2, .beat = 4};
	printf("%i\n", *((uint8_t*)&test));
	printf("%i\n", test.subBeat);
	printf("%i\n", test.beat);
	return 0;*/

	tester_t testStruct = {&intArray};
	uint8_t* arrayPointer = testStruct.intArray;
	uint8_t inttest;
	for (int i = 0; i < 6; i++) {
		inttest = *(arrayPointer + i);
		printf("%i", testStruct.intArray[i]);
	}
}