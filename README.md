# Change Generator
- This program generates the amount of change you can generate for a given amount. This only supports values in the US currency with major denominations. Only non-negative values are accepted and any values that cannot be represented in US denominations (e.g. dollars and cents) will be unaccepted/discarded. This project was built under the assumption that only numeric values will be provided as input.

## Running the program
### Running the program using CMake
To run the program manually please run the following commands.

In the root directory, please run the following commands in order.
```
cmake .
make
./cg
```
### Running the program using Docker
This program can be built into a docker container.

In the root directory, please run the following commands in order.
```
docker build -t change-generator .
docker run -it change-generator
```

## Running test cases
This program supports testing using CTest. The test file is located in /tests/tests.c.

To run the test cases manually please run the following commands.

In the root directory, please run the following commands in order.
```
cmake .
make
./tests/cg_tests
```