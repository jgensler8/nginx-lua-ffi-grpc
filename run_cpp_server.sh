#!/bin/bash

# https://hub.docker.com/r/grpc/cxx/tags

docker run -it \
 --name server \
 --rm \
 -v $PWD:/workdir \
 --workdir /workdir \
 --net=host \
 grpc/cxx:1.12.0 \
 bash

#  ./routeprinter_server