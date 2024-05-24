#include "pitches.h"
#define NPS_1 333
#define NPS_2 346

int music_1[] = {
  NOTE_A5, NOTE_G5, NOTE_A5, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_C6,
  NOTE_A5, NOTE_G5, NOTE_A5, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_DS4, NOTE_D4, NOTE_C4,
  NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_G5, NOTE_A5, NOTE_C6, NOTE_D6, NOTE_DS6,

};
float tempo_1[] = {
  0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,

};

int music_2[] = {
  NOTE_A4,NOTE_A5,0,NOTE_A5,0,NOTE_A5,0,NOTE_E5,NOTE_CS6,NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_DS5,NOTE_F5,NOTE_CS5,
  NOTE_DS5,NOTE_DS5,NOTE_DS5,NOTE_DS5,NOTE_DS5,NOTE_DS5,NOTE_DS5,NOTE_DS5,NOTE_F5,NOTE_FS5,NOTE_G5,
  NOTE_GS5,NOTE_GS5,NOTE_GS5,NOTE_GS5,NOTE_GS5,NOTE_GS5,NOTE_GS5,NOTE_GS5,NOTE_AS5,NOTE_C6,NOTE_DS6,
  NOTE_CS6,NOTE_CS6,NOTE_CS6,NOTE_CS6,NOTE_CS6,NOTE_CS6,NOTE_CS6,NOTE_CS6,NOTE_DS6,NOTE_F5,NOTE_FS6,
  NOTE_GS5,NOTE_GS5,NOTE_GS5,NOTE_GS5,NOTE_F5,NOTE_F5,NOTE_F5,NOTE_DS5,NOTE_DS5,NOTE_DS5,NOTE_F5,NOTE_DS5,NOTE_F5,
  NOTE_DS5,NOTE_DS5,NOTE_DS5,NOTE_F5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_DS5,NOTE_DS5,NOTE_F5,NOTE_DS5,NOTE_CS5,
  NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_GS5,NOTE_GS5,NOTE_GS5,NOTE_F5,NOTE_F5,NOTE_F5,NOTE_F5,NOTE_DS5,NOTE_DS5,
  NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_DS5,NOTE_F5,NOTE_CS5,0,
};

float tempo_2[] = {
  1,0.5,0.5,0.5,0.5,0.5,0.5,1,0.5,0.25,0.25,0.5,0.25,0.25,0.5,0.25,0.25,0.5,0.25,
  0.5,0.25,0.25,0.5,0.25,0.25,0.5,0.25,0.25,0.5,0.25,
  0.5,0.25,0.25,0.5,0.25,0.25,0.5,0.25,0.25,0.5,0.25,
  0.5,0.25,0.25,0.5,0.25,0.25,0.5,0.25,0.25,0.5,0.25,
  0.25,0.25,0.25,0.25,0.5,0.25,0.25,0.25,0.25,0.25,0.25,0.5,0.5,
  0.25,0.25,0.25,0.25,0.5,0.5,0.25,0.25,0.25,0.25,0.5,0.5,
  0.25,0.25,0.25,0.25,0.5,0.25,0.25,0.25,0.25,0.25,0.25,0.5,0.5,
  0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.5,0.5,0.5,0.5
};

int mode = 1;
int premode = 0;
int nextmode = 0;

int dura(float eva, int NPS) {
  int rev = (eva * NPS);
  return (rev);
}

void setup() {
  pinMode(9,  INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (mode == 1) {
    noTone(8);
    for (int i = 0; i < 47; i++) {
      nextmode = digitalRead(9);
      Serial.println(premode);
      Serial.println(nextmode);
      Serial.println(' ');
      tone(8, music_1[i], dura(tempo_1[i],NPS_1));
      delay(dura(tempo_1[i] * 1.1, NPS_1));
      noTone(8);

      if (premode == 0 && nextmode == 1) {
        mode = 2;
        break;
      }
      premode = nextmode;
    }
  }
  if (mode == 2) {
    noTone(8);
    for (int i = 0; i <102 ; i++) {
      nextmode = digitalRead(9);
      Serial.println(premode);
      Serial.println(nextmode);
      Serial.println(' ');
      tone(8, music_2[i], dura(tempo_2[i],NPS_2));
      delay(dura(tempo_2[i] * 1.1,NPS_2));
      noTone(8);
      if (premode == 1 && nextmode == 0) {
        mode = 1;
        break;
      }
      premode = nextmode;
    }
  }
}
