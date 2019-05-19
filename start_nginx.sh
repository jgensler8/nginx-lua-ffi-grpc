#!/bin/bash

# https://hub.docker.com/_/nginx?tab=tags
# https://hub.docker.com/r/openresty/openresty

# IMAGE=nginx:1.16.0
# IMAGE=openresty/openresty:1.13.6.2-xenial
# NOTE: replace the following with whatever you run "docker build -t ... ." with
IMAGE=test

exec docker run -it \
 --rm \
 --name nginx \
 -p 8989:8989 \
 -v $PWD/nginx.conf:/etc/nginx/conf.d/default.conf \
 -v $PWD/routeprinter_server:/usr/local/openresty/lualib/routeprinter.so \
 "${IMAGE}" $@
