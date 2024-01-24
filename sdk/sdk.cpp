#include <pylon/PylonIncludes.h>
#include <iostream>
extern "C"
{
#include "libsdk.h"
}
// Namespace for using pylon objects.
using namespace Pylon;

void CPylonInitialize()
{
    puts("----");
    PylonInitialize();
}

int CPylonGetDeviceInfo()
{
    try
    {
        CTlFactory &tlFactory = CTlFactory::GetInstance();
        DeviceInfoList_t devices;
        tlFactory.EnumerateDevices(devices);
        // 遍历设备信息列表并打印设备信息
        std::cout << "Device count: " << devices.size() << std::endl;

        for (size_t i = 0; i < devices.size(); ++i)
        {
            puts(devices[i].GetFriendlyName());
        }
    }
    catch (const GenericException e)
    {
        puts(e.GetDescription());
        return 1;
    }
    // CInstantCamera camera(CTlFactory::GetInstance().CreateFirstDevice());
    PylonTerminate();
    return 0;
}

void CPylonTerminate()
{
    PylonTerminate();
}