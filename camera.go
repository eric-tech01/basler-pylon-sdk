package gopylon

/*
#include "camera.h"
*/
import "C"
import (
	"fmt"
)

type Camera struct {
	index  int
	HDev   C.PYLON_DEVICE_HANDLE
	IsOpen bool //相机是否打开

	ModelName       string
	FullName        string
	FriendlyName    string
	VendorName      string
	SerialNumber    string
	DeviceClass     string
	DeviceVersion   string
	UserDefinedName string
}

// 把DeviceInfoList_t 转成自定义的类型
func (camera *Camera) FetchCamera() error {

	res := C.BindCamera(C.CString(camera.SerialNumber), &(camera.HDev))
	if C.GENAPI_E_OK == res {
		// camera.GetDeviceInfo()
		return nil
	}

	return fmt.Errorf("bind camera error, serial no: %s, reslt code is %d", camera.SerialNumber, int(res))
}

func (camera *Camera) GetDeviceInfo() {
	// var deviceInfo C.CDeviceInfo
	//获取deviceInfo
	var info C.PylonDeviceInfo_t
	res := C.CPylonGetDeviceInfo(C.ulong(camera.index), &info)
	if C.GENAPI_E_OK == res {
		//解deviceinfo
		// fmt.Printf("%s \n", info.SerialNumber)
		camera.SerialNumber = C.GoString(&info.SerialNumber[0])
		camera.ModelName = C.GoString(&info.ModelName[0])
		camera.FullName = C.GoString(&info.FullName[0])
		camera.FriendlyName = C.GoString(&info.FriendlyName[0])
		camera.VendorName = C.GoString(&info.VendorName[0])
		camera.DeviceClass = C.GoString(&info.DeviceClass[0])
		camera.DeviceVersion = C.GoString(&info.DeviceVersion[0])
		camera.UserDefinedName = C.GoString(&info.UserDefinedName[0])

	}
	fmt.Printf("%v \n", res)

}

func (camera Camera) Open() error {
	if camera.IsOpen {
		camera.Close()
	}
	res := C.CPylonDeviceOpen(camera.HDev, C.PYLONC_ACCESS_MODE_CONTROL|C.PYLONC_ACCESS_MODE_STREAM)
	if C.GENAPI_E_OK != res {
		return fmt.Errorf("DeviceOpen failed: %d", res)
	}

	return nil
}

func (camera Camera) StopAndClean() {
	camera.Close()
	camera.Destroy()
}

func (camera Camera) Close() {
	C.CPylonDeviceClose(camera.HDev)
}
func (camera Camera) PylonDeviceFeatureIsReadable(prop string) {
	C.CPylonDeviceFeatureIsReadable(camera.HDev, C.CString(prop))
}

func (camera Camera) PylonDeviceGetNumStreamGrabberChannels() (int, error) {
	var numChannels C.size_t
	res := C.PylonDeviceGetNumStreamGrabberChannels(camera.HDev, &numChannels)
	if C.GENAPI_E_OK != res {
		return -1, fmt.Errorf("PylonDeviceGetNumStreamGrabberChannels failed: %d", res)
	}
	return int(numChannels), nil

}

func (camera Camera) Destroy() {
	C.CPylonDestroyDevice(camera.HDev)
}

func (camera Camera) PylonDeviceGetStreamGrabber(index int, ghandle *C.PYLON_STREAMGRABBER_HANDLE) error {
	res := C.CPylonDeviceGetStreamGrabber(camera.HDev, C.size_t(index), ghandle)
	if C.GENAPI_E_OK != res {
		return fmt.Errorf("PylonDeviceGetStreamGrabber failed: %d", res)
	}
	return nil
}

func (camera Camera) GetIntegerFeatureInt32(name string, retValue *int32) error {
	var value C.int
	res := C.CPylonDeviceGetIntegerFeatureInt32(camera.HDev, C.CString(name), &value)
	if C.GENAPI_E_OK != res {
		return fmt.Errorf("PylonDeviceGetIntegerFeatureInt32 failed: %d", res)
	}
	*retValue = (int32(value))
	return nil
}

func (camera Camera) ExecuteCommandFeature(cmd string) error {
	res := C.CPylonDeviceExecuteCommandFeature(camera.HDev, C.CString(cmd))
	if C.GENAPI_E_OK != res {
		return fmt.Errorf("CPylonDeviceExecuteCommandFeature failed: %d", res)
	}
	return nil

}
