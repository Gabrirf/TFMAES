#define buzzer 3
double songspeed = 1.5;
#define NOTE_C4  262   //Defining note frequency
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
//*****************************************
int notes[] = {       //Note of the song, 0 is a rest/pulse
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,

   NOTE_A4, NOTE_A4, 
   //Repeat of first part
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,

   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,
   //End of Repeat

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
};
//*****************************************
int negra = 10;
int corchea = negra/2;
int negrapuntillo = negra*1.5;
int blanca = negra*2;
int duration[] = {         //duration of each note (in ms) Quarter Note is set to negra ms
  corchea, corchea, negra, corchea, corchea, 
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negrapuntillo, corchea, 
  
  corchea, corchea, negra, corchea, corchea, 
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negrapuntillo, corchea, 
  
  corchea, corchea, negra, corchea, corchea, 
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, corchea, negra, corchea,

  corchea, corchea, negra, corchea, corchea, 
  negra, corchea, negra, corchea, 
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negrapuntillo, negrapuntillo,

  negra, corchea,
  //Rpeat of First Part
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negrapuntillo, corchea, 
  
  corchea, corchea, negra, corchea, corchea, 
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negrapuntillo, corchea, 
  
  corchea, corchea, negra, corchea, corchea, 
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, corchea, negra, corchea,

  corchea, corchea, negra, corchea, corchea, 
  negra, corchea, negra, corchea, 
  corchea, corchea, negra, corchea, corchea,
  corchea, corchea, negrapuntillo, negrapuntillo,
  //End of Repeat
  
  negra, corchea, negrapuntillo, negra, corchea, negrapuntillo,
  corchea, corchea, corchea, corchea, corchea, corchea, corchea, corchea, negrapuntillo,
  negra, corchea, negrapuntillo, negra, corchea, negrapuntillo,
  corchea, corchea, corchea, corchea, corchea, blanca,

  negra, corchea, negrapuntillo, negra, corchea, negrapuntillo,
  corchea, corchea, corchea, corchea, corchea, corchea, corchea, corchea, negrapuntillo,
  negra, corchea, negrapuntillo, negra, corchea, negrapuntillo,
  corchea, corchea, corchea, corchea, corchea, blanca
};
