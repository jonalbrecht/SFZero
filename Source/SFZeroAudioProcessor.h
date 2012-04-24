#ifndef __PLUGINPROCESSOR_H_7DD34D53__
#define __PLUGINPROCESSOR_H_7DD34D53__

#include "../JuceLibraryCode/JuceHeader.h"
#include "SFZSynth.h"

class SFZSound;
class FifoLogger;


class SFZeroAudioProcessor  : public AudioProcessor {
	public:
		SFZeroAudioProcessor();
		~SFZeroAudioProcessor();

		void prepareToPlay(double sampleRate, int samplesPerBlock);
		void releaseResources();
		void processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

		AudioProcessorEditor* createEditor();
		bool hasEditor() const;

		const String getName() const;

		int getNumParameters();

		float getParameter(int index);
		void setParameter(int index, float newValue);

		const String getParameterName(int index);
		const String getParameterText(int index);

		void	setSfzFile(File* newSfzFile, double* progressVar = NULL);
		File	getSfzFile() { return sfzFile; }

		const String getInputChannelName(int channelIndex) const;
		const String getOutputChannelName(int channelIndex) const;
		bool isInputChannelStereoPair(int index) const;
		bool isOutputChannelStereoPair(int index) const;

		bool acceptsMidi() const;
		bool producesMidi() const;

		int getNumPrograms();
		int getCurrentProgram();
		void setCurrentProgram(int index);
		const String getProgramName(int index);
		void changeProgramName(int index, const String& newName);

		void getStateInformation(MemoryBlock& destData);
		void setStateInformation(const void* data, int sizeInBytes);

		MidiKeyboardState	keyboardState;

		SFZSound*	getSound();

#if JUCE_DEBUG
		void	relayLogMessages();
#endif

	protected:
		File sfzFile;
		SFZSynth synth;
		AudioFormatManager formatManager;

		void	loadSound(double* progressVar = NULL);

	private:
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SFZeroAudioProcessor);
	};


#endif  // __PLUGINPROCESSOR_H_7DD34D53__

