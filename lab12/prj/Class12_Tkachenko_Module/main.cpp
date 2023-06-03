#include <string>
#include <Class12_Tkachenko_Header.h>


Class12_Tkachenko::Class12_Tkachenko(int mmWidth, int mmHeight, std::string boardText){
    height = mmHeight;
    width = mmWidth;
    text = boardText;
};

int Class12_Tkachenko::mmReturnSquare(){
    return width * height;
};

void Class12_Tkachenko::changeText(std::string newText){
    text = newText;
    return;
};

int Class12_Tkachenko::setSize(int mmNewHeight, int mmNewWidth){
    if (mmNewHeight > 0 && mmNewWidth > 0 ){
        width = mmNewWidth;
        height = mmNewHeight;
        return 1;
    }
    return 0;
};

int Class12_Tkachenko::setSize(std::string type, int mmNewSize){
    if (mmNewSize > 0)
        if(type == "width"){
            width = mmNewSize;
        } else if(type == "height"){
            height = mmNewSize;
        } else  {
            return 0;
        }
        return 1;
    return 0;
}

attributes Class12_Tkachenko::returnAttributes(std::string type){
    attributes atrLst;
    if(type == "all"){
        atrLst.mmWidth = width;
        atrLst.mmHeight = height;
        atrLst.boardText = text;
    } else if (type == "width"){
        atrLst.mmWidth = width;
    } else if (type == "height"){
        atrLst.mmHeight = height;
    } else if (type == "text"){
        atrLst.boardText = text;
    }
    return atrLst;
};
attributes Class12_Tkachenko::returnAttributes(std::string type1, std::string type2){
    attributes atrLst;
    if (type1 == "width" || type2 == "width"){atrLst.mmWidth = width;}
    if (type1 == "height" || type2 == "height" ){atrLst.mmHeight = height;}
    if (type1 == "text" || type2 == "text"){atrLst.boardText = text;}
    return atrLst;
};
