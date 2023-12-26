CPP_SAFETY_FEATURES = [
    "treat_warnings_as_errors",
    "strict_warnings",
    "additional_warnings",
]

cc_library(
    name = "simulator",
    features = CPP_SAFETY_FEATURES,
    srcs = ["Application.cpp", "Circuit.cpp", "Simulate.cpp",],
    hdrs = ["Application.hpp", "Circuit.hpp", "Simulate.hpp",],
    deps = ["//src/components:component_factory", "@eigen", ],
)

cc_binary(
    name = "circuit_simulator",
    features = CPP_SAFETY_FEATURES,
    srcs = [
        "CircuitSim.cpp"
        ],
        copts = ["-std=c++17", "-Iexternal/eigen"],
    deps = [
        ":simulator",
    ],
)

cc_test(
    name = "test",
    srcs = ["test/CircuitSimulatorTest.cpp"],
    copts = ["-std=c++17"],
    deps = [
        "@catch2//:catch2_main",
        ":simulator_lib"
    ],
)