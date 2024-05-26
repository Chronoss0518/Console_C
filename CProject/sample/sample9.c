//ここではプリプロセッサの利用方法を記述します//

/*
//プリプロセッサとは//
プリプロセッサはコンパイル時に実行する時に走る処理を指します。

プリプロセッサは#から始まる1行になります。
ここではプリプロセッサの一部を紹介します。
*/

#include<stdio.h>
/*
//#include

対象のファイルを展開するプリプロセッサです。
簡単に言うなら、ファイルの中身をこのプリプロセッサの場所にコピペを行うような機能になります。
#includeは次の使用方法があります

//#include<ファイル名>
こちらはコンパイル時に対象の場所から見たファイルを展開します。

//#include"ファイル名"
こちらはコンパイル時にこのファイルのパスから見て相対パスのファイルを展開します。
*/

/*
//#define

こちらのプリプロセッサは指定したテキストを置き換えてコンパイルを行う機能になります。
別名にマクロと言われています。

#defineの指定方法は3種類あります。
*/


#define TEST
/*
//#define マクロ名
こちらはマクロを指定します。
*/
#define TEST_1 10
/*
//#define マクロ名 値
こちらはマクロ名に紐づけられた値を指定します。
*/

#define TEST_2(_value) \
int test =  _value + 10;  \
test += 10;
/*
//#define マクロ名(引数) 値
こちらは値に対して引数を指定することができます。
こちらでは次のような書き方もできます。
*/

//マクロに引数をつけて代入する処理に置換する
#define TEST_INSERT(val1,val2) val1 = val2

//関数のように利用する//
#define TEST_PRINTF(val) val("print")

//マクロに入れた値を文字列に変換する//
#define TEST_TO_STRING(to_str) #to_str

//マクロに入れた値をそのままコードとして連結する//
#define TEST_CODE(to_str1,to_str2) to_str1 ## to_str2


#if 0
#elif 0
#else
#endif
/*
#if 値
#ifは値が真の場合#ifと特定のプリプロセッサ間に記述されたコードをコンパイルに含むプリプロセッサになります。



終わりには必ず#endifが必要になります。
*/

#ifdef TEST
#elif 0
#else
#endif
/*
#ifdef マクロ名
#ifdefは対象のマクロが作成されている場合#ifdefと特定のプリプロセッサ間に記述されたコードをコンパイルに含むプリプロセッサになります。

終わりには必ず#endifが必要になります。
*/

#ifndef TEST
#elif 0
#else
#endif
/*
#ifndef マクロ名
#ifndefは対象のマクロが作成されていない場合#ifndefと特定のプリプロセッサ間に記述されたコードをコンパイルに含むプリプロセッサになります。

終わりには必ず#endifが必要になります。
*/

/*
#ifと#ifdefと#ifndefの説明にある特定のプリプロセッサの説明になります。
ここ以降の特定のプリプロセッサも同じものになります。

#elif 値
#elifは#if,#ifdef,#ifndef,#elifと#endifの間に記述できるプリプロセッサです。
#elif前の#if,#ifdef,#ifndef,#elifが偽の場合に#elifと特定のプリプロセッサ間にあるコードをコンパイルに含むプリプロセッサになります。

#else
#elseは#if,#ifdef,#ifndef,#elifと#endifの間に記述できるプリプロセッサです。
こちらは#endif 1つにつき#elseは1つまで指定することができます。
*/


int main()
{

int test = 0;

//マクロに引数をつけて代入する処理に置換する
TEST_INSERT(test,100);//->test = 100;

//関数のように利用する//
TEST_PRINTF(printf); //-> printf("print");

//マクロに入れた値を文字列に変換する//
printf(TEST_TO_STRING(10));//->"10";

int test1 = 10;
//マクロに入れた値をそのままコードとして連結する//
TEST_CODE(test,1) = 100;//->test1 = 100;

    return 0;
}