#include <iostream>
#include <stdio.h>
extern "C"
{
#include "camera.h"
}
// Namespace for using pylon objects.
// using namespace Pylon;

void CPylonInitialize()
{
    PylonInitialize();
}

GENAPIC_RESULT BindCamera(char *serialNo, PYLON_DEVICE_HANDLE *hdev)
{
    size_t num;
    GENAPIC_RESULT res;
    res = PylonEnumerateDevices(&num);
    if (GENAPI_E_OK != res)
    {
        goto err;
    }
    for (int i = 0; i < num; ++i)
    {
        res = PylonCreateDeviceByIndex(i, hdev);
        if (GENAPI_E_OK != res)
        {
            goto err;
        }
    }
    return GENAPI_E_OK;

err:
    return res;
}
// GENAPIC_RESULT CEnumerateDevices(size_t *num)
// {
//     // size_t num;
//     GENAPIC_RESULT res;
//     res = PylonEnumerateDevices(num);
//     printf("device num isx: %ld \n", *num);
//     printf("res is %ld \n", res);
//     if (GENAPI_E_OK != res)
//     {
//         goto err;
//     }

//     printf("----start \n");
//     res = PylonCreateDeviceByIndex(0, &hdev);
//     if (GENAPI_E_OK != res)
//     {
//         printf("----ssoooo \n");
//         goto err;
//     }
//     res = PylonDeviceOpen(hdev, PYLONC_ACCESS_MODE_CONTROL | PYLONC_ACCESS_MODE_STREAM | PYLONC_ACCESS_MODE_EVENT);

//     NtitBaslerPrintName(0);

//     // for (int i = 0; i < ; ++i)
//     // {

//     // }
//     return GENAPI_E_OK;

// err:
//     return res;
// }
GENAPIC_RESULT CPylonGetDeviceInfo(PylonDeviceInfo_t *deviceInfo)
{
    return PylonGetDeviceInfo(0, deviceInfo);
}
GENAPIC_RESULT CPylonDeviceClose(PYLON_DEVICE_HANDLE hdev)
{
    return PylonDeviceClose(hdev);
}

void CPylonDestroyDevice(PYLON_DEVICE_HANDLE hdev)
{
    PylonDestroyDevice(hdev);
}

void CPylonTerminate()
{
    PylonTerminate();
}

GENAPIC_RESULT CPylonDeviceOpen(PYLON_DEVICE_HANDLE hdev, int mode)
{
    return PylonDeviceOpen(hdev, mode);
}
int CPylonDeviceFeatureIsReadable(PYLON_DEVICE_HANDLE hdev, char *prop);
{
}

// void CPylonDeviceClose()
// {
//     PylonDeviceClose();
// }

void NtitBaslerPrintName(PYLON_DEVICE_HANDLE hdev)
{
    char buf[256];
    GENAPIC_RESULT res;
    unsigned char is_readable;
    // PYLON_DEVICE_HANDLE   hdev;

    if (PYLONC_INVALID_HANDLE == hdev)
    {
        printf("error \n");
        return;
    }

    size_t siz = sizeof(buf);

    is_readable = PylonDeviceFeatureIsReadable(hdev, "DeviceModelName");
    printf("is_readable %u \n", is_readable);
    if (is_readable)
    {
        res = PylonDeviceFeatureToString(hdev, "DeviceModelName", buf, &siz);
        printf("Using camera %s.\n", buf);
    }

    printf("---rrreturn \n");
    return;
}
int CPylonDeviceFeatureIsReadable(PYLON_DEVICE_HANDLE hdev, char *prop)
{
    return 0;
}