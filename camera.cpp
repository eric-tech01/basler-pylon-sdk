#include <iostream>
#include <stdio.h>
extern "C"
{
#include "camera.h"
}

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


GENAPIC_RESULT CPylonGetDeviceInfo(size_t index, PylonDeviceInfo_t* pDi)
{
    return PylonGetDeviceInfo(index, pDi);
}

void CPylonTerminate()
{
    PylonTerminate();
}

GENAPIC_RESULT CPylonDeviceOpen(PYLON_DEVICE_HANDLE hdev, int mode)
{
    return PylonDeviceOpen(hdev, mode);
}


GENAPIC_RESULT CPylonDeviceClose(PYLON_DEVICE_HANDLE hdev)
{
    return PylonDeviceClose(hdev);
}

GENAPIC_RESULT CPylonDestroyDevice(PYLON_DEVICE_HANDLE hdev)
{
    return PylonDestroyDevice(hdev);
}



_Bool CPylonDeviceFeatureIsReadable(PYLON_DEVICE_HANDLE hdev,const char *prop)
{
    bool isAvail;
    isAvail = PylonDeviceFeatureIsAvailable(hdev, prop);
    
    return true;
}


// GENAPIC_RESULT CPylonDeviceGetNumStreamGrabberChannels(PYLON_DEVICE_HANDLE hdev,size_t* pNumChannels )
// {
//     return PylonDeviceGetNumStreamGrabberChannels(hdev, pNumChannels);
// }

GENAPIC_RESULT CPylonDeviceGetStreamGrabber( PYLON_DEVICE_HANDLE hDev, size_t index, PYLON_STREAMGRABBER_HANDLE* phStg )
{
    return PylonDeviceGetStreamGrabber(hDev, index, phStg);
}

// GENAPIC_RESULT CPylonStreamGrabberOpen(PYLON_STREAMGRABBER_HANDLE hStg)
// {
//     return PylonStreamGrabberOpen(hStg);
// }

// GENAPIC_RESULT CPylonStreamGrabberGetWaitObject( PYLON_STREAMGRABBER_HANDLE hStg, PYLON_WAITOBJECT_HANDLE* phWobj )
// {
//     return PylonStreamGrabberGetWaitObject(hStg, phWobj);
// }
GENAPIC_RESULT CPylonDeviceGetIntegerFeatureInt32( PYLON_DEVICE_HANDLE dev, const char* name, int32_t* value )
{
    return PylonDeviceGetIntegerFeatureInt32(dev, name, value);
}

// GENAPIC_RESULT CPylonStreamGrabberSetMaxNumBuffer( PYLON_STREAMGRABBER_HANDLE hStg, size_t numBuffers )
// {
//     return PylonStreamGrabberSetMaxNumBuffer(hStg, numBuffers);
// }
// GENAPIC_RESULT CPylonStreamGrabberSetMaxBufferSize( PYLON_STREAMGRABBER_HANDLE hStg, size_t maxSize )
// {
//     return PylonStreamGrabberSetMaxBufferSize(hStg, maxSize);
// }

// GENAPIC_RESULT CPylonStreamGrabberPrepareGrab( PYLON_STREAMGRABBER_HANDLE hStg )
// {
//     return PylonStreamGrabberPrepareGrab(hStg);
// }

// GENAPIC_RESULT CPylonStreamGrabberRegisterBuffer( PYLON_STREAMGRABBER_HANDLE hStg, void* pBuffer, size_t BufLen, PYLON_STREAMBUFFER_HANDLE* phBuf )
// {
//     return PylonStreamGrabberRegisterBuffer(hStg, pBuffer, BufLen, phBuf);
// }
// GENAPIC_RESULT CPylonStreamGrabberQueueBuffer( PYLON_STREAMGRABBER_HANDLE hStg, PYLON_STREAMBUFFER_HANDLE hBuf, const void* pContext )
// {
//     return PylonStreamGrabberQueueBuffer(hStg, hBuf, pContext);
// }


void CPrintError(GENAPIC_RESULT errc) {
    char* errMsg;
    size_t length;
	GenApiGetLastErrorMessage(NULL, &length);
    errMsg = (char*) malloc( length );

	GenApiGetLastErrorMessage(errMsg, &length);
    
    fprintf( stderr, "%s (%#08x).\n", errMsg, (unsigned int) errc );
    free( errMsg );
}

GENAPIC_RESULT CPylonDeviceExecuteCommandFeature( PYLON_DEVICE_HANDLE hDev, const char* pName )
{
    return C.PylonDeviceExecuteCommandFeature(hDev, pName);
}
