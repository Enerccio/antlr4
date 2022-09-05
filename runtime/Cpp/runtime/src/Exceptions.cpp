/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#include "Exceptions.h"

using namespace antlr4;

ANTLR4CPP_ALLOCATION_IMPLEMENTATION(RuntimeException)

RuntimeException::RuntimeException(const std::string &msg) : std::exception(), _message(msg) {
}

const char* RuntimeException::what() const noexcept {
  return _message.c_str();
}

//------------------ IOException ---------------------------------------------------------------------------------------

ANTLR4CPP_ALLOCATION_IMPLEMENTATION(IOException)

IOException::IOException(const std::string &msg) : std::exception(), _message(msg) {
}

const char* IOException::what() const noexcept {
  return _message.c_str();
}

//------------------ IllegalStateException -----------------------------------------------------------------------------

IllegalStateException::~IllegalStateException() {
}

//------------------ IllegalArgumentException --------------------------------------------------------------------------

IllegalArgumentException::~IllegalArgumentException() {
}

//------------------ NullPointerException ------------------------------------------------------------------------------

NullPointerException::~NullPointerException() {
}

//------------------ IndexOutOfBoundsException -------------------------------------------------------------------------

IndexOutOfBoundsException::~IndexOutOfBoundsException() {
}

//------------------ UnsupportedOperationException ---------------------------------------------------------------------

UnsupportedOperationException::~UnsupportedOperationException() {
}

//------------------ EmptyStackException -------------------------------------------------------------------------------

EmptyStackException::~EmptyStackException() {
}

//------------------ CancellationException -----------------------------------------------------------------------------

CancellationException::~CancellationException() {
}

//------------------ ParseCancellationException ------------------------------------------------------------------------

ParseCancellationException::~ParseCancellationException() {
}
