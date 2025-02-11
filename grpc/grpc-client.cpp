#include "grpc-client.h"

int LoadTransportControlClient::start()
{
    StartRequest request;
    request.set_name("start bro");

    Reply reply;
    ClientContext context;

    Status status = stub_->start(&context, request, &reply);

    return 0;
}

int LoadTransportControlClient::change_movement_type(RLTManualModeChangeMove MoveType)
{
    MoveRequest request;

    switch (MoveType) {
        case RLTManualModeChangeMove::RLT_MOVE_FORWARD:
            request.set_move_type(RLTMoveType::MOVE_FORWARD);
            break;
        case RLTManualModeChangeMove::RLT_MOVE_LEFT:
            request.set_move_type(RLTMoveType::MOVE_LEFT);
            break;
        case RLTManualModeChangeMove::RLT_MOVE_RIGHT:
            request.set_move_type(RLTMoveType::MOVE_RIGHT);
            break;
        case RLTManualModeChangeMove::RLT_MOVE_STOP:
            request.set_move_type(RLTMoveType::MOVE_STOP);
            break;
    }

    Reply reply;
    ClientContext context;

    Status status = stub_->change_movement_type(&context, request, &reply);

    return 0;   
}

int LoadTransportControlClient::stop()
{
    StopRequest request;
    request.set_name("stop bro");

    Reply reply;
    ClientContext context;

    Status status = stub_->stop(&context, request, &reply);

    return 0;   
}

int LoadTransportControlClient::set_mode(bool isManualMode)
{
    SetModeRequest request;
    request.set_mode(isManualMode ? RLTMode::MANUAL_MODE : RLTMode::AUTOMATIC_MODE);

    Reply reply;
    ClientContext context;

    Status status = stub_->set_mode(&context, request, &reply);

    return 0;   
}