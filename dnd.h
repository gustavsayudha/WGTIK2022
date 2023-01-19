#ifndef DND_H_INCLUDED
#define DND_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct party *adrParty;
typedef struct member *adrMember;
typedef struct mapp *adrMap;
typedef struct boss *adrBoss;

struct party{
    string partyName;
    adrMember members;
    adrMap location;
    adrParty next;
};
struct infoMember{
    string name,race,role,specialty;
};

struct member{
    infoMember info;
    adrMember next;
};

struct mapp{
    string mapName,monsterType,terrain;
    adrMap next;
};

struct boss{
    string bossName,bossRace,bossDrop;
    adrMap location;
    adrBoss next;
};


struct listParty{adrParty first;};
struct listMember{adrMember first;};
struct listMap{adrMap first;};
struct listBoss{adrBoss first;};

void createParty(listParty &L);
void insertParty(listParty &L, string name);
void deleteParty(listParty &L, adrParty &p);
void createMember(listMember &L);
void insertMember(listMember &L, string name, string race, string role, string specialty);
void deleteMember(listMember &L, adrMember &p);
void createMap(listMap &L);
void insertMap(listMap &L, string name,string type, string terrain);
void deleteMap(listMap &L, adrMap &p);
void createBoss(listBoss &L);
void insertBoss(listBoss &L, string name,string race, string drop);
void deleteBoss(listBoss &L, adrBoss &p);
void showParty(listParty);
void showMap(listMap);
void showBoss(listBoss);
void showMember(adrMember);
void member2Party(listParty &Lp, listMember &Lm, string partyName, string name);
void connectParty(listParty &Lp, listMap &Lm, string partyName, string mapName);
void connectBoss(listBoss &Lb, listMap &Lm, string bossName, string mapName);

#endif // DND_H_INCLUDED
