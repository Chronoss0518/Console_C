import TestFolder.TestJava2;

class MainClass{
  public static void main(String[] args){
    System.out.println("Hello");

    //test.value = 0,test2 = null//
    TestJava test = new TestJava();

    //test.value = 10,test2 = null//
    test.SetValue(10);

    //test.value = 10,test2 = null//
    int val = test.GetValue();

    //test.value = 10,test2 = null//
    val = 100;

    //test.value = 10,test2.value = 0//
    TestJava test2 = new TestJava();

    //test.value = 10,test2.value = 100//
    test2.SetValue(val);

    //test.value = 100,test2.value = 100//
    test.SetValue(test2);

  }

  private TestJava2 test3 = new TestJava2();
}