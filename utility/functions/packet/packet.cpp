// Copyright (c) 2023 Sri Lakshmi Kanthan P
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "packet.hpp"

namespace srilakshmikanthanp::clipbirdesk::utility::functions {
/**
 * @brief Create the DiscoveryPacket
 *
 * @param packetType
 * @param ipType
 * @param ipaddr
 * @param port
 *
 * @return DiscoveryPacket
 */
network::packets::DiscoveryPacket createPacket(internals::DiscoveryPacketParams params) {
  // create the packet
  network::packets::DiscoveryPacket packet;

  // set the packet type
  packet.setPacketType(params.packetType);

  // set the ip type
  packet.setIpType(params.ipType);

  // set the ip address
  if (params.ipType == types::enums::IPType::IPv4) {
    packet.setHostIp(toIPV4QByteArray(params.ipaddr));
  } else {
    packet.setHostIp(toIPV6QByteArray(params.ipaddr));
  }

  // set the port
  packet.setHostPort(params.port);

  // set the packet length
  packet.setPacketLength(packet.size());

  // return the packet
  return packet;
}

/**
 * @brief Create the ErrorMessage
 *
 * @param packetType
 * @param errorCode
 * @param errorMessage
 *
 * @return ErrorMessage
 */
network::packets::InvalidRequest createPacket(internals::InvalidPacketParams params) {
  // create the packet
  network::packets::InvalidRequest packet;

  // set the packet type
  packet.setPacketType(params.packetType);

  // set the error code
  packet.setErrorCode(params.errorCode);

  // set the error message
  packet.setErrorMessage(params.errorMessage.toUtf8());

  // set the packet length
  packet.setPacketLength(packet.size());

  // return the packet
  return packet;
}

/**
 * @brief Create the SyncingItem
 *
 * @param mime
 * @param payload
 *
 * @return SyncingItem
 */
network::packets::SyncingItem createPacket(internals::SyncingItemParams params) {
  // create the SyncingItem
  network::packets::SyncingItem syncItem;

  // set the mime length
  syncItem.setMimeLength(params.mimeType.size());

  // set the mime type
  syncItem.setMimeType(params.mimeType.toUtf8());

  // set the payload length
  syncItem.setPayloadLength(params.payload.size());

  // set the payload
  syncItem.setPayload(params.payload);

  // return the SyncingItem
  return syncItem;
}

/**
 * @brief Create the SyncingPacket
 *
 * @param packetType
 * @param items
 *
 * @return SyncingPacket
 */
network::packets::SyncingPacket createPacket(internals::SyncingPacketParams params) {
  // create the packet
  network::packets::SyncingPacket packet;

  // set the packet type
  packet.setPacketType(params.packetType);

  // set the item count
  packet.setItemCount(params.items.size());

  // Convert the items to SyncingItem
  QVector<network::packets::SyncingItem> items;

  // reserve the memory
  items.reserve(params.items.size());

  // convert the items
  for (const auto& [mime, payload] : params.items) {
    items.push_back(createPacket({mime, payload}));
  }

  // set the items
  packet.setItems(items);

  // set the packet length
  packet.setPacketLength(packet.size());

  // return the packet
  return packet;
}

/**
 * @brief Create the SyncingPacket
 *
 * @param packetType
 * @param items
 *
 * @return SyncingPacket
 */
network::packets::SyncingPacket createPacket(
    quint8 packetType, QVector<QPair<QString, QByteArray>> items
) {
  // create the packet
  network::packets::SyncingPacket packet;

  // set the packet type
  packet.setPacketType(packetType);

  // set the item count
  packet.setItemCount(items.size());

  // Convert the items to SyncingItem
  QVector<network::packets::SyncingItem> syncItems;

  // reserve the memory
  syncItems.reserve(items.size());

  // convert the items
  for (const auto& [mime, payload] : items) {
    syncItems.push_back(createPacket({mime, payload}));
  }

  // set the items
  packet.setItems(syncItems);

  // set the packet length
  packet.setPacketLength(packet.size());

  // return the packet
  return packet;
}
}  // namespace srilakshmikanthanp::clipbirdesk::utility::functions
