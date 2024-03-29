#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <bitset>
#include <cstdlib>
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
        std::cout << "����i����� ����i�� �����i ������ � �����i��� �� �'������, ����i����� �� ������������ Enter" <<std::endl;
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
        std::cout << "����i�� ����i� ���������(����i���: �i�� ����� �i� 23 �� 31)" << std::endl;
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
        std::cout << "����i�� �i�� ����� �i� 0 �� 7483650"<<std::endl;
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



int task10_1_fFunc(std::string iFileName, std::string oFileName){
    srand((int)time(0));
    try{
        std::ifstream iFile(iFileName, std::ios_base::in | std::ios::binary);
        if(!iFile.is_open()){throw(1);}
        std::ofstream oFile(oFileName, std::ios_base::out | std::ios::binary);
        if(!oFile.is_open()){throw(0);}

        oFile << "���������: �����i� ��������\n�����i���i�: ����\n�i���, �����: �������������, ������\n�i� ��������: 2023\n"
              << (rand()%90)+10 << " - ��������� ����� �� 10 �� 100"<<'\n';
        std::string s;
        std::string myText;
        std::string sArr[300];
        std::string pcArr[6] {",", ".", ".", ".", ",", "."};
        while (getline (iFile, myText)) {
            s = s + myText;
        }
        int arrCounter = 0;
        std::string buffer;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ','){
                sArr[arrCounter] = buffer;
                arrCounter++;
                buffer.clear();
                sArr[arrCounter] = ",";
                arrCounter++;
            } else if(s[i] == '.'){
                sArr[arrCounter] = buffer;
                arrCounter++;
                buffer.clear();
                sArr[arrCounter] = ".";
                arrCounter++;
            } else if(s[i] == ' '){
                continue;
            } else{
                buffer +=s[i];
            }
        }
        bool isErr = false;
        for(int pcArrCounter = 0, arrCounter = 1; pcArrCounter<6;pcArrCounter++, arrCounter+=2){
            if(sArr[arrCounter] != pcArr[pcArrCounter]){
                isErr = true;
                break;
            }
        }
        if(isErr){
            oFile << "������� ���� ������ ������������ �������"<<'\n';
        }else {oFile << "������� ���� �� ������ ������������� �������" << '\n';}
        oFile.close();
        iFile.close();
        return 1;
    }
    catch(int erNum){
        switch(erNum){
        case 0:
            std::cout << "�� ������� �������� ����\n";
            break;
        case 1:
            std::cout << "������� ���� �� ����\n";
            break;
        }
        return 0;
    }
}

int task10_2_fFunc(std::string iFileName){
    char s[12];
    time_t t = time(0);
    strftime(s, 12, "%d.%m.%Y", localtime(&t));
    try{
        std::ifstream itFile(iFileName, std::ios_base::in);
        if(!itFile.is_open()){throw(0);}
        itFile.close();
        std::ofstream iFile(iFileName, std::ios_base::app | std::ios::binary);
        if(!iFile.is_open()){throw(0);}
        iFile << s << '\n';
        iFile.close();
        return 1;
    }
    catch(int erNum){
        std::cout << "������� ���� �� ����\n";
        return 0;
    }
}

std::string binary {""};
void binFunc(size_t b)
{

    if (b > 1)
        binFunc(b / 2);

     binary += std::to_string(b % 2);
}

int task10_3_fFunc(std::string oFileName, float x = 0, float y = 0, float z = 0, size_t b = 0){
    if(x == 0){
        std::cout << "������ x(����� �����): " << '\n';
        std::cin >> x;
    }
    if(y == 0){
        std::cout << "������ y(����� �����): " << '\n';
        std::cin >> y;
    }
    if(z == 0){
        std::cout << "������ z(����� �����): " << '\n';
        std::cin >> z;
    }
    if(b == 0){
        std::cout << "������ b(���������� �����): " << '\n';
        std::cin >> b;
    }
    try{
        std::ofstream oFile(oFileName, std::ios_base::app | std::ios::binary);
        if(!oFile.is_open()){throw(0);}
        binFunc(b);
        oFile << s_calculation(x,y,z)<<" - ��������� ������ ������� s_calculation()" << '\n' << binary << '\n';
        oFile.close();
        binary = "";
        return 1;
    }
    catch(int erNum){
        std::cout << "�� ������� �������� ��� ������� ����\n";
        return 0;
    }
}
