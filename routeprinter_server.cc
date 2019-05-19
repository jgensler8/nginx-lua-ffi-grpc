/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>
// #include "helper.h"
#ifdef BAZEL_BUILD
#include "examples/protos/routeprinter.grpc.pb.h"
#else
#include "routeprinter.grpc.pb.h"
#endif

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using routeprinter::RoutePrinter;
using routeprinter::PrintableRoute;
using routeprinter::PrintRouteResponse;
using std::chrono::system_clock;


class RoutePrinterImpl final : public RoutePrinter::Service {
 public:
  explicit RoutePrinterImpl() {}

  Status PrintRoute(ServerContext* context, const PrintableRoute* route, PrintRouteResponse* response) override {
      response->set_success(42);
      return Status::OK;
  }

};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  RoutePrinterImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();
  return 0;
}