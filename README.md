# Change Generator
- This program generates the amount of change you can generate for a given amount. This only supports values in the US currency with major denominations. Only non-negative values are accepted and any values that cannot be represented in US denominations (e.g. dollars and cents) will be unaccepted/discarded.

## Running the program
### Running the program using CMake
To run the program manually please run the following commands.

In the root directory, please run the following commands in order.
```
cmake .
make
./cg.out
```
### Running the program using Docker
This program can be built into a docker container.

In the root directory, please run the following commands in order.
```
docker build -t change-generator .
docker run -it change-generator
```