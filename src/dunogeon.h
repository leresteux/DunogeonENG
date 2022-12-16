#ifndef dunogeon_h
#define dunogeon_h
#include "Arduino.h"

class DUNOGEON
{
public :
          void begin();
private : 
          uint8_t actualRoom =1;
          String erreur;
          bool chronoDandD(long frequency);
          void playerLed();
          void playerInfos();
          bool etatLed=0;
          void breakTime(uint16_t varBreakTime);
// avant en public
          uint16_t playerLife = 10;
          uint8_t playerAttack=1;
          uint8_t rooms;// nombre de salle a effectué
          uint8_t meet[10];
          uint8_t maxCaraPourLaReponse = 10;
          String reponse;
          bool reponseEnvoyee = false;
          uint8_t R;
          void verification();
          void wrongAnswer();
          void quest();

          void roomDescription();
          void emptyRoomMeet();
          void monsterMeet();
          void trapMeet();
          void tresorMeet();
          void whatDoor();

          void quid(  String reponseAttendu1,  String reponseAttendu2,  String reponseAttendu3);

          void monsterFight(byte varMonsterLife, byte varMonsterAttack);
};
#endif