package gopylon

/*
#include "camera.h"
*/
import "C"
import (
	"fmt"
)

type Camera struct {
	SerialNo string
	index    int
	hdev     C.PYLON_DEVICE_HANDLE
	IsOpen   bool //相机是否打开
}

// 把DeviceInfoList_t 转成自定义的类型
func (camera *Camera) FetchCamera() error {

	res := C.BindCamera(C.CString(camera.SerialNo), &(camera.hdev))
	if C.GENAPI_E_OK == res {
		// camera.GetDeviceInfo()
		return nil
	}

	return fmt.Errorf("bind camera error, serial no: %s, reslt code is %d", camera.SerialNo, int(res))
}

//把DeviceInfoList_t 转成自定义的类型
// func EnumerateDevices() int {
// 	var num C.size_t
// 	ret := C.CEnumerateDevices(&num)
// 	fmt.Println("return ret is: ", ret)
// 	return int(num)
// }

func (camera *Camera) GetDeviceInfo() {
	// hdev C.PYLON_DEVICE_HANDLE
}

func (Camera) PylonGetDeviceInfo() {
	// var deviceInfo C.CDeviceInfo
	//获取deviceInfo
	var info C.PylonDeviceInfo_t
	res := C.CPylonGetDeviceInfo(&info)
	if C.GENAPI_E_OK == res {
		//解deviceinfo
		fmt.Printf("%s \n", info.SerialNumber)
	}
	fmt.Printf("%v \n", res)

}

func (camera Camera) Open() {
	if camera.IsOpen {
		camera.Close()
	}
	C.CPylonDeviceOpen(camera.hdev, C.int(camera.index))
}

func (camera Camera) Close() {
	C.CPylonDeviceClose(camera.hdev)
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
