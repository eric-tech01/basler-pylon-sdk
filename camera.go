package gopylon

/*
#include "camera.h"
*/
import "C"

type Camera struct {
	hdev C.PYLON_DEVICE_HANDLE
}

func PylonInitialize() {
	C.CPylonInitialize()
}

//把DeviceInfoList_t 转成自定义的类型
func EnumerateDevices() int {
	num := C.CEnumerateDevices()
	return int(num)
}
func (Camera) PylonGetDeviceInfo() {
	// var deviceInfo C.CDeviceInfo
	C.CPylonGetDeviceInfo()
}
func PylonTerminate() {
	C.CPylonTerminate()
}

func (camera Camera) PylonDeviceFeatureIsReadable(prop string) {
	C.CPylonDeviceFeatureIsReadable(camera.hdev, C.CString(prop))
}

// func PylonDeviceClose()  {
// 	C.CPylonDeviceClose()
// }
// func PylonDeviceOpen()  {
// 	C.CPylonDeviceOpen()
// }
