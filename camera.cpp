#include <pylon/PylonIncludes.h>

#include <iostream>
extern "C"
{
#include "camera.h"
}
// Namespace for using pylon objects.
using namespace Pylon;

void CPylonInitialize()
{
    PylonInitialize();
}

int CEnumerateDevices()
{
    try
    {
        DeviceInfoList_t devices;
        CTlFactory &tlFactory = CTlFactory::GetInstance();
        tlFactory.EnumerateDevices(devices);
        return devices.size();
    }
    catch (const GenericException e)
    {
        std::cout << "Enumberate devices error: " << e.GetDescription() << std::endl;
        return 0;
    }
    return 0;
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