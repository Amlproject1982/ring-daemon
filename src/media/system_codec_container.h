/*
 *  Copyright (C) 2015 Savoir-Faire Linux Inc.
 *  Author: Eloi BAIL <eloi.bail@savoirfairelinux.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA  02110-1301 USA.
 *
 *  Additional permission under GNU GPL version 3 section 7:
 *
 *  If you modify this program, or any covered work, by linking or
 *  combining it with the OpenSSL project's OpenSSL library (or a
 *  modified version of that library), containing parts covered by the
 *  terms of the OpenSSL or SSLeay licenses, Savoir-Faire Linux Inc.
 *  grants you additional permission to convey the resulting work.
 *  Corresponding Source for a non-source form of such a combination
 *  shall include the source code for the parts of OpenSSL used as well
 *  as that of the covered work.
 */

#ifndef __SYSTEM_CODEC_CONTAINER_H__
#define __SYSTEM_CODEC_CONTAINER_H__

#include "media_codec.h"
#include "ring_types.h"

#include <string>
#include <vector>
#include <memory>

namespace ring {

class SystemCodecContainer;

extern decltype(getGlobalInstance<SystemCodecContainer>)& getSystemCodecContainer;

class SystemCodecContainer
{
    public:
        SystemCodecContainer();
        ~SystemCodecContainer();

        std::vector<std::shared_ptr<SystemCodecInfo>>
        getSystemCodecInfoList(MediaType mediaType = MEDIA_ALL);

        std::vector<unsigned>
        getSystemCodecInfoIdList(MediaType type = MEDIA_ALL);

        std::shared_ptr<SystemCodecInfo>
        searchCodecById(unsigned codecId, MediaType type = MEDIA_ALL);

        std::shared_ptr<SystemCodecInfo>
        searchCodecByName(std::string name, MediaType type = MEDIA_ALL);

        std::shared_ptr<SystemCodecInfo>
        searchCodecByPayload(unsigned payload, MediaType type = MEDIA_ALL);

    private:
        /* available audio & video codec  */
        std::vector<std::shared_ptr<SystemCodecInfo>> availableCodecList_;

        void initCodecConfig();
        void checkInstalledCodecs();
};

} // namespace ring

#endif //SYSTEM_CODEC_CONTAINER