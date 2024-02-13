package gopylon

/*
#include "camera.h"
*/
import "C"
import "fmt"

type WaitObject struct {
	Hwait C.PYLON_WAITOBJECT_HANDLE
}

func (w WaitObject) Wait() error {
	var isReady C._Bool
	res := C.CPylonWaitObjectWait(w.Hwait, 1000, &isReady)
	if C.GENAPI_E_OK != res {
		return fmt.Errorf("%d", res)
	}
	if !isReady {
		return fmt.Errorf("wait timeout")
	}

	return nil
}
