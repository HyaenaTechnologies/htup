// swift-tools-version: 5.10
import PackageDescription

let package = Package(
    name: "local_workflow",
    platforms: [
        .macOS(.v11),
    ],
    products: [
        .executable(
            name: "local_workflow_executable",
            targets: ["local_workflow_target"]
        ),
    ],
    dependencies: [
        .package(
            url: "https://github.com/apple/swift-algorithms", 
            from: "1.2.0"
        ),
        .package(
            url: "https://github.com/apple/swift-argument-parser", 
            from: "1.3.0"
        ),
        .package(
            url: "https://github.com/apple/swift-async-algorithms", 
            from: "1.0.0"
        ),
        .package(
            url: "https://github.com/apple/swift-collections.git", 
            from: "1.1.0"
        ),
        .package(
            url: "https://github.com/apple/swift-log.git", 
            from: "1.0.0"
        ),
        .package(
            url: "https://github.com/apple/swift-metrics.git", 
            from: "2.4.1"
        ),
        .package(
            url: "https://github.com/apple/swift-metrics-extras.git", 
            from: "0.1.0"
        ),
        .package(
            url: "https://github.com/apple/swift-numerics", 
            from: "1.0.0"
        ),
        .package(
            url: "https://github.com/apple/swift-system", 
            from: "1.0.0"
        ),
        .package(
            url: "https://github.com/apple/swift-testing.git", 
            branch: "main"
        ),
    ],
    targets: [
        .executableTarget(
            name: "local_workflow_target", 
            dependencies: [
                .product(
                    name: "Algorithms", 
                    package: "swift-algorithms"
                ),
                .product(
                    name: "ArgumentParser", 
                    package: "swift-argument-parser"
                ),
                .product(
                    name: "AsyncAlgorithms", 
                    package: "swift-async-algorithms"
                ),
                .product(
                    name: "Collections", 
                    package: "swift-collections"
                ),
                .product(
                    name: "Logging", 
                    package: "swift-log"
                ),
                .product(
                    name: "Metrics", 
                    package: "swift-metrics"
                ),
                .product(
                    name: "Numerics", 
                    package: "swift-numerics"
                ),
                .product(
                    name: "SystemPackage", 
                    package: "swift-system"
                ),
                .product(
                    name: "Testing", 
                    package: "swift-testing"
                ),
        ]),
        .testTarget(
            name: "cli_test",
            dependencies: ["local_workflow_target"]
        ),
    ]
)
