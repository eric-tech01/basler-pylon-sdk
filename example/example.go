package main

import (
	gopylon "github.com/eric-tech01/gopylon"
	"fmt"
)

func main()  {
	fmt.Println("---===")
	gopylon.PylonInitialize()
	num := gopylon.EnumerateDevices()
	fmt.Println("device nums: ", num)
	gopylon.PylonTerminate()
}