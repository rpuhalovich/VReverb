// Copyright(c) 2021 rpuhalovich.

#pragma once

#include "vstgui/plugin-bindings/vst3editor.h"
#include "public.sdk/source/vst/vsteditcontroller.h"

namespace rpuhalovich {

enum class ParamIDs { reverbParam };

class ReverbParameter : public Steinberg::Vst::Parameter {
public:
    ReverbParameter(Steinberg::int32 flags, Steinberg::int32 id);
};

//  VReverbController
class VReverbController : public Steinberg::Vst::EditControllerEx1 {
public:
    VReverbController () = default;
    ~VReverbController () SMTG_OVERRIDE = default;

    // Create function
    static Steinberg::FUnknown* createInstance (void* /*context*/) {
        return (Steinberg::Vst::IEditController*)new VReverbController;
    }

    // IPluginBase
    Steinberg::tresult PLUGIN_API initialize (Steinberg::FUnknown* context) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API terminate () SMTG_OVERRIDE;

    // EditController
    Steinberg::tresult PLUGIN_API setComponentState (Steinberg::IBStream* state) SMTG_OVERRIDE;
    Steinberg::IPlugView* PLUGIN_API createView (Steinberg::FIDString name) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API setState (Steinberg::IBStream* state) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API getState (Steinberg::IBStream* state) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API setParamNormalized (Steinberg::Vst::ParamID tag,
            Steinberg::Vst::ParamValue value) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API getParamStringByValue (Steinberg::Vst::ParamID tag,
            Steinberg::Vst::ParamValue valueNormalized,
            Steinberg::Vst::String128 string) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API getParamValueByString (Steinberg::Vst::ParamID tag,
            Steinberg::Vst::TChar* string,
            Steinberg::Vst::ParamValue& valueNormalized) SMTG_OVERRIDE;

    //---Interface---------
    DEFINE_INTERFACES
    // Here you can add more supported VST3 interfaces
    // DEF_INTERFACE (Vst::IXXX)
    END_DEFINE_INTERFACES (EditController)
    DELEGATE_REFCOUNT (EditController)

protected:
};

} // namespace rpuhalovich
