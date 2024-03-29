#include "../protocol/protocol.h"
#include "pipeline.h"
#include <iostream>

bool PacketEncoder::encode(ConnectionContext* ctx, void* src, void*& dst) {
    dst = new ByteBuffer();
    auto* buf = (ByteBuffer*) dst;
    auto* packet = (ServerboundPacket*) src;

    buf->writeByte(0x0A);
    buf->writeByte(0x1F);
    buf->writeByte(packet->getPacketID());

    ByteBuffer tmp;
    packet->write(tmp);

    buf->writeInt((int) tmp.readableBytes());
    buf->writeBytes(tmp.data);

    std::cout << "Sent packet: 0x" << std::hex << (int) packet->getPacketID() << std::dec << std::endl;

    return true;
};