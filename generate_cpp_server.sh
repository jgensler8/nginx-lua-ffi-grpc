#!/bin/bash

# https://hub.docker.com/r/grpc/cxx/tags

docker run -it \
 --name cpp \
 --rm \
 -v $PWD:/workdir \
 --workdir /workdir \
 grpc/cxx:1.12.0 \
 make clean routeprinter_server