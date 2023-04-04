#include <cmath>
#include <iostream>
#include <iomanip>
#include <bitset>
#define PI 3.14

struct result{
    float results[3];
};

float s_calculation(float x, float y, float z){
    float s = round(pow( 2*z+1 , x) * 100)/100 - round(sqrt(abs(y - z/2))*100)/100 + z + PI;
    return s;
}

result wagePaid(int a = 0, int b = 0, int c = 0, int d = 0 , int e = 0)
{
    int workHours[5] {a, b, c, d, e};
    int totalWage;
    float totalTax;
    if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
        std::cout << "¬вед≥ть к≥льк≥сть в≥дпрацьованих годин понед≥лок-п'€тниц€, розд≥л€ючи њх натисканн€м Enter" <<std::endl;
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
    result wageResults;
    wageResults.results[0] = totalWage;
    wageResults.results[1] = totalTax;
    wageResults.results[2] = totalWage - totalTax;
    return wageResults;
};

result maleSocksSize(int sockSize = 0){
    result sockSizes;
    if (sockSize == 0){
        std::cout << "¬вед≥ть розм≥р шкарпеток(ѕрим≥тка: ц≥ле число в≥д 23 до 31 включно)" << std::endl;
        std::cin >> sockSize;
    }
    if(sockSize>=23 && sockSize<=31){
        switch (sockSize){
            case 23:
                sockSizes.results[0] = 37; sockSizes.results[1] = 38; sockSizes.results[2] = 8;
                break;
            case 25:
                sockSizes.results[0] = 39; sockSizes.results[1] = 40; sockSizes.results[2] = 9;
                break;
            case 27:
                sockSizes.results[0] = 41; sockSizes.results[1] = 42; sockSizes.results[2] = 10;
                break;
            case 29:
                sockSizes.results[0] = 43; sockSizes.results[1] = 44; sockSizes.results[2] = 11;
                break;
            case 31:
                sockSizes.results[0] = 45; sockSizes.results[1] = 46; sockSizes.results[2] = 12;
                break;
        }
    }
    return sockSizes;
}
int bitInNumber(int num = -1){
    int counter;
    int N7;
    if(num == -1){
        std::cout << "¬вед≥ть ц≥ле число в≥д 0 до 7483650"<<std::endl;
        std::cin >> num;
    }
    N7 = (num >> 6)& 1;
    if(N7){
        while (num) {
            counter += !(num & 1);
            num >>= 1;
        }
    } else{
        while (num) {
            counter += num & 1;
            num >>= 1;
        }
    }
    return counter;
}
