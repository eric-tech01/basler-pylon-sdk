package main

/*
#cgo CFLAGS: -Ihello -I.
#cgo LDFLAGS: -Lhello -L. -lhello
#cgo LDFLAGS: -Wl,-rpath=".:hello"
#include "hello.h"
int SayHello();
*/
import "C"
import (
	"fmt"
)

func main() {
	ret := C.SayHello()
	fmt.Println(ret)
}
