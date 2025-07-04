//ここでは基本的な値型の種類と構造体を記述します。//

//int型 基本的な数値を入れる代表的な型です//
int i_value = 0;

//unsigned int型 int型の符号なし(+-がない)型になります。そのため負の値がなく、その分最大値が約2倍近く多くなります。//
unsigned int ui_value = 0; 

//char型 端的に言えば1文字を格納するための型です。
//サイズは1byte(8bit)になります。
//char型には''で囲った1文字のみを入れるか、直接数値を入れることが可能です。
char c_value = '\0';

//unsigned char型 char型の符号なし型になります。かなりわかりやすく、char型の時の最大値は127なのに対してこちらは255(16進数だと0xff)まで入れることができます//
unsigned char uc_value = '\0';

//short型 こちらも整数を入れる型になります//
short s_value = 0;

//unsigned short型 short型の符号なし型になります。//
unsigned short us_value = 0;

//long型 整数型では最大の容量を誇る型です//
long l_value = 0;

//unsigned long型 long型の符号なし型になります。//
unsigned long ul_value = 0;

//整数型のサイズは基本的に以下のようになります//
/*
char == unsigned cahr
< short == unsigned short
<= int == unsigned int
<= long == unsigned long

&&

short < long
*/

//float型 小数点の計算ができる浮動小数点型になります。//
//浮動小数点型には符号の有無の概念がないため、基本的にはすべて符号ありになります。//
//サイズは4byteになります。//
float f_value = 0.0f;

//double型 一番大きいメモリを利用する浮動小数点型になります。//
//サイズは8byteになります。//
double d_value = 0.0;

//long double型 double型よりも大きい浮動小数点型になります。//
//場合によってはdoubleと同じサイズになっていたりもします。//
long double ld_value = 0.0;


//C言語のバージョンアップにより追加された型//

//long long型 long型よりも大きい整数型になります。//

long long ll_value = 0;

//unsigned long long型 long long型の符号なし型になります。//

unsigned long long ull_value = 0;

/*
//構造体//
構造体は変数をまとめたものになります。
そのため構造体のサイズは利用した変数のサイズの合計値になります。

基本的な構文は次の通りです。
struct 構造体名 
{
    メンバー変数;
    メンバー変数;
    ...
};

利用するときは次のようになります。
struct 構造体名 変数名;

構造体のメンバー変数へアクセスする方法は次のように利用します。
変数名.メンバー変数

また構造体名は違う名前でも利用することが可能です。

方法は次の3種類になります。
//#defineを利用する
#define TEST_STRUCT struct Test
TEST_STRUCT test;//-> struct Test test;

//typedefを利用する1
typedef struct Test{}Test;
//typedef struct {}Test;でも可//
Test test;

//typedefを利用する2(こちらの方法は値型でも利用可能です。)
typedef struct Test Test;
Test test;

*/
struct Test
{
    int m_i_value;

    double m_d_value;
    
    char m_c_value;
};

/*
//配列の作成
配列は値型、構造体どちらでも利用することができます。
この時必ず配列の要素数を指定する必要があります。

配列のして方法は次の2つになります。

型名 変数名[配列数];
型名 変数名[] = {初期値,初期値...};

2つめの初期値は1個以上指定します。
*/
int array[5];

int array2[] = {0,1,2,3,4,5};

/*
//配列の利用方法

配列から値を利用する場合は添え字を利用する必要があります。
取り出し方は次の通りです。

変数名[取り出す番号]

この時取り出す番号は0番を先頭とした数字になります。
また、定義した配列以上の値を配列から取り出そうとするとエラーが起きるため、注意が必要です。
*/