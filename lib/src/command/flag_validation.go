package command

import (
	"log"
	"os"
)

// Command and Flag Validation
func FlagValidation() {
	if dartCommandError != nil {
		log.Fatal(dartCommandError)
	}
	if flutterCommandError != nil {
		log.Fatal(flutterCommandError)
	}
	if goCommandError != nil {
		log.Fatal(goCommandError)
	}
	if len(os.Args) < 2 {
		log.Fatal("Command Required: htwork <Workflow> --help")
	}
}
