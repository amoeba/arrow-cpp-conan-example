# arrow-cpp-conan-example

Example of using [conan](http://conan.io) to use a customized version of libarrow in a C++ project.

This specific example builds libarrow with:

- Flight RPC
- Parquet

## Pre-requisites

- A source checkout of the [arrow](https://github.com/apache/arrow) repository
- A C++ compiler
- cmake

## Building

1. Build a Conan recipe for libarrow
    - Set the `ARROW_HOME` environment variable
        ```sh
        export ARROW_HOME=$ARROW_SOURCE_DIR
        ```
    - Create the Conan recipe

        ```sh
        cd $ARROW_HOME
        conan create ci/conan/all arrow/10.0.0@ \
            -o arrow:with_flight_rpc=True \
            -o arrow:parquet=True \
            --build missing \
            --require-override protobuf/3.21.4
        ```
2. Build the example project

    From this directory, run:

    ```sh
    mkdir build
    cd build
    conan install .. \
        -o arrow:with_flight_rpc=True \
        -o arrow:parquet=True \
        --build missing
    cmake ..
    make
    ```

## Running

```sh
./bin/example
```

You should get the following output:

```
[
  1,
  2,
  3,
  4
]
```

## Contributing

Please feel free to open [an issue](https://github.com/amoeba/arrow-cpp-conan-example) or file a PR if the change is fairly straightforward.
