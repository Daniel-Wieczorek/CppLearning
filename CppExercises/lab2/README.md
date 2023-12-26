# Lab 2: Sorted LinkedList class implementation

- Requirements are placed in [exercise_2.pdf](exercise_1.pdf).
- Source code is placed in `LinkedList.h`.
- For a quick check if library can be compiled please build with `main.cpp`
  using instructions below.


## Run program:

Program can be compiled using `g++` (tested with v.9.4.0):

```Shell
g++ main.cpp -o main.out
```

and started via:

```Shell
./main.out
```

successful compilation will print to the shell:

```
LinkedList library started and printed: 21 
```


## Run tests:

Tests are written in Catch 2 v 3.x. Tests needs `CMake` to be installed before
(at least v.3.15). To run the tests execute following commands:

```Shell
cd test/build/
cmake..
make
./tests
```
