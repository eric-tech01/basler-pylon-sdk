#ifndef __CYBER_BASLER_DRIVER_H__
#define __CYBER_BASLER_DRIVER_H__

/* Pylon */
#include <pylonc/PylonC.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define NUM_DEVICES 1
    void CPylonInitialize();
    GENAPIC_RESULT BindCamera(char *serialNo, PYLON_DEVICE_HANDLE *hdev);
    // GENAPIC_RESULT CEnumerateDevices(size_t *num);
    GENAPIC_RESULT CPylonGetDeviceInfo(PylonDeviceInfo_t *deviceInfo);
    void CPylonTerminate();
    int CPylonDeviceFeatureIsReadable(PYLON_DEVICE_HANDLE hdev, char *prop);

    void NtitBaslerPrintName(PYLON_DEVICE_HANDLE hdev);
    GENAPIC_RESULT CPylonDeviceClose(PYLON_DEVICE_HANDLE hdev);
    GENAPIC_RESULT CPylonDeviceOpen(PYLON_DEVICE_HANDLE hdev, int mode);
#ifdef __cplusplus
}
#endif

#endif
