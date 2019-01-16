#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int convertirStringToInt(string v){
    // proceso para convertir un cadena en entero

    int i;
    std:: istringstream(v) >> i;
    return i;
}

int main()
{
    string s;
    int sum = 0 ;
    ifstream f( "t2.txt" );
    if ( f.is_open() )
    {
        // getline( f, s );

        while( !f.eof() )
        {
            getline( f, s );
            if (convertirStringToInt(s) % 2 == 0) {
            sum = sum + convertirStringToInt(s);
            cout << s << endl;
        }
        }
    }else{
        cout << "Error de apertura del archivo." << endl;
    }
     cout << sum << endl;
    return 0;
}
