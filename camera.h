#ifndef __CYBER_BASLER_DRIVER_H__
#define __CYBER_BASLER_DRIVER_H__

/* Pylon */
#include <pylonc/PylonC.h>

#ifdef __cplusplus
extern "C"
{
#endif


    /* pylon invalid handle type */
#define PYLONC_INVALID_HANDLE GENAPIC_INVALID_HANDLE

    void CPylonInitialize();
    GENAPIC_RESULT BindCamera(char *serialNo, PYLON_DEVICE_HANDLE *hdev);

    void CPylonTerminate();
    

    

    /*
    * ----------------------------------------------------------------------------
    * Interface functions
    * ----------------------------------------------------------------------------
    */
     GENAPIC_RESULT  CPylonEnumerateInterfaces( size_t* numInterfaces );
     GENAPIC_RESULT  CPylonEnumerateInterfacesByDeviceClass( const char* pDeviceClass, size_t* numInterfaces );
     GENAPIC_RESULT  CPylonGetInterfaceInfo( size_t index, PylonInterfaceInfo_t* pIfInfo );
     GENAPIC_RESULT  CPylonCreateInterfaceByIndex( size_t index, PYLON_INTERFACE_HANDLE* phIf );
     GENAPIC_RESULT  CPylonDestroyInterface( PYLON_INTERFACE_HANDLE hIf );
     GENAPIC_RESULT  CPylonInterfaceOpen( PYLON_INTERFACE_HANDLE hIf );
     GENAPIC_RESULT  CPylonInterfaceClose( PYLON_INTERFACE_HANDLE hIf );
     GENAPIC_RESULT  CPylonInterfaceIsOpen( PYLON_INTERFACE_HANDLE hIf, _Bool* pOpen );
     GENAPIC_RESULT  CPylonInterfaceGetInterfaceInfo( PYLON_INTERFACE_HANDLE hIf, PylonInterfaceInfo_t* pIfInfo );
     GENAPIC_RESULT  CPylonInterfaceGetNodeMap( PYLON_INTERFACE_HANDLE hIf, NODEMAP_HANDLE* phMap );


    /*
    * ----------------------------------------------------------------------------
    * Device enumeration
    * ----------------------------------------------------------------------------
    */
     GENAPIC_RESULT  CPylonEnumerateDevices( size_t* numDevices );


    /*
    * ----------------------------------------------------------------------------
    * GigE Device specific enumeration / creation
    * ----------------------------------------------------------------------------
    */
     GENAPIC_RESULT  CPylonGigEEnumerateAllDevices( size_t* numDevices );
     GENAPIC_RESULT  CPylonGigEForceIp( const char* pMacAddress, const char* pIpAddress, const char* pSubnetMask, const char* pDefaultGateway );
     GENAPIC_RESULT  CPylonGigERestartIpConfiguration( const char* pMacAddress );
     GENAPIC_RESULT  CPylonGigEChangeIpConfiguration( PYLON_DEVICE_HANDLE hDev, _Bool EnablePersistentIp, _Bool EnableDhcp );
     GENAPIC_RESULT  CPylonGigESetPersistentIpAddress( PYLON_DEVICE_HANDLE hDev, const char* pIpAddress, const char* pSubnetMask, const char* pDefaultGateway );
     GENAPIC_RESULT  CPylonGigEAnnounceRemoteDevice( const char* pIpAddress );
     GENAPIC_RESULT  CPylonGigERenounceRemoteDevice( const char* pIpAddress, _Bool* pFound );
     GENAPIC_RESULT  CPylonGigEGetPersistentIpAddress( PYLON_DEVICE_HANDLE hDev, char* pIpAddress, size_t* pIpAddressLen, char* pSubnetMask, size_t* pSubnetMaskLen, char* pDefaultGateway, size_t* pDefaultGatewayLen );
     GENAPIC_RESULT  CPylonGigEBroadcastIpConfiguration( const char* pMacAddress, _Bool EnablePersistentIp, _Bool EnableDHCP, const char* pIpAddress, const char* pSubnetMask, const char* pDefaultGateway, const char* pUserdefinedName, _Bool* pRetval );
     GENAPIC_RESULT  CPylonGigEIssueActionCommand( uint32_t deviceKey, uint32_t groupKey, uint32_t groupMask, const char* pBroadcastAddress, uint32_t timeoutMs, uint32_t* pNumResults, PylonGigEActionCommandResult_t* pResults );
     GENAPIC_RESULT  CPylonGigEIssueScheduledActionCommand( uint32_t deviceKey, uint32_t groupKey, uint32_t groupMask, uint64_t actiontimeNs, const char* pBroadcastAddress, uint32_t timeoutMs, uint32_t* pNumResults, PylonGigEActionCommandResult_t* pResults );


    /*
    * ----------------------------------------------------------------------------
    * DeviceInfo
    * ----------------------------------------------------------------------------
    */
     GENAPIC_RESULT CPylonGetDeviceInfo( size_t index, PylonDeviceInfo_t* pDi );
     GENAPIC_RESULT CPylonGetDeviceInfoHandle( size_t index, PYLON_DEVICE_INFO_HANDLE* phDi );
     GENAPIC_RESULT CPylonDeviceInfoGetNumProperties( PYLON_DEVICE_INFO_HANDLE hDi, size_t* numProperties );
     GENAPIC_RESULT CPylonDeviceInfoGetPropertyValueByName( PYLON_DEVICE_INFO_HANDLE hDi, const char* pName, char* pValue, size_t* pBufLen );
     GENAPIC_RESULT CPylonDeviceInfoGetPropertyValueByIndex( PYLON_DEVICE_INFO_HANDLE hDi, size_t index, char* pBuf, size_t* pBufLen );
     GENAPIC_RESULT CPylonDeviceInfoGetPropertyName( PYLON_DEVICE_INFO_HANDLE hDi, size_t index, char* pName, size_t* pBufLen );


    /*
    * ----------------------------------------------------------------------------
    * Device creation / destruction
    * ----------------------------------------------------------------------------
    */
     GENAPIC_RESULT CPylonCreateDeviceByIndex( size_t index, PYLON_DEVICE_HANDLE* phDev );
     GENAPIC_RESULT CPylonDestroyDevice( PYLON_DEVICE_HANDLE hDev );
     GENAPIC_RESULT CPylonIsDeviceAccessible( size_t index, int accessMode, _Bool* pIsAccessible );

    /*
    * ----------------------------------------------------------------------------
    * Device operations
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonDeviceOpen( PYLON_DEVICE_HANDLE hDev, int accessMode );
    GENAPIC_RESULT CPylonDeviceClose( PYLON_DEVICE_HANDLE hDev );
    GENAPIC_RESULT CPylonDeviceIsOpen( PYLON_DEVICE_HANDLE hDev, _Bool* pOpen );
    GENAPIC_RESULT CPylonDeviceAccessMode( PYLON_DEVICE_HANDLE hDev, int* pAccessMode );
    GENAPIC_RESULT CPylonDeviceGetDeviceInfo( PYLON_DEVICE_HANDLE hDev, /* */ PylonDeviceInfo_t* pDeviceInfo );
    GENAPIC_RESULT CPylonDeviceGetDeviceInfoHandle( PYLON_DEVICE_HANDLE hDev, PYLON_DEVICE_INFO_HANDLE* phDi );
    GENAPIC_RESULT CPylonDeviceGetNumStreamGrabberChannels( PYLON_DEVICE_HANDLE hDev, size_t* pNumChannels );
    GENAPIC_RESULT CPylonDeviceGetStreamGrabber( PYLON_DEVICE_HANDLE hDev, size_t index, PYLON_STREAMGRABBER_HANDLE* phStg );
    GENAPIC_RESULT CPylonDeviceGetEventGrabber( PYLON_DEVICE_HANDLE hDev, PYLON_EVENTGRABBER_HANDLE* phEvg );
    GENAPIC_RESULT CPylonDeviceGetNodeMap( PYLON_DEVICE_HANDLE hDev, NODEMAP_HANDLE* phMap );
    GENAPIC_RESULT CPylonDeviceGetTLNodeMap( PYLON_DEVICE_HANDLE hDev, NODEMAP_HANDLE* phMap );
    GENAPIC_RESULT CPylonDeviceCreateChunkParser( PYLON_DEVICE_HANDLE hDev, PYLON_CHUNKPARSER_HANDLE* phChp );
    GENAPIC_RESULT CPylonDeviceDestroyChunkParser( PYLON_DEVICE_HANDLE hDev, PYLON_CHUNKPARSER_HANDLE hChp );
    GENAPIC_RESULT CPylonDeviceCreateEventAdapter( PYLON_DEVICE_HANDLE hDev, PYLON_EVENTADAPTER_HANDLE* phEva );
    GENAPIC_RESULT CPylonDeviceDestroyEventAdapter( PYLON_DEVICE_HANDLE hDev, PYLON_EVENTADAPTER_HANDLE hEva );
    GENAPIC_RESULT CPylonDeviceRegisterRemovalCallback( PYLON_DEVICE_HANDLE hDev, PylonDeviceRemCb_t* pCbFunction, PYLON_DEVICECALLBACK_HANDLE* phCb );
    GENAPIC_RESULT CPylonDeviceDeregisterRemovalCallback( PYLON_DEVICE_HANDLE hDev, PYLON_DEVICECALLBACK_HANDLE hCb );



    /*
    * ----------------------------------------------------------------------------
    * Device convenience methods to access the device node map
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonDeviceSetIntegerFeature( PYLON_DEVICE_HANDLE hDev, const char* pName, int64_t value );
    GENAPIC_RESULT CPylonDeviceGetIntegerFeature( PYLON_DEVICE_HANDLE hDev, const char* pName, int64_t* pValue );
    GENAPIC_RESULT CPylonDeviceGetIntegerFeatureMin( PYLON_DEVICE_HANDLE hDev, const char* pName, int64_t* pValue );
    GENAPIC_RESULT CPylonDeviceGetIntegerFeatureMax( PYLON_DEVICE_HANDLE hDev, const char* pName, int64_t* pValue );
    GENAPIC_RESULT CPylonDeviceGetIntegerFeatureInc( PYLON_DEVICE_HANDLE hDev, const char* pName, int64_t* pValue );
    GENAPIC_RESULT CPylonDeviceGrabSingleFrame( PYLON_DEVICE_HANDLE hDev, size_t channel, void* pBuffer, size_t bufferSize, PylonGrabResult_t* pGrabResult, _Bool* pReady, uint32_t timeout );

    GENAPIC_RESULT CPylonDeviceSetFloatFeature( PYLON_DEVICE_HANDLE hDev, const char* pName, double value );
    GENAPIC_RESULT CPylonDeviceGetFloatFeature( PYLON_DEVICE_HANDLE hDev, const char* pName, double* pValue );
    GENAPIC_RESULT CPylonDeviceGetFloatFeatureMin( PYLON_DEVICE_HANDLE hDev, const char* pName, double* pValue );
    GENAPIC_RESULT CPylonDeviceGetFloatFeatureMax( PYLON_DEVICE_HANDLE hDev, const char* pName, double* pValue );

    GENAPIC_RESULT CPylonDeviceSetBooleanFeature( PYLON_DEVICE_HANDLE hDev, const char* pName, _Bool value );
    GENAPIC_RESULT CPylonDeviceGetBooleanFeature( PYLON_DEVICE_HANDLE hDev, const char* pName, _Bool* pValue );

    GENAPIC_RESULT CPylonDeviceExecuteCommandFeature( PYLON_DEVICE_HANDLE hDev, const char* pName );
    GENAPIC_RESULT CPylonDeviceIsCommandDone( PYLON_DEVICE_HANDLE hDev, const char* pName, _Bool* pResult );

    GENAPIC_RESULT CPylonDeviceFeatureFromString( PYLON_DEVICE_HANDLE hDev, const char* pName, const char* pValue );
    GENAPIC_RESULT CPylonDeviceFeatureToString( PYLON_DEVICE_HANDLE hDev, const char* pName, char* pBuf, size_t* pBufLen );

    _Bool CPylonDeviceFeatureIsImplemented( PYLON_DEVICE_HANDLE hDev, const char* pName );
    _Bool CPylonDeviceFeatureIsAvailable( PYLON_DEVICE_HANDLE hDev, const char* pName );
    _Bool CPylonDeviceFeatureIsReadable( PYLON_DEVICE_HANDLE hDev, const char* pName );
    _Bool CPylonDeviceFeatureIsWritable( PYLON_DEVICE_HANDLE hDev, const char* pName );
    GENAPIC_RESULT CPylonDeviceFeatureGetAccessMode( PYLON_DEVICE_HANDLE hDev, const char* pName, EGenApiAccessMode* pResult );



    /*
    * ----------------------------------------------------------------------------
    * Stream grabber operations
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonStreamGrabberOpen( PYLON_STREAMGRABBER_HANDLE hStg );
    GENAPIC_RESULT CPylonStreamGrabberClose( PYLON_STREAMGRABBER_HANDLE hStg );
    GENAPIC_RESULT CPylonStreamGrabberIsOpen( PYLON_STREAMGRABBER_HANDLE hStg, _Bool* pOpen );
    GENAPIC_RESULT CPylonStreamGrabberGetWaitObject( PYLON_STREAMGRABBER_HANDLE hStg, PYLON_WAITOBJECT_HANDLE* phWobj );
    GENAPIC_RESULT CPylonStreamGrabberSetMaxNumBuffer( PYLON_STREAMGRABBER_HANDLE hStg, size_t numBuffers );
    GENAPIC_RESULT CPylonStreamGrabberGetMaxNumBuffer( PYLON_STREAMGRABBER_HANDLE hStg, size_t* pNumBuffers );
    GENAPIC_RESULT CPylonStreamGrabberSetMaxBufferSize( PYLON_STREAMGRABBER_HANDLE hStg, size_t maxSize );
    GENAPIC_RESULT CPylonStreamGrabberGetMaxBufferSize( PYLON_STREAMGRABBER_HANDLE hStg, size_t* pMaxSize );
    GENAPIC_RESULT CPylonStreamGrabberGetPayloadSize( PYLON_DEVICE_HANDLE hDev, PYLON_STREAMGRABBER_HANDLE hStg, size_t* payloadsize );
    GENAPIC_RESULT CPylonStreamGrabberRegisterBuffer( PYLON_STREAMGRABBER_HANDLE hStg, void* pBuffer, size_t BufLen, PYLON_STREAMBUFFER_HANDLE* phBuf );
    GENAPIC_RESULT CPylonStreamGrabberDeregisterBuffer( PYLON_STREAMGRABBER_HANDLE hStg, PYLON_STREAMBUFFER_HANDLE hBuf );
    GENAPIC_RESULT CPylonStreamGrabberPrepareGrab( PYLON_STREAMGRABBER_HANDLE hStg );
    GENAPIC_RESULT CPylonStreamGrabberIsStartAndStopStreamingMandatory( PYLON_STREAMGRABBER_HANDLE hStg, _Bool* pMandatory );
    GENAPIC_RESULT CPylonStreamGrabberStartStreamingIfMandatory( PYLON_STREAMGRABBER_HANDLE hStg );
    GENAPIC_RESULT CPylonStreamGrabberStopStreamingIfMandatory( PYLON_STREAMGRABBER_HANDLE hStg );
    GENAPIC_RESULT CPylonStreamGrabberFinishGrab( PYLON_STREAMGRABBER_HANDLE hStg );
    GENAPIC_RESULT CPylonStreamGrabberFlushBuffersToOutput( PYLON_STREAMGRABBER_HANDLE hStg );
    GENAPIC_RESULT CPylonStreamGrabberCancelGrab( PYLON_STREAMGRABBER_HANDLE hStg );
    GENAPIC_RESULT CPylonStreamGrabberRetrieveResult( PYLON_STREAMGRABBER_HANDLE hStg, PylonGrabResult_t* pGrabResult, _Bool* pReady );
    GENAPIC_RESULT CPylonStreamGrabberQueueBuffer( PYLON_STREAMGRABBER_HANDLE hStg, PYLON_STREAMBUFFER_HANDLE hBuf, const void* pContext );
    GENAPIC_RESULT CPylonStreamGrabberGetNodeMap( PYLON_STREAMGRABBER_HANDLE hStg, NODEMAP_HANDLE* phMap );

  /*
    * ----------------------------------------------------------------------------
    * Functions doing an implicit cast to 32-bit values
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonDeviceSetIntegerFeatureInt32( PYLON_DEVICE_HANDLE dev, const char* name, int32_t value );
    GENAPIC_RESULT CPylonDeviceGetIntegerFeatureInt32( PYLON_DEVICE_HANDLE dev, const char* name, int32_t* value );
    GENAPIC_RESULT CPylonDeviceGetIntegerFeatureMinInt32( PYLON_DEVICE_HANDLE dev, const char* name, int32_t* value );
    GENAPIC_RESULT CPylonDeviceGetIntegerFeatureMaxInt32( PYLON_DEVICE_HANDLE dev, const char* name, int32_t* value );
    GENAPIC_RESULT CPylonDeviceGetIntegerFeatureIncInt32( PYLON_DEVICE_HANDLE dev, const char* name, int32_t* value );




    /*
    * ----------------------------------------------------------------------------
    * Wait object
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonWaitObjectIsValid( PYLON_WAITOBJECT_HANDLE hWobj, _Bool* pValid );
    GENAPIC_RESULT CPylonWaitObjectWait( PYLON_WAITOBJECT_HANDLE hWobj, uint32_t timeout, _Bool* pResult );
    GENAPIC_RESULT CPylonWaitObjectWaitEx( PYLON_WAITOBJECT_HANDLE hWobj, uint32_t timeout, _Bool alertable, EPylonWaitExResult* pWaitResult );
    GENAPIC_RESULT CPylonWaitObjectCreate( PYLON_WAITOBJECT_HANDLE* phWobj );
    GENAPIC_RESULT CPylonWaitObjectDestroy( PYLON_WAITOBJECT_HANDLE hWobj );
    GENAPIC_RESULT CPylonWaitObjectsignal( PYLON_WAITOBJECT_HANDLE hWobj );
    GENAPIC_RESULT CPylonWaitObjectReset( PYLON_WAITOBJECT_HANDLE hWobj );

    GENAPIC_RESULT CPylonWaitObjectFromFd( int fd, PYLON_WAITOBJECT_HANDLE* phWobj );
    GENAPIC_RESULT CPylonWaitObjectGetFd( PYLON_WAITOBJECT_HANDLE hWobj, int* pFd );
    /*
    * ----------------------------------------------------------------------------
    * Wait objects
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonWaitObjectsCreate( PYLON_WAITOBJECTS_HANDLE* phWos );
    GENAPIC_RESULT CPylonWaitObjectsDestroy( PYLON_WAITOBJECTS_HANDLE hWos );
    GENAPIC_RESULT CPylonWaitObjectsAdd( PYLON_WAITOBJECTS_HANDLE hWos, PYLON_WAITOBJECT_HANDLE hWobj, size_t* pIndex );
    GENAPIC_RESULT CPylonWaitObjectsAddMany( PYLON_WAITOBJECTS_HANDLE hWos, size_t numWaitObjects, ... );
    GENAPIC_RESULT CPylonWaitObjectsRemoveAll( PYLON_WAITOBJECTS_HANDLE hWos );
    GENAPIC_RESULT CPylonWaitObjectsWaitForAll( PYLON_WAITOBJECTS_HANDLE hWos, uint32_t timeout, _Bool* pResult );
    GENAPIC_RESULT CPylonWaitObjectsWaitForAny( PYLON_WAITOBJECTS_HANDLE hWos, uint32_t timeout, size_t* pIndex, _Bool* pResult );
    GENAPIC_RESULT CPylonWaitObjectsWaitForAny( PYLON_WAITOBJECTS_HANDLE hWos, uint32_t timeout, size_t* pIndex, _Bool* pResult );
    GENAPIC_RESULT CPylonWaitObjectsWaitForAllEx( PYLON_WAITOBJECTS_HANDLE hWos, uint32_t timeout, _Bool alertable, EPylonWaitExResult* pWaitResult );
    GENAPIC_RESULT CPylonWaitObjectsWaitForAnyEx( PYLON_WAITOBJECTS_HANDLE hWos, uint32_t timeout, size_t* pIndex, _Bool alertable, EPylonWaitExResult* pWaitResult );


    /*
    * ----------------------------------------------------------------------------
    * Event grabber
    * ----------------------------------------------------------------------------
    */
    extern const size_t CPylonEventGrabberBufferSize;
    GENAPIC_RESULT CPylonEventGrabberOpen( PYLON_EVENTGRABBER_HANDLE hEvg );
    GENAPIC_RESULT CPylonEventGrabberClose( PYLON_EVENTGRABBER_HANDLE hEvg );
    GENAPIC_RESULT CPylonEventGrabberIsOpen( PYLON_EVENTGRABBER_HANDLE hEvg, _Bool* pOpen );
    GENAPIC_RESULT CPylonEventGrabberRetrieveEvent( PYLON_EVENTGRABBER_HANDLE hEvg, PylonEventResult_t* pEventResult, _Bool* pReady );
    GENAPIC_RESULT CPylonEventGrabberGetWaitObject( PYLON_EVENTGRABBER_HANDLE hEvg, PYLON_WAITOBJECT_HANDLE* phWobj );
    GENAPIC_RESULT CPylonEventGrabberGetNodeMap( PYLON_EVENTGRABBER_HANDLE hEvg, NODEMAP_HANDLE* phMap );


    /*
    * ----------------------------------------------------------------------------
    * Event grabber convenience methods
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonEventGrabberGetNumBuffers( PYLON_EVENTGRABBER_HANDLE hEvg, size_t* pNumBuffers );
    GENAPIC_RESULT CPylonEventGrabberSetNumBuffers( PYLON_EVENTGRABBER_HANDLE hEvg, size_t numBuffers );


    /*
    * ----------------------------------------------------------------------------
    * Event adapter
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonEventAdapterDeliverMessage( PYLON_EVENTADAPTER_HANDLE hEva, const PylonEventResult_t* pEventResult );


    /*
    * ----------------------------------------------------------------------------
    * Chunk parser
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonChunkParserAttachBuffer( PYLON_CHUNKPARSER_HANDLE hChp, const void* pBuffer, size_t BufLen );
    GENAPIC_RESULT CPylonChunkParserDetachBuffer( PYLON_CHUNKPARSER_HANDLE hChp );
    GENAPIC_RESULT CPylonChunkParserUpdateBuffer( PYLON_CHUNKPARSER_HANDLE hChp, const void* pBuffer );
    GENAPIC_RESULT CPylonChunkParserHasCRC( PYLON_CHUNKPARSER_HANDLE hChp, _Bool* pResult );
    GENAPIC_RESULT CPylonChunkParserCheckCRC( PYLON_CHUNKPARSER_HANDLE hChp, _Bool* pResult );


    /*
    * ----------------------------------------------------------------------------
    * Deprecated PixelFormat functions. Use ImageFormat functions instead.
    * ----------------------------------------------------------------------------
    */
    /* Deprecated: PylonPixelFormatConverterCreate has been deprecated. Use CPylonImageFormatConverterCreate instead. */
    GENAPIC_RESULT CPylonPixelFormatConverterCreate( PYLON_DEVICE_HANDLE hDev, int outAlign, PYLON_FORMAT_CONVERTER_HANDLE* phConv );
    /* Deprecated: PylonPixelFormatConverterConvert has been deprecated. Use CPylonImageFormatConverterConvert instead. */
    GENAPIC_RESULT CPylonPixelFormatConverterConvert( PYLON_FORMAT_CONVERTER_HANDLE hConv, void* targetBuffer, size_t targetBufferSize, const void* sourceBuffer, size_t sourceBufferSize );
    /* Deprecated: PylonPixelFormatConverterGetOutputBufferSize has been deprecated. Use CPylonImageFormatConverterGetBufferSizeForConversion instead. */
    GENAPIC_RESULT CPylonPixelFormatConverterGetOutputBufferSize( PYLON_FORMAT_CONVERTER_HANDLE hConv, size_t* pBufSiz );
    /* Deprecated: PylonPixelFormatConverterDestroy has been deprecated. Use CPylonImageFormatConverterDestroy instead. */
    GENAPIC_RESULT CPylonPixelFormatConverterDestroy( PYLON_FORMAT_CONVERTER_HANDLE hConv );


    /*
    * ----------------------------------------------------------------------------
    * Pixel Type operations
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonBitsPerPixel( EPylonPixelType pixelType, int* pResult );
    GENAPIC_RESULT CPylonIsMono( EPylonPixelType pixelType, _Bool* pResult );
    GENAPIC_RESULT CPylonIsBayer( EPylonPixelType pixelType, _Bool* pResult );
    GENAPIC_RESULT CPylonPixelTypeFromString( const char* pString, EPylonPixelType* pPixelType );



    /*
    * ----------------------------------------------------------------------------
    * Port read and write operations
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonDevicePortRead( PYLON_DEVICE_HANDLE hDev, void* pBuffer, int64_t Address, size_t Length );
    GENAPIC_RESULT CPylonDevicePortWrite( PYLON_DEVICE_HANDLE hDev, const void* pBuffer, int64_t Address, size_t Length );


    /*
    * ----------------------------------------------------------------------------
    * Feature Persistence
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonFeaturePersistenceSave( NODEMAP_HANDLE hMap, const char* pFileName );
    GENAPIC_RESULT CPylonFeaturePersistenceLoad( NODEMAP_HANDLE hMap, const char* pFileName, _Bool verify );
    GENAPIC_RESULT CPylonFeaturePersistenceSaveToString( NODEMAP_HANDLE hMap, char* pFeatures, size_t* pFeaturesLen );
    GENAPIC_RESULT CPylonFeaturePersistenceLoadFromString( NODEMAP_HANDLE hMap, const char* pFeatures, _Bool verify );


    /*
    * ----------------------------------------------------------------------------
    * Image Persistence
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonImagePersistenceSave( EPylonImageFileFormat imageFileFormat, const char* pFilename, const void* pBuffer, size_t bufferSize, EPylonPixelType pixelType, uint32_t width, uint32_t height, size_t paddingX, EPylonImageOrientation orientation, PylonImagePersistenceOptions_t* pOptions );
    GENAPIC_RESULT CPylonImagePersistenceLoad( const char* pFilename, void* pBuffer, size_t* pBufferSize, EPylonPixelType* pPixelType, uint32_t* pWidth, uint32_t* pHeight, size_t* pPaddingX, EPylonImageOrientation* pOrientation );


    /*
    * ----------------------------------------------------------------------------
    * Image Format Converter
    * ----------------------------------------------------------------------------
    */
    GENAPIC_RESULT CPylonImageFormatConverterCreate( PYLON_IMAGE_FORMAT_CONVERTER_HANDLE* phConv );
    GENAPIC_RESULT CPylonImageFormatConverterGetNodeMap( PYLON_IMAGE_FORMAT_CONVERTER_HANDLE hConv, NODEMAP_HANDLE* phMap );
    GENAPIC_RESULT CPylonImageFormatConverterSetOutputPixelFormat( PYLON_IMAGE_FORMAT_CONVERTER_HANDLE hConv, EPylonPixelType pixelType );
    GENAPIC_RESULT CPylonImageFormatConverterGetOutputPixelFormat( PYLON_IMAGE_FORMAT_CONVERTER_HANDLE hConv, EPylonPixelType* pPixelType );
    GENAPIC_RESULT CPylonImageFormatConverterSetOutputPaddingX( PYLON_IMAGE_FORMAT_CONVERTER_HANDLE hConv, size_t paddingX );
    GENAPIC_RESULT CPylonImageFormatConverterGetOutputPaddingX( PYLON_IMAGE_FORMAT_CONVERTER_HANDLE hConv, size_t* pPaddingX );
    GENAPIC_RESULT CPylonImageFormatConverterConvert( PYLON_IMAGE_FORMAT_CONVERTER_HANDLE hConv, void* targetBuffer, size_t targetBufferSize, const void* sourceBuffer, size_t sourceBufferSize, EPylonPixelType sourcePixelType, uint32_t sourceWidth, uint32_t sourceHeight, size_t sourcePaddingX, EPylonImageOrientation sourceOrientation );
    GENAPIC_RESULT CPylonImageFormatConverterGetBufferSizeForConversion( PYLON_IMAGE_FORMAT_CONVERTER_HANDLE hConv, EPylonPixelType sourcePixelType, uint32_t sourceWidth, uint32_t sourceHeight, size_t* pBufSize );
    GENAPIC_RESULT CPylonImageFormatConverterDestroy( PYLON_IMAGE_FORMAT_CONVERTER_HANDLE hConv );



    void CPrintError(GENAPIC_RESULT errc);
#ifdef __cplusplus
}
#endif

#endif
