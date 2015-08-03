//******************************************************************
//
// Copyright 2015 Samsung Electronics All Rights Reserved.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#ifndef OIC_SERVICE_RCSADDRESS_H
#define OIC_SERVICE_RCSADDRESS_H

#include <string>
#include <memory>

namespace OIC
{
    namespace Service
    {
        class RCSAddressDetail;

        class RCSAddress
        {
        public:
            static RCSAddress multicast();
            static RCSAddress unicast(const std::string& address);
            static RCSAddress unicast(std::string&& address);

        private:
            RCSAddress(const std::shared_ptr< RCSAddressDetail >&);

        private:
            std::shared_ptr< RCSAddressDetail > m_detail;

            friend class RCSAddressDetail;
        };
    }
}

#endif // OIC_SERVICE_RCSADDRESS_H
