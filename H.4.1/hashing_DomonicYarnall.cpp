
//Domonic Yarnall H.4.1

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
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
    newrecord.salt = generateSalt(8);

    string combine = password + newrecord.salt;

    newrecord.hashedPassword = hashPassword(combine);

    cout << "The User [ " << newrecord.username << " ] stored. User's Hash is [ " << newrecord.hashedPassword << " ]" << endl;


return newrecord;
}

bool loginUser(SaltedUserRecord user, string attemptedPassword) {
    string combinedAttempt = attemptedPassword + user.salt;
    unsigned long attemptedHash = hashPassword(combinedAttempt);

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

    SaltedUserRecord bob = registerUser("bob", "123456");

    
    cout << "Logging In" << endl;
    string bobattempt;
    cout << "Enter password to login: ";
    cin >> bobattempt;

    loginUser(bob, bobattempt); 

    SaltedUserRecord carol = registerUser("carol", "123456");

    
    cout << "Logging In" << endl;
    string carolattempt;
    cout << "Enter password to login: ";
    cin >> carolattempt;

    loginUser(carol, carolattempt); 

    //Bonus +4


    string blandPassword = "abcd"; 
unsigned long blandHash = hashPassword(blandPassword); 

string saltedPassword = "abcd";
string salt = "abc12345"; 
unsigned long saltedHash = hashPassword(saltedPassword + salt);

string target = "abcd"; 
unsigned long targetHash = hashPassword("abcd" + alice.salt);

auto startSalted = chrono::high_resolution_clock::now();

    bool foundSalted = false;
    for (char c1 = 'a'; c1 <= 'z' && !foundSalted; c1++) {
    for (char c2 = 'a'; c2 <= 'z' && !foundSalted; c2++) {
    for (char c3 = 'a'; c3 <= 'z' && !foundSalted; c3++){
    for (char c4 = 'a'; c4 <= 'z' && !foundSalted; c4++){
        string guess = "";
        guess += c1; guess += c2; guess += c3; guess += c4;

        if (hashPassword(guess + alice.salt) == targetHash) {
                    cout << "Found it! Password is: " << guess << endl;
                   foundSalted=true;
        
            }
        }
    }
}
auto endSalted = chrono::high_resolution_clock::now();

string target2 = "abcd"; 
unsigned long targetHash2 = hashPassword("abcd");

auto startBland = chrono::high_resolution_clock::now();

    bool found = false;
    for (char c1 = 'a'; c1 <= 'z' && !found; c1++) {
    for (char c2 = 'a'; c2 <= 'z' && !found; c2++) {
    for (char c3 = 'a'; c3 <= 'z' && !found; c3++){
    for (char c4 = 'a'; c4 <= 'z' && !found; c4++){
        string guess2 = "";
        guess2 += c1; guess2 += c2; guess2 += c3; guess2 += c4;

       if (hashPassword(guess2) == blandHash) { 
            cout << "Bland password found!" << endl;
            found = true;
       }
        
            }
        }
    }
}

auto endBland = chrono::high_resolution_clock::now();

chrono::duration<double> Salted = endSalted - startSalted;
chrono::duration<double> Bland = endBland - startBland;


cout << "Salted cracking took: " << Salted.count() << " seconds." << endl;
cout << "Bland cracking took: " << Bland.count() << " seconds." << endl;


    return 0;
}




