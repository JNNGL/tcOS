#pragma once

#include "packet.h"

void protocol_registerPackets();

class ClientboundConnectionSuccessPacket : public ClientboundPacket {
public:
    ClientboundConnectionSuccessPacket();

public:
    void read(ByteBuffer&) override;
    ClientboundPacket* createInstance() override;
    unsigned char getPacketID() const override;

public:
    std::string name;

};

class ClientboundCreationRequestPacket : public ClientboundPacket {
public:
    ClientboundCreationRequestPacket();

public:
    void read(ByteBuffer&) override;
    ClientboundPacket* createInstance() override;
    unsigned char getPacketID() const override;

public:
    short width;
    short height;
    short id;
    std::string name;

};

class ClientboundDestroyPacket : public ClientboundPacket {
public:
    ClientboundDestroyPacket();

public:
    void read(ByteBuffer&) override;
    ClientboundPacket* createInstance() override;
    unsigned char getPacketID() const override;

public:
    short id;

};

class ClientboundDisconnectPacket : public ClientboundPacket {
public:
    ClientboundDisconnectPacket();

public:
    void read(ByteBuffer&) override;
    ClientboundPacket* createInstance() override;
    unsigned char getPacketID() const override;

public:
    std::string reason;

};