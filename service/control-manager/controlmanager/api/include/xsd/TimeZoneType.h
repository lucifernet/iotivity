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



#ifndef TIMEZONETYPE_H_
#define TIMEZONETYPE_H_

/**
*  @addtogroup xsd
*  @{
*/
/**
 * @class TimeZoneType
 *
 * The enumeration set of time zones.
 */
class TimeZoneType
{
    public:

        /**
         * Variable that contains TimeZoneType type value.
         */
        std::string value;

        /**
         * Check whether the value is following the rules or not.
         *
         * @return @c True if the value is valid@n
         *         @c False if the value is not valid
         */
        bool validateContent()
        {
            if (value == "Africa/Abidjan") {}
            else if (value == "Africa/Accra") {}
            else if (value == "Africa/Addis_Ababa") {}
            else if (value == "Africa/Algiers") {}
            else if (value == "Africa/Asmara") {}
            else if (value == "Africa/Bamako") {}
            else if (value == "Africa/Bangui") {}
            else if (value == "Africa/Banjul") {}
            else if (value == "Africa/Bissau") {}
            else if (value == "Africa/Blantyre") {}
            else if (value == "Africa/Brazzaville") {}
            else if (value == "Africa/Bujumbura") {}
            else if (value == "Africa/Cairo") {}
            else if (value == "Africa/Casablanca") {}
            else if (value == "Africa/Ceuta") {}
            else if (value == "Africa/Conakry") {}
            else if (value == "Africa/Dakar") {}
            else if (value == "Africa/Dar_es_Salaam") {}
            else if (value == "Africa/Djibouti") {}
            else if (value == "Africa/Douala") {}
            else if (value == "Africa/El_Aaiun") {}
            else if (value == "Africa/Freetown") {}
            else if (value == "Africa/Gaborone") {}
            else if (value == "Africa/Harare") {}
            else if (value == "Africa/Johannesburg") {}
            else if (value == "Africa/Juba") {}
            else if (value == "Africa/Kampala") {}
            else if (value == "Africa/Khartoum") {}
            else if (value == "Africa/Kigali") {}
            else if (value == "Africa/Kinshasa") {}
            else if (value == "Africa/Lagos") {}
            else if (value == "Africa/Libreville") {}
            else if (value == "Africa/Lome") {}
            else if (value == "Africa/Luanda") {}
            else if (value == "Africa/Lubumbashi") {}
            else if (value == "Africa/Lusaka") {}
            else if (value == "Africa/Malabo") {}
            else if (value == "Africa/Maputo") {}
            else if (value == "Africa/Maseru") {}
            else if (value == "Africa/Mbabane") {}
            else if (value == "Africa/Mogadishu") {}
            else if (value == "Africa/Monrovia") {}
            else if (value == "Africa/Nairobi") {}
            else if (value == "Africa/Ndjamena") {}
            else if (value == "Africa/Niamey") {}
            else if (value == "Africa/Nouakchott") {}
            else if (value == "Africa/Ouagadougou") {}
            else if (value == "Africa/Porto-Novo") {}
            else if (value == "Africa/Sao_Tome") {}
            else if (value == "Africa/Tripoli") {}
            else if (value == "Africa/Tunis") {}
            else if (value == "Africa/Windhoek") {}
            else if (value == "America/Adak") {}
            else if (value == "America/Anchorage") {}
            else if (value == "America/Anguilla") {}
            else if (value == "America/Antigua") {}
            else if (value == "America/Araguaina") {}
            else if (value == "America/Argentina/Buenos_Aires") {}
            else if (value == "America/Argentina/Catamarca") {}
            else if (value == "America/Argentina/Cordoba") {}
            else if (value == "America/Argentina/Jujuy") {}
            else if (value == "America/Argentina/L_aRioja") {}
            else if (value == "America/Argentina/Mendoza") {}
            else if (value == "America/Argentina/Rio_Gallegos") {}
            else if (value == "America/Argentina/Salta") {}
            else if (value == "America/Argentina/San_Juan") {}
            else if (value == "America/Argentina/San_Luis") {}
            else if (value == "America/Argentina/Tucuman") {}
            else if (value == "America/Argentina/Ushuaia") {}
            else if (value == "America/Aruba") {}
            else if (value == "America/Asuncion") {}
            else if (value == "America/Atikokan") {}
            else if (value == "America/Bahi_aBanderas") {}
            else if (value == "America/Bahia") {}
            else if (value == "America/Barbados") {}
            else if (value == "America/Belem") {}
            else if (value == "America/Belize") {}
            else if (value == "America/Blanc-Sablon") {}
            else if (value == "America/Bo_aVista") {}
            else if (value == "America/Bogota") {}
            else if (value == "America/Boise") {}
            else if (value == "America/Cambridge_Bay") {}
            else if (value == "America/Campo_Grande") {}
            else if (value == "America/Cancun") {}
            else if (value == "America/Caracas") {}
            else if (value == "America/Cayenne") {}
            else if (value == "America/Cayman") {}
            else if (value == "America/Chicago") {}
            else if (value == "America/Chihuahua") {}
            else if (value == "America/Cost_aRica") {}
            else if (value == "America/Creston") {}
            else if (value == "America/Cuiaba") {}
            else if (value == "America/Curacao") {}
            else if (value == "America/Danmarkshavn") {}
            else if (value == "America/Dawson") {}
            else if (value == "America/Dawson_Creek") {}
            else if (value == "America/Denver") {}
            else if (value == "America/Detroit") {}
            else if (value == "America/Dominica") {}
            else if (value == "America/Edmonton") {}
            else if (value == "America/Eirunepe") {}
            else if (value == "America/El_Salvador") {}
            else if (value == "America/Fortaleza") {}
            else if (value == "America/Glace_Bay") {}
            else if (value == "America/Godthab") {}
            else if (value == "America/Goose_Bay") {}
            else if (value == "America/Grand_Turk") {}
            else if (value == "America/Grenada") {}
            else if (value == "America/Guadeloupe") {}
            else if (value == "America/Guatemala") {}
            else if (value == "America/Guayaquil") {}
            else if (value == "America/Guyana") {}
            else if (value == "America/Halifax") {}
            else if (value == "America/Havana") {}
            else if (value == "America/Hermosillo") {}
            else if (value == "America/Indiana/Indianapolis") {}
            else if (value == "America/Indiana/Knox") {}
            else if (value == "America/Indiana/Marengo") {}
            else if (value == "America/Indiana/Petersburg") {}
            else if (value == "America/Indiana/Tell_City") {}
            else if (value == "America/Indiana/Vevay") {}
            else if (value == "America/Indiana/Vincennes") {}
            else if (value == "America/Indiana/Winamac") {}
            else if (value == "America/Inuvik") {}
            else if (value == "America/Iqaluit") {}
            else if (value == "America/Jamaica") {}
            else if (value == "America/Juneau") {}
            else if (value == "America/Kentucky/Louisville") {}
            else if (value == "America/Kentucky/Monticello") {}
            else if (value == "America/Kralendijk") {}
            else if (value == "America/L_aPaz") {}
            else if (value == "America/Lima") {}
            else if (value == "America/Los_Angeles") {}
            else if (value == "America/Lower_Princes") {}
            else if (value == "America/Maceio") {}
            else if (value == "America/Managua") {}
            else if (value == "America/Manaus") {}
            else if (value == "America/Marigot") {}
            else if (value == "America/Martinique") {}
            else if (value == "America/Matamoros") {}
            else if (value == "America/Mazatlan") {}
            else if (value == "America/Menominee") {}
            else if (value == "America/Merida") {}
            else if (value == "America/Metlakatla") {}
            else if (value == "America/Mexico_City") {}
            else if (value == "America/Miquelon") {}
            else if (value == "America/Moncton") {}
            else if (value == "America/Monterrey") {}
            else if (value == "America/Montevideo") {}
            else if (value == "America/Montserrat") {}
            else if (value == "America/Nassau") {}
            else if (value == "America/New_York") {}
            else if (value == "America/Nipigon") {}
            else if (value == "America/Nome") {}
            else if (value == "America/Noronha") {}
            else if (value == "America/North_Dakota/Beulah") {}
            else if (value == "America/North_Dakota/Center") {}
            else if (value == "America/North_Dakota/New_Salem") {}
            else if (value == "America/Ojinaga") {}
            else if (value == "America/Panama") {}
            else if (value == "America/Pangnirtung") {}
            else if (value == "America/Paramaribo") {}
            else if (value == "America/Phoenix") {}
            else if (value == "America/Port-au-Prince") {}
            else if (value == "America/Port_of_Spain") {}
            else if (value == "America/Porto_Velho") {}
            else if (value == "America/Puerto_Rico") {}
            else if (value == "America/Rainy_River") {}
            else if (value == "America/Rankin_Inlet") {}
            else if (value == "America/Recife") {}
            else if (value == "America/Regina") {}
            else if (value == "America/Resolute") {}
            else if (value == "America/Rio_Branco") {}
            else if (value == "America/Sant_aIsabel") {}
            else if (value == "America/Santarem") {}
            else if (value == "America/Santiago") {}
            else if (value == "America/Santo_Domingo") {}
            else if (value == "America/Sao_Paulo") {}
            else if (value == "America/Scoresbysund") {}
            else if (value == "America/Sitka") {}
            else if (value == "America/St_Barthelemy") {}
            else if (value == "America/St_Johns") {}
            else if (value == "America/St_Kitts") {}
            else if (value == "America/St_Lucia") {}
            else if (value == "America/St_Thomas") {}
            else if (value == "America/St_Vincent") {}
            else if (value == "America/Swift_Current") {}
            else if (value == "America/Tegucigalpa") {}
            else if (value == "America/Thule") {}
            else if (value == "America/Thunder_Bay") {}
            else if (value == "America/Tijuana") {}
            else if (value == "America/Toronto") {}
            else if (value == "America/Tortola") {}
            else if (value == "America/Vancouver") {}
            else if (value == "America/Whitehorse") {}
            else if (value == "America/Winnipeg") {}
            else if (value == "America/Yakutat") {}
            else if (value == "America/Yellowknife") {}
            else if (value == "Antarctica/Casey") {}
            else if (value == "Antarctica/Davis") {}
            else if (value == "Antarctica/DumontDUrville") {}
            else if (value == "Antarctica/Macquarie") {}
            else if (value == "Antarctica/Mawson") {}
            else if (value == "Antarctica/McMurdo") {}
            else if (value == "Antarctica/Palmer") {}
            else if (value == "Antarctica/Rothera") {}
            else if (value == "Antarctica/Syowa") {}
            else if (value == "Antarctica/Troll") {}
            else if (value == "Antarctica/Vostok") {}
            else if (value == "Arctic/Longyearbyen") {}
            else if (value == "Asia/Aden") {}
            else if (value == "Asia/Almaty") {}
            else if (value == "Asia/Amman") {}
            else if (value == "Asia/Anadyr") {}
            else if (value == "Asia/Aqtau") {}
            else if (value == "Asia/Aqtobe") {}
            else if (value == "Asia/Ashgabat") {}
            else if (value == "Asia/Baghdad") {}
            else if (value == "Asia/Bahrain") {}
            else if (value == "Asia/Baku") {}
            else if (value == "Asia/Bangkok") {}
            else if (value == "Asia/Beirut") {}
            else if (value == "Asia/Bishkek") {}
            else if (value == "Asia/Brunei") {}
            else if (value == "Asia/Choibalsan") {}
            else if (value == "Asia/Chongqing") {}
            else if (value == "Asia/Colombo") {}
            else if (value == "Asia/Damascus") {}
            else if (value == "Asia/Dhaka") {}
            else if (value == "Asia/Dili") {}
            else if (value == "Asia/Dubai") {}
            else if (value == "Asia/Dushanbe") {}
            else if (value == "Asia/Gaza") {}
            else if (value == "Asia/Harbin") {}
            else if (value == "Asia/Hebron") {}
            else if (value == "Asia/Ho_Chi_Minh") {}
            else if (value == "Asia/Hong_Kong") {}
            else if (value == "Asia/Hovd") {}
            else if (value == "Asia/Irkutsk") {}
            else if (value == "Asia/Jakarta") {}
            else if (value == "Asia/Jayapura") {}
            else if (value == "Asia/Jerusalem") {}
            else if (value == "Asia/Kabul") {}
            else if (value == "Asia/Kamchatka") {}
            else if (value == "Asia/Karachi") {}
            else if (value == "Asia/Kashgar") {}
            else if (value == "Asia/Kathmandu") {}
            else if (value == "Asia/Khandyga") {}
            else if (value == "Asia/Kolkata") {}
            else if (value == "Asia/Krasnoyarsk") {}
            else if (value == "Asia/Kual_aLumpur") {}
            else if (value == "Asia/Kuching") {}
            else if (value == "Asia/Kuwait") {}
            else if (value == "Asia/Macau") {}
            else if (value == "Asia/Magadan") {}
            else if (value == "Asia/Makassar") {}
            else if (value == "Asia/Manila") {}
            else if (value == "Asia/Muscat") {}
            else if (value == "Asia/Nicosia") {}
            else if (value == "Asia/Novokuznetsk") {}
            else if (value == "Asia/Novosibirsk") {}
            else if (value == "Asia/Omsk") {}
            else if (value == "Asia/Oral") {}
            else if (value == "Asia/Phnom_Penh") {}
            else if (value == "Asia/Pontianak") {}
            else if (value == "Asia/Pyongyang") {}
            else if (value == "Asia/Qatar") {}
            else if (value == "Asia/Qyzylorda") {}
            else if (value == "Asia/Rangoon") {}
            else if (value == "Asia/Riyadh") {}
            else if (value == "Asia/Sakhalin") {}
            else if (value == "Asia/Samarkand") {}
            else if (value == "Asia/Seoul") {}
            else if (value == "Asia/Shanghai") {}
            else if (value == "Asia/Singapore") {}
            else if (value == "Asia/Taipei") {}
            else if (value == "Asia/Tashkent") {}
            else if (value == "Asia/Tbilisi") {}
            else if (value == "Asia/Tehran") {}
            else if (value == "Asia/Thimphu") {}
            else if (value == "Asia/Tokyo") {}
            else if (value == "Asia/Ulaanbaatar") {}
            else if (value == "Asia/Urumqi") {}
            else if (value == "Asia/Ust-Nera") {}
            else if (value == "Asia/Vientiane") {}
            else if (value == "Asia/Vladivostok") {}
            else if (value == "Asia/Yakutsk") {}
            else if (value == "Asia/Yekaterinburg") {}
            else if (value == "Asia/Yerevan") {}
            else if (value == "Atlantic/Azores") {}
            else if (value == "Atlantic/Bermuda") {}
            else if (value == "Atlantic/Canary") {}
            else if (value == "Atlantic/Cape_Verde") {}
            else if (value == "Atlantic/Faroe") {}
            else if (value == "Atlantic/Madeira") {}
            else if (value == "Atlantic/Reykjavik") {}
            else if (value == "Atlantic/South_Georgia") {}
            else if (value == "Atlantic/St_Helena") {}
            else if (value == "Atlantic/Stanley") {}
            else if (value == "Australia/Adelaide") {}
            else if (value == "Australia/Brisbane") {}
            else if (value == "Australia/Broken_Hill") {}
            else if (value == "Australia/Currie") {}
            else if (value == "Australia/Darwin") {}
            else if (value == "Australia/Eucla") {}
            else if (value == "Australia/Hobart") {}
            else if (value == "Australia/Lindeman") {}
            else if (value == "Australia/Lord_Howe") {}
            else if (value == "Australia/Melbourne") {}
            else if (value == "Australia/Perth") {}
            else if (value == "Australia/Sydney") {}
            else if (value == "Europe/Amsterdam") {}
            else if (value == "Europe/Andorra") {}
            else if (value == "Europe/Athens") {}
            else if (value == "Europe/Belgrade") {}
            else if (value == "Europe/Berlin") {}
            else if (value == "Europe/Bratislava") {}
            else if (value == "Europe/Brussels") {}
            else if (value == "Europe/Bucharest") {}
            else if (value == "Europe/Budapest") {}
            else if (value == "Europe/Busingen") {}
            else if (value == "Europe/Chisinau") {}
            else if (value == "Europe/Copenhagen") {}
            else if (value == "Europe/Dublin") {}
            else if (value == "Europe/Gibraltar") {}
            else if (value == "Europe/Guernsey") {}
            else if (value == "Europe/Helsinki") {}
            else if (value == "Europe/Isle_of_Man") {}
            else if (value == "Europe/Istanbul") {}
            else if (value == "Europe/Jersey") {}
            else if (value == "Europe/Kaliningrad") {}
            else if (value == "Europe/Kiev") {}
            else if (value == "Europe/Lisbon") {}
            else if (value == "Europe/Ljubljana") {}
            else if (value == "Europe/London") {}
            else if (value == "Europe/Luxembourg") {}
            else if (value == "Europe/Madrid") {}
            else if (value == "Europe/Malta") {}
            else if (value == "Europe/Mariehamn") {}
            else if (value == "Europe/Minsk") {}
            else if (value == "Europe/Monaco") {}
            else if (value == "Europe/Moscow") {}
            else if (value == "Europe/Oslo") {}
            else if (value == "Europe/Paris") {}
            else if (value == "Europe/Podgorica") {}
            else if (value == "Europe/Prague") {}
            else if (value == "Europe/Riga") {}
            else if (value == "Europe/Rome") {}
            else if (value == "Europe/Samara") {}
            else if (value == "Europe/San_Marino") {}
            else if (value == "Europe/Sarajevo") {}
            else if (value == "Europe/Simferopol") {}
            else if (value == "Europe/Skopje") {}
            else if (value == "Europe/Sofia") {}
            else if (value == "Europe/Stockholm") {}
            else if (value == "Europe/Tallinn") {}
            else if (value == "Europe/Tirane") {}
            else if (value == "Europe/Uzhgorod") {}
            else if (value == "Europe/Vaduz") {}
            else if (value == "Europe/Vatican") {}
            else if (value == "Europe/Vienna") {}
            else if (value == "Europe/Vilnius") {}
            else if (value == "Europe/Volgograd") {}
            else if (value == "Europe/Warsaw") {}
            else if (value == "Europe/Zagreb") {}
            else if (value == "Europe/Zaporozhye") {}
            else if (value == "Europe/Zurich") {}
            else if (value == "Indian/Antananarivo") {}
            else if (value == "Indian/Chagos") {}
            else if (value == "Indian/Christmas") {}
            else if (value == "Indian/Cocos") {}
            else if (value == "Indian/Comoro") {}
            else if (value == "Indian/Kerguelen") {}
            else if (value == "Indian/Mahe") {}
            else if (value == "Indian/Maldives") {}
            else if (value == "Indian/Mauritius") {}
            else if (value == "Indian/Mayotte") {}
            else if (value == "Indian/Reunion") {}
            else if (value == "Pacific/Apia") {}
            else if (value == "Pacific/Auckland") {}
            else if (value == "Pacific/Chatham") {}
            else if (value == "Pacific/Chuuk") {}
            else if (value == "Pacific/Easter") {}
            else if (value == "Pacific/Efate") {}
            else if (value == "Pacific/Enderbury") {}
            else if (value == "Pacific/Fakaofo") {}
            else if (value == "Pacific/Fiji") {}
            else if (value == "Pacific/Funafuti") {}
            else if (value == "Pacific/Galapagos") {}
            else if (value == "Pacific/Gambier") {}
            else if (value == "Pacific/Guadalcanal") {}
            else if (value == "Pacific/Guam") {}
            else if (value == "Pacific/Honolulu") {}
            else if (value == "Pacific/Johnston") {}
            else if (value == "Pacific/Kiritimati") {}
            else if (value == "Pacific/Kosrae") {}
            else if (value == "Pacific/Kwajalein") {}
            else if (value == "Pacific/Majuro") {}
            else if (value == "Pacific/Marquesas") {}
            else if (value == "Pacific/Midway") {}
            else if (value == "Pacific/Nauru") {}
            else if (value == "Pacific/Niue") {}
            else if (value == "Pacific/Norfolk") {}
            else if (value == "Pacific/Noumea") {}
            else if (value == "Pacific/Pago_Pago") {}
            else if (value == "Pacific/Palau") {}
            else if (value == "Pacific/Pitcairn") {}
            else if (value == "Pacific/Pohnpei") {}
            else if (value == "Pacific/Port_Moresby") {}
            else if (value == "Pacific/Rarotonga") {}
            else if (value == "Pacific/Saipan") {}
            else if (value == "Pacific/Tahiti") {}
            else if (value == "Pacific/Tarawa") {}
            else if (value == "Pacific/Tongatapu") {}
            else if (value == "Pacific/Wake") {}
            else if (value == "Pacific/Wallis") {}
            else if (value == "UTC") {}
            else
                return false;
            return true;
        }
};
/** @} */
#endif
