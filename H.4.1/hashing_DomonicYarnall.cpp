
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

int main(){

    string username;
    string userpass;


    cout << "Please Enter Your Username: ";
    cin >>  username;
    cout << endl;
    cout << "Please Enter Your Password: " ;
    cin >> userpass;
    cout << endl;

    unsigned long result = hashPassword(userpass);
   

    cout << "Your password hash is: " << result << endl;



    return 0;
}

