#include<stdio.h>
#include<stdlib.h>

#define DRAW_BLOCK_TEXT "  "
#define TO_TEXT(num) #num
#define CREATE_COLOR_TEXT(colorNum)  "\x1b[" #colorNum "m"
#define ADD_TEXT(t1,t2) #t1 #t2

//this is color map//
int* doubleBuffer = NULL;
unsigned long width = 0;
unsigned long height = 0;

int colorNumber = 105;

char inputKeyValue = 0;
char endFlg = 0;

enum
{
    ColorName_Red
};

void InputTest()
{
    while(endFlg == 0)
    {
        inputKeyValue = getchar();
    }
}

void CreateDoubleBuffer(unsigned long _width,unsigned long _height);

void ClearDoubleBuffer(int _color);

void SetColor(unsigned long _x,unsigned long _y,int _colorNum);

void DrawDisplay(int _clearFlg);

void ReleaseBuffer();

int main()
{

    //printf("Hello World\n");

    CreateDoubleBuffer(1280,720);
    
    unsigned long x = 0;
    unsigned long y = 300;

    ClearDoubleBuffer(colorNumber);

    SetColor(x,y,110);
    SetColor(x+1,y,110);
    SetColor(x,y+1,110);
    SetColor(x+1,y+1,110);

    DrawDisplay(1);

    endFlg = 1;

    ReleaseBuffer();
    
    return 0;
}

void CreateDoubleBuffer(unsigned long _width,unsigned long _height)
{
    if(_width <= 0 || _height <= 0)return;
    
    width = _width;
    height = _height;
    
    doubleBuffer = (int*)malloc(sizeof(int) * _width * _height);

    for(unsigned long i = 0;i<_width * _height;i++)
    {
        *(doubleBuffer + i) = colorNumber;
    }
}

void ClearDoubleBuffer(int _color)
{
    if(doubleBuffer == NULL)return;
    
    for(unsigned long h = 0;h < height;h++)
    {
        for(unsigned long w = 0; w < width;w++)
        {
            *(doubleBuffer + (w + (width * h))) = _color;
        }
    }
}

void SetColor(unsigned long _x,unsigned long _y,int _colorNum)
{
    if(doubleBuffer == NULL)return;
    if(_x >= width || _y >= height)return;
    *(doubleBuffer + (_x + (_y * width))) = _colorNum;
}

void DrawDisplay(int _clearFlg)
{
    if(doubleBuffer == NULL)
    {
        return;
    }

    char* echoText = "";

    char* tmp = NULL;

    for(unsigned long h = 0;h < height;h++)
    {
        for(unsigned long w = 0; w < width;w++)
        {
            tmp = CREATE_COLOR_TEXT(*(doubleBuffer + (w + (width * h)))) DRAW_BLOCK_TEXT;
            echoText = ADD_TEXT(echoText,tmp);
        }
        echoText = ADD_TEXT(echoText,"\n");
    }

    if(_clearFlg != 0)system("clear");
    system(ADD_TEXT("echo ", echoText));
}

void ReleaseBuffer()
{
    if(doubleBuffer == NULL)
    {
        return;
    }

    free(doubleBuffer);
    doubleBuffer = NULL;
}