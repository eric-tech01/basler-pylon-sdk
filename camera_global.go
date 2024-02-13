package gopylon

/*
#include "camera.h"
*/
import "C"
import "fmt"

func PylonInitialize() {
	C.CPylonInitialize()
}

func PylonTerminate() {
	C.CPylonTerminate()
}

type Cameras []Camera

func (cameras *Cameras) EnumerateDevices() error {
	var num C.size_t
	res := C.CPylonEnumerateDevices(&num)
	if C.GENAPI_E_OK != res {
		return fmt.Errorf("%d", res)
	}
	fmt.Printf("num is : %d \n", int(num))
	for i := 0; i < int(num); i++ {
		c := Camera{}
		res := C.CPylonCreateDeviceByIndex(C.ulong(i), &c.HDev)
		if C.GENAPI_E_OK != res {
			C.CPrintError(res)
			return fmt.Errorf("%d", res)
		}
		*cameras = append(*cameras, c)
	}
	return nil
}

// char* errMsg;
// size_t length;

// /* Retrieve the error message.
// ... First find out how big the buffer must be, */
// GenApiGetLastErrorMessage( NULL, &length );
// errMsg = (char*) malloc( length );
// /* ... and retrieve the message. */
// GenApiGetLastErrorMessage( errMsg, &length );
