

#include <iostream>
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

GENAPIC_RESULT CEnumerateDevices()
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
        res = PylonCreateDeviceByIndex(i, &hdevs[i]);
        if (GENAPI_E_OK != res)
        {
            goto err;
        }
    }
    return GENAPI_E_OK;

err:
    return res;
}
void CPylonGetDeviceInfo()
{
    // GENAPIC_RESULT res;
    // res = PylonGetDeviceInfo(index, deviceInfo);
    return;
}

void CPylonTerminate()
{
    PylonTerminate();
}

int CPylonDeviceFeatureIsReadable(PYLON_DEVICE_HANDLE hdev, char *prop);
{
}

// void CPylonDeviceClose()
// {
//     PylonDeviceClose();
// }

// void CPylonDeviceOpen()
// {
//     GENAPIC_RESULT res;
//     PYLON_DEVICE_HANDLE hdev;
//     res = PylonDeviceOpen(hdev, PYLONC_ACCESS_MODE_STREAM);
// }
