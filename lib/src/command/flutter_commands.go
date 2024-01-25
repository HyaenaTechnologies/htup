package command

import (
	"flag"
	"os"
)

// Flutter Commands and Flags
var (
	flutterCommand      = flag.NewFlagSet("flutter", flag.ExitOnError)
	flutterCommandError = flutterCommand.Parse(os.Args[2:])
	flutterBuildFlag    = flutterCommand.String(
		"build",
		"/bin/flutter_application",
		"Build Package: --build Path: <String>",
	)
	flutterDocFlag = flutterCommand.Bool(
		"doc",
		false,
		"Document Package: --doc <Bool>",
	)
	flutterIntegrationFlag = flutterCommand.Bool(
		"integration",
		false,
		"Continuous Integration: --integration <Bool>",
	)
	flutterTestFlag = flutterCommand.String(
		"test",
		".",
		"Run Test: --test Path: <String>",
	)
)
