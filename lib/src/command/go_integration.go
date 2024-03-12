package command

import (
	"fmt"
	"log"
	"os/exec"
	"strings"
)

type GoCommands struct {
	build     string
	document  string
	integrate []string
	test      string
}

// Go Command Strings
var (
	goBuildPackage = GoCommands{
		build: "go build -o",
	}
	goDocument = GoCommands{
		document: "go doc",
	}
	goIntegration = strings.Join(
		goIntegrate.integrate,
		" && ",
	)
	goRunTest = GoCommands{
		test: "go test -v",
	}
)

// Go Integration Commands
var goIntegrate = GoCommands{
	integrate: []string{
		"go env",
		"go fix ./lib",
		"go fmt ./lib",
		"go list",
		"go list -m",
		"go mod download",
		"go mod graph",
		"go mod verify",
		"go version",
		"go vet ./lib",
		"go work sync",
		"go work use ./"},
}

// Build Package
func (buildPackage GoCommands) GoBuild() {
	var goBuild, goBuildError = exec.Command(
		buildPackage.build,
		*goBuildFlag,
	).Output()
	if goBuildError != nil {
		log.Fatal(goBuildError)
	}
	fmt.Print(goBuild)
}

// Document Package
func (documentation GoCommands) GoDoc() {
	var goDoc, goDocError = exec.Command(
		documentation.document,
	).Output()
	if goDocError != nil {
		log.Fatal(goDocError)
	}
	fmt.Print(goDoc)
}

// Go Command Flag Execution
func GoFlagExecute() {
	if *goBuildFlag != "" {
		goBuildPackage.GoBuild()
	}
	if *goIntegrationFlag == true {
		GoIntegration()
	}
	if *goDocFlag == true {
		goDocument.GoDoc()
	}
	if *goTestFlag != "./test" {
		goRunTest.GoTest()
	}
}

func GoIntegration() {
	var goIntegrated, goIntegratedError = exec.Command(
		goIntegration,
	).Output()
	if goIntegratedError != nil {
		log.Fatal(goIntegratedError)
	}
	fmt.Print(goIntegrated)
}

// Run Test
func (runTest GoCommands) GoTest() {
	var goTest, goTestError = exec.Command(
		runTest.test,
		*goTestFlag,
	).Output()
	if goTestError != nil {
		log.Fatal(goTestError)
	}
	fmt.Print(goTest)
}
