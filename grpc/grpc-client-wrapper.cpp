#include "grpc-client-wrapper.h"
#include "grpc-client.h"

int GrpcClientWrapper::EstablishConnection(const std::string& ConfiguredIp) {
  RLTChannel = grpc::CreateChannel(ConfiguredIp, grpc::InsecureChannelCredentials());
  RLTClient = std::make_shared<LoadTransportControlClient>(RLTChannel);
}

int GrpcClientWrapper::Start() {
    RLTClient->start();
}

int GrpcClientWrapper::Stop() {
    RLTClient->stop();
}

int GrpcClientWrapper::SetMode(bool isManualMode) {
    RLTClient->set_mode(isManualMode);
}

int GrpcClientWrapper::MoveForward() {
    RLTClient->change_movement_type(RLTManualModeChangeMove::RLT_MOVE_FORWARD);
}

int GrpcClientWrapper::MoveRight() {
    RLTClient->change_movement_type(RLTManualModeChangeMove::RLT_MOVE_RIGHT);
}

int GrpcClientWrapper::MoveLeft() {
    RLTClient->change_movement_type(RLTManualModeChangeMove::RLT_MOVE_LEFT);
}

int GrpcClientWrapper::MoveStop() {
    RLTClient->change_movement_type(RLTManualModeChangeMove::RLT_MOVE_STOP);
}