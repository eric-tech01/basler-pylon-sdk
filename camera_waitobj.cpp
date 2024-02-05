
#include <iostream>
#include <stdio.h>
extern "C"
{
#include "camera.h"
}



/*
* ----------------------------------------------------------------------------
* Wait object
* ----------------------------------------------------------------------------
*/
GENAPIC_RESULT CPylonWaitObjectIsValid( PYLON_WAITOBJECT_HANDLE hWobj, _Bool* pValid )
{
     return PylonWaitObjectIsValid(hWobj, pValid);
}
GENAPIC_RESULT CPylonWaitObjectWait( PYLON_WAITOBJECT_HANDLE hWobj, uint32_t timeout, _Bool* pResult )
{
     return PylonWaitObjectWait(hWobj, timeout, pResult);
}
GENAPIC_RESULT CPylonWaitObjectWaitEx( PYLON_WAITOBJECT_HANDLE hWobj, uint32_t timeout, _Bool alertable, EPylonWaitExResult* pWaitResult )
{
     return PylonWaitObjectWaitEx(hWobj,timeout, alertable, pWaitResult );
}
GENAPIC_RESULT CPylonWaitObjectCreate( PYLON_WAITOBJECT_HANDLE* phWobj )
{
     return PylonWaitObjectCreate(phWobj);
}
GENAPIC_RESULT CPylonWaitObjectDestroy( PYLON_WAITOBJECT_HANDLE hWobj )
{
     return PylonWaitObjectDestroy(hWobj);
}
// GENAPIC_RESULT CPylonWaitObjectsignal( PYLON_WAITOBJECT_HANDLE hWobj )
// {
//      return PylonWaitObjectsignal(hWobj);
// }
GENAPIC_RESULT CPylonWaitObjectReset( PYLON_WAITOBJECT_HANDLE hWobj )
{
     return PylonWaitObjectReset(hWobj);
}


GENAPIC_RESULT CPylonWaitObjectFromFd( int fd, PYLON_WAITOBJECT_HANDLE* phWobj )
{
     return PylonWaitObjectFromFd(fd,phWobj);
}
GENAPIC_RESULT CPylonWaitObjectGetFd( PYLON_WAITOBJECT_HANDLE hWobj, int* pFd )
{
     return PylonWaitObjectGetFd(hWobj,pFd);
}

