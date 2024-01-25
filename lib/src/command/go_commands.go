package command

import (
	"flag"
	"os"
)

// Go Commands and Flags
var (
	goCommand      = flag.NewFlagSet("go", flag.ExitOnError)
	goCommandError = goCommand.Parse(os.Args[2:])
	goBuildFlag    = goCommand.String(
		"build",
		"",
		"Build Package: --build Path: <String>",
	)
	goDocFlag = goCommand.Bool(
		"doc",
		false,
		"Document Package: --doc <Bool>",
	)
	goIntegrationFlag = goCommand.Bool(
		"integration",
		false,
		"Continuous Integration: --integration <Bool>",
	)
	goTestFlag = goCommand.String(
		"test",
		"./test",
		"Run Test: --test Path: <String>",
	)
)
