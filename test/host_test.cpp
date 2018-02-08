//
// Created by Mike Loomis on 2/7/2018.
//

#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "../crypto/primitives/asymmetric.hpp"


SCENARIO("I can implement a key interface") {
  GIVEN("A class definition") {
    class myKey : public PrivateKey {
    public:
      std::vector<uint8_t> Bytes() const override {
        return std::vector<uint8_t>(0);
      };

      bool operator==(const Key &other) const override {
        return other.Bytes() == this->Bytes();
      }
    };

    WHEN("I instantiate the class") {
      myKey a_key, b_key;
      THEN("The program compiles") {
        REQUIRE(a_key.Bytes() == b_key.Bytes());
      }
    }
  }
}