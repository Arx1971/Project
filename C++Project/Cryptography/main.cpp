#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <sstream>
#include <cstdio>
#include <fstream>
#include <iostream>

#define N 100000

using namespace std;

vector < int > primeholder;
bool sieve[N];
void sieve_method();
ifstream instream;
ofstream outstream;


class Encryption                    ///Encryption class
{
private:                            ///Private Members
    string encriptstring;
    string encpass;

public:                             ///Public Members
    Encryption(string , string);
    Encryption();
    char buffer[N];
    int b[N];
    string pattern[N];
    void setencriptingstring(string);
    string getencriptingstring();
    void setencpass(string);
    bool getencpass();
    void show();
    void input();
    void getlettertoprime();
    void primeto90();
    vector < int > wordprime;
};
class Decryption                        ///Decryption Class
{
private:                                ///Private members
    string decpass;
    string decstring;
public:                                 ///Public members
    void input();
    void show();
    vector < string > words;
    string word;
    int carry[100];
    char *pEnd;
    void basechange();
    int placeholder[1000];
    void findplace();
    void setdecpass(string);
    bool getdecpass();
};
void Decryption :: setdecpass(string pass){
    this->decpass = pass;
}
bool Decryption :: getdecpass(){
    if(decpass == "4321")
        return true;
    else
        return false;

}
void Decryption :: input(){                     ///input function for decryption

    getline(cin,decstring);

    istringstream iss(decstring);

    while(iss >> word) {
        words.push_back(word);
    }

    basechange();
}
void Decryption :: basechange(){               ///Number base change function(33 - 10)

    for(int i=0; i<words.size(); i++){
        carry[i] = strtol (words[i].c_str(), &pEnd, 33);
    }
}
void Decryption :: findplace(){                ///Number position
    primeholder.clear();
    memset(sieve,true,sizeof sieve);
    sieve_method();
    for(int i=1; i<10000; i++){                ///Insert values to the vector
        if(sieve[i]==true)
            primeholder.push_back(i);
    }

    for(int i=0; i<words.size(); i++){
        for(int j=0; j<primeholder.size(); j++){
            if(carry[i]==primeholder[j]){
                placeholder[i] = j;
                break;
            }
        }
    }
}

void Decryption :: show(){
    findplace();

    cout << endl <<"Decrypted String IS: ";

    for(int i=0; i<words.size(); i++){
        cout << (char)placeholder[i];
    }

    cout << endl;

    word.clear();
    words.clear();
}
                                            ///Encryption

void Encryption :: setencpass(string pass){
    this->encpass = pass;
}
bool Encryption :: getencpass(){
    if(encpass == "1234")
        return true;
    else
        return false;

}

Encryption :: Encryption(){                                         ///Default constructor

}
Encryption:: Encryption(string encriptstring, string encpass){     /// Parameterized Constructor
        this->encpass = encpass;
        this->encriptstring = encriptstring;

}
void Encryption :: setencriptingstring(string encriptstring){       /// Mutator method
    this->encriptstring = encriptstring;
}
string Encryption :: getencriptingstring(){                         /// Accessor method
    return encriptstring;
}

void Encryption :: getlettertoprime(){         ///Interchange the number values to the prime

    primeholder.clear();

    memset(sieve,true,sizeof sieve);
    sieve_method();
    for(int i=1; i<10000; i++){                ///Insert the values to the vector
        if(sieve[i]==true)
            primeholder.push_back(i);
    }
    for(int i=0; i<encriptstring.size(); i++){
            b[i] = encriptstring[i];// - 'A' + 1;
    }
     for(int i=0; i<encriptstring.size(); i++){ ///word contained prime number holder
        wordprime.push_back(primeholder[b[i]]);
    }
}

void Encryption :: primeto90(){                 ///change the number base

    for(int i=0; i<wordprime.size(); i++){
        pattern[i].clear();
    }

    for(int i=0; i<wordprime.size(); i++){
        itoa(wordprime[i],buffer,33);           ///using built-in function for change number base

        for(int j=0; j<strlen(buffer); j++){
            pattern[i].push_back(buffer[j]);    ///using 2d string to hold all the number
        }
    }
}

void Encryption :: show(){                      ///show function for output

    getlettertoprime();
    primeto90();

    cout << endl << "Encrypted String Is: ";

    for(int i=0; i<wordprime.size(); i++){

        //outstream << pattern[i] << " ";

        cout << pattern[i] << " ";
    }
    cout << endl;

    wordprime.clear();
    primeholder.clear();
    for(int i=0; i<wordprime.size(); i++){
        pattern[i].clear();
    }
}
void sieve_method(){              ///Prime Generator Using Sieve Method

    for(int i=2; i<N; i++){
        for(int j=2*i; j<N; j+=i){
            sieve[j] = false;
        }
    }
}
void  welcome_massage(){

    char date[9];
	_strdate(date);

    cout << "Adnan H Rahin." << endl << endl;
    cout << "MAC125." << endl << endl;
    cout << date << endl << endl;
    cout << "Prof. Doyel Pal." << endl << endl << endl;
    cout << "\t\t\t--------------------------------" << endl;
    cout << "\t\t\t|  Project Name: Cryptography. |" << endl;
    cout << "\t\t\t________________________________" << endl;
    cout << endl;
}

int main()                                     /// main function
{
    Encryption encword;
    Decryption decword;
    string massage,pass;
    char n1[10];
    welcome_massage();
    int select;

    //instream.open("infile.txt", ios::app);
    //outstream.open("outfile.txt", ios::app);

    while(true){

        cout << "1 - Press 1 For Encryption: " << endl << endl;
        cout << "2 - Press 2 For Decryption: " << endl << endl;
        cout << "3 - Press 3 For Exit: " << endl << endl;

        cin >> select;

        gets(n1);

        if(select == 1){

            cout << "You select a Key for the Encryption. " << endl << endl;
            cout << "Please Enter The Password For The Encryption: " << endl << endl;
            getline(cin, pass);
            encword.setencpass(pass);
            if(encword.getencpass() == true){

                cout << "Please Enter Your String: ";
                getline(cin, massage);
                //instream >> massage;
                encword.setencriptingstring(massage);
                encword.show();
                }
            }

        else if(select == 2){
            cout << "You select a Key for the Decryption. " << endl << endl;
            cout << "Please Enter The Password For The Decryption: " << endl << endl;
            getline(cin ,pass);
            decword.setdecpass(pass);
            if(decword.getdecpass() == true){

                cout << "Please Enter Your String: ";
                decword.input();
                decword.show();
            }
        }
        else if(select == 3)
                exit(0);

        cout << endl << endl;

        system("pause");

        cout << endl << endl;

        //instream.close();
        //outstream.close();
    }
    return 0;
}
