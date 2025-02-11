#pragma once

#include "control.grpc.pb.h"
#include <grpcpp/grpcpp.h>

#include "grpc-manual-movement-types.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class LoadTransportControlClient {
 public:
  LoadTransportControlClient(std::shared_ptr<grpc::ChannelInterface> channel)
      : stub_(LoadTransportControl::NewStub(channel)) {}

    ~LoadTransportControlClient() {
        stop();
    }

  int start();

  int stop();

  int set_mode(bool isManualMode);

  int change_movement_type(RLTManualModeChangeMove MoveType);

 private:
  std::unique_ptr<LoadTransportControl::Stub> stub_;
};