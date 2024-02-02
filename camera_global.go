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
