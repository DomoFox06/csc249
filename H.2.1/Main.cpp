/* Domonic Yanall
3/14/26
H.2.1 The standard list */

#include <iostream>

using namespace std;

void Invintory();

int main (){

    cout << "Welcome to the main menu! You are a player in an RPG game. Would you like to:" <<
    endl << "Press 1 - Veiw invintory list " << endl << "Press 2 - Search inventory list " << endl <<
    "Press 3 - Exit " << endl;

    cout << "Inventory: " << endl;

    int mainMenuChoice;
    cin >> mainMenuChoice;

    if (mainMenuChoice == 1){
        Invintory;
    }
    else if(mainMenuChoice == 2){
        cout << "Let's search!" << endl;
    }
    else if (mainMenuChoice == 3){
        cout << "Exiting..." << endl;
    }
    else{
        cout << "Uh oh, that was not a choice :,( " << endl;
    }

    return 0;
}

void Invintory(){

    cout<< "Inventory";

   ;
}