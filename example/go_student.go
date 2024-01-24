package main

/*
#include "loadHelper.h"
*/
import "C"
import (
	// "fmt"
	"unsafe"
)

type Student struct {
	student unsafe.Pointer
}
func NewStudent() *Student  {
	s := C.NewStudent()
	return &Student{student: s}
}
func (s Student)Name()  {
	C.SName(s.student)
}
func (s Student)DoSomething(name string)  {
	
	C.DoSomething(s.student, C.CString(name))
}
func (s Student)Delete()  {
	C.DeleteStudent(s.student)
	
}
func main() {
	s := NewStudent()
	s.Name()
	s.DoSomething("zzz")
}
