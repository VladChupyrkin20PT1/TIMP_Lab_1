#pragma once
#include <vector>
#include <string>
#include <iostream>
class modCipher
{
private:
	int key;
public:
	modCipher()=delete; //запретим конструктор без параметров
	modCipher(int k); //конструктор для установки ключа
	std::wstring encrypt(modCipher key, std::wstring& open_text); //зашифрование
	std::wstring decrypt(modCipher key, std::wstring& cipher_text);//расшифрование
};
