#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int convertirStringToInt(string v){
    // proceso para convertir un cadena en entero

    int i;
    std::istringstream(v) >> i;
    return i;
}


void split(const string& s, char c,
           vector<string>& v) {
   string::size_type i = 0;
   string::size_type j = s.find(c);

   while (j != string::npos) {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}

int main()
{
    int suma = 0;
    string s;
    ifstream f( "datacuatro.txt" );
    if ( f.is_open() )
    {
        // getline( f, s );

        while( !f.eof() )
        {
            vector<string> v;
            getline( f, s );
            split(s, ';', v);


                // cout << v[i];
                for (int i = 0; i < v.size(); ++i) {
                // cout << v[i];

                suma = suma + convertirStringToInt(v[i]);
            }
            if (suma <=  20){
                cout << "regular" << endl;
            }else{
               if(suma >= 20  &&  suma <= 40){
                cout << "bueno" << endl;
               }else{
                    if(suma > 40){
                       cout << "exelente" << endl;
                    }
               }

            }


          //  cout << s << endl;



            // cout << endl;
            // cout << s << endl;

        }
    }else{
        cout << "Error de apertura del archivo." << endl;
    }

    cout << "La suma de los datos es: " << suma << endl;

    return 0;
}
