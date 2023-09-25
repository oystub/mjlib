// Copyright 2023 mjbots Robotic Systems, LLC.  info@mjbots.com
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

namespace mjlib {
namespace base {

/// Manages ownership of a system file descriptor.
class SystemFd {
 public:
  SystemFd() : fd_(-1) {}
  SystemFd(int fd) : fd_(fd) {}

  SystemFd(SystemFd&& rhs) {
    fd_ = rhs.fd_;
    rhs.fd_ = -1;
  }

  SystemFd& operator=(SystemFd&& rhs) {
    fd_ = rhs.fd_;
    rhs.fd_ = -1;
    return *this;
  }

  ~SystemFd();

  SystemFd(const SystemFd&) = delete;
  SystemFd& operator=(const SystemFd&) = delete;

  operator int() { return fd_; }
  operator int() const { return fd_; }

 private:
  int fd_ = -1;
};

}
}
