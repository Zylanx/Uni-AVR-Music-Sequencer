// 
// 
// 

#include "NoteLoader.h"

note_t* loadNote(PGM_VOID_P noteToLoad) {
	return (note_t*)pgm_read_word(noteToLoad);
}