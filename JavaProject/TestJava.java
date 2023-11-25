public class TestJava {
   
    public void SetValue(int _value)
    {
        value = _value;
    }

    public void SetValue(TestJava _value)
    {
        if(_value == null)return;
        value = _value.value;
    }

    public int GetValue()
    {
        return value;
    }

    private int value = 0;
}
