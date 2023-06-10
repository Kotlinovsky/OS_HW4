#ifndef IDZ3_NETWORK_HPP
#define IDZ3_NETWORK_HPP

#include <string>
#include <csignal>
#include <netinet/in.h>

/// Записывает uint8 в буфер.
/// @param buffer Буфер сообщения.
/// @param offset Отступ, байт, с которого будет начата запись.
/// @param value Передаваемое значение.
void writeByteToBuffer(std::string &buffer, size_t offset, uint8_t value);

/// Записывает uint32 в буфер.
/// @param buffer Буфер сообщения.
/// @param offset Отступ, байт, с которого будет начата запись.
/// @param value Передаваемое значение.
void writeUInt32ToBuffer(std::string &buffer, size_t offset, uint32_t value);

/// Читает uint32 из буфера.
/// @param buffer Буфер сообщения.
/// @param offset Отступ, байт, с которого будет начато чтение.
uint32_t readUInt32FromBuffer(std::string &buffer, size_t offset);

#endif //IDZ3_NETWORK_HPP
