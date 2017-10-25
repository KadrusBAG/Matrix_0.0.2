#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    bool f=0;
    float **m1, **m2;
    unsigned int rows1, columns1;
    char znak1;
    string stroka1;
    getline(cin, stroka1);
    istringstream stream1(stroka1);
    if((stream1>>rows1)&&(stream1>>znak1)&&(stream1>>columns1)){
        m1=new float* [rows1];
        for(unsigned int i=0; i<rows1; ++i){
            m1[i]=new float[columns1];
        }
        for(unsigned int i=0; i<rows1; ++i){
            string stroka;
            getline(cin, stroka);
            istringstream stream(stroka);
            for(unsigned int j=0; j<columns1; ++j){ 
                if(!(stream>>m1[i][j])){
                    cout<<"An error has occured while reading input data"<<endl;
                    return -2; 
                }
            }
        }
    }
    else{
        cout<<"An error has occured while reading input data"<<endl;
        return -1;
    }
    char op;
    string operat;
    getline(cin, operat);
    istringstream stream_op(operat);
    if(!(stream_op>>op)){
        cout<<"An error has occured while reading input data"<<endl;
        return -3;
    }
    if((op!='+')&&(op!='-')&&(op!='*')&&(op!='R')&&(op!='T')){
        cout<<"An error has occured while reading input data"<<endl;
        return -10;
    }
    if((op=='+')||(op=='-')||(op=='*')){
        unsigned int rows2, columns2;
        char znak2;
        string stroka2;
        getline(cin, stroka2);
        istringstream stream2(stroka2);
        if((stream2>>rows2)&&(stream2>>znak2)&&(stream2>>columns2)){
            m2=new float* [rows2];
            for(unsigned int i=0; i<rows2; ++i){
                m2[i]=new float[columns2];
            }
            for(unsigned int i=0; i<rows2; ++i){
                string stroka;
                getline(cin, stroka);
                istringstream stream(stroka);
                for(unsigned int j=0; j<columns2; ++j){ 
                    if(!(stream>>m2[i][j])){
                        cout<<"An error has occured while reading input data"<<endl;
                        return -2; 
                    }
                }
            }
        }
        else{
            cout<<"An error has occured while reading input data"<<endl;
            return -4;
        }
        if((op=='+')&&(rows1==rows2)&&(columns1==columns2)){
            f=1;
            cout<<endl;
            for(unsigned int i=0; i<rows1; ++i){
                for(unsigned int j=0; j<columns1; ++j){
                    cout<<(m1[i][j]+m2[i][j])<<" ";
                }
                cout<<endl;
            }
        }
        if((op=='-')&&(rows1==rows2)&&(columns1==columns2)){
            f=1;
            cout<<endl;
            for(unsigned int i=0; i<rows1; ++i){
                for(unsigned int j=0; j<columns1; ++j){
                    cout<<(m1[i][j]-m2[i][j])<<" ";
                }
                cout<<endl;
            }
        }
        if((op=='*')&&(columns1==rows2)){
            f=1;
            cout<<endl;
            for(unsigned int i=0; i<rows1; ++i){
                for(unsigned int j=0; j<columns2; ++j){
                    int result_op=0;
                    for(unsigned int k=0; k<columns1; ++k){
                        result_op+=m1[i][k]*m2[k][j];
                    }
                    cout<<result_op<<" ";
                }
                cout<<endl;
            }
        }
    }
    if((op=='T')||(op=='R')){
        f=1;
        if(op=='T'){
            cout<<endl;
            for(unsigned int j=0; j<columns1; ++j){
                for(unsigned int i=0; i<rows1; ++i){
                    cout<<m1[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        if((op=='R')&&(rows1==columns1)){
            f=1;
            cout<<endl;
            double temp;
            double **E=new double *[rows1];
            for (unsigned int i=0; i<rows1; ++i){
                E[i]=new double [rows1];
            }
            for (unsigned int i=0; i<rows1; ++i){
                for (unsigned int j=0; j<rows1; ++j){
                    E[i][j]=0.0;
                    if (i==j){
                        E[i][j]=1.0;
                    }
                }
            }
            for (unsigned int k=0; k<rows1; ++k){
                temp=m1[k][k];
                for (unsigned int j=0; j<rows1; ++j){
                    m1[k][j]=E[k][j]/temp;
                    E[k][j]=E[k][j]/temp;
                }
                for (unsigned int i=k+1; i<rows1; ++i){
                    temp=m1[i][k];
                    for (unsigned int j=0; j<rows1; ++j){
                        m1[i][j]=m1[i][j]-(A[k][j]*temp);
                        E[i][j]=m1[i][j]-(E[k][j]*temp);
                    }
                }
            }
            for (unsigned int k=rows1-1; k>0; --k){
                for (unsigned int i=k-1; i>=0; --i){
                    temp = m1[i][k];
                    for (unsigned int j=0; j<rows1; ++j){
                        m1[i][j]=m1[i][j]-(m1[k][j]*temp);
                        E[i][j]=E[i][j]-(E[k][j]*temp);
                    }
                }
            }
            for (unsigned int i=0; i<rows1; ++i){
                for (unsigned int j=0; j<rows1; ++j){
                    m1[i][j]=E[i][j];
                }
            }
            for(unsigned int i=0; i<rows1; ++i){
                for(unsigned int j=0; j<columns1; ++j){
                    cout<<m1[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    if(!f){
        cout<<"An error has occured while reading input data"<<endl;
        return -20;
    }
    return 0;
}
