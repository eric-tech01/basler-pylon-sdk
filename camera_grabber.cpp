
#include <iostream>
#include <stdio.h>
extern "C"
{
#include "camera.h"
}


/*
* ----------------------------------------------------------------------------
* Stream grabber operations
* ----------------------------------------------------------------------------
*/
GENAPIC_RESULT CPylonStreamGrabberOpen( PYLON_STREAMGRABBER_HANDLE hStg ) {
    return PylonStreamGrabberOpen(hStg);
}
GENAPIC_RESULT CPylonStreamGrabberClose( PYLON_STREAMGRABBER_HANDLE hStg ) 
{
     return PylonStreamGrabberClose(hStg);
}
GENAPIC_RESULT CPylonStreamGrabberIsOpen( PYLON_STREAMGRABBER_HANDLE hStg, _Bool* pOpen )
{
     return PylonStreamGrabberIsOpen(hStg,pOpen);
}
GENAPIC_RESULT CPylonStreamGrabberGetWaitObject( PYLON_STREAMGRABBER_HANDLE hStg, PYLON_WAITOBJECT_HANDLE* phWobj )
{
     return PylonStreamGrabberGetWaitObject(hStg, phWobj );
}
GENAPIC_RESULT CPylonStreamGrabberSetMaxNumBuffer( PYLON_STREAMGRABBER_HANDLE hStg, size_t numBuffers )
{

 return PylonStreamGrabberSetMaxNumBuffer(hStg, numBuffers);
}
GENAPIC_RESULT CPylonStreamGrabberGetMaxNumBuffer( PYLON_STREAMGRABBER_HANDLE hStg, size_t* pNumBuffers )
{

 return PylonStreamGrabberGetMaxNumBuffer(hStg, pNumBuffers);
}
GENAPIC_RESULT CPylonStreamGrabberSetMaxBufferSize( PYLON_STREAMGRABBER_HANDLE hStg, size_t maxSize )
{
     return PylonStreamGrabberSetMaxBufferSize(hStg, maxSize);

}
GENAPIC_RESULT CPylonStreamGrabberGetMaxBufferSize( PYLON_STREAMGRABBER_HANDLE hStg, size_t* pMaxSize )
{
     return PylonStreamGrabberGetMaxBufferSize(hStg, pMaxSize);

}
GENAPIC_RESULT CPylonStreamGrabberGetPayloadSize( PYLON_DEVICE_HANDLE hDev, PYLON_STREAMGRABBER_HANDLE hStg, size_t* payloadsize )
{
     return PylonStreamGrabberGetPayloadSize(hDev, hStg, payloadsize);

}
GENAPIC_RESULT CPylonStreamGrabberRegisterBuffer( PYLON_STREAMGRABBER_HANDLE hStg, void* pBuffer, size_t BufLen, PYLON_STREAMBUFFER_HANDLE* phBuf )
{
     return PylonStreamGrabberRegisterBuffer(hStg,pBuffer, BufLen, phBuf );

}
GENAPIC_RESULT CPylonStreamGrabberDeregisterBuffer( PYLON_STREAMGRABBER_HANDLE hStg, PYLON_STREAMBUFFER_HANDLE hBuf )
{
     return PylonStreamGrabberDeregisterBuffer(hStg, hBuf);

}
GENAPIC_RESULT CPylonStreamGrabberPrepareGrab( PYLON_STREAMGRABBER_HANDLE hStg )
{
     return PylonStreamGrabberPrepareGrab(hStg);

}
GENAPIC_RESULT CPylonStreamGrabberIsStartAndStopStreamingMandatory( PYLON_STREAMGRABBER_HANDLE hStg, _Bool* pMandatory )
{
     return PylonStreamGrabberIsStartAndStopStreamingMandatory(hStg, pMandatory);

}
GENAPIC_RESULT CPylonStreamGrabberStartStreamingIfMandatory( PYLON_STREAMGRABBER_HANDLE hStg )
{
     return PylonStreamGrabberStartStreamingIfMandatory(hStg);


}
GENAPIC_RESULT CPylonStreamGrabberStopStreamingIfMandatory( PYLON_STREAMGRABBER_HANDLE hStg )
{
     return PylonStreamGrabberStopStreamingIfMandatory(hStg);

}
GENAPIC_RESULT CPylonStreamGrabberFinishGrab( PYLON_STREAMGRABBER_HANDLE hStg )
{
 return PylonStreamGrabberFinishGrab(hStg);
}
GENAPIC_RESULT CPylonStreamGrabberFlushBuffersToOutput( PYLON_STREAMGRABBER_HANDLE hStg )
{
     return PylonStreamGrabberFlushBuffersToOutput(hStg);

}
GENAPIC_RESULT CPylonStreamGrabberCancelGrab( PYLON_STREAMGRABBER_HANDLE hStg )
{
     return PylonStreamGrabberCancelGrab(hStg);
}
GENAPIC_RESULT CPylonStreamGrabberRetrieveResult( PYLON_STREAMGRABBER_HANDLE hStg, PylonGrabResult_t* pGrabResult, _Bool* pReady )
{
     return PylonStreamGrabberRetrieveResult(hStg, pGrabResult, pReady);
}
GENAPIC_RESULT CPylonStreamGrabberQueueBuffer( PYLON_STREAMGRABBER_HANDLE hStg, PYLON_STREAMBUFFER_HANDLE hBuf, const void* pContext )
{
     return PylonStreamGrabberQueueBuffer(hStg, hBuf, pContext);

}
GENAPIC_RESULT CPylonStreamGrabberGetNodeMap( PYLON_STREAMGRABBER_HANDLE hStg, NODEMAP_HANDLE* phMap )
{
     return PylonStreamGrabberGetNodeMap(hStg, phMap);
}
