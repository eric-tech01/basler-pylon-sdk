package main

import (
	"fmt"

	gopylon "github.com/eric-tech01/gopylon"
)

func main() {
	fmt.Println("---===")
	gopylon.PylonInitialize()

	camera := &gopylon.Camera{SerialNumber: "ML230-40C"}
	num := camera.FetchCamera()
	fmt.Println("device nums: ", num)
	camera.GetDeviceInfo()
	fmt.Printf("%v \n", camera)
	camera.Open()

	// camera.GetIntegerFeatureInt32("PayloadSize", &camera.PayloadSize)
	// fmt.Println("payloadSize: ", camera.PayloadSize)

	grabber, err := camera.NewGrabber()
	if err != nil {
		fmt.Println("new grabber:", err)
		return
	}
	if err := grabber.Open(); err != nil {
		fmt.Println("open grab:", err)
		return
	}
	if !grabber.IsSupportStream() {
		fmt.Println("not support image streams")
		return
	}

	grabber.GetPayloadSize(camera.HDev)
	if err := grabber.SetMaxNumBuffer(); err != nil {
		fmt.Printf("set max num buffer: %d \n", err)
		return
	}

	if err := grabber.SetMaxBufferSize(); err != nil {
		fmt.Printf("set max buffer size: %d \n", err)
		return
	}
	//开始按照需要调用一次拍照抓取

	if err := grabber.PrepareGrab(); err != nil {
		fmt.Printf("prepare grab: %d \n", err)
		return
	}

	if err := grabber.RegisterBuffer(); err != nil {
		fmt.Printf("RegisterBuffer: %d \n", err)
		return
	}
	if err := grabber.QueueBuffer(); err != nil {
		fmt.Printf("QueueBuffer: %d \n", err)
		return
	}

	//start capture

	if err := grabber.StartStreamingIfMandatory(); err != nil {
		fmt.Printf("StartStreamingIfMandatory: %d \n", err)
		return
	}

	if err := camera.ExecuteCommandFeature("AcquisitionStart"); err != nil {
		fmt.Printf("AcquisitionStart: %d \n", err)
		return
	}

	GrabNums := 0
	for {

		if GrabNums > 10 {
			break
		}

	}
	//stop all
	if err := grabber.StopStreamingIfMandatory(); err != nil {
		fmt.Printf("StopStreamingIfMandatory: %d \n", err)
		return
	}

	defer func() {
		grabber.StopClose()
		camera.StopAndClean()

		gopylon.PylonTerminate()
	}()
}

// 触发一次拍一个照片
func TriggerCapture() {

}
