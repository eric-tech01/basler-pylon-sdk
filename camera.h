#ifndef __CYBER_BASLER_DRIVER_H__
#define __CYBER_BASLER_DRIVER_H__

/* Pylon */
#include <pylonc/PylonC.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define NUM_DEVICES 1

    PYLON_DEVICE_HANDLE hdevs[NUM_DEVICES];

    void CPylonInitialize();
    GENAPIC_RESULT CEnumerateDevices();
    void CPylonGetDeviceInfo();
    void CPylonTerminate();
    int CPylonDeviceFeatureIsReadable(PYLON_DEVICE_HANDLE hdev, char *prop);
// void CPylonDeviceClose();
// void CPylonDeviceOpen();
#ifdef __cplusplus
}
#endif

#endif
