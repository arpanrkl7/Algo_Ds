#include <iostream>
#include <climits>

using namespace std;

main(int argc,char** argv){

    char input;
    cin >> input;

    cout << CHAR_MAX;
    cout << CHAR_MIN;
    

    if(input >='a' & input <='z'){
        cout << "lowercase" <<endl;
        cout <<(char)( 'A' + (input -'a')) << endl;
    }
    else if(input >='A' & input <='Z'){
        cout << "Upercase" << endl;
        cout <<(char)( 'a' + (input -'A')) << endl;
    }
    else{

    }
}