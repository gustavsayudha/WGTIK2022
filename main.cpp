#include "dnd.h"

int main()
{

    listParty Lparty; listBoss Lboss; listMap Lmap; listMember Lmember;
    int choice;
    createParty(Lparty);
    createBoss(Lboss);
    createMap(Lmap);
    createMember(Lmember);

    do {
        cout << endl;
        cout << "========== DnD ==========" << endl;
        cout << "1. Insert Party" << endl;
        cout << "2. Delete Party" << endl;
        cout << "3. Display Parties" << endl;
        cout << "4. Insert Map" << endl;
        cout << "5. Delete Map" << endl;
        cout << "6. Display Maps" << endl;
        cout << "7. Insert Boss" << endl;
        cout << "8. Delete Boss" << endl;
        cout << "9. Display Bosses" << endl;
        cout << "10. Connect Party to Map" << endl;
        cout << "11. Connect Boss to Map" << endl;
        cout << "12. Display Member of Party" << endl;
        cout << "13. Delete Member"<<endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        cout << endl;
        switch(choice) {
            case 1: {
                string sInput,name,role,race,specialty;
                cout << "Enter party name: ";
                cin >> sInput;
                insertParty(Lparty,sInput);
                for (int i = 0; i < 4; i++) {
                    cout << "Enter member name "<< i+1 <<": ";
                    cin >> name;
                    cout << "Enter member role (knight, archer, tanker, mage): ";
                    cin >> role;
                    cout << "Enter member race : ";
                    cin >> race;
                    cout << "Enter member specialty (bow, sword, staff): ";
                    cin >> specialty;
                    insertMember(Lmember,name,race,role,specialty);
                    member2Party(Lparty,Lmember,sInput,name);
                }
                break;
            }
            case 2: {
                adrParty deletedP;
                deleteParty(Lparty,deletedP);
                break;
            }
            case 3: {

                showParty(Lparty);
                break;
            }
            case 4: {
                string newMap, terrain, type;
                cout << "Enter map name: ";
                cin >> newMap;
                cout << "Enter enemy type of map: ";
                cin >> type;
                cout << "Enter map terrain: ";
                cin >> terrain;
                insertMap(Lmap,newMap,type,terrain);
                break;
            }
            case 5: {
                adrMap deleteM;
                deleteMap(Lmap,deleteM);
                break;
            }
            case 6: {
                showMap(Lmap);
                break;
            }
            case 7: {
                string newBoss, race,drop;
                cout << "Enter boss name: ";
                cin >> newBoss;
                cout << "Enter boss race: ";
                cin >> race;
                cout << "Enter boss drop: ";
                cin >> drop;
                insertBoss(Lboss, newBoss,race,drop);
                break;
            }
            case 8: {
                adrBoss deletedB;
                deleteBoss(Lboss,deletedB);
                break;
            }
            case 9: {
                showBoss(Lboss);
                break;
            }
            case 10: {
                string partyName;
                cout << "Enter party name: ";
                cin >> partyName;
                string mapName;
                cout << "Enter map name: ";
                cin >> mapName;
                connectParty(Lparty,Lmap,partyName,mapName);
                cout<< partyName<<" entered "<<mapName<<endl;
                break;
            }
            case 11: {
                string bossName;
                cout << "Enter boss name: ";
                cin >> bossName;
                string mapName;
                cout << "Enter map name: ";
                cin >> mapName;
                connectBoss(Lboss,Lmap,bossName,mapName);
                cout<< bossName<<" entered "<<mapName<<endl;
                break;
            }
            case 12: {
                string partyName;
                cout << "Enter party name: ";
                cin >> partyName;
                adrParty partyFinder = Lparty.first;
                while(partyFinder != NULL && partyFinder->partyName != partyName){
                    partyFinder = partyFinder->next;
                }
                if(partyFinder != NULL){
                    showMember(partyFinder->members);
                }
                break;
            }
            case 13: {
                adrMember deletedMem;
                deleteMember(Lmember,deletedMem);
                break;
            }
            case 0: {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while(choice != 0);

    return 0;
}
