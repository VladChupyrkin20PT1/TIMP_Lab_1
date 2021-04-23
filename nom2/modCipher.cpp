#include "modCipher.h"

modCipher::modCipher(int k)
{
	this->key=k;
}

std::wstring modCipher::encrypt(modCipher key, std::wstring& open_text)
{
	std::wstring Result;
    const int str = ((open_text.size()-1)/key.key)+1;
    int index = 0;
    wchar_t mtr[str][key.key];
    for (int i = 0; i <str; i++) {
        for (int j = 0; j < key.key; j++ ) {
            if (index < open_text.size()) {
                mtr[i][j] = open_text[index];
                index++;
            } else {
                mtr[i][j] =' ';
            }
        }
    }
    for (int i = 0; i < key.key; i++) {
        for (int j = 0; j < str; j++ ) {
            Result.push_back(mtr[j][i]);
        }
    }
    return Result;
}
std::wstring modCipher::decrypt(modCipher key, std::wstring& cipher_text)
{
    std::wstring Result;
    int index = 0;
    const int str = ((cipher_text.size()-1)/key.key)+1;
    wchar_t mtr[str][key.key];

    for (int i = 0; i < key.key; i++) {
        for (int j = 0; j < str; j++ ) {
            if (index < cipher_text.size()) {
                mtr[j][i] = cipher_text[index];
                index++;
            } else {
                mtr[j][i] = ' ';
                index++;
            }
        }
    }
    for(int i = 0; i < str; i++) {
        for (int j = 0; j< key.key; j++) {
            Result.push_back(mtr[i][j]);
        }
    }
    return Result;
}