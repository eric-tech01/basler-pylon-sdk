# all:
# 	g++ sdk.cpp -g -Wall -Iinclude -Ideps -std=c++11 -Ihcsdk \
# 		-shared -fPIC -Lhcsdk/lib -lhcnetsdk \
# 		-Wl,-rpath=hcsdk/lib:./:./sdk/:./sdk/hcsdk/lib/HCNetSDKCom:./sdk/hcsdk/lib:hcsdk/lib/HCNetSDKCom \
# 		-o libsdk.so

# CC := g++
# CFLAGS := -std=c++11 -fPIC -I/opt/pylon/include/
# LDFLAGS := -L/opt/pylon/lib/ -lpylonbase -lpylonutility
# all: libsdk.so
# libsdk.so: sdk.cpp
#     $(CC) $(CFLAGS) $(LDFLAGS) -shared -o libsdk.so
# clean:
#     rm -f libsdk.so


all:
	g++ sdk.cpp  -std=c++11 -fPIC -I/opt/pylon/include/ -shared -fPIC  -L/opt/pylon/lib/ -lpylonbase -lpylonutility  -o libsdk.so