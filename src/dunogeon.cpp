

#include "dunogeon.h"

#define porte Serial.println(F("Which door are you taking?"))
#define chapitre Serial.println();Serial.print(F("Chapiter")); Serial.println(actualRoom);
#define ligne Serial.println(F("-_-_-_-_-_-_-_-"))

//main void
void DUNOGEON::begin(){
 //set up Arduino
 randomSeed(analogRead(A0)+analogRead(A1)+analogRead(A2));
 Serial.begin(115200);
 pinMode(LED_BUILTIN, OUTPUT);
//set dunogeon
 rooms = random(6)+5;// nombre de salle a effectué   
 for (uint8_t i = rooms ; i>0 ; i--){
  meet[i] = random(10);
 }
 //verification();
 quest();

}

void DUNOGEON::quest(){
 Serial.println(F("Welcome to the DUNOGEON!"));
breakTime(3000);
 Serial.println(F("!!Attention this program functions with a speed 115200 for the serial monitor!!"));
breakTime(3000);
 Serial.println(F("You will have to survive in this dungeon, ranging from 5 to 10 rooms."));
breakTime(3000);
 Serial.println(F("The LED integrated into the Arduino and linked to pin 13 represents your heartbeats."));
breakTime(3000);
 Serial.println(F("Use the serial to communicate with the DUNOGEON."));
breakTime(3000);
 Serial.println(F("Good luck !"));
breakTime(3000);
 ligne;

 
 Serial.println(F("After going through a few corridors and minor rooms, you arrive in a first room..."));
breakTime(3000);

 while(1){
  
  if (actualRoom==rooms+1){
   Serial.println(F("Congratulations, you are out of the Dunogeon.  At the exit you see a redhead who welcomes you saying: "));
Serial.println(F("- I was waiting for you…"));
breakTime(3000);
Serial.println(F("...congratulations!"));
breakTime(3000);
Serial.println(F("- Because you are admitted to the largest of the Guilds, you will be able to join the [insert what you like :p ] "));
Serial.println();
breakTime(3000);
Serial.print(F("E"));breakTime(3000);;Serial.print(F("N"));breakTime(3000);;Serial.println(F("D"));
breakTime(3000);
Serial.println();
Serial.println(F("Texts : Maëlle L.B. aka Roukinette"));
Serial.println(F("Codes : Julien L. aka HorriblePère"));
Serial.println();
breakTime(3000);
Serial.println(F("Licence : cc by nc sa"));
Serial.println(F("2022"));

while(1);

  }else{
    
   chapitre;
   delay(10);
   roomDescription();
 //tableau de rencontre(de 0 à 9) : 0-1=vide ; 2-5=monstres ; 6-7 =piège ; 8-9 = trésor
   switch (meet[actualRoom]) {
  case 0 : case 1 :
   emptyRoomMeet();
   break;
  case 2 : case 3 : case 4 :case 5 :
   monsterMeet();
   break;
  case 6 : case 7 :
   trapMeet();
   break;
  case 8 : case 9 :
   tresorMeet();
   break;
  default: 
  Serial.println(F("error in void quest"));
   break;
  }
  actualRoom++;
  whatDoor();
  }
 }
}

void DUNOGEON::emptyRoomMeet(){
R=random(5);
delay(10);
 switch (R) {
  case 0 :
  Serial.println(F("Apart from dust...nothing."));
  break;
  case 1 :
   Serial.println(F("There are just two rats fighting with their paws."));
  break;
  case 2 :
      Serial.println(F("SHH!  A noise..."));
     breakTime(3000);
      Serial.println(F("Oh no, there is nothing.")); 
  break;
  case 3 :
     Serial.println(F("Boom!!!"));
     breakTime(3000);
     
     Serial.println(F("A piece of the ceiling collapsed, but you are not hurt"));  
  break;
  case 4 : 
   Serial.println(F("Complete silence.  It's even more stressful"));
  break;
   }
}

void DUNOGEON::monsterMeet(){
 R=random(5);
 delay(10);
 switch (R) {
  case 0 :
  Serial.println(F("A skeleton advances towards you... The blank stare."));
 breakTime(3000);
  monsterFight(1,1);
   break;
  case 1 :
  Serial.println(F("A tomb, hidden in the ground, opens and an undead comes out."));
 breakTime(3000);
  monsterFight(2,1);
   break;
  case 2 :
    Serial.println(F("A vampire is about to jump on you to bite your neck!"));
   breakTime(3000);
    monsterFight(2,2);
   break;
  case 3 :
Serial.print(F("GRRRRRR!!!"));
breakTime(3000);   
Serial.println(F("A werewolf appears in front of you, growling!"));
breakTime(3000);
   monsterFight(2,2);
   break;
  case 4 : 
Serial.println(F("The most terrible creature you know is coming towards you..."));
breakTime(3000); 
Serial.println(F("Your father!" ));
breakTime(3000); 
Serial.println(F("He repeats this phrase over and over : ")); 
breakTime(3000); 
Serial.println(F("DO THE DISHWASHER, DO THE DISHWASHER... "));
breakTime(3000);
  monsterFight(5,3);
   break;
   }
}

void DUNOGEON::trapMeet(){
R=random(5);
delay(10);
 switch (R) {
  case 0 :
  Serial.println(F("A hatch opens under your feet."));
  playerLife-=1;
   break;
  case 1 :
  Serial.println(F("Stones fall from the cracked ceiling."));
  playerLife-=1;
   break;
  case 2 :
    Serial.println(F("Many arrows shoot out of nowhere"));
    playerLife-=2;
   break;
  case 3 : 
  Serial.println(F("The whole ceiling crashes down on your head and an ax cuts off your arm!"));
  Serial.println(F("By 'lucky' you had a helmet and you are ambidextrous."));
  playerLife-=3;;
   break;
   }
   playerInfos();
}

void DUNOGEON::tresorMeet(){
R=random(5);
delay(10);
 switch (R) {
  case 0 :
  Serial.println(F("You find a TAGADA strawberry on the ground.  You pick it up and gobble it up."));
  playerLife+=2;
   break;
  case 1 :
  Serial.println(F("You see something shine on the floor, a juicy apple."));
  playerLife+=5;
   break;
  case 2 :
    Serial.println(F("You find a yellowish, unsavory potion.  You decide to drink it anyway.")); 
    Serial.println(F("You feel your strength regenerating"));
  playerLife+=10;
   break;
  case 3 :
    Serial.println(F("You find a sword with an engraving:")); 
breakTime(3000);
Serial.println(F("REDHAIRDISHEVELED ONE DAY"));
breakTime(3000);
Serial.println(F("REDHAIRDISHEVELED FOREVER"));
   if (playerAttack < 2)
   {playerAttack = 2;}else{Serial.println(F("Not interesting for you."));}
   break;
  case 4 : 
  Serial.println(F("You find a simple apple... made of metal?"));
  Serial.println(F(" A mechanism starts.  the fruit transforms into a lightsaber [in the color of your choice]. "));
  playerAttack = 3;
   break;
   }
   if (playerLife>10){playerLife=10;};
   playerInfos();
}

void DUNOGEON::roomDescription(){
 R=random(5);
 delay(10);
 Serial.print(F("It's a room"));
 switch (R) {
  case 0 :
  Serial.println(F("with a fireplace and a large table with the place setting."));
   break;
  case 1 :
  Serial.println(F("which looks like a small living room, very dusty"));
   break;
  case 2 :
  Serial.println(F("bigger than the others.  There is a huge library with all kinds of books "));
   break;
  case 3 :
  Serial.println(F("filled with mirrors.  There are in every direction."));
   break;
  case 4 : 
  Serial.println(F("filled with a cloud of opaque, gray smoke."));
   break;
   }
}

void DUNOGEON::whatDoor(){
R=random(4);
 switch (R) {
  case 0 :
  Serial.println(F("There is a door on the LEFT and one on the RIGHT."));
  porte;
  quid("left","left","right");
   break;
  case 1 :
  Serial.println(F("There is a door on the LEFT and one in FRONT.."));
  porte;
  quid("left","left","front");
   break;
  case 2 :
    Serial.println(F("There is a door on the RIGHT, and one in FRONT."));
  porte;
  quid("right","right","front");
   break;
  case 3 :
    Serial.println(F("There is a door on the RIGHT, one on the LEFT and one in FRONT."));
  porte;
  quid("right","left","front");
   break;
  default: 
  Serial.println(F("error in void whatDoor"));
   break;
   }
}

void DUNOGEON::quid(String reponseAttendu1, String reponseAttendu2, String reponseAttendu3) 
 {
  bool reponseOk =false;
  while(!reponseOk){ 
 
 reponseEnvoyee = false;
 delay(1);
 // Vider le buffer Serial s'il reste des caractères...
while (Serial.available()) 
    {
     Serial.read();
     }  
// en attente de réponse
while (!reponseEnvoyee) {
 playerLed();
  if (Serial.available() > 0) {
   reponse = Serial.readStringUntil('\n');
   //si reponse à trop de caractère
  if (reponse.length() > maxCaraPourLaReponse ){
   Serial.println(F("~~~~"));
    Serial.println(F("I'm sorry, but the writing is limited to 10 characters and this in a totally arbitrary way."));
    
    //offense();
    }else{
   //longueur correcte
   Serial.println("");
   Serial.print("> ");
   Serial.println(reponse);
   reponseEnvoyee = true;
   }
   delay (10);
  }
}
  // si réponses attendues absentes
  if ( reponse != reponseAttendu1 && reponse != reponseAttendu2 && reponse != reponseAttendu3) {
   wrongAnswer();
  }else{
   reponseOk =true;
  }

 }
 }

void DUNOGEON::verification(){
  Serial.print(F("number of rooms: "));
  Serial.print(rooms);
  Serial.println();
  Serial.print(F("met :"));
 for (uint8_t i=rooms;i>0;i--){
  Serial.print(meet[i]);
 }  
 Serial.println();

}

void DUNOGEON::wrongAnswer(){
 byte R = random(5);
 switch (R) {
  case 0 :
   Serial.println(F("I can't use this answer"));
   break;
  case 1 :
   Serial.println(F("I did not understand."));
   break;
  case 2 :
   Serial.println(F("Unable to read, try again"));
   break;
  case 3 :
   Serial.println(F("Value not taken into account"));
   break;
  case 4 :
   Serial.println(F("Invalid"));
   break;
  default :
   Serial.println(F("Unfortunately I am limited in my understanding of human intentions"));   
   break;
 }
}

void DUNOGEON::monsterFight(byte varMonsterLife, byte varMonsterAttack){

 Serial.println();
 Serial.println(F("FIGHT!"));
 Serial.println();
 int8_t monsterLife=varMonsterLife;
 byte monsterAttack=varMonsterAttack;
 byte playerMoves;
 while(playerLife>0 && monsterLife>0){
  playerInfos();
  Serial.print(F("Monster > Health: "));Serial.print(monsterLife);Serial.print(F(" - damage: "));Serial.println(monsterAttack);
 Serial.println(F("What attack do you make, a direct ATTACK, a PARRY, a CHARGE?"));
 quid("attack", "parry", "charge");
 if(reponse=="attack"){playerMoves=0;}
 if(reponse=="parry"){playerMoves=1;}
 if(reponse=="charge"){playerMoves=2;}
 R=random(3);
 if(playerMoves == R){
  Serial.println(F("Same movement, neither of you touching the other."));}
else if ((playerMoves==0 && R==2) ||playerMoves>R){
  monsterLife -= playerAttack;
  Serial.println(F("Well done, you hurt him."));
 
 }else{ 
 playerLife -= monsterAttack;
 Serial.println(F("Oh, it hurts!!!"));
 }
 if(monsterLife<1){
  Serial.println(F("victory !"));
  }
 }
 Serial.println(F("End of the fight."));
}

void DUNOGEON::playerLed(){ 
  bool etatLed = chronoDandD(playerLife*100);

  digitalWrite(LED_BUILTIN, etatLed);
}
void DUNOGEON::playerInfos(){
 Serial.print("Player > Health: ");Serial.print(playerLife);Serial.print("/10 - damage: ");Serial.print(playerAttack);
 Serial.println();
 if ( playerLife < 1 ){
 Serial.println(F("Too bad you're dead!")); 
 while(1);
}}

// return 0 ou 1 alternativement en fonction de la durée d'une frequence attribué (long frequence) 
// utilisé pour la led 
bool DUNOGEON::chronoDandD(long frequency){
 static bool chronoTop;
 unsigned long millisNow = millis();
 static unsigned long millisOld;
if ((millisNow-millisOld) >frequency ){
  millisOld=millis();
  chronoTop = !chronoTop;
  }
  return chronoTop;
  
}

void DUNOGEON::breakTime(uint16_t varBreakTime){
  uint32_t startTime = millis();

  while(millis()-startTime<varBreakTime){

    playerLed();
  }
}
