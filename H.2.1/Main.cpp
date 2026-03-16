/* Domonic Yanall
3/14/26
H.2.1 The standard list */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Invintory(vector<string> invintory);
void SearchInvintory(vector<string> invintory);

int main (){

    cout << "Welcome to the main menu! You are a player in an RPG game. Would you like to:" <<
    endl << "Press 1 - Veiw invintory list " << endl << "Press 2 - Search inventory list " << endl <<
    "Press 3 - Exit " << endl << endl;

    //first few items

  
    cout << "Inventory: " << endl;

    vector<string> invintory = {"Mushroom", "Poision Mushroom", "Golden Pipe", "Star", 
    "Coins", "Lamp", "Dice", "Boo Bell", "Coinado", "Golden Mushroom", "Pipe", "Warp Block", "Double Dice" , "Triple Dice"
, "Super Dice", "Custum Die", "Stickers"};
    
    for (int i=0; i<4; i++){
        cout << invintory[i] << endl;
    }
   
        //player choice
    int mainMenuChoice;
    cin >> mainMenuChoice;

    if (mainMenuChoice == 1){
        Invintory(invintory);
    }
    else if(mainMenuChoice == 2){
        SearchInvintory(invintory);
    }
    else if (mainMenuChoice == 3){
        cout << "Exiting..." << endl;
    }
    else{
        cout << "Uh oh, that was not a choice :,( " << endl;
        return 0;
    }

    return 0;
    }


void Invintory(vector<string> invintory){

  
    for (int i=0; i<invintory.size(); i++){
        cout << invintory[i] << endl;
    }

   
}

void SearchInvintory(vector<string> invintory){
    cout << "What are you searching for: " ;

    string item;
    getline(cin >> ws, item);
    cout << endl;

    bool found = false;

    for (int i=0; i<invintory.size(); i++){

        if(invintory[i] == item){

            cout << item << " was found in list!" << endl;
            found = true;
            break;
        }
    }

    if(!found){
        cout << item << " was not found in list." << endl;
    }

}