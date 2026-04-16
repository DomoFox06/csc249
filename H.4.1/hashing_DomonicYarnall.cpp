
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

    UserRecord registerUser(string username, string password){
    UserRecord newrecord;
    newrecord.username = username;

    unsigned long hashPassword(password);

    newrecord.hashPassword = hashPassword(password);

    cout << "The User [ " << newrecord.username << " ] stored. User's Hash is [ " << newrecord.hashPassword << " ]" << endl;


return newrecord;
}

bool loginUser(UserRecord user, string attemptedPassword, string password) {
    unsigned long attemtedPassword;
    if (hashPassword(attemptedPassword)==hashPassword(password)){
        cout<< "Login Successful" << endl;
        return true;
        else{
            cout << "Login Failed" << endl;
            return false;
        }
    }
}

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



}

int main(){

    int registerUser();
    int loginUser();
    
    return 0;
}


