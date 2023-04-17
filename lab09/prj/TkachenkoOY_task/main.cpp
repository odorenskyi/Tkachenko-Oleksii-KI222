#include <iostream>
#include <ModulesTkachenkoOY.h>

using namespace std;

int main()
{
    results funcResults;
    bool killSwitch = true;
    char choice;
    float x, y, z;
    while(killSwitch){
        cout<< "����i�� v ��� ������� �㭪�i� s_calculation\n����i�� n ��� ������� �㭪�i� wagePaid\n"
            << "����i�� m ��� ������� �㭪�i� maleSocksSizeConvert\n����i�� q ��� ������� �㭪�i� bitInNumber\n"
            << "����i�� w ��� W ��� �����襭�� �ணࠬ�\n\n";
        cin >> choice;
        switch(choice){
        case 'v':
            cout << "����i�� ���i����� �᫠ x, y, z, ஧�i���� �� �஡i���� ��� Enter: ";
            cin >> x >> y >> z;
            cout << "�������: "<<s_calculation(x, y, z)<< endl;
            break;
        case 'n':
            funcResults = wagePaid();
            cout <<"��쮣� ��௫��i: "<< funcResults.totalWage<<endl<<"��쮣� �����i�: "<<funcResults.totalTax<<endl
            <<"�㬠 ��௫��i ��客��� ����⪨: "<<funcResults.processedWage<<endl<<endl;
            break;
        case 'm':
            funcResults = maleSocksSizeConvert();
            cout <<"����i� ⠪�� 誠௥⮪ � �: "<<funcResults.sockSizeEU<<endl
                 <<"����i� ⠪�� 誠௥⮪ � ���: "<< funcResults.sockSizeUS<<endl<<endl;
            break;
        case 'q':
            funcResults = bitInNumber();
            cout <<"�i��i��� �i�i� '"<<funcResults.typeOfBits<<"' � ��讬� ��i - "<<funcResults.numberOfBits<<endl<<endl;
            break;
        case 'w':
            killSwitch = false;
            break;
        case 'W':
            killSwitch = false;
            break;
        default:
            cout << "\a";
            break;
        }

    }

    return 0;
}
