#include <iostream>
#include <vector>
using namespace std;

class SpecialSymbols{
    static const vector<wchar_t> m_listEnglish;
    static const vector<wchar_t> m_listUkrainian;
    wchar_t m_character;
public:
    SpecialSymbols(wchar_t character) : m_character(character){}

    wchar_t getCharacter(){
        return m_character;
    }

    friend bool operator==(SpecialSymbols &ss1, SpecialSymbols &ss2);
    friend bool operator==(SpecialSymbols &ss1, wchar_t s2);
    friend bool operator==(wchar_t s1, SpecialSymbols &ss2);

    friend bool operator!=(SpecialSymbols &ss1, SpecialSymbols &ss2);
    friend bool operator!=(SpecialSymbols &ss1, wchar_t s2);
    friend bool operator!=(wchar_t s1, SpecialSymbols &ss2);
};

const vector<wchar_t> SpecialSymbols::m_listEnglish = { 'O', 'A', 'I', 'E', 'H', 'C', 'B', 'K', 'P', 'X', 'T', 'M' };
const vector<wchar_t> SpecialSymbols::m_listUkrainian = { U'О', U'А', U'І', U'Е', U'Н', U'С', U'В', U'К', U'Р', U'Х', U'Т', U'М' };

bool operator==(SpecialSymbols &ss1, SpecialSymbols &ss2){
    wchar_t s1 = ss1.m_character;
    return (s1 == ss2);
}
bool operator==(SpecialSymbols &ss1, wchar_t s2) {
    return (s2 == ss1);
}
bool operator==(wchar_t s1, SpecialSymbols &ss2) {
    wchar_t s2 = ss2.m_character;
    for(int i = 0; i < SpecialSymbols::m_listEnglish.size(); ++i){
        if(s1 == SpecialSymbols::m_listEnglish[i]){
            if((s1 == s2) || (s2 == SpecialSymbols::m_listUkrainian[i])){
                return true;
            }
        }
    }
    for(int i = 0; i < SpecialSymbols::m_listUkrainian.size(); ++i){
        if(s1 == SpecialSymbols::m_listUkrainian[i]){
            if((s1 == s2) || (s2 == SpecialSymbols::m_listEnglish[i])){
                return true;
            }
        }
    }
    return false;
}

bool operator!=(SpecialSymbols &ss1, SpecialSymbols &ss2) {
    wchar_t s1 = ss1.m_character;
    return !(s1 == ss2);
}
bool operator!=(SpecialSymbols &ss1, wchar_t s2) {
    return !(s2 == ss1);
}
bool operator!=(wchar_t s1, SpecialSymbols &ss2) {
    return !(s1 == ss2);
}

int main()
{
    std::locale::global(std::locale(""));

    wchar_t firstCharacter;
    wprintf(L"Введіть перший символ : ");
    wscanf(L"%lc", &firstCharacter);
    SpecialSymbols ss1(firstCharacter);

    wcin.clear();
    wcin.ignore();

    wchar_t secondCharacter = 0;
    wprintf(L"Введіть другий символ : ");
    wscanf(L"%lc", &secondCharacter);
    SpecialSymbols ss2(secondCharacter);


    wprintf(L"\nРезультат роботи оператора == класу SpecialSymbols для %lc та %lc :\n", ss1.getCharacter(), ss2.getCharacter());
    if(ss1 == ss2){
        wprintf(L"Символи є особливими та дорівнюють один одному !\n");
    }
    else{
        wprintf(L"Символи або не є особливими,  або є особливими та не рівні один одному !\n");
    }



    wprintf (L"\nРезультат роботи оператора != класу SpecialSymbols для %lc та %lc :\n", ss1.getCharacter(), ss2.getCharacter());
    if(ss1 != ss2){
        wprintf(L"Символи або не є особливими,  або є особливими та не рівні один одному !\n");
    }
    else{
        wprintf(L"Символи є особливими та дорівнюють один одному !\n");
    }

}
