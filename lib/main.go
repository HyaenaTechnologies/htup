package main

import (
	"local_workflow/lib/src/command"
	"os"
)

func main() {
	command.FlagValidation()
	switch os.Args[1] {
	case "dart":
		go command.DartFlagExecute()
	case "flutter":
		go command.FlutterFlagExecute()
	case "go":
		go command.GoFlagExecute()
	}
}
