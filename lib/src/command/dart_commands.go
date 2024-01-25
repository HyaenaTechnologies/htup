package command

import (
	"flag"
	"os"
)

// Dart Commands and Flags
var (
	dartCommand      = flag.NewFlagSet("dart", flag.ExitOnError)
	dartCommandError = dartCommand.Parse(os.Args[2:])
	dartCompileFlag  = dartCommand.String(
		"compile",
		"/bin/dart_application",
		"Compile Package: --compile Path: <String>",
	)
	dartDocFlag = dartCommand.Bool(
		"doc",
		false,
		"Document Package: --doc <Bool>",
	)
	dartIntegrationFlag = dartCommand.Bool(
		"integration",
		false,
		"Continuous Integration: --integration <Bool>",
	)
	dartTestFlag = dartCommand.String(
		"test",
		".",
		"Run Test: --test Path: <String>",
	)
)
