#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool proverka(float **matrix, unsigned int rows, unsigned int columns){
    for(unsigned int i=0; i<rows; ++i){
        string stroka;
        getline(cin, stroka);
        istringstream stream(stroka);
        for(unsigned int j=0; j<columns; ++j){ 
            if(!(stream>>matrix[i][j])){
                cout<<"An error has occured while reading input data"<<endl;
                return false; 
            }
        }
    }
    return true;
}

void summa(float **m1, float **m2, float **m_result, unsigned int rows1, unsigned int columns1){
    cout<<endl;
    for(unsigned int i=0; i<rows1; ++i){
        for(unsigned int j=0; j<columns1; ++j){
            m_result[i][j]=m1[i][j]+m2[i][j];
        }
    }
}

void raznost(float **m1, float **m2, float **m_result, unsigned int rows1, unsigned int columns1){
    cout<<endl;
    for(unsigned int i=0; i<rows1; ++i){
        for(unsigned int j=0; j<columns1; ++j){
            m_result[i][j]=m1[i][j]-m2[i][j];
        }
    }
}

void umnozhenie(float **m1, float** m2, float **m_result, unsigned int rows1, unsigned int columns1, unsigned int columns2){
    cout<<endl;
    for(unsigned int i=0; i<rows1; ++i){
        for(unsigned int j=0; j<columns2; ++j){
            int result_op=0;
            for(unsigned int k=0; k<columns1; ++k){
                result_op+=m1[i][k]*m2[k][j];
            }
            m_result[i][j]=result_op;
        }
    }
}

void transponirovanie(float **m1, float **m_result, unsigned int rows1, unsigned int columns1){
    cout<<endl;
    for(unsigned int j=0; j<columns1; ++j){
        for(unsigned int i=0; i<rows1; ++i){
            m_result[j][i]=m1[i][j];
        }
    }
}

void inversiya(float **A, float **m_result, unsigned int rows)
{
    float temp;
    float **E = new float *[rows];
    for (unsigned int i = 0; i < rows; i++){
        E[i] = new float [rows];
    }
    for (unsigned int i = 0; i < rows; i++){
        for (unsigned int j = 0; j < rows; j++){
            E[i][j] = 0;
            if (i == j){
                E[i][j] = 1;
            }
        }
    }
    for (unsigned int k = 0; k < rows; k++){
        temp = A[k][k];
        for (unsigned int j = 0; j < rows; j++){
            A[k][j] /= temp;
            E[k][j] /= temp;
        }
        for (unsigned int i = k + 1; i < rows; i++){
            temp = A[i][k];
            for (unsigned int j = 0; j < rows; j++){
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    for (int k = rows - 1; k > 0; k--){
        for (int i = k - 1; i >= 0; i--){
            temp = A[i][k];
            for (unsigned int j = 0; j < rows; j++){
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    for (unsigned int i = 0; i < rows; i++){
        for (unsigned int j = 0; j < rows; j++){
            A[i][j] = E[i][j];
            m_result[i][j]=A[i][j];
        }
    }
}

int main(){
    bool f=0;
    float **m_result;
    float **m1;
    unsigned int rows1, columns1;
    char znak1;
    string stroka1;
    getline(cin, stroka1);
    istringstream stream1(stroka1);
    if((stream1>>rows1)&&(stream1>>znak1)&&(znak1==',')&&(stream1>>columns1)){
        m1=new float *[rows1];
        for(unsigned int i=0; i<rows1; ++i){
            m1[i]=new float[columns1];
            for(unsigned int j=0; j<columns1; ++j){
                m1[i][j]=0.0f;
            }
        }
    }
    else{
        cout<<"An error has occured while reading input data"<<endl;
        return -1;
    }
    if(proverka(m1, rows1, columns1)){
        char op;
        string operat;
        getline(cin, operat);
        istringstream stream_op(operat);
        if((!(stream_op>>op))||((op!='+')&&(op!='-')&&(op!='*')&&(op!='R')&&(op!='T'))){
            cout<<"An error has occured while reading input data"<<endl;
            return -2;
        }
        if((op=='+')||(op=='-')||(op=='*')){
            float **m2;
            unsigned int rows2, columns2;
            char znak2;
            string stroka2;
            getline(cin, stroka2);
            istringstream stream2(stroka2);
            if((stream2>>rows2)&&(stream2>>znak2)&&(znak2==',')&&(stream2>>columns2)){
                m2=new float *[rows2];
                for(unsigned int i=0; i<rows2; ++i){
                    m2[i]=new float[columns2];
                    for(unsigned int j=0; j<columns2; ++j){
                        m2[i][j]=0.0f;
                    }
                }
            }
            else{
                cout<<"An error has occured while reading input data"<<endl;
                return -3;
            }
            if(proverka(m2, rows2, columns2)){
                if((op=='+')&&(rows1==rows2)&&(columns1==columns2)){
                    f=1;
                    m_result=new float *[rows1];
                    for(unsigned int i=0; i<rows1; ++i){
                        m_result[i]=new float[columns1];
                        for(unsigned int j=0; j<columns1; ++j){
                            m_result[i][j]=0.0f;
                        }
                    }
                    summa(m1, m2, m_result, rows1, columns1);
                }
                if((op=='-')&&(rows1==rows2)&&(columns1==columns2)){
                    f=1;
                    m_result=new float *[rows1];
                    for(unsigned int i=0; i<rows1; ++i){
                        m_result[i]=new float[columns1];
                        for(unsigned int j=0; j<columns1; ++j){
                            m_result[i][j]=0.0f;
                        }
                    }
                    raznost(m1, m2, m_result, rows1, columns1);
                }
                if((op=='*')&&(columns1==rows2)){
                    f=1;
                    m_result=new float *[rows1];
                    for(unsigned int i=0; i<rows1; ++i){
                        m_result[i]=new float[columns2];
                        for(unsigned int j=0; j<columns2; ++j){
                            m_result[i][j]=0.0f;
                        }
                    }
                    umnozhenie(m1, m2, m_result, rows1, columns1, columns2);
                    columns1=columns2;
                }
            }
            else{
                return -20;
            }
        }
        if((op=='T')||(op=='R')){
            if(op=='T'){
                f=1;
                m_result=new float *[columns1];
                for(unsigned int i=0; i<columns1; ++i){
                    m_result[i]=new float [rows1];
                    for(unsigned int j=0; j<rows1; ++j){
                        m_result[i][j]=0.0f;
                    }
                }
                transponirovanie(m1, m_result, rows1, columns1);
                unsigned int time=rows1;
                rows1=columns1;
                columns1=time;
            }
            if((op=='R')&&(rows1==columns1)){
                f=1;
                m_result=new float *[rows1];
                for(unsigned int i=0; i<rows1; ++i){
                    m_result[i]=new float[rows1];
                    for(unsigned int j=0; j<rows1; ++j){
                        m_result[i][j]=0.0f;
                    }
                }
                inversiya(m1, m_result, rows1);
            }
        }
    }
    else{
        return -10;
    }
    for(unsigned int i=0; i<rows1; ++i){
        for(unsigned int j=0; j<columns1; ++j){
            cout<<m_result[i][j]<<" ";
        }
        cout<<endl;
    }
    if(!f){
        cout<<"An error has occured while reading input data"<<endl;
        return -10;
    }
    return 0;
}
