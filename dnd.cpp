#include "dnd.h"

void createParty(listParty &L){
    L.first = NULL;
}
void insertParty(listParty &L, string name){
    adrParty p;
    p = new party;
    p->partyName = name;
    p->next = NULL;
    p->members = NULL;
    p->location = NULL;
    if(L.first == NULL){
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}

void deleteParty(listParty &L, adrParty &p){
    p = L.first;
    if (L.first == NULL){
        cout<<"No active party"<<endl;
    } else {
        adrParty q = L.first;
        while (q != NULL){
            q = q->next;
        }
        q = L.first->next;
        L.first = p->next;
        p->next = NULL;
    }
}

void createMember(listMember &L){
    L.first = NULL;
}
void insertMember(listMember &L, string name, string race, string role, string specialty){
    adrMember p;
    p = new member;
    p->info.name = name;
    p->info.race = race;
    p->info.role = role;
    p->info.specialty = specialty;
    p->next = NULL;
    if(L.first == NULL){
        L.first = p;
    } else {
        p->next = NULL;
        L.first = p;
    }
}
void deleteMember(listMember &L, adrMember &p){
    p = L.first;
    if (L.first == NULL){
        cout<<"No member"<<endl;
    } else {
        adrMember q = L.first;
        while (q != NULL){
            q = q->next;
        }
        q = L.first->next;
        L.first = p->next;
        p->next = NULL;
    }
}
void createMap(listMap &L){
    L.first = NULL;
}
void insertMap(listMap &L, string name,string type, string terrain){
    adrMap p;
    p = new mapp;
    p->mapName = name;
    p->monsterType = type;
    p->terrain = terrain;
    p->next = NULL;
    if(L.first == NULL){
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}
void deleteMap(listMap &L, adrMap &p){
    p = L.first;
    if (L.first == NULL){
        cout<<"No map ready"<<endl;
    } else {
        adrMap q = L.first;
        while (q != NULL){
            q = q->next;
        }
        q = L.first->next;
        L.first = p->next;
        p->next = NULL;
    }
}
void createBoss(listBoss &L){
    L.first = NULL;
}
void insertBoss(listBoss &L, string name, string race, string drop){
    adrBoss p;
    p = new boss;
    p->bossName = name;
    p->bossRace = race;
    p->bossDrop = drop;
    p->next = NULL;
    p->location = NULL;
    if(L.first == NULL){
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}
void deleteBoss(listBoss &L, adrBoss &p){
    p = L.first;
    if (L.first == NULL){
        cout<<"No boss alive"<<endl;
    } else {
        adrBoss q = L.first;
        while (q != NULL){
            q = q->next;
        }
        q = L.first->next;
        L.first = p->next;
        p->next = NULL;
    }
}

void showParty(listParty L){
    adrParty p = L.first;
    while (p != NULL){
        cout<<"Party: "<<p->partyName<<endl;
        p = p->next;
    }
}
void showMap(listMap L){
    adrMap p = L.first;
    while (p != NULL){
        cout<<"Map: "<<p->mapName<<endl;
        cout<<"Monster type: "<<p->monsterType<<endl;
        cout<<"Terrain: "<<p->terrain<<endl;
        p = p->next;
    }
}
void showBoss(listBoss L){
    adrBoss p = L.first;
    while (p != NULL){
        cout<<"Boss: "<<p->bossName<<endl;
        cout<<"Race: "<<p->bossRace<<endl;
        cout<<"Drop: "<<p->bossDrop<<endl;
        p = p->next;
    }
}
void showMember(adrMember p){
    while (p != NULL){
        cout<<"Name: "<<p->info.name<<endl;
        cout<<"Role: "<<p->info.role<<endl;
        cout<<"Race: "<<p->info.race<<endl;
        cout<<"Specialty: "<<p->info.specialty<<endl;
        p = p->next;
    }
}
void member2Party(listParty &Lp, listMember &Lm, string partyName, string name){
    adrMember pM = Lm.first; //pointer to member
    adrParty pP = Lp.first; // pointer to party
    while (pM != NULL && pM->info.name != name){
        pM=pM->next;
    }
    while (pP != NULL && pP->partyName != partyName){
        pP=pP->next;
    }
    if (pM != NULL && pP != NULL){
        if(pP->members == NULL){
            pP->members = pM;
        } else {
            pP->members->next = pM;
        }

    } else {
        cout<<"Party/Member not found"<<endl;
    }
}
void connectParty(listParty &Lp, listMap &Lm, string partyName, string mapName){
    adrMap pM = Lm.first; //pointer to map
    adrParty pP = Lp.first; //pointer to party
    while (pM != NULL && pM->mapName != mapName){
        pM=pM->next;
    }
    while (pP != NULL && pP->partyName != partyName){
        pP=pP->next;
    }
    if (pM != NULL && pP != NULL){
        pP->location = pM;
    } else {
        cout<<"Party/Map not found"<<endl;
    }

}
void connectBoss(listBoss &Lb, listMap &Lm, string bossName, string mapName){
    adrMap pM = Lm.first; //pointer to map
    adrBoss pB = Lb.first; //pointer to boss
    while (pM != NULL && pM->mapName != mapName){
        pM=pM->next;
    }
    while (pB != NULL && pB->bossName != bossName){
        pB=pB->next;
    }
    if (pM != NULL && pB != NULL){
        pB->location = pM;
    } else {
        cout<<"Boss/Map not found"<<endl;
    }

}
