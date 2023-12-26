CPP_SAFETY_FEATURES = [
    "treat_warnings_as_errors",
    "strict_warnings",
    "additional_warnings",
]

# Component Interface:
cc_library(
    name = "common",
    features = CPP_SAFETY_FEATURES,
    hdrs = ["IComponent.hpp", "Parameters.hpp", ],
    deps = ["@eigen"],
)

# Electric Components:
cc_library(
    name = "components_lib",
    srcs = ["Battery.cpp", "Resistor.cpp",],
    hdrs = ["BaseComponent.hpp", "Battery.hpp", "Resistor.hpp",],
    features = CPP_SAFETY_FEATURES,
    deps = [":common", "@eigen"],
)

# Main library:
cc_library(
    name = "component_factory",
    srcs = ["Factory.cpp"],
    features = CPP_SAFETY_FEATURES,
    hdrs = ["IFactory.hpp", "Factory.hpp",],
    deps = [":components_lib",],
    visibility = ["//src/simulator:__subpackages__"],
)
