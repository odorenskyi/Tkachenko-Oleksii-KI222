#include <iostream>
#include <fstream>
#include <filesystem>
#include <Class12_Tkachenko_Header.h>

 using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    ofstream testResults("../../TestSuite/TestResults.txt", ios_base::out|ios::binary);
    try{
    if(!(testResults.is_open())){
        throw(1);
    }
    } catch (int exc){
        cout<<"Не вдалось відкрити файл...";
        getchar();
        return 0;
    }

    string curDir = __FILE__;
    if (curDir.find("\\lab12\\prj") == string::npos){
        for(int i = 0; i<100; i++){
            cout<<'\a';
        }
    } else{
        ifstream unit("../../TestSuite/unitTests.txt", ios_base::in|ios::binary);
        try{
            if (!(unit.is_open())){throw(1);}
        } catch(int exc){
            cout<< "Файлу unitTests.txt не існує...";
            getchar();
            return 0;
        };


        string line;
        int elemNumber = 0;
        getline(unit, line);
        Class12_Tkachenko newObject(0,0);
        attributes atrLst;
        int gotRight;
        while(getline(unit, line, '\t')){
            switch(elemNumber%4){
            case 0:
                gotRight = 0;
                if(newObject.setSize("width", stoi(line))){
                    atrLst = newObject.returnAttributes();
                    if (atrLst.mmWidth == stoi(line)){
                        gotRight++;
                    }
                };
                break;
            case 1:
                if(newObject.setSize("height", stoi(line))){
                    atrLst = newObject.returnAttributes();
                    if (atrLst.mmHeight == stoi(line)){
                        gotRight++;
                    }
                };
                break;
            case 2:
                newObject.changeText(line);
                atrLst = newObject.returnAttributes();
                if (atrLst.boardText == line){
                    gotRight++;
                }
                break;
            case 3:
                if (newObject.mmReturnSquare() == stoi(line)){
                    gotRight++;
                }
                if (gotRight == 4){
                    testResults << "unit test #" <<(elemNumber+1)/4<<": passed\n";
                }   else{
                    testResults << "unit test #" <<(elemNumber+1)/4<<": failed\n";
                }
                break;
            }
            elemNumber ++;
        }
    }
}
