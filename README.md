# Change Generator
- This program generates the amount of change you can generate for a given amount. This only supports values in the US currency with major denominations. Only non-negative values are accepted and any values that cannot be represented in US denominations (e.g. dollars and cents) will be unaccepted/discarded.

## Running the program
To run the program manually please run the following commands:
In the root directory,
```
$ cmake .
$ make
$ ./cg.out
```

This program can be built into a docker container.
Please run the following commands in order.
To generate the docker container:
```
$ docker build -t change-generator .
```

Once the docker container is generated, run this command to run the docker container,
```
$ docker run -it change-generator
```