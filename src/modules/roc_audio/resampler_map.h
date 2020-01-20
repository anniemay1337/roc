/*
 * Copyright (c) 2019 Roc authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

//! @file roc_audio/resampler_map.h
//! @brief Resampler Map.

#ifndef ROC_AUDIO_RESAMPLER_MAP_H_
#define ROC_AUDIO_RESAMPLER_MAP_H_

#include "roc_core/stddefs.h"

#include "roc_audio/iresampler.h"
#include "roc_audio/resampler_config.h"
#include "roc_core/iallocator.h"
#include "roc_core/scoped_ptr.h"
#include "roc_packet/units.h"

namespace roc {
namespace audio {
//! Factory class for IResampler objects, according to the ResamplerBackend input
class ResamplerMap {
public:
    //! Method to instantiate and return a pointer to a IResampler object
    IResampler* new_resampler(ResamplerBackend resampler_backend,
                              core::IAllocator& allocator,
                              const ResamplerConfig& config,
                              packet::channel_mask_t channels,
                              size_t frame_size);
};

} // namespace audio
} // namespace roc

#endif // ROC_AUDIO_RESAMPLER_MAP_H_