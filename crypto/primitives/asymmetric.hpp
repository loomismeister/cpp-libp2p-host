//
// Created by Mike Loomis on 2/7/2018.
//

#ifndef ASYMMETRIC_HPP
#define ASYMMETRIC_HPP

#include <vector>

enum KeyTypes : int {
  RSA,
  ED25519,
  SECP256K1
};

class Key {
public:
  Key() = default;

  virtual ~Key() = default;

  virtual std::vector<uint8_t> Bytes() const = 0;

  virtual bool operator==(const Key &other) const = 0;
};

class PublicKey : public Key {
public:
  PublicKey() = default;

  ~PublicKey() override = default;

  // Verify that data is signed by the matching private key for this public key
  virtual bool Verify(std::vector<uint8_t> data, std::vector<uint8_t> signature) = 0;
};

class PrivateKey : public Key {
public:
  PrivateKey() = default;

  ~PrivateKey() override = default;

  virtual std::vector<uint8_t> Sign(std::vector<uint8_t> message) const = 0;

  virtual PublicKey GetPublic() const = 0;
};

// #TODO Make a strong random generator for supported platforms
std::tuple<PrivateKey, PublicKey> GenerateKeyPair(KeyTypes key_type, int num_bits) {
  return GenerateKeyPairWithGenerator(key_type, num_bits, rand);
};

std::tuple<PrivateKey, PublicKey> GenerateKeyPairWithGenerator(KeyTypes key_type, int num_bits, random_source) {
  switch(key_type) {
    case RSA:
      break;
    case ED25519:
      break;
    case SECP256K1:
      break;
    case default:
      return std::make_tuple(PrivateKey, PublicKey);
  }
};



#endif //ASYMMETRIC_HPP
