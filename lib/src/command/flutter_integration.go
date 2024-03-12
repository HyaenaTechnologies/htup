package command

import (
	"fmt"
	"log"
	"os/exec"
	"strings"
)

type FlutterCommands struct {
	build     string
	integrate []string
	test      string
}

// Flutter Command Strings
var (
	flutterBuildPackage = FlutterCommands{
		build: "flutter build lib/main.dart",
	}
	flutterIntegration = strings.Join(
		flutterIntegrate.integrate,
		" && ",
	)
	flutterRunTest = FlutterCommands{
		test: "flutter test",
	}
)

// Flutter Integration Commands
var flutterIntegrate = FlutterCommands{
	integrate: []string{
		"flutter analyze lib",
		"flutter doctor",
		"dart fix lib --dry-run",
		"dart fix lib --apply",
		"dart format lib",
		"dart info",
		"flutter pub deps",
		"flutter pub upgrade"},
}

// Build Package
func (buildPackage FlutterCommands) FlutterBuild() {
	var flutterBuild, flutterBuildError = exec.Command(
		buildPackage.build,
		*flutterBuildFlag,
	).Output()
	if flutterBuildError != nil {
		log.Fatal(flutterBuildError)
	}
	fmt.Print(flutterBuild)
}

// Flutter Command Flag Execution
func FlutterFlagExecute() {
	if *flutterBuildFlag != "/bin/flutter_application" {
		flutterBuildPackage.FlutterBuild()
	}
	if *flutterIntegrationFlag == true {
		FlutterIntegration()
	}
	if *flutterDocFlag == true {
		dartDocument.DartDoc()
	}
	if *flutterTestFlag != "." {
		flutterRunTest.FlutterTest()
	}
}

func FlutterIntegration() {
	var flutterIntegrated, flutterIntegratedError = exec.Command(
		flutterIntegration,
	).Output()
	if flutterIntegratedError != nil {
		log.Fatal(flutterIntegratedError)
	}
	fmt.Print(flutterIntegrated)
}

// Run Test
func (runTest FlutterCommands) FlutterTest() {
	var flutterTest, flutterTestError = exec.Command(
		runTest.test,
		*flutterTestFlag,
	).Output()
	if flutterTestError != nil {
		log.Fatal(flutterTestError)
	}
	fmt.Print(flutterTest)
}
