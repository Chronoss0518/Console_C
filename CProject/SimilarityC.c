//ここではいろいろな言語とC言語の類似性を確認します//

/*
//Java言語の場合
import java.time.LocalDate;

//Pythonの場合(Cとは若干動きが違うため注意してください)
import numpy
*/
#include<stdio.h>


/*
//Javaの場合
public static int g_num = 0;

//JavaScriptの場合
var g_num = 0;

//PHPの場合
$g_num = 0;

//Pythonの場合
g_num = 0

*/
int g_num = 0;


/*
//Javaの場合
public static String g_str = "";

//JavaScriptの場合
var g_str = "";

//PHPの場合
$g_str = "";

//Pythonの場合
g_str = ""
*/
char* g_str = "";

/*
//Javaの場合
public static int[] g_array = new int[4];

//JavaScriptの場合
var g_array = [0,0,0,0];

//PHPの場合
$g_str = array(0, 0, 0, 0);

//Pythonの場合
g_str = [0,0,0,0]
*/
int g_array[] = {0,0,0,0};

int Test(int num);
void Test2(int in);

/*
//Javaの場合
public class TestStruct
{
  public int m_value = 0;
};

//PHPの場合
class TestStruct {
  public $m_value = 0;
}

//JavaScriptの場合
class TestStruct {
  var m_value = 0;
}

//Pythonの場合
class TestStruct:
  m_value = 0
*/
struct TestStruct
{
  int m_value;
};

/*
//Javaの場合
class クラス名{
  public static void main(String[] args){
    int test = Test(10);
    Test2(0);
    return 0;
  }
}

//Pythonの場合
def main():
  test = Test(10)
  Test2(0)
  return 0

//エントリーポイントの定義
if __name__ == '__main__':
    sys.exit(main(sys.argv))
*/
int main()
{
  int test = Test(10);
  Test2(0);
  return 0;
}

/*
//Javaの場合
public int Test(int num)
{
  return num * num;
}

public void Test2(int in)
{
  if(in)return;

  for(int i = 0;i<10;i++)
  {
    continue;
  }

  while(in)
  {
    break;
  }

  return;
}

//JavaScriptの場合
function Test(num) {
  return num * num;
}

function Test2(in) {
  
  if(in)return;

  for(var i = 0;i<10;i++)
  {
    continue;
  }

  while(in)
  {
    break;
  }

  return;
}

//PHPの場合
function Test($num)
{
    return $num * $num;
}

function Test2($in)
{
  if($in)return;

  for($i = 0;$i<10;$i++)
  {
    continue;
  }

  while($in)
  {
    break;
  }

  return;
}

//Pythonの場合
def Test(num):
  return num * num

def Test2(in):
  if(in)
    return

  for(i = 0;i<10;i++):
    continue

  while(in):
    break

  return

*/
int Test(int num)
{
  return num * num;
}

void Test2(int in)
{
  if(in)return;

  for(int i = 0;i<10;i++)
  {
    continue;
  }

  while(in)
  {
    break;
  }

  return;
}