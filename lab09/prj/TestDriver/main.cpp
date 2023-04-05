#include <iostream>
#include <ModulesTkachenkoOY.h>

using namespace std;

int main()
{
    int inputArr[2][5] {{8, 8, 8, 8, 8}, {9, 2, 9, 10, 1}};
    int input[4] {23, 31, 65, 5789};
    float totalWageOutput[2] { 1600.0, 2140.0 };
    float processedWageOutput[2] { 1302.4, 1741.96 };
    float totalTaxOutput[2] { 297.6, 398.04 };
    string sockSizeEUoutput[2] {"37/38", "45/46"};
    int sockSizeUSoutput[2] {8, 12} , numberOfBitsOutput[2] {5,  8}, typeOfBitsOutput[2] {0, 1};


    for (int i=0;i<6; i++){
        cout << "Test case #"<<i<<" status: ";
        if(i<2){
            results inputFunc = wagePaid(inputArr[i][0], inputArr[i][1],inputArr[i][2],inputArr[i][3],inputArr[i][4]);
            if(inputFunc.totalWage == totalWageOutput[i] && inputFunc.totalTax == totalTaxOutput[i] && inputFunc.processedWage == processedWageOutput[i]){
                cout<<"passed\n";
            }
            else{
                cout<<"failed\n";
            }
        } else if(i>3){
            if(bitInNumber(input[i-2]).numberOfBits == numberOfBitsOutput[i-4] && bitInNumber(input[i-2]).typeOfBits == typeOfBitsOutput[i-4]){
                cout<<"passed\n";
            }
            else{
                cout<<"failed\n";
            }
        } else{
            if(maleSocksSizeConvert(input[i-2]).sockSizeEU == sockSizeEUoutput[i-2] && maleSocksSizeConvert(input[i-2]).sockSizeUS == sockSizeUSoutput[i-2]){
                cout<<"passed\n";
            }
            else{
                cout<<"failed\n";
            }
        }
    }
    return 0;
}
