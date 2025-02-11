# RLTClient
**GUI Client for the RpiLoadTransportApp**

Client application, using Qt for GUI, supporting the two modes of the RpiLoadTransportApp and sending requests with grpc to the service.
For building cmake is used. Run commands:

*mkdir build && cd build*

*cmake ..*

*make -j8*

**Prerequisites**:
Qt and grpc installed for Linux x64. RpiLoadTrasportApp srvice running on Raspberry Pi. Service repo: https://github.com/pkolev98/RpiLoadTransportApp
