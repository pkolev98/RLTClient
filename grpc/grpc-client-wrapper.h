#pragma once

#include <string>
#include <memory>

namespace grpc {
    class ChannelInterface;
}
class LoadTransportControlClient;

class GrpcClientWrapper {
public:
    GrpcClientWrapper() = default;

    ~GrpcClientWrapper() = default;

    int EstablishConnection(const std::string& ConfiguredIp);

    int Start();

    int Stop();

    int SetMode(bool isManualMode);

    int MoveForward();

    int MoveRight();

    int MoveLeft();

    int MoveStop();

private:
    std::shared_ptr<grpc::ChannelInterface> RLTChannel;// = grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials());
    std::shared_ptr<LoadTransportControlClient> RLTClient;
};