//******************************************************************
//
// Copyright 2014 Samsung Electronics All Rights Reserved.
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

/* This code is generated by SHP Code Generator. Please do not modify */

package gen.xsd;

/**
 * The enumeration set of open type which the door of device supports.
 */
public class OpenType {
    /**
     * Variable that contains OpenType type value.
     */
    public String value;

    /**
     * Check whether the value is following the rules or not.
     * 
     * @return True if the value is valid / False if the value is not valid
     */
    public boolean validateContent() {
        if (value.equals("Open")) {
        } else if (value.equals("Close")) {
        } else
            return false;
        return true;
    }
};
