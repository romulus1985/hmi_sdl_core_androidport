// Copyright (c) 2013, Ford Motor Company
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following
// disclaimer in the documentation and/or other materials provided with the
// distribution.
//
// Neither the name of the Ford Motor Company nor the names of its contributors
// may be used to endorse or promote products derived from this software
// without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 'A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef SRC_COMPONENTS_SMART_OBJECTS_INCLUDE_SMART_OBJECTS_ERRORS_H_
#define SRC_COMPONENTS_SMART_OBJECTS_INCLUDE_SMART_OBJECTS_ERRORS_H_

#ifdef OS_WIN32
#ifdef ERROR
#undef ERROR
#endif // ERROR
//>>>>>>>>>> DECLARE_ENUM >>>>>>>>>>
#define DECLARE_ENUM(E) \
struct E \
{ \
public: \
	E(int value = 0) : _value((__Enum)value) { \
	} \
	E& operator=(int value) { \
	this->_value = (__Enum)value; \
	return *this; \
	} \
	operator int() const { 	\
	return this->_value; \
	} \
	\
enum __Enum {

#define END_ENUM() \
}; \
	\
private: \
	__Enum _value; \
};
//<<<<<<<<<< DECLARE_ENUM <<<<<<<<<<
#endif // OS_WIN32

namespace NsSmartDeviceLink {
namespace NsSmartObjects {
namespace Errors {
/**
 * @brief Enumeration that provides information about SmartObject validation errors
 **/
enum eType {
  /**
   * @brief Success validation
   **/
  OK = 0,

  /**
   * @brief Invalid value.
   **/
  INVALID_VALUE,

  /**
   * @brief Value is out of allowed range.
   **/
  OUT_OF_RANGE,

  /**
   * @brief Mandatory parameter is missing.
   **/
  MISSING_MANDATORY_PARAMETER,

  /**
    * @brief Mandatory untitled (with any name) parameter is missing.
    **/
  MISSING_MANDATORY_UNTITLED_PARAMETER,

  /**
    * @brief Unexpected parameter.
    **/
  UNEXPECTED_PARAMETER,

  /**
   * @brief General validation error
   **/
  ERROR
};
}  // namespace Errors
}  // namespace NsSmartObjects
}  // namespace NsSmartDeviceLink

#endif  // SRC_COMPONENTS_SMART_OBJECTS_INCLUDE_SMART_OBJECTS_ERRORS_H_
