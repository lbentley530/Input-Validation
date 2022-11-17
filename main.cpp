#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

char get_char_from_user();
string get_word_from_user();
string get_sentence_from_user();
int get_int_from_user();
double get_float_from_user();

int main() {
    char letter = get_char_from_user();
    cout << "You entered the character " << letter << endl;
    string word = get_word_from_user();
    cout << "You entered the word " << word << endl;
    string sentence = get_sentence_from_user();
    cout << "You entered the sentence: " << sentence << endl;
    int num = get_int_from_user();
    cout << "You entered the number " << num << endl;
    double flo = get_float_from_user();
    cout << "You entered the floating-point number " << flo << endl;
    return 0;

}

char get_char_from_user() {

    string tString;
    char input;
    char temp;

    cout << "Enter a single character: ";
    getline(cin, tString);

    if (tString.empty() ) {
        cout << "No input. ";
        tString = get_char_from_user();
    }

    if ( (tString.length()) == 1 ) {
        input = tString.at(0);
    } else {
        cout << "Invalid input. ";
        tString = get_char_from_user();
    }

    input = tString.at(0);
    return input;

}

string get_word_from_user() {

    string tString;
    string input;
    char ws = ' ';

    cout << "Enter a single word: ";
    getline(cin, tString);

    if (tString.empty() ) {
        cout << "No input. ";
        tString = get_word_from_user();
    }

    for ( int i = 0 ; i < tString.length() ; i++ ) {
        if ( isspace(tString.at(i)) ) {
            cout << "Invalid input. ";
            tString = get_word_from_user();
        } else
            input = tString;
    }

    input = tString;
    return input;
}

string get_sentence_from_user() {

    // a string that is read in until the user hits enter/newline

    string tString;
    string input;

    cout << "Enter a sentence: ";
    getline(cin, tString);

    if ( tString.empty() ) {
        cout << "No input. ";
        tString = get_sentence_from_user();
    } else
        input = tString;

    input = tString;
    return input;
}

int get_int_from_user() {

    string toValidate = "";
    stringstream ss;
    bool notValid = true;
    int tInt;
    double input;

    cout << "Enter a integer: ";
    getline(cin, toValidate);


    if ( toValidate.empty() ) {

        cin.clear();
        cout << "No input. ";
        input = get_int_from_user();

    } else {

        for ( int i = 0 ; i < toValidate.length() ; i++ ) {
            if (isalpha(toValidate.at(i)) ) {
                notValid = false;
            }
        }

        ss << toValidate;

        if ( ( ss >> tInt).fail() || notValid  == false ) {
            cin.clear();
            ss.clear();
            cout << "Invalid input. ";
            input = get_int_from_user();
        } else {
            // ss >> tFloat;
            input = tInt;
        }

    }

    return input;

}

double get_float_from_user() {

    string toValidate;
    bool notValid = true;
    stringstream ss;
    double tFloat;
    double input;

    cout << "Enter a floating-point number: ";
    getline(cin, toValidate);

    if ( toValidate.empty() ) {

        cin.clear();
        cout << "No input. ";
        input = get_float_from_user();

    } else {

        for ( int i = 0 ; i < toValidate.length() ; i++ ) {
            if (isalpha(toValidate.at(i)) ) {
                notValid = false;
            }
        }

        ss << toValidate;

        if ( ( ss >> tFloat).fail() || notValid == false ) {
            cin.clear();
            ss.clear();
            cout << "Invalid input. ";
            input = get_float_from_user();
        } else {
            // ss >> tFloat;
            input = tFloat;
        }

    }

    return input;

}
