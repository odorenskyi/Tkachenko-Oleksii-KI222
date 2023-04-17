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
        cout<< "Введiть v для виклику функцiї s_calculation\nВведiть n для виклику функцiї wagePaid\n"
            << "Введiть m для виклику функцiї maleSocksSizeConvert\nВведiть q для виклику функцiї bitInNumber\n"
            << "Введiть w або W для завершення програми\n\n";
        cin >> choice;
        switch(choice){
        case 'v':
            cout << "Введiть послiдовно числа x, y, z, роздiляючи їх пробiлами або Enter: ";
            cin >> x >> y >> z;
            cout << "Результат: "<<s_calculation(x, y, z)<< endl;
            break;
        case 'n':
            funcResults = wagePaid();
            cout <<"Всього зарплатнi: "<< funcResults.totalWage<<endl<<"Всього податкiв: "<<funcResults.totalTax<<endl
            <<"Сума зарплатнi враховуючи податки: "<<funcResults.processedWage<<endl<<endl;
            break;
        case 'm':
            funcResults = maleSocksSizeConvert();
            cout <<"Розмiр таких шкарпеток в ЄС: "<<funcResults.sockSizeEU<<endl
                 <<"Розмiр таких шкарпеток в США: "<< funcResults.sockSizeUS<<endl<<endl;
            break;
        case 'q':
            funcResults = bitInNumber();
            cout <<"Кiлькiсть бiтiв '"<<funcResults.typeOfBits<<"' у вашому числi - "<<funcResults.numberOfBits<<endl<<endl;
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
