
//Domonic Yarnall H.4.1

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

unsigned long hashPassword(string password) {
    unsigned long hash = 0;
    for (char c :password){
        hash = hash * 31 + (unsigned char)c;
    }
    return hash;
}

struct SaltedUserRecord {
string username;
unsigned long hashedPassword;
string salt;
};

string generateSalt(int length) {
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string s = "";
    for (int i = 0; i < length; i++) {

      int index = rand() % characters.length();
        s = s+ characters[index];
       
    }
    return s;
}


    SaltedUserRecord registerUser(string username, string password){
    SaltedUserRecord newrecord;
    newrecord.username = username;

    //unsigned long hashPassword(password);

    newrecord.hashedPassword = hashPassword(password);

    cout << "The User [ " << newrecord.username << " ] stored. User's Hash is [ " << newrecord.hashedPassword << " ]" << endl;


return newrecord;
}

bool loginUser(SaltedUserRecord user, string attemptedPassword) {
    unsigned long attemptedHash = hashPassword(attemptedPassword);

    if (attemptedHash == user.hashedPassword){
        cout<< "Login Successful" << endl;
        return true;
    }
    else{
            cout << "Login Failed" << endl;
            return false;
        }
    }

/*
int loginUser(){

    string username1;
    string userpass;

    string username2;
    string userpass2;

    string username3;
    string userpass3;


    cout << "Please Enter Your Username: ";
    cin >>  username1;
    cout << endl;
    cout << "Please Enter Your Password: " ;
    cin >> userpass;
    cout << endl;

    cout << "Please Enter Your Username: ";
    cin >>  username2;
    cout << endl;
    cout << "Please Enter Your Password: " ;
    cin >> userpass2;
    cout << endl;

    cout << "Please Enter Your Username: ";
    cin >>  username3;
    cout << endl;
    cout << "Please Enter Your Password: " ;
    cin >> userpass3;
    cout << endl;

    unsigned long result = hashPassword(userpass);
    unsigned long result2 = hashPassword(userpass2);
    unsigned long result3 = hashPassword(userpass3);
   

        cout << username1 << ": your password hash is: " << result << endl;
        cout << username2 << ": your password hash is: " << result2 << endl;
        cout << username3 << ": your password hash is: " << result3 << endl;



}*/

int main(){

    srand(time(0));

  SaltedUserRecord alice = registerUser("alice", "securePass99!");

    
    cout << "Logging In" << endl;
    string attempt;
    cout << "Enter password to login: ";
    cin >> attempt;

    loginUser(alice, attempt); 

    SaltedUserRecord bob = registerUser("bob", "securePass99!");

    
    cout << "Logging In" << endl;
    string bobattempt;
    cout << "Enter password to login: ";
    cin >> bobattempt;

    loginUser(bob, bobattempt); 
    return 0;
}




