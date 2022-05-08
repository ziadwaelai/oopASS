#include<iostream>
#include <fstream>
using namespace std;

class FloatArray
{
protected:
    int Size;
public:
    float * arr;
    FloatArray(int _size,float _arr[]){
        Size=_size;
        arr = new float[Size];
        add(_arr);
    };
       FloatArray(int _size){
        Size=_size;
        arr = new float[Size];
    };
    void add(float _arr[]){
        for(int i=0;i<Size;i++){
            arr[i]=_arr[i];
        }
    }
    ~FloatArray(){
        delete []arr ;
    }

    friend ostream& operator<<(ostream& os, const FloatArray& fi);
    friend istream& operator>>(istream& is, FloatArray& fi);
};
ostream& operator<<(ostream& os, const FloatArray& fi)
{
    for(int i=0;i<fi.Size;i++){
        if(i==0){
    os<<fi.Size<<"|";
        }
         
        os<<'\t'<<fi.arr[i]<<'\t';
        
    }
    return os;
};
istream& operator>>(istream& is, FloatArray& fi)
{
   for(int i=0;i<fi.Size;i++){
        is>>fi.arr[i];
   }
    return is;
};


class SortedArray : public FloatArray
{
protected:
public:
    SortedArray(int Size,float _arr[]) : FloatArray( Size,_arr){
        add();
    }
    void add(){
        float temp;
       for(int i=0;i<Size;i++)
	{		
		for(int j=i+1;j<Size;j++)
		{
			if(arr[i]>arr[j])
			{
				temp  =arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
    }
 
};

class FrontArray : public FloatArray
{
private:
   
public:
    FrontArray(int size,float arr[]):FloatArray(size,arr){};
    friend ostream& operator<<(ostream& os, const FrontArray& fi);
};
ostream& operator<<(ostream& os, const FrontArray& fi)
{
    for(int i=fi.Size;i>fi.Size;i--){
        if(i==fi.Size){
    os<<fi.Size<<"|";
        }
         
        os<<'\t'<<fi.arr[i]<<'\t';
    }
    return os;
};

class PositiveArray :public SortedArray
{
private:
    float *posiarr;
    int Size;
public:
    PositiveArray(int _Size,float _posiarr[]):SortedArray(_Size,_posiarr){
        Size=_Size;
        posiarr = new float[Size];
        add(_posiarr);


    };
    void add(float _posiarr[]){
        for(int i=0;i<Size;i++){
            if(_posiarr[i]>0){
                arr[i]=_posiarr[i];
            }else{
                arr[i]=0;
            }
        }

    }
};

class NegativeArray : public SortedArray
{
private:
    float *nagiarr;
    int Size;
public:
    NegativeArray(int _Size,float _nagiarr[]):SortedArray(_Size,_nagiarr){
        Size=_Size;
        nagiarr = new float[Size];
        add(_nagiarr);


    };
 void add(float _nagiarr[]){
        for(int i=0;i<Size;i++){
            if(_nagiarr[i]<0){
                arr[i]=_nagiarr[i];
            }else{
                arr[i]=0;
            }
        }

    }
};






int main(){
string input,output;
cout<<"Enter the name of the input file: "<<endl;
cin>>input;
cout<<"Enter the name of the output file: "<<endl;
cin>>output;
fstream in(input, ios::in);
fstream out(output, ios::out);

string name ;
int size;
float num;
int x=15;

while(!in.eof()){
in>>name>>size;
int i=0;
float arr[size];
int realSize=0;
while(size--){
    in>>num;
    arr[i]=num;
    i++; 
    realSize++;
}
if(name=="Sorted"){
    SortedArray F(realSize,arr);
    out<<F;
}

else if(name=="Array"){
    FloatArray F(realSize,arr);
    out<<F;
}
else if(name=="Positive"){
    PositiveArray F(realSize,arr);
    out<<F;
}
else if(name=="Negative"){
    NegativeArray F(realSize,arr);
    out<<F;
}
else if(name=="Front"){
    FloatArray F(realSize,arr);
    out<<F;
}
else{
    out<<"undiff";
}
out<<endl;
realSize=0;
}


in.close();
return 0;
}