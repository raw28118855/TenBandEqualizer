// -----------------------------------------------------------------------------
//    ASPiK Plugin Kernel File:  plugincore.cpp
//
/**
    \file   plugincore.cpp
    \author Will Pirkle
    \date   17-September-2018
    \brief  Implementation file for PluginCore object
    		- http://www.aspikplugins.com
    		- http://www.willpirkle.com
*/
// -----------------------------------------------------------------------------
#include "plugincore.h"
#include "plugindescription.h"

/**
\brief PluginCore constructor is launching pad for object initialization

Operations:
- initialize the plugin description (strings, codes, numbers, see initPluginDescriptors())
- setup the plugin's audio I/O channel support
- create the PluginParameter objects that represent the plugin parameters (see FX book if needed)
- create the presets
*/
PluginCore::PluginCore()
{
    // --- describe the plugin; call the helper to init the static parts you setup in plugindescription.h
    initPluginDescriptors();

    // --- default I/O combinations
	// --- for FX plugins
	if (getPluginType() == kFXPlugin)
	{
		addSupportedIOCombination({ kCFMono, kCFMono });
		addSupportedIOCombination({ kCFMono, kCFStereo });
		addSupportedIOCombination({ kCFStereo, kCFStereo });
	}
	else // --- synth plugins have no input, only output
	{
		addSupportedIOCombination({ kCFNone, kCFMono });
		addSupportedIOCombination({ kCFNone, kCFStereo });
	}

	// --- for sidechaining, we support mono and stereo inputs; auxOutputs reserved for future use
	addSupportedAuxIOCombination({ kCFMono, kCFNone });
	addSupportedAuxIOCombination({ kCFStereo, kCFNone });

	// --- create the parameters
    initPluginParameters();

    // --- create the presets
    initPluginPresets();
}

/**
\brief create all of your plugin parameters here

\return true if parameters were created, false if they already existed
*/
bool PluginCore::initPluginParameters()
{
	if (pluginParameterMap.size() > 0)
		return false;

    // --- Add your plugin parameter instantiation code bewtween these hex codes
	// **--0xDEA7--**


	// --- Declaration of Plugin Parameter Objects 
	PluginParameter* piParam = nullptr;

	// --- continuous control: Q
	piParam = new PluginParameter(controlID::filterQ, "Q", "Units", controlVariableType::kDouble, 0.707000, 20.000000, 0.707000, taper::kLinearTaper);
	piParam->setParameterSmoothing(true);
	piParam->setSmoothingTimeMsec(10.00);
	piParam->setBoundVariable(&filterQ, boundVariableType::kDouble);
	addPluginParameter(piParam);

	// --- continuous control: 32Hz
	piParam = new PluginParameter(controlID::boostCut32Hz_dB, "32Hz", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
	piParam->setParameterSmoothing(true);
	piParam->setSmoothingTimeMsec(10.00);
	piParam->setBoundVariable(&boostCut32Hz_dB, boundVariableType::kDouble);
	addPluginParameter(piParam);

	// --- continuous control: 64Hz
	piParam = new PluginParameter(controlID::boostCut64Hz_dB, "64Hz", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
	piParam->setParameterSmoothing(true);
	piParam->setSmoothingTimeMsec(10.00);
	piParam->setBoundVariable(&boostCut64Hz_dB, boundVariableType::kDouble);
	addPluginParameter(piParam);

	// --- continuous control: 125Hz
	piParam = new PluginParameter(controlID::boostCut125Hz_dB, "125Hz", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
	piParam->setParameterSmoothing(true);
	piParam->setSmoothingTimeMsec(10.00);
	piParam->setBoundVariable(&boostCut125Hz_dB, boundVariableType::kDouble);
	addPluginParameter(piParam);

	// --- continuous control: 250Hz
	piParam = new PluginParameter(controlID::boostCut250Hz_dB, "250Hz", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
	piParam->setParameterSmoothing(true);
	piParam->setSmoothingTimeMsec(10.00);
	piParam->setBoundVariable(&boostCut250Hz_dB, boundVariableType::kDouble);
	addPluginParameter(piParam);

	// --- continuous control: 500Hz
	piParam = new PluginParameter(controlID::boostCut500Hz_dB, "500Hz", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
	piParam->setParameterSmoothing(true);
	piParam->setSmoothingTimeMsec(10.00);
	piParam->setBoundVariable(&boostCut500Hz_dB, boundVariableType::kDouble);
	addPluginParameter(piParam);

	// --- continuous control: 1kHz
	piParam = new PluginParameter(controlID::boostCut1kHz_dB, "1kHz", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
	piParam->setParameterSmoothing(true);
	piParam->setSmoothingTimeMsec(10.00);
	piParam->setBoundVariable(&boostCut1kHz_dB, boundVariableType::kDouble);
	addPluginParameter(piParam);

	// --- continuous control: 2kHz
	piParam = new PluginParameter(controlID::boostCut2kHz_dB, "2kHz", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
	piParam->setParameterSmoothing(true);
	piParam->setSmoothingTimeMsec(10.00);
	piParam->setBoundVariable(&boostCut2kHz_dB, boundVariableType::kDouble);
	addPluginParameter(piParam);

	// --- continuous control: 4k
	piParam = new PluginParameter(controlID::boostCut4kHz_dB, "4k", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
	piParam->setParameterSmoothing(true);
	piParam->setSmoothingTimeMsec(10.00);
	piParam->setBoundVariable(&boostCut4kHz_dB, boundVariableType::kDouble);
	addPluginParameter(piParam);

	// --- continuous control: 8kHz
	piParam = new PluginParameter(controlID::boostCut8kHz_dB, "8kHz", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
	piParam->setParameterSmoothing(true);
	piParam->setSmoothingTimeMsec(10.00);
	piParam->setBoundVariable(&boostCut8kHz_dB, boundVariableType::kDouble);
	addPluginParameter(piParam);

	// --- continuous control: 16k
	piParam = new PluginParameter(controlID::boostCut16kHz_dB, "16k", "dB", controlVariableType::kDouble, -20.000000, 20.000000, 0.000000, taper::kLinearTaper);
	piParam->setParameterSmoothing(true);
	piParam->setSmoothingTimeMsec(10.00);
	piParam->setBoundVariable(&boostCut16kHz_dB, boundVariableType::kDouble);
	addPluginParameter(piParam);

	// --- Aux Attributes
	AuxParameterAttribute auxAttribute;

	// --- RAFX GUI attributes
	// --- controlID::filterQ
	auxAttribute.reset(auxGUIIdentifier::guiControlData);
	auxAttribute.setUintAttribute(2147483648);
	setParamAuxAttribute(controlID::filterQ, auxAttribute);

	// --- controlID::boostCut32Hz_dB
	auxAttribute.reset(auxGUIIdentifier::guiControlData);
	auxAttribute.setUintAttribute(2147483648);
	setParamAuxAttribute(controlID::boostCut32Hz_dB, auxAttribute);

	// --- controlID::boostCut64Hz_dB
	auxAttribute.reset(auxGUIIdentifier::guiControlData);
	auxAttribute.setUintAttribute(2147483648);
	setParamAuxAttribute(controlID::boostCut64Hz_dB, auxAttribute);

	// --- controlID::boostCut125Hz_dB
	auxAttribute.reset(auxGUIIdentifier::guiControlData);
	auxAttribute.setUintAttribute(2147483648);
	setParamAuxAttribute(controlID::boostCut125Hz_dB, auxAttribute);

	// --- controlID::boostCut250Hz_dB
	auxAttribute.reset(auxGUIIdentifier::guiControlData);
	auxAttribute.setUintAttribute(2147483648);
	setParamAuxAttribute(controlID::boostCut250Hz_dB, auxAttribute);

	// --- controlID::boostCut500Hz_dB
	auxAttribute.reset(auxGUIIdentifier::guiControlData);
	auxAttribute.setUintAttribute(2147483648);
	setParamAuxAttribute(controlID::boostCut500Hz_dB, auxAttribute);

	// --- controlID::boostCut1kHz_dB
	auxAttribute.reset(auxGUIIdentifier::guiControlData);
	auxAttribute.setUintAttribute(2147483648);
	setParamAuxAttribute(controlID::boostCut1kHz_dB, auxAttribute);

	// --- controlID::boostCut2kHz_dB
	auxAttribute.reset(auxGUIIdentifier::guiControlData);
	auxAttribute.setUintAttribute(2147483648);
	setParamAuxAttribute(controlID::boostCut2kHz_dB, auxAttribute);

	// --- controlID::boostCut4kHz_dB
	auxAttribute.reset(auxGUIIdentifier::guiControlData);
	auxAttribute.setUintAttribute(2147483648);
	setParamAuxAttribute(controlID::boostCut4kHz_dB, auxAttribute);

	// --- controlID::boostCut8kHz_dB
	auxAttribute.reset(auxGUIIdentifier::guiControlData);
	auxAttribute.setUintAttribute(2147483648);
	setParamAuxAttribute(controlID::boostCut8kHz_dB, auxAttribute);

	// --- controlID::boostCut16kHz_dB
	auxAttribute.reset(auxGUIIdentifier::guiControlData);
	auxAttribute.setUintAttribute(2147483648);
	setParamAuxAttribute(controlID::boostCut16kHz_dB, auxAttribute);


	// **--0xEDA5--**
   
    // --- BONUS Parameter
    // --- SCALE_GUI_SIZE
    PluginParameter* piParamBonus = new PluginParameter(SCALE_GUI_SIZE, "Scale GUI", "tiny,small,medium,normal,large,giant", "normal");
    addPluginParameter(piParamBonus);

	// --- create the super fast access array
	initPluginParameterArray();

    return true;
}

/**
\brief initialize object for a new run of audio; called just before audio streams

Operation:
- store sample rate and bit depth on audioProcDescriptor - this information is globally available to all core functions
- reset your member objects here

\param resetInfo structure of information about current audio format

\return true if operation succeeds, false otherwise
*/
bool PluginCore::reset(ResetInfo& resetInfo)
{
    // --- save for audio processing
    audioProcDescriptor.sampleRate = resetInfo.sampleRate;
    audioProcDescriptor.bitDepth = resetInfo.bitDepth;
	filterBand32.reset(resetInfo.sampleRate);
	filterBand64.reset(resetInfo.sampleRate);
	filterBand125.reset(resetInfo.sampleRate);
	filterBand250.reset(resetInfo.sampleRate);
	filterBand500.reset(resetInfo.sampleRate);
	filterBand1k.reset(resetInfo.sampleRate);
	filterBand2k.reset(resetInfo.sampleRate);
	filterBand4k.reset(resetInfo.sampleRate);
	filterBand8k.reset(resetInfo.sampleRate);
	filterBand16k.reset(resetInfo.sampleRate);
    // --- other reset inits
    return PluginBase::reset(resetInfo);
}

/**
\brief one-time initialize function called after object creation and before the first reset( ) call

Operation:
- saves structure for the plugin to use; you can also load WAV files or state information here
*/
bool PluginCore::initialize(PluginInfo& pluginInfo)
{
	// --- add one-time init stuff here

	return true;
}

/**
\brief do anything needed prior to arrival of audio buffers

Operation:
- syncInBoundVariables when preProcessAudioBuffers is called, it is *guaranteed* that all GUI control change information
  has been applied to plugin parameters; this binds parameter changes to your underlying variables
- NOTE: postUpdatePluginParameter( ) will be called for all bound variables that are acutally updated; if you need to process
  them individually, do so in that function
- use this function to bulk-transfer the bound variable data into your plugin's member object variables

\param processInfo structure of information about *buffer* processing

\return true if operation succeeds, false otherwise
*/
bool PluginCore::preProcessAudioBuffers(ProcessBufferInfo& processInfo)
{
    // --- sync internal variables to GUI parameters; you can also do this manually if you don't
    //     want to use the auto-variable-binding
    syncInBoundVariables();

    return true;
}

/**
\brief frame-processing method

Operation:
- decode the plugin type - for synth plugins, fill in the rendering code; for FX plugins, delete the if(synth) portion and add your processing code
- note that MIDI events are fired for each sample interval so that MIDI is tightly sunk with audio
- doSampleAccurateParameterUpdates will perform per-sample interval smoothing

\param processFrameInfo structure of information about *frame* processing

\return true if operation succeeds, false otherwise
*/
double PluginCore::updateParameters(double in) {

	//update GUI parameter
	AudioFilterParameters filterParams = filterBand32.getParameters();
	//--alter param values
	filterParams.Q = filterQ;
	filterParams.algorithm = filterAlgorithm::kCQParaEQ;

	//cascade 32 EQ
	filterParams.fc = 32;    //32Hz filter
	filterParams.boostCut_dB = boostCut32Hz_dB;
	filterBand32.setParameters(filterParams);
	cascad32Hz= filterBand32.processAudioSample(in);
	//cascade 64 EQ
	filterParams.fc = 64;    //64Hz filter
	filterParams.boostCut_dB = boostCut64Hz_dB;
	filterBand64.setParameters(filterParams);
	cascad64Hz = filterBand64.processAudioSample(cascad32Hz);
	//cascade 125 EQ
	filterParams.fc = 125;  
	filterParams.boostCut_dB = boostCut125Hz_dB;
	filterBand125.setParameters(filterParams);
	cascad125Hz = filterBand125.processAudioSample(cascad64Hz);
	//cascade 250 EQ
	filterParams.fc = 250;
	filterParams.boostCut_dB = boostCut250Hz_dB;
	filterBand250.setParameters(filterParams);
	cascad250Hz = filterBand250.processAudioSample(cascad125Hz);
	//cascade 500 EQ
	filterParams.fc = 500;
	filterParams.boostCut_dB = boostCut500Hz_dB;
	filterBand500.setParameters(filterParams);
	cascad500Hz = filterBand500.processAudioSample(cascad250Hz);
	//cascade 1k EQ
	filterParams.fc = 1000;
	filterParams.boostCut_dB = boostCut1kHz_dB;
	filterBand1k.setParameters(filterParams);
	cascad1kHz = filterBand1k.processAudioSample(cascad500Hz);
	//cascade 2k EQ
	filterParams.fc = 2000;
	filterParams.boostCut_dB = boostCut2kHz_dB;
	filterBand2k.setParameters(filterParams);
	cascad2kHz = filterBand2k.processAudioSample(cascad1kHz);
	//cascade 4k EQ
	filterParams.fc = 4000;
	filterParams.boostCut_dB = boostCut4kHz_dB;
	filterBand4k.setParameters(filterParams);
	cascad4kHz = filterBand4k.processAudioSample(cascad2kHz);
	//cascade 8k EQ
	filterParams.fc = 8000;
	filterParams.boostCut_dB = boostCut8kHz_dB;
	filterBand8k.setParameters(filterParams);
	cascad8kHz = filterBand8k.processAudioSample(cascad4kHz);
	//cascade 16k EQ
	filterParams.fc = 16000;
	filterParams.boostCut_dB = boostCut16kHz_dB;
	filterBand16k.setParameters(filterParams);
	cascad16kHz = filterBand16k.processAudioSample(cascad8kHz);
	return cascad16kHz;
}
bool PluginCore::processAudioFrame(ProcessFrameInfo& processFrameInfo)
{
    // --- fire any MIDI events for this sample interval
    processFrameInfo.midiEventQueue->fireMidiEvents(processFrameInfo.currentFrame);

	// --- do per-frame updates; VST automation and parameter smoothing
	doSampleAccurateParameterUpdates();
	double xn = processFrameInfo.audioInputFrame[0];

	double yn = updateParameters(xn);

    // --- FX Plugin:
    if(processFrameInfo.channelIOConfig.inputChannelFormat == kCFMono &&
       processFrameInfo.channelIOConfig.outputChannelFormat == kCFMono)
    {
		// --- pass through code: change this with your signal processing
        processFrameInfo.audioOutputFrame[0] = yn;

        return true; /// processed
    }

    // --- Mono-In/Stereo-Out
    else if(processFrameInfo.channelIOConfig.inputChannelFormat == kCFMono &&
       processFrameInfo.channelIOConfig.outputChannelFormat == kCFStereo)
    {
		// --- pass through code: change this with your signal processing
        processFrameInfo.audioOutputFrame[0] = yn;
        processFrameInfo.audioOutputFrame[1] = yn;

        return true; /// processed
    }

    // --- Stereo-In/Stereo-Out
    else if(processFrameInfo.channelIOConfig.inputChannelFormat == kCFStereo &&
       processFrameInfo.channelIOConfig.outputChannelFormat == kCFStereo)
    {
		// --- pass through code: change this with your signal processing
        processFrameInfo.audioOutputFrame[0] = yn;
        processFrameInfo.audioOutputFrame[1] = yn;

        return true; /// processed
    }

    return false; /// NOT processed
}


/**
\brief do anything needed prior to arrival of audio buffers

Operation:
- updateOutBoundVariables sends metering data to the GUI meters

\param processInfo structure of information about *buffer* processing

\return true if operation succeeds, false otherwise
*/
bool PluginCore::postProcessAudioBuffers(ProcessBufferInfo& processInfo)
{
	// --- update outbound variables; currently this is meter data only, but could be extended
	//     in the future
	updateOutBoundVariables();

    return true;
}

/**
\brief update the PluginParameter's value based on GUI control, preset, or data smoothing (thread-safe)

Operation:
- update the parameter's value (with smoothing this initiates another smoothing process)
- call postUpdatePluginParameter to do any further processing

\param controlID the control ID value of the parameter being updated
\param controlValue the new control value
\param paramInfo structure of information about why this value is being udpated (e.g as a result of a preset being loaded vs. the top of a buffer process cycle)

\return true if operation succeeds, false otherwise
*/
bool PluginCore::updatePluginParameter(int32_t controlID, double controlValue, ParameterUpdateInfo& paramInfo)
{
    // --- use base class helper
    setPIParamValue(controlID, controlValue);

    // --- do any post-processing
    postUpdatePluginParameter(controlID, controlValue, paramInfo);

    return true; /// handled
}

/**
\brief update the PluginParameter's value based on *normlaized* GUI control, preset, or data smoothing (thread-safe)

Operation:
- update the parameter's value (with smoothing this initiates another smoothing process)
- call postUpdatePluginParameter to do any further processing

\param controlID the control ID value of the parameter being updated
\param normalizedValue the new control value in normalized form
\param paramInfo structure of information about why this value is being udpated (e.g as a result of a preset being loaded vs. the top of a buffer process cycle)

\return true if operation succeeds, false otherwise
*/
bool PluginCore::updatePluginParameterNormalized(int32_t controlID, double normalizedValue, ParameterUpdateInfo& paramInfo)
{
	// --- use base class helper, returns actual value
	double controlValue = setPIParamValueNormalized(controlID, normalizedValue, paramInfo.applyTaper);

	// --- do any post-processing
	postUpdatePluginParameter(controlID, controlValue, paramInfo);

	return true; /// handled
}

/**
\brief perform any operations after the plugin parameter has been updated; this is one paradigm for
	   transferring control information into vital plugin variables or member objects. If you use this
	   method you can decode the control ID and then do any cooking that is needed. NOTE: do not
	   overwrite bound variables here - this is ONLY for any extra cooking that is required to convert
	   the GUI data to meaninful coefficients or other specific modifiers.

\param controlID the control ID value of the parameter being updated
\param controlValue the new control value
\param paramInfo structure of information about why this value is being udpated (e.g as a result of a preset being loaded vs. the top of a buffer process cycle)

\return true if operation succeeds, false otherwise
*/
bool PluginCore::postUpdatePluginParameter(int32_t controlID, double controlValue, ParameterUpdateInfo& paramInfo)
{
    // --- now do any post update cooking; be careful with VST Sample Accurate automation
    //     If enabled, then make sure the cooking functions are short and efficient otherwise disable it
    //     for the Parameter involved
    /*switch(controlID)
    {
        case 0:
        {
            return true;    /// handled
        }

        default:
            return false;   /// not handled
    }*/

    return false;
}

/**
\brief has nothing to do with actual variable or updated variable (binding)

CAUTION:
- DO NOT update underlying variables here - this is only for sending GUI updates or letting you
  know that a parameter was changed; it should not change the state of your plugin.

WARNING:
- THIS IS NOT THE PREFERRED WAY TO LINK OR COMBINE CONTROLS TOGETHER. THE PROPER METHOD IS
  TO USE A CUSTOM SUB-CONTROLLER THAT IS PART OF THE GUI OBJECT AND CODE.
  SEE http://www.willpirkle.com for more information

\param controlID the control ID value of the parameter being updated
\param actualValue the new control value

\return true if operation succeeds, false otherwise
*/
bool PluginCore::guiParameterChanged(int32_t controlID, double actualValue)
{
	/*
	switch (controlID)
	{
		case controlID::<your control here>
		{

			return true; // handled
		}

		default:
			break;
	}*/

	return false; /// not handled
}

/**
\brief For Custom View and Custom Sub-Controller Operations

NOTES:
- this is for advanced users only to implement custom view and custom sub-controllers
- see the SDK for examples of use

\param messageInfo a structure containing information about the incoming message

\return true if operation succeeds, false otherwise
*/
bool PluginCore::processMessage(MessageInfo& messageInfo)
{
	// --- decode message
	switch (messageInfo.message)
	{
		// --- add customization appearance here
	case PLUGINGUI_DIDOPEN:
	{
		return false;
	}

	// --- NULL pointers so that we don't accidentally use them
	case PLUGINGUI_WILLCLOSE:
	{
		return false;
	}

	// --- update view; this will only be called if the GUI is actually open
	case PLUGINGUI_TIMERPING:
	{
		return false;
	}

	// --- register the custom view, grab the ICustomView interface
	case PLUGINGUI_REGISTER_CUSTOMVIEW:
	{

		return false;
	}

	case PLUGINGUI_REGISTER_SUBCONTROLLER:
	case PLUGINGUI_QUERY_HASUSERCUSTOM:
	case PLUGINGUI_USER_CUSTOMOPEN:
	case PLUGINGUI_USER_CUSTOMCLOSE:
	case PLUGINGUI_EXTERNAL_SET_NORMVALUE:
	case PLUGINGUI_EXTERNAL_SET_ACTUALVALUE:
	{

		return false;
	}

	default:
		break;
	}

	return false; /// not handled
}


/**
\brief process a MIDI event

NOTES:
- MIDI events are 100% sample accurate; this function will be called repeatedly for every MIDI message
- see the SDK for examples of use

\param event a structure containing the MIDI event data

\return true if operation succeeds, false otherwise
*/
bool PluginCore::processMIDIEvent(midiEvent& event)
{
	return true;
}

/**
\brief (for future use)

NOTES:
- MIDI events are 100% sample accurate; this function will be called repeatedly for every MIDI message
- see the SDK for examples of use

\param vectorJoysickData a structure containing joystick data

\return true if operation succeeds, false otherwise
*/
bool PluginCore::setVectorJoystickParameters(const VectorJoystickData& vectorJoysickData)
{
	return true;
}

/**
\brief use this method to add new presets to the list

NOTES:
- see the SDK for examples of use
- for non RackAFX users that have large paramter counts, there is a secret GUI control you
  can enable to write C++ code into text files, one per preset. See the SDK or http://www.willpirkle.com for details

\return true if operation succeeds, false otherwise
*/
bool PluginCore::initPluginPresets()
{
	// **--0xFF7A--**

	// --- Plugin Presets 
	int index = 0;
	PresetInfo* preset = nullptr;

	// --- Preset: Factory Preset
	preset = new PresetInfo(index++, "Factory Preset");
	initPresetParameters(preset->presetParameters);
	setPresetParameter(preset->presetParameters, controlID::filterQ, 0.707000);
	setPresetParameter(preset->presetParameters, controlID::boostCut32Hz_dB, 0.000000);
	setPresetParameter(preset->presetParameters, controlID::boostCut64Hz_dB, 0.000000);
	setPresetParameter(preset->presetParameters, controlID::boostCut125Hz_dB, 0.000000);
	setPresetParameter(preset->presetParameters, controlID::boostCut250Hz_dB, 0.000000);
	setPresetParameter(preset->presetParameters, controlID::boostCut500Hz_dB, 0.000000);
	setPresetParameter(preset->presetParameters, controlID::boostCut1kHz_dB, 0.000000);
	setPresetParameter(preset->presetParameters, controlID::boostCut2kHz_dB, 0.000000);
	setPresetParameter(preset->presetParameters, controlID::boostCut4kHz_dB, 0.000000);
	setPresetParameter(preset->presetParameters, controlID::boostCut8kHz_dB, 0.000000);
	setPresetParameter(preset->presetParameters, controlID::boostCut16kHz_dB, 0.000000);
	addPreset(preset);


	// **--0xA7FF--**

    return true;
}

/**
\brief setup the plugin description strings, flags and codes; this is ordinarily done through the ASPiKreator or CMake

\return true if operation succeeds, false otherwise
*/
bool PluginCore::initPluginDescriptors()
{
    pluginDescriptor.pluginName = PluginCore::getPluginName();
    pluginDescriptor.shortPluginName = PluginCore::getShortPluginName();
    pluginDescriptor.vendorName = PluginCore::getVendorName();
    pluginDescriptor.pluginTypeCode = PluginCore::getPluginType();

	// --- describe the plugin attributes; set according to your needs
	pluginDescriptor.hasSidechain = kWantSidechain;
	pluginDescriptor.latencyInSamples = kLatencyInSamples;
	pluginDescriptor.tailTimeInMSec = kTailTimeMsec;
	pluginDescriptor.infiniteTailVST3 = kVSTInfiniteTail;

    // --- AAX
    apiSpecificInfo.aaxManufacturerID = kManufacturerID;
    apiSpecificInfo.aaxProductID = kAAXProductID;
    apiSpecificInfo.aaxBundleID = kAAXBundleID;  /* MacOS only: this MUST match the bundle identifier in your info.plist file */
    apiSpecificInfo.aaxEffectID = "aaxDeveloper.";
    apiSpecificInfo.aaxEffectID.append(PluginCore::getPluginName());
    apiSpecificInfo.aaxPluginCategoryCode = kAAXCategory;

    // --- AU
    apiSpecificInfo.auBundleID = kAUBundleID;   /* MacOS only: this MUST match the bundle identifier in your info.plist file */
    apiSpecificInfo.auBundleName = kAUBundleName;

    // --- VST3
    apiSpecificInfo.vst3FUID = PluginCore::getVSTFUID(); // OLE string format
    apiSpecificInfo.vst3BundleID = kVST3BundleID;/* MacOS only: this MUST match the bundle identifier in your info.plist file */
	apiSpecificInfo.enableVST3SampleAccurateAutomation = kVSTSAA;
	apiSpecificInfo.vst3SampleAccurateGranularity = kVST3SAAGranularity;

    // --- AU and AAX
    apiSpecificInfo.fourCharCode = PluginCore::getFourCharCode();

    return true;
}

// --- static functions required for VST3/AU only --------------------------------------------- //
const char* PluginCore::getPluginBundleName() { return kAUBundleName; }
const char* PluginCore::getPluginName(){ return kPluginName; }
const char* PluginCore::getShortPluginName(){ return kShortPluginName; }
const char* PluginCore::getVendorName(){ return kVendorName; }
const char* PluginCore::getVendorURL(){ return kVendorURL; }
const char* PluginCore::getVendorEmail(){ return kVendorEmail; }
const char* PluginCore::getAUCocoaViewFactoryName(){ return AU_COCOA_VIEWFACTORY_STRING; }
pluginType PluginCore::getPluginType(){ return kPluginType; }
const char* PluginCore::getVSTFUID(){ return kVSTFUID; }
int32_t PluginCore::getFourCharCode(){ return kFourCharCode; }
