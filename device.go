package main


/*
#cgo CFLAGS: -Isdk -I.
#cgo LDFLAGS: -Lsdk -L. -lsdk
#cgo LDFLAGS: -Wl,-rpath=".:sdk"
#include "./sdk/libsdk.h"
*/
import "C"
import "fmt"

func main()  {
	C.CPylonInitialize()
	ret := C.CPylonGetDeviceInfo()
	fmt.Println(ret)
}