package gopylon

/*
#include "camera.h"
*/
import "C"

type CameraSlice []Camera

// 把DeviceInfoList_t 转成自定义的类型
func (cameras *CameraSlice) FetchAll() error {
	//枚举出所有的 相机，得到camera数组

	return nil
}
