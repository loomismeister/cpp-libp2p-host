//
// Created by Mike Loomis on 2/7/2018.
//

#ifndef LIBP2P_HOST_HPP
#define LIBP2P_HOST_HPP

#include <string>
#include <vector>

class Host {
public:
  Host() = default;
  virtual ~Host() = default;

  // Returns local peer ID of this host
  virtual string id() = 0;

  // Returns the host's known peer addresses and keys
  virtual peerstore peerstore() = 0;

  // Returns the listen addresses of the host
  virtual std::vector<address> addresses() = 0;

  // Returns the network interface of the host
  virtual network network() = 0;

  virtual void connect(int peer_info)
};

#endif //LIBP2P_HOST_HPP
