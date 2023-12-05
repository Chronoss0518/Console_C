//ここでは文字列を操作する方法に関する内容を記述します。//

/*
//string.h

文字列に関する関数がまとめられたファイルになります。
詳細は以下のURLを参考にしてください
https://ja.wikibooks.org/wiki/C%E8%A8%80%E8%AA%9E/%E6%A8%99%E6%BA%96%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA/string.h
*/

#include<string.h>

int main()
{
    /*
    //strcat
    文字列を連結する関数です
    */
    char* test = strcat("Test","1");//Test1

    /*
    //strncat
    指定した個数分だけ基本となる文字列に対象の文字列を連結する関数です
    */
    test = strncat("Test","12345",1);//Test1

    /*
    //strlen
    文字列の長さを返す関数です
    */
    size_t testLen = strlen(test);//5

    /*
    //strcpy
    文字列をコピーします
    */
    test = strcpy(test, "Test2");//Test2

    /*
    //strncpy
    指定した数値分文字列をコピーします//
    */
    test = strncpy(test,"Test3",3);//Tes 
}