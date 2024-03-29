#include "protocol.h"

ServerboundEncryptionPacket::ServerboundEncryptionPacket() = default;

void ServerboundEncryptionPacket::write(ByteBuffer& dst) {
    dst.writeBytes(secret);
}

unsigned char ServerboundEncryptionPacket::getPacketID() const {
    return 0xC4;
}