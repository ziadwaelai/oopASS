/*
Name: Ziad Wael Abdl Hamed               ID: 20200211
Name: Suhayla Ehab Gamal Malatie         ID: 20200236
*/
#include <iostream>
#include <fstream>

using namespace std;

class FloatArray
{
protected:
    int Size, c = 0; // C:the index of last element in array ; ie.the number of elements in array
    float *arr;      // dynamic array
public:

    FloatArray(int _size)
    {
        Size = _size;
        arr = new float[Size];
    };
    virtual void add(float num) // virtual add function to fill array
    {
        arr[c] = num;
        c++;
    }

    virtual~FloatArray()
    {
        delete[] arr; // delete dynamic allocate
    }

    friend ostream &operator<<(ostream &os, const FloatArray &fi); // operator overloading <<
    friend istream &operator>>(istream &is, FloatArray &fi);       // operator overloading >>
};
ostream &operator<<(ostream &os, const FloatArray &fi)
{
    for (int i = 0; i < fi.c; i++)
    {
        if (i == 0)
        {
            os << fi.c << "|" << '\t';
        }
        os << fi.arr[i] << '\t';
    }
    return os;
};
istream &operator>>(istream &is, FloatArray &fi)
{
    float num;
    int t=fi.Size;
    while (t--)
    {
        is >> num;
        fi.add(num);
    }
    return is;
};

class SortedArray : public FloatArray
{
public:
    SortedArray(int _Size) : FloatArray(_Size) {}
    virtual void add(float num){ // add function (insertion sort) (override)
        arr[c] = num;
        float key = arr[c];
        int j = c - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        c += 1;
    }
    virtual~SortedArray() {}
};

class FrontArray : public FloatArray
{
private:
    int i = Size - 1;

public:
    FrontArray(int _size) : FloatArray(_size){};
    void add(float num){ // add function (to reverse the array)(override)
        arr[i] = num;
        i--;
        c++;
    }
    ~FrontArray() {}
};

class PositiveArray : public SortedArray
{
public:
    PositiveArray(int size) : SortedArray(size){};
    void add(float num){ // add function (to add only positive numbers)(override)
        if (num > 0)
        {
            SortedArray::add(num); // to call add function in SortedArray class
        }
    }
    ~PositiveArray() {}
};

class NegativeArray : public SortedArray
{
public:
    NegativeArray(int size) : SortedArray(size){};
    void add(float num){ // add fuction (to add only negative numbers) (override)
        if (num < 0)
        {
            SortedArray::add(num); // to call add function in SortedArray class
        }
    }
    ~NegativeArray() {}
};

int main()
{
    string input, output;
    cout << "Enter the name of the input file: " << endl;
    cin >> input;
    cout << "Enter the name of the output file: " << endl;
    cin >> output;
    fstream in(input, ios::in);
    fstream out(output, ios::out);
    string name;
    int size;

    while (!in.eof())
    {
        in >> name >> size;
        if (name == "Array")
        {
            FloatArray f(size);
            in>>f;
            out << f;
        }
        else if (name == "Sorted")
        {
            SortedArray f(size);
            in>>f;
            out << f;
        }
        else if (name == "Front")
        {
            FrontArray f(size);
            in>>f;
            out << f;
        }
        else if (name == "Positive")
        {
            PositiveArray f(size);
            in>>f;
            out << f;
        }
        else
        {
            NegativeArray f(size);
            in>>f;
            out << f;
        }
        out << endl;
    }
    in.close();
    return 0;
}
