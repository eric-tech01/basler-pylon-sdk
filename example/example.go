package main

import (
	"fmt"

	gopylon "github.com/eric-tech01/gopylon"
)

func main() {
	fmt.Println("---===")
	gopylon.PylonInitialize()

	camera := &gopylon.Camera{SerialNo: "ML230-40C"}
	num := camera.FetchCamera()
	fmt.Println("device nums: ", num)
	gopylon.PylonTerminate()
}
