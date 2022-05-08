/*
Name:Ziad wael abdl hamed   ID:20200211
Name:Safa mahmoud dosky     ID:20201103

*/

#include <iostream>
#include <windows.h>
using namespace std;
void setColors(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
class ColoredBox
{
private:
    int len, wid, color, area;
    char **arr = new char *[len];
    char Boxchar;

public:
    static int maxArea;
    ColoredBox(int l, int w, int col = 15, char boxchar = '#')
    {
        setLenght(l);
        setWidth(w);
        setColor(col);
        setChar(boxchar);
        setColors(col);
        for (int i = 0; i < wid; i++)
        {
            arr[i] = new char[wid];
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < wid; j++)
            {
                arr[i][j] = boxchar;
            }
        }
        setColors(15);
    }
    void setLenght(int l ){len=l;}
    void setWidth(int w ){wid=w;}
    void setChar(char boxchar ){Boxchar=boxchar;}
    void setColor(int col){color = col;}
    int getWidth() const{return wid;}
    int getLenght() const{return len;}
    int getColor() const{return color;}
    int getCharacter() const{return Boxchar;}
    int getArea()
    {
        area = len * wid;

        return area;
    }
    void display()
    {
        setColors(color);
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < wid; j++)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
        setColors(15);
    }

    int getMaxArea()
    {
        if (maxArea < area)
            maxArea = area;
        return maxArea;
    }
    void displayTransposed()
    {
        setColors(color);
        for (int i = 0; i < wid; i++)
        {

            for (int j = 0; j < len; j++)
            {
                cout << arr[j][i];
            }
            cout << endl;
        }
        setColors(15);
    }
    void displayChess(int col)
    {
        bool isColour = false;
        for (int i = 0; i < len; i++)
        {

            for (int j = 0; j < wid; j++)
            {
                if (isColour)
                {
                    setColors(col);
                    isColour = false;
                }
                else
                {
                    setColors(color);
                    isColour = true;
                }
                cout << arr[i][j];
            }
            cout << endl;
        }
        setColors(15);
    }
    void displayWider()
    {
        setColors(color);
        for (int i = 0; i < len; i++)
        {

            for (int j = 0; j < wid; j++)
            {
                cout << arr[i][j] << "  ";
            }
            cout << endl;
        }
        setColors(15);
    }

    ~ColoredBox()
    {
        for (int x = 0; x < len; x++)
        {
            delete[] arr[x];
        }
        delete[] arr;
        *arr=0;
    }
};
int ColoredBox ::maxArea = 0;

int main()
{

    int len, wid, col, col2;
    char boxChar;
    cout << "Enter length and width of the box separated by a space: ";
    cin >> len >> wid;
    ColoredBox *cb1;
    cb1 = new ColoredBox(len, wid);
    cb1->display();
    cout << "Set the box to another color: ";
    cin >> col;
    cb1->setColor(col);
    cout << "Displaying Transposed: " << endl;
    cb1->displayTransposed();
    cout << "Displaying Wider: " << endl;
    cb1->displayWider();
    cout << "Displaying Chess, enter the other color: " << endl;
    cin >> col2;
    cb1->displayChess(col2);
    cout << endl
         << "Area=" << cb1->getArea();
    cout << endl
         << "Max Area=" << cb1->getMaxArea() << endl;
    delete cb1;

    cout << "Enter length,width,color,character of the box separated by spaces: ";
    cin >> len >> wid >> col >> boxChar;
    ColoredBox *cb2;
    cb2 = new ColoredBox(len, wid, col, boxChar);
    cb2->display();
    cout << "Displaying Transposed: " << endl;
    cb2->displayTransposed();
    cout << "Displaying Wider: " << endl;
    cb2->displayWider();
    cout << "Displaying Chess, enter the other color: " << endl;
    cin >> col2;
    cb2->displayChess(col2);
    cout << "Displaying original again:" << endl;
    cb2->display();
    cout << endl
         << "Area=" << cb2->getArea();
    cout << endl
         << "Max Area=" << cb2->getMaxArea();
    delete cb2;
    return 0;
}
