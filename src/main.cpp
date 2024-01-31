/*

  Audio player, non blocking.
  read 8bit mono .wav file, up to 4 channels
  use Audacity to convert your audio file
  Author : AloyseTech with subsequent modifications by various people including,Hydronics and Gambalunga

  03/17/19: https://github.com/hydronics2/SamdAudio
    updated to work with Adafruit Qaud Flash memory boards.
    This will work with any SAMD21 chip using SPI flash with a little tinkering
     - itsyBitsy M0 Express, 
     - Feather M0 Express, 

   23/07/2020:
    updated to work with the current version of the Adafruit_SPIFlash library.
    Not tested but could probably be modified to function with an SD card.
    For use with an SD card refer to https://github.com/hydronics2/SamdAudio
    
     - Will not work with Adafruit Feather M4 Express and other boards with the SAMD51 processor 

    Read this great description in the Adafruit tutorial for getting the WAV files onto your Adafruit M0 Express board
    https://learn.adafruit.com/introducing-itsy-bitsy-m0?view=all#using-spi-flash
    Thanks to Tondy Dicola and Adafruit for making this so easy!

*/

#include <SPI.h>
// #include <SD.h>
#include <Adafruit_SPIFlash.h>
#include <Audio_FeatherM0.h> // 
#include <SdFat.h>

#define TRIGGER_THRESHOLD 900   // [0-1023]

#define SD_FAT_TYPE 1
#define SD_CS_PIN 5

// Try max SPI clock for an SD. Reduce SPI_CLOCK if errors occur.
#define SPI_CLOCK SD_SCK_MHZ(4)

// Try to select the best SD card configuration.
#if HAS_SDIO_CLASS
#define SD_CONFIG SdioConfig(FIFO_SDIO)
#elif  ENABLE_DEDICATED_SPI
#define SD_CONFIG SdSpiConfig(SD_CS_PIN, DEDICATED_SPI, SPI_CLOCK)
#else  // HAS_SDIO_CLASS
#define SD_CONFIG SdSpiConfig(SD_CS_PIN, SHARED_SPI, SPI_CLOCK)
#endif  // HAS_SDIO_CLASS


#if SD_FAT_TYPE == 0
SdFat sd;
File file;
#elif SD_FAT_TYPE == 1
SdFat32 sd;
File32 file;
#elif SD_FAT_TYPE == 2
SdExFat sd;
ExFile file;
#elif SD_FAT_TYPE == 3
SdFs sd;
FsFile file;
#else  // SD_FAT_TYPE
#error Invalid SD_FAT_TYPE
#endif  // SD_FAT_TYPE



SamdAudio AudioPlayer; 

#define NUM_AUDIO_CHANNELS 1 //could be 1,2 or 4 for sound

#define AUDIO_BUFFER_SIZE 1024 //512 works fine for 22.05kh, use 1024 for 32khz and 44.1khz

//indicate sample rate here (use audacity to convert your wav)
const unsigned int sampleRate = 32000; //hz


void setup()
{
  delay(1500);
  Serial.begin(9600);
  Serial.println("yey");
  if (!sd.begin(SD_CONFIG)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  } else {
    Serial.println("SD works");
  }  
  
  Serial.print("Initializing Audio Player...");
  if (AudioPlayer.begin(sampleRate, NUM_AUDIO_CHANNELS, AUDIO_BUFFER_SIZE) == -1) 
  {
    Serial.println(" failed!");
    return;
  }
  Serial.println(" done.");

  // AudioPlayer.play("test32.wav", 0);

  Serial.println("Playing file.....");
}


void loop()
{
  if (analogRead(A1) < TRIGGER_THRESHOLD) {
    delay(200);
    AudioPlayer.play("test32.wav", 0);
  }

  if (analogRead(A2) < TRIGGER_THRESHOLD) {
    delay(200);
    AudioPlayer.play("himilu32.wav", 0);
  }

}
