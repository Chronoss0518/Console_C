#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

#define DRAW_BLOCK_TEXT "_"
#define TO_TEXT(num) #num
#define CREATE_COLOR_TEXT(out,colorNum)  sprintf(out,"\x1b[%dm",colorNum)

#define FPS 60

//this is color map//
int* doubleBuffer = NULL;
unsigned long width = 0;
unsigned long height = 0;

int colorNumber = 105;

enum
{
    VK_LEFT = 128,
    VK_UP,
    VK_RIGHT,
    VK_DOWN,
};

enum
{
    ColorName_Red
};

int Input()
{
    if(_kbhit() == 0)return -1;

    int inputKeyValue = 0;
    inputKeyValue = getch();

    if(inputKeyValue == EOF)return -1;
    
    if(inputKeyValue == 224)
    {
        inputKeyValue = getch();
        if(inputKeyValue == 75)inputKeyValue = VK_LEFT;
        else if(inputKeyValue == 72)inputKeyValue = VK_UP;
        else if(inputKeyValue == 77)inputKeyValue = VK_RIGHT;
        else if(inputKeyValue == 80)inputKeyValue = VK_DOWN;
    }

    return inputKeyValue;
}

void CreateDoubleBuffer(unsigned long _width,unsigned long _height);

void ClearDoubleBuffer(int _color);

void SetColor(unsigned long _x,unsigned long _y,int _colorNum);

void DrawDisplay(int _clearFlg);

void ReleaseBuffer();

int main()
{
    CreateDoubleBuffer(640,360);
    
    unsigned long x = 0;
    unsigned long y = 300;

    char endFlg = 0;
    int keyValue = 0;

    unsigned long num = clock() / CLOCKS_PER_SEC;
    while(1)
    {
        unsigned long now = clock() / CLOCKS_PER_SEC;
        if(1000 / FPS < now - num)continue;
        num = now;

        keyValue = Input();

        if(keyValue == 27)break;
        
        if(keyValue == VK_UP)y--;
        if(keyValue == VK_DOWN)y++;
        if(keyValue == VK_LEFT)x--;
        if(keyValue == VK_RIGHT)x++;
        ClearDoubleBuffer(colorNumber);

        SetColor(x,y,110);
        SetColor(x+1,y,110);
        SetColor(x,y+1,110);
        SetColor(x+1,y+1,110);

        DrawDisplay(1);

    }
    char* tmp = "";
    CREATE_COLOR_TEXT(tmp,0);
    printf(tmp);
    printf("Release Buffer\n");
    ReleaseBuffer();

    
    return 0;
}

void CreateDoubleBuffer(unsigned long _width,unsigned long _height)
{
    if(_width <= 0 || _height <= 0)return;
    
    width = _width;
    height = _height;
    
    doubleBuffer = (int*)malloc(sizeof(int) * _width * _height);

    ClearDoubleBuffer(colorNumber);
}

void ClearDoubleBuffer(int _color)
{
    if(doubleBuffer == NULL)return;
    
    for(unsigned long i = 0;i<width * height;i++)
    {
        *(doubleBuffer + i) = _color;
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

    char* tmp = "";

    for(unsigned long h = 0;h < height;h++)
    {
        for(unsigned long w = 0; w < width;w++)
        {
            tmp = "";
            CREATE_COLOR_TEXT(tmp,*(doubleBuffer + (w + (width * h))));

            sprintf(echoText,"%s%s%s\x1b[0m",echoText,tmp,DRAW_BLOCK_TEXT);
        }
        sprintf(echoText,"%s\n",echoText);
    }

    if(_clearFlg != 0)system("cls");
    printf(echoText);
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