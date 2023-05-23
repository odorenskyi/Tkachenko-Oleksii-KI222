#ifndef MODULESTKACHENKOOY_H_INCLUDED
#define MODULESTKACHENKOOY_H_INCLUDED

struct results{
    float totalWage, processedWage, totalTax;
    std::string sockSizeEU;
    int sockSizeUS, numberOfBits, typeOfBits;
};
float s_calculation(float x, float y, float z);
results wagePaid(int a = 0, int b = 0, int c = 0, int d = 0 , int e = 0);
results maleSocksSizeConvert(int sockSize = 0 );
results bitInNumber(int num = -1);
int task10_1_fFunc(std::string iFileName, std::string oFileName);
int task10_2_fFunc(std::string oFileName);
int task10_3_fFunc(std::string oFileName, float x = 0, float y = 0, float z = 0, size_t b = 0);
#endif // MODULESTKACHENKOOY_H_INCLUDED
