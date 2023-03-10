#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ModulesTkachenkoOY.h>

using namespace std;

float decHexSFunc(float x, float y, float z){
    float s = s_calculation(x, y, z);
    cout <<"x, y ,z у десятковій системі числення: " <<endl << (int)x <<endl<<(int)y <<endl<<(int)z<< endl<<endl
         <<"x, y, z у шістнадцятковій системі числення: "<<endl << hex << (int)x <<endl<<(int)y <<endl<<(int)z<< endl<<endl
         <<"s = ";
    return s;
}

string isGreater(char a, char b){
    string result = "(a + 1 >= b) результат: ";
    return result +  (a+1>= b ? "true" : "false");
}

string copyrightDeveloper(){
    return "            |------------------------------|\n"
           "            | Ткаченко Олексiй Юрiйович (©)|\n"
           "            |------------------------------|\n\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float x, y, z;
    char a, b;
    cout << copyrightDeveloper();

    cout << "Введiть послiдовно числа x, y, z та символи a, b, роздiляючи їх пробілами або Enter: ";
    cin >> x >> y >> z >> a >> b;
    cout << isGreater(a, b) <<endl;
    cout << decHexSFunc(x,y,z)<< endl;
    cout << "Натиснiть Enter для завершення...";
    cin.get();
    cin.get();
    return 0;
}
