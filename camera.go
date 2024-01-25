package gopylon

/*
#include "camera.h"
*/
import "C"

type Camera struct {

}


func PylonInitialize()  {
	C.CPylonInitialize()
}

//把DeviceInfoList_t 转成自定义的类型
func EnumerateDevices() int {
	num := C.CEnumerateDevices()
	return int(num)
}
func PylonGetDeviceInfo()  {
	// var deviceInfo C.CDeviceInfo
	C.CPylonGetDeviceInfo()
}
func PylonTerminate()  {
	C.CPylonTerminate()
}
// func PylonDeviceClose()  {
// 	C.CPylonDeviceClose()
// }
// func PylonDeviceOpen()  {
// 	C.CPylonDeviceOpen()
// }