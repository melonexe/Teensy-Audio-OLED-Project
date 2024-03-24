#include <Audio.h>
#include <sawtooth.h>

sawtooth faustSawtooth;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(faustSawtooth,0,out,0);
AudioConnection patchCord1(faustSawtooth,0,out,1);

void setupFaust() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.1);
}

void loopFaust() {
  faustSawtooth.setParamValue("freq",random(50,1000));
  delay(50);
}