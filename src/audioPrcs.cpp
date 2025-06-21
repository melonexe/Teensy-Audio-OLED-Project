#include "audioPrcs.h"

/*
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=135,421
AudioEffectDelay         DelayR;         //xy=338,523
AudioEffectDelay         DelayL;         //xy=339,389
AudioEffectBitcrusher    bitcrusher1;    //xy=436,855
AudioEffectBitcrusher    bitcrusher2;    //xy=436,899
AudioEffectFreeverb      freeverbL;      //xy=454,59
AudioEffectFreeverb      freeverbR;      //xy=456,106
AudioAmplifier           Tap5R; //xy=581,614
AudioAmplifier           Tap6R; //xy=581,647
AudioAmplifier           Tap7R; //xy=581,682
AudioAmplifier           Tap3R; //xy=582,545
AudioAmplifier           Tap4R; //xy=582,580
AudioAmplifier           Tap1R; //xy=583,476
AudioAmplifier           Tap2R; //xy=583,512
AudioAmplifier           Tap8R; //xy=583,720
AudioAmplifier           Tap8L; //xy=588,428
AudioAmplifier           Tap5L; //xy=589,324
AudioAmplifier           Tap6L; //xy=589,357
AudioAmplifier           Tap7L; //xy=589,392
AudioAmplifier           Tap3L; //xy=590,255
AudioAmplifier           Tap4L; //xy=590,290
AudioAmplifier           Tap1L;           //xy=591,186
AudioAmplifier           Tap2L; //xy=591,222
AudioMixer4              TapSubMixR; //xy=771,554
AudioMixer4              TapSubMix2R; //xy=776,638
AudioMixer4              TapSubMixL;         //xy=782,264
AudioMixer4              TapSubMix2L; //xy=783,343
AudioMixer4              TapSumL; //xy=997,314
AudioMixer4              TapSumR; //xy=1010,565
AudioAmplifier           CrushAmpL; //xy=1111,847
AudioAmplifier           CrushAmpR; //xy=1112,895
AudioAmplifier           FreeverbAmpL;           //xy=1127,55
AudioAmplifier           FreeverbAmpR;           //xy=1129,103
AudioAmplifier           DelayAmpL; //xy=1293,391
AudioAmplifier           DelayAmpR; //xy=1296,458
AudioMixer4              MixerL;         //xy=1442,324
AudioMixer4              MixerR;         //xy=1446,550
AudioAnalyzePeak         peak2;          //xy=1721,526
AudioAnalyzePeak         peak1;          //xy=1730,211
AudioAnalyzeRMS          rms2;           //xy=1730,592
AudioAnalyzeRMS          rms1;           //xy=1735,279
AudioOutputI2S           i2s2;           //xy=1888,395
AudioConnection          patchCord1(i2s1, 0, freeverbL, 0);
AudioConnection          patchCord2(i2s1, 0, DelayL, 0);
AudioConnection          patchCord3(i2s1, 0, bitcrusher1, 0);
AudioConnection          patchCord4(i2s1, 1, freeverbR, 0);
AudioConnection          patchCord5(i2s1, 1, DelayR, 0);
AudioConnection          patchCord6(i2s1, 1, bitcrusher2, 0);
AudioConnection          patchCord7(DelayR, 0, Tap1R, 0);
AudioConnection          patchCord8(DelayR, 1, Tap2R, 0);
AudioConnection          patchCord9(DelayR, 2, Tap3R, 0);
AudioConnection          patchCord10(DelayR, 3, Tap4R, 0);
AudioConnection          patchCord11(DelayR, 4, Tap5R, 0);
AudioConnection          patchCord12(DelayR, 5, Tap6R, 0);
AudioConnection          patchCord13(DelayR, 6, Tap7R, 0);
AudioConnection          patchCord14(DelayR, 7, Tap8R, 0);
AudioConnection          patchCord15(DelayL, 0, Tap1L, 0);
AudioConnection          patchCord16(DelayL, 1, Tap2L, 0);
AudioConnection          patchCord17(DelayL, 2, Tap3L, 0);
AudioConnection          patchCord18(DelayL, 3, Tap4L, 0);
AudioConnection          patchCord19(DelayL, 4, Tap5L, 0);
AudioConnection          patchCord20(DelayL, 5, Tap6L, 0);
AudioConnection          patchCord21(DelayL, 6, Tap7L, 0);
AudioConnection          patchCord22(DelayL, 7, Tap8L, 0);
AudioConnection          patchCord23(bitcrusher1, CrushAmpL);
AudioConnection          patchCord24(bitcrusher2, CrushAmpR);
AudioConnection          patchCord25(freeverbL, FreeverbAmpL);
AudioConnection          patchCord26(freeverbR, FreeverbAmpR);
AudioConnection          patchCord27(Tap5R, 0, TapSubMix2R, 0);
AudioConnection          patchCord28(Tap6R, 0, TapSubMix2R, 1);
AudioConnection          patchCord29(Tap7R, 0, TapSubMix2R, 2);
AudioConnection          patchCord30(Tap3R, 0, TapSubMixR, 2);
AudioConnection          patchCord31(Tap4R, 0, TapSubMixR, 3);
AudioConnection          patchCord32(Tap1R, 0, TapSubMixR, 0);
AudioConnection          patchCord33(Tap2R, 0, TapSubMixR, 1);
AudioConnection          patchCord34(Tap8R, 0, TapSubMix2R, 3);
AudioConnection          patchCord35(Tap8L, 0, TapSubMix2L, 3);
AudioConnection          patchCord36(Tap5L, 0, TapSubMix2L, 0);
AudioConnection          patchCord37(Tap6L, 0, TapSubMix2L, 1);
AudioConnection          patchCord38(Tap7L, 0, TapSubMix2L, 2);
AudioConnection          patchCord39(Tap3L, 0, TapSubMixL, 2);
AudioConnection          patchCord40(Tap4L, 0, TapSubMixL, 3);
AudioConnection          patchCord41(Tap1L, 0, TapSubMixL, 0);
AudioConnection          patchCord42(Tap2L, 0, TapSubMixL, 1);
AudioConnection          patchCord43(TapSubMixR, 0, TapSumR, 0);
AudioConnection          patchCord44(TapSubMix2R, 0, TapSumR, 1);
AudioConnection          patchCord45(TapSubMixL, 0, TapSumL, 0);
AudioConnection          patchCord46(TapSubMix2L, 0, TapSumL, 1);
AudioConnection          patchCord47(TapSumL, DelayAmpL);
AudioConnection          patchCord48(TapSumR, DelayAmpR);
AudioConnection          patchCord49(CrushAmpL, 0, MixerL, 2);
AudioConnection          patchCord50(CrushAmpR, 0, MixerR, 2);
AudioConnection          patchCord51(FreeverbAmpL, 0, MixerL, 0);
AudioConnection          patchCord52(FreeverbAmpR, 0, MixerR, 0);
AudioConnection          patchCord53(DelayAmpL, 0, MixerL, 1);
AudioConnection          patchCord54(DelayAmpR, 0, MixerR, 1);
AudioConnection          patchCord55(MixerL, 0, i2s2, 0);
AudioConnection          patchCord56(MixerL, rms1);
AudioConnection          patchCord57(MixerL, peak1);
AudioConnection          patchCord58(MixerR, 0, i2s2, 1);
AudioConnection          patchCord59(MixerR, peak2);
AudioConnection          patchCord60(MixerR, rms2);
AudioControlSGTL5000     sgtl5000_1;     //xy=121,500
// GUItool: end automatically generated code

void Audiosetup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.7);

  //set up amp and mixer values etc etc refer to system diagram

  AudioMemory(512);// arbritary value at the moment need to look into this
}

void AudioLoop(){
}
*/
