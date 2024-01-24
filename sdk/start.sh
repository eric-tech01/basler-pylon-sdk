
# export LD_LIBRARY_PATH=`/opt/pylon/lib/`
# ../device $(basename $(pwd))  
# # nohup ../device $(basename $(pwd)) >device.log 2>&1 &


#!/bin/bash

PYLON_PATH=/opt/pylon

libs=(
	-lpylonbase 
	-lpylon_TL_usb    # FIX here for other HW
	-lpylonutility 

)

CPATH=${PYLON_PATH}/include/
CGO_CPPFLAGS=-I${CPATH}
CGO_LDFLAGS="-L${PYLON_PATH}/lib -L. -Wl,--start-group ${libs[@]} -Wl,--end-group"

set -xe
exec env \
    LD_LIBRARY_PATH="${PYLON_PATH}/lib" \
    PYLON_PATH="${PYLON_PATH}" \
    CGO_CPPFLAGS="${CGO_CPPFLAGS}" \
    CGO_LDFLAGS="${CGO_LDFLAGS}" \
  ../device


