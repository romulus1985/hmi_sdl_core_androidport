/**
* \file watchdog.h
* \brief Watchdog interface header file.
*
* Copyright (c) 2013, Ford Motor Company
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following
* disclaimer in the documentation and/or other materials provided with the
* distribution.
*
* Neither the name of the Ford Motor Company nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef SRC_COMPONENTS_REQUEST_WATCHDOG_INCLUDE_REQUEST_WATCHDOG_WATCHDOG_H_
#define SRC_COMPONENTS_REQUEST_WATCHDOG_INCLUDE_REQUEST_WATCHDOG_WATCHDOG_H_

#include <stdint.h>
#include "request_watchdog/watchdog_subscriber.h"
#include "request_watchdog/request_info.h"

namespace request_watchdog {

class Watchdog {
  public:

    /*
     * @brief Default constructor
     */
    Watchdog();

    /*
     * @brief Destructor
     */
    virtual ~Watchdog();

    virtual void AddListener(WatchdogSubscriber* subscriber) = 0;
    virtual void RemoveListener(WatchdogSubscriber* listener) = 0;
    virtual void removeAllListeners() = 0;

    /*
     * @brief Adds request
     *
     * @brief requestInfo Request info (connection key, request correlation id,
     * request id, watchdog timeout for request, current application hmi level
     */
    virtual void addRequest(RequestInfo* requestInfo) = 0;

    /*
     * @brief Removes corresponding request
     *
     * @brief connection_key    Application connection key
     * @brief correlation_id    Mobile request correlation ID
     */
    virtual void removeRequest(int32_t connection_key,
                               int32_t correlation_id) = 0;

    /*
     * @brief Update request watchdog timeout
     *
     * @brief connection_key    Application connection key
     * @brief correlation_id    Mobile request correlation ID
     * @brief new_timeout_value New value of request watchdog timeout
     */
    virtual void updateRequestTimeout(int32_t connection_key,
                                      int32_t correlation_id,
                                      int32_t new_timeout_value) = 0;

    /*
     * @brief Check if amount of requests during time scale for application
     * doesn't exceed limit.
     *
     * @brief connection_key Application ID
     * @brief app_time_scale Configured time scale for application
     * @brief max_request_per_time_scale Configured max request amount for
     * application time scale
     *
     * @return TRUE if amount of request doesn't exceed limit, otherwise FALSE
     */
    virtual bool checkTimeScaleMaxRequest(
                            const int32_t& connection_key,
                            const uint32_t& app_time_scale,
                            const uint32_t& max_request_per_time_scale) = 0;

    /*
     * @brief Check if amount of requests during time scale for application in
     * specified hmi level doesn't exceed limit.
     *
     * @brief hmi_level      Application hmi level(NONE)
     * @brief connection_key Application ID
     * @brief app_time_scale Configured time scale for application
     * @brief max_request_per_time_scale Configured max request amount for
     * application time scale
     *
     * @return TRUE if amount of request doesn't exceed limit, otherwise FALSE
     */
    virtual bool checkHMILevelTimeScaleMaxRequest(
                            const int32_t& hmi_level,
                            const int32_t& connection_key,
                            const uint32_t& app_time_scale,
                            const uint32_t& max_request_per_time_scale) = 0;

    /*
     * @brief Removes all requests
     */
    virtual void removeAllRequests() = 0;

    virtual int32_t getRegesteredRequestsNumber() = 0;
};

}  //  namespace request_watchdog

#endif  // SRC_COMPONENTS_REQUEST_WATCHDOG_INCLUDE_REQUEST_WATCHDOG_WATCHDOG_H_
