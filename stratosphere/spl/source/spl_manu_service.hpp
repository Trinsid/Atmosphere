/*
 * Copyright (c) Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <stratosphere.hpp>
#include "spl_device_unique_data_service.hpp"

namespace ams::spl {

    class ManuService : public DeviceUniqueDataService {
        public:
            explicit ManuService(SecureMonitorManager *manager) : DeviceUniqueDataService(manager) { /* ... */ }
        public:
            /* Actual commands. */
            Result ReencryptDeviceUniqueData(const sf::OutPointerBuffer &out, const sf::InPointerBuffer &src, AccessKey access_key_dec, KeySource source_dec, AccessKey access_key_enc, KeySource source_enc, u32 option) {
                return m_manager.ReencryptDeviceUniqueData(out.GetPointer(), out.GetSize(), src.GetPointer(), src.GetSize(), access_key_dec, source_dec, access_key_enc, source_enc, option);
            }
    };
    static_assert(spl::impl::IsIManuInterface<ManuService>);

}
