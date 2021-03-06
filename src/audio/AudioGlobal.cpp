/*
 * Copyright 2011-2012 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Arx Libertatis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arx Libertatis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Arx Libertatis.  If not, see <http://www.gnu.org/licenses/>.
 */
/* Based on:
===========================================================================
ARX FATALIS GPL Source Code
Copyright (C) 1999-2010 Arkane Studios SA, a ZeniMax Media company.

This file is part of the Arx Fatalis GPL Source Code ('Arx Fatalis Source Code'). 

Arx Fatalis Source Code is free software: you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Arx Fatalis Source Code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Arx Fatalis Source Code.  If not, see 
<http://www.gnu.org/licenses/>.

In addition, the Arx Fatalis Source Code is also subject to certain additional terms. You should have received a copy of these 
additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Arx 
Fatalis Source Code. If not, please request a copy in writing from Arkane Studios at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing Arkane Studios, c/o 
ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.
===========================================================================
*/

#include "audio/AudioGlobal.h"

#include "audio/Mixer.h"
#include "audio/Sample.h"
#include "audio/Ambiance.h"
#include "audio/AudioEnvironment.h"

#include "io/resource/ResourcePath.h"

namespace audio {

// Audio device interface
Backend * backend = NULL;

// Global settings
res::path sample_path;
res::path ambiance_path;
res::path environment_path;
size_t stream_limit_bytes = DEFAULT_STREAMLIMIT;
size_t session_time = 0;

// Resources
ResourceList<Mixer> _mixer;
ResourceList<Sample> _sample;
ResourceList<Ambiance> _amb;
ResourceList<Environment> _env;

size_t unitsToBytes(size_t v, const PCMFormat & _format, TimeUnit unit) {
	switch(unit) {
		case UNIT_MS:
			return (size_t)(float(v) * 0.001f * _format.frequency * _format.channels * (_format.quality >> 3)) / 1000;
		case UNIT_SAMPLES:
			return v * _format.channels * (_format.quality >> 3);
		default:
			return v;
	}
}

size_t bytesToUnits(size_t v, const PCMFormat & _format, TimeUnit unit) {
	switch(unit) {
		case UNIT_MS      :
			return (size_t)(float(v) * 1000.f / (_format.frequency * _format.channels * (_format.quality >> 3)));
		case UNIT_SAMPLES :
			return v / (_format.frequency * _format.channels * (_format.quality >> 3));
		
		default:
			return v;
	}
}

} // namespace audio
