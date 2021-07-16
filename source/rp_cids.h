//------------------------------------------------------------------------
// Copyright(c) 2021 rpuhalovich.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace rpuhalovich {
//------------------------------------------------------------------------
static const Steinberg::FUID kVReverbProcessorUID (0x1CD644A9, 0x040D5A02, 0xB8A0E6B3, 0x25ADAC73);
static const Steinberg::FUID kVReverbControllerUID (0xC721273F, 0xEC3A579B, 0x8A673D14, 0xAA5F7324);

#define VReverbVST3Category "Fx"

//------------------------------------------------------------------------
} // namespace rpuhalovich
