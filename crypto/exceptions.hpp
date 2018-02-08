//
// Created by Mike Loomis on 2/8/2018.
//

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class UnsupportedAlgorithm : public std::exception {
  const char *what() const throw() override { return "Unsupported Algorithm"; }
};

class AlreadyFinalized : public std::exception {
  const char *what() const throw() override { return "Already Finalized"; }
};

class AlreadyUpdated : public std::exception {
  const char *what() const throw() override { return "Already Updated"; }
};

class NotYetFinalized : public std::exception {
  const char *what() const throw() override { return "NotYetFinalized"; }
};

class InvalidTag : public std::exception {
  const char *what() const throw() override { return "Invalid Tag"; }
};

class InvalidSignature : public std::exception {
  const char *what() const throw() override { return "Invalid Signature"; }
};

class InternalError : public std::exception {
  const char *what() const throw() override { return "Internal Error"; }
};

class InvalidKey : public std::exception {
  const char *what() const throw() override { return "Invalid Key"; }
};

#endif //EXCEPTIONS_HPP
