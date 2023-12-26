## Circuit Simulator

- [Object-Oriented Analysis (OOA) for Circuit Simulator](design/object_oriented_analysis.md)
- [Object-Oriented Design (OOD) for Circuit Simulator](design/object_oriented_design.md)


### Run program:
To run the program install `bazel` and execute following command:
```Bazel
bazel run //src/simulator:circuit_simulator
```

### Run the tests:
To run the program install `bazel` and execute following command:
```Bazel
bazel test //:test --cxxopt='-std=c++14'
```