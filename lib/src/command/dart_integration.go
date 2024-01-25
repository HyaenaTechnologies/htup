package command

import (
	"fmt"
	"log"
	"os/exec"
	"strings"
)

type DartCommands struct {
	compile   string
	document  string
	integrate []string
	test      string
}

// Dart Command Strings
var (
	dartCompileBuild = DartCommands{
		compile: "dart compile exe lib/main.dart --output",
	}
	dartDocument = DartCommands{
		document: "dart doc .",
	}
	dartRunTest = DartCommands{
		test: "dart test",
	}
	dartIntegration = strings.Join(
		dartIntegrate.integrate,
		" && ",
	)
)

// Dart Integration Commands
var dartIntegrate = DartCommands{
	integrate: []string{
		"dart analyze lib",
		"dart fix lib --dry-run",
		"dart fix lib --apply",
		"dart format lib",
		"dart info",
		"dart pub deps",
		"dart pub upgrade"},
}

// Compile Package
func (compileBuild DartCommands) DartCompile() {
	var dartCompile, dartCompileError = exec.Command(
		compileBuild.compile,
		*dartCompileFlag,
	).Output()
	if dartCompileError != nil {
		log.Fatal(dartCompileError)
	}
	fmt.Print(dartCompile)
}

// Document Package
func (documentation DartCommands) DartDoc() {
	var dartDoc, dartDocError = exec.Command(
		documentation.document,
	).Output()
	if dartDocError != nil {
		log.Fatal(dartDocError)
	}
	fmt.Print(dartDoc)
}

// Dart Command Flag Execution
func DartFlagExecute() {
	if *dartCompileFlag != "/bin/dart_application" {
		dartCompileBuild.DartCompile()
	}
	if *dartIntegrationFlag == true {
		DartIntegration()
	}
	if *dartDocFlag == true {
		dartDocument.DartDoc()
	}
	if *dartTestFlag != "." {
		dartRunTest.DartTest()
	}
}

func DartIntegration() {
	var dartIntegrate, dartIntegrateError = exec.Command(
		dartIntegration,
	).Output()
	if dartIntegrateError != nil {
		log.Fatal(dartIntegrateError)
	}
	fmt.Print(dartIntegrate)
}

// Run Test
func (runTest DartCommands) DartTest() {
	var dartTest, dartTestError = exec.Command(
		runTest.test,
		*dartTestFlag,
	).Output()
	if dartTestError != nil {
		log.Fatal(dartTestError)
	}
	fmt.Print(dartTest)
}
