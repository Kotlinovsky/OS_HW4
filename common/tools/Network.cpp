#include <cstdint>
#include <netinet/in.h>
#include "Network.hpp"

void writeByteToBuffer(std::string &buffer, size_t offset, uint8_t value) {
    buffer[offset] = static_cast<char>(value);
}

void writeUInt32ToBuffer(std::string &buffer, size_t offset, uint32_t value) {
    value = htonl(value);
    buffer[offset] = ((char *) &value)[0];
    buffer[offset + 1] = ((char *) &value)[1];
    buffer[offset + 2] = ((char *) &value)[2];
    buffer[offset + 3] = ((char *) &value)[3];
}

uint32_t readUInt32FromBuffer(std::string &buffer, size_t offset) {
    uint32_t value;
    ((char *) &value)[0] = buffer[offset];
    ((char *) &value)[1] = buffer[offset + 1];
    ((char *) &value)[2] = buffer[offset + 2];
    ((char *) &value)[3] = buffer[offset + 3];
    return ntohl(value);
}
