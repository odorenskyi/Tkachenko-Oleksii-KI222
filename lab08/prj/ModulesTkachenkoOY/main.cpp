#include <cmath>
#include <iostream>
#include <iomanip>

#define PI 3.14

struct results{
    float totalWage, processedWage, totalTax;
    std::string sockSizeEU;
    int sockSizeUS, numberOfBits, typeOfBits;

};

float s_calculation(float x, float y, float z){
    float s = round(pow( 2*z+1 , x) * 100)/100 - round(sqrt(abs(y - z/2))*100)/100 + z + PI;
    return s;
}

results wagePaid(int a = 0, int b = 0, int c = 0, int d = 0 , int e = 0)
{
    int workHours[5] {a, b, c, d, e};
    int totalWage;
    float totalTax;
    if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
        std::cout << "���i����� ����i�� ஡��i ������ � �����i��� �� �'�⭨��, ஧�i���� �� ���᪠��ﬨ Enter" <<std::endl;
    for(int i=0;i<5;i++){
         if(workHours[i] == 0){
          std::cin >> workHours[i];
         }
         if(workHours[i] > 8){
            totalWage+=300;
         }
         totalWage+=workHours[i]*40;
    }
    totalTax = totalWage * 0.186;
    results wageResults;
    wageResults.totalWage = totalWage;
    wageResults.totalTax = totalTax;
    wageResults.processedWage = totalWage - totalTax;
    return wageResults;
};

results maleSocksSizeConvert(int sockSize = 0){
    results sockSizes;
    if (sockSize == 0){
        std::cout << "����i�� ஧�i� 誠௥⮪(�ਬi⪠: �i�� �᫮ �i� 23 �� 31)" << std::endl;
        std::cin >> sockSize;
    }
    if(sockSize>=23 && sockSize<=31){
        switch (sockSize){
            case 23:
                sockSizes.sockSizeEU = "37/38"; sockSizes.sockSizeUS = 8;
                break;
            case 25:
                sockSizes.sockSizeEU = "39/40"; sockSizes.sockSizeUS = 9;
                break;
            case 27:
                sockSizes.sockSizeEU = "41/42"; sockSizes.sockSizeUS = 10;
                break;
            case 29:
                sockSizes.sockSizeEU = "43/44"; sockSizes.sockSizeUS = 11;
                break;
            case 31:
                sockSizes.sockSizeEU = "45/46"; sockSizes.sockSizeUS = 12;
                break;
        }
    }
    return sockSizes;
}
results bitInNumber(int num = -1){
    results bitResults;
    int counter = 0;
    int N7;
    if(num == -1){
        std::cout << "����i�� �i�� �᫮ �i� 0 �� 7483650"<<std::endl;
        std::cin >> num;
    }
    N7 = (num >> 6)& 1;
    if(N7){
        while (num) {
            counter += !(num & 1);
            num >>= 1;
        }
        bitResults.typeOfBits = 0;
    } else{
        while (num) {
            counter += num & 1;
            num >>= 1;
        }
        bitResults.typeOfBits = 1;
    }
    bitResults.numberOfBits = counter;
    return bitResults;
}
