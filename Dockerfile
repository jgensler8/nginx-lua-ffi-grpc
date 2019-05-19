FROM grpc/cxx:1.12.0 as grpclibs
FROM openresty/openresty:1.13.6.2-xenial
COPY --from=grpclibs /usr/local/lib/* /lib/x86_64-linux-gnu/