#ifndef CLASS12_TKACHENKO_HEADER_H_INCLUDED
#define CLASS12_TKACHENKO_HEADER_H_INCLUDED
#include <string>
struct attributes{
    int mmHeight = 0, mmWidth = 0;
    std::string boardText;
};

class Class12_Tkachenko{
    public:
        int mmReturnSquare();
        int setSize(std::string type, int mmNewSize);
        int setSize(int mmNewHeight, int mmNewWidth);

        void changeText(std::string newText="Тут могла б бути ваша реклама");

        attributes returnAttributes(std::string type = "all");
        attributes returnAttributes(std::string type1, std::string type2);

        Class12_Tkachenko(int mmWidth, int mmHeight, std::string boardText = "Тут могла б бути ваша реклама" );
    private:
        int width;
        int height;

        std::string text;
};

#endif // CLASS12_TKACHENKO_HEADER_H_INCLUDED
