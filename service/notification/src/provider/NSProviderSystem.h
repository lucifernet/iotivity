//******************************************************************
//
// Copyright 2016 Samsung Electronics All Rights Reserved.
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

#ifndef _NS_PROVIDER_SYSTEM__H_
#define _NS_PROVIDER_SYSTEM__H_

#include <string.h>
#include "logger.h"
#include "NSCommon.h"
#include "NSConstants.h"
#include "oic_malloc.h"
#include "NSStructs.h"

void NSSetProviderConnectionState(NSConnectionState state);
NSConnectionState NSGetProviderConnectionState();

void NSInitProviderInfo();
void NSDeinitProviderInfo();
NSProviderInfo * NSGetProviderInfo();

#endif /* _NS_PROVIDER_SYSTEM__H_ */
