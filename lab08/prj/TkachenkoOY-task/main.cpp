#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ModulesTkachenkoOY.h>

using namespace std;

float decHexSFunc(float x, float y, float z){
    float s = s_calculation(x, y, z);
    cout <<"x, y ,z � ��������� ������ ��������: " <<endl << (int)x <<endl<<(int)y <<endl<<(int)z<< endl<<endl
         <<"x, y, z � �������������� ������ ��������: "<<endl << hex << (int)x <<endl<<(int)y <<endl<<(int)z<< endl<<endl
         <<"s = ";
    return s;
}

string isGreater(char a, char b){
    string result = "(a + 1 >= b) ���������: ";
    return result +  (a+1>= b ? "true" : "false");
}

string copyrightDeveloper(){
    return "            |------------------------------|\n"
           "            | �������� �����i� ��i����� (�)|\n"
           "            |------------------------------|\n\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float x, y, z;
    char a, b;
    cout << copyrightDeveloper();

    cout << "����i�� ����i����� ����� x, y, z �� ������� a, b, ����i����� �� �������� ��� Enter: ";
    cin >> x >> y >> z >> a >> b;
    cout << isGreater(a, b) <<endl;
    cout << decHexSFunc(x,y,z)<< endl;
    cout << "������i�� Enter ��� ����������...";
    cin.get();
    cin.get();
    return 0;
}
