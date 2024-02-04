package gopylon

/*
#include "camera.h"
*/
import "C"

func PylonInitialize() {
	C.CPylonInitialize()
}

func PylonTerminate() {
	C.CPylonTerminate()
}

// char* errMsg;
// size_t length;

// /* Retrieve the error message.
// ... First find out how big the buffer must be, */
// GenApiGetLastErrorMessage( NULL, &length );
// errMsg = (char*) malloc( length );
// /* ... and retrieve the message. */
// GenApiGetLastErrorMessage( errMsg, &length );
