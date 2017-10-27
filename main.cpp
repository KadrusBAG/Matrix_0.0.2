#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool input(float ** & matrix, unsigned int & rows, unsigned int & columns){
    string RoCo;
    getline(cin, RoCo);
    istringstream RC(RoCo);
    char znak;
    if((RC>>rows)&&(RC>>znak)&&(znak==',')&&(RC>>columns)){
        matrix=new float *[rows];
        for(unsigned int i=0; i<rows; ++i){
            matrix[i]=new float[columns];
            string stroka;
            getline(cin, stroka);
            istringstream stream(stroka);
            for(unsigned int j=0; j<columns; ++j){ 
                if(!(stream>>matrix[i][j])){
                    return false; 
                }
            }
        }
    }
    else{
        return false;
    }
    return true;
}    

bool add(float **lhs_elements, unsigned int lhs_rows, unsigned int lhs_columns, float **rhs_elements, unsigned int rhs_rows, unsigned int rhs_columns, float ** & result_elements, unsigned int & result_rows, unsigned int & result_columns){
    if(lhs_rows!=rhs_rows || lhs_columns!=rhs_columns){
        return false;
    }
    result_rows=lhs_rows; result_columns=lhs_columns;
    result_elements=new float *[result_rows];
    for(unsigned int i=0; i<result_rows; ++i){
        result_elements[i]=new float[result_columns];
        for(unsigned int j=0; j<result_columns; ++j){
            result_elements[i][j]=lhs_elements[i][j]+rhs_elements[i][j];
        }
    }
    return true;
}

bool sub(float **lhs_elements, unsigned int lhs_rows, unsigned int lhs_columns, float **rhs_elements, unsigned int rhs_rows, unsigned int rhs_columns, float ** & result_elements, unsigned int & result_rows, unsigned int & result_columns){
    if(lhs_rows!=rhs_rows || lhs_columns!=rhs_columns){
        return false;
    }
    result_rows=lhs_rows; result_columns=lhs_columns;
    result_elements=new float *[result_rows];
    for(unsigned int i=0; i<result_rows; ++i){
        result_elements[i]=new float[result_columns];
        for(unsigned int j=0; j<result_columns; ++j){
            result_elements[i][j]=lhs_elements[i][j]-rhs_elements[i][j];
        }
    }
    return true;
}

bool multiply(float **lhs_elements, unsigned int lhs_rows, unsigned int lhs_columns, float **rhs_elements, unsigned int rhs_rows, unsigned int rhs_columns, float ** & result_elements, unsigned int & result_rows, unsigned int & result_columns){
    if(lhs_columns!=rhs_rows){
        return false;
    }
    result_rows=lhs_rows; result_columns=rhs_columns;
    result_elements=new float *[result_rows];
    for(unsigned int i=0; i<result_rows; ++i){
        result_elements[i]=new float[result_columns];
        for(unsigned int j=0; j<result_columns; ++j){
            int result_op=0;
            for(unsigned int k=0; k<lhs_columns; ++k){
                result_op+=lhs_elements[i][k]*rhs_elements[k][j];
            }
            result_elements[i][j]=result_op;
        }
    }
    return true;
}

bool transpose(float **A, unsigned int rows, unsigned int columns, float ** & result_elements, unsigned int & result_rows, unsigned int & result_columns){
    result_rows=columns; result_columns=rows;
    result_elements=new float *[result_rows];
    for(unsigned int i=0; i<result_rows; ++i){
        result_elements[i]=new float[result_columns];
        for(unsigned int j=0; j<result_columns; ++j){
            result_elements[i][j]=A[j][i];
        }
    }
    return true;
}

bool reverse(float **A, unsigned int rows, unsigned int columns, float ** & result_elements, unsigned int & result_rows, unsigned int & result_columns){
    if(rows!=columns){
        return false;
    }
    result_rows=rows; result_columns=columns;
    result_elements=new float *[result_rows];
    for(unsigned int i=0; i<result_rows; ++i){
        result_elements[i]=new float[result_columns];
    }
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
            result_elements[i][j]=A[i][j];
        }
    }
    return true;
}

void destroy(float **matrix, unsigned int & rows){
    for(unsigned int i=0; i<rows; ++i){
        delete[]matrix[i];
    }
    delete[]matrix;
}

int main(){
    float **lhs_elements;
    unsigned int lhs_rows, lhs_columns;
    if(!(input(lhs_elements, lhs_rows, lhs_columns))){
        cout<<"An error has occured while reading input data"<<endl;
        return -1;
    }
    char op;
    cin>>op;
    cin.get();
    if((op!='+')&&(op!='-')&&(op!='*')&&(op!='R')&&(op!='T')){
        cout<<"An error has occured while reading input data"<<endl;
        return -2;
    }
    float **result_elements;
    unsigned int result_rows, result_columns;
    switch(op){
        case '+':{
            float **rhs_elements;
            unsigned int rhs_rows, rhs_columns;
            if(!(input(rhs_elements, rhs_rows, rhs_columns))){
                cout<<"An error has occured while reading input data"<<endl;
                return -3;
            }
            if(!(add(lhs_elements, lhs_rows, lhs_columns, rhs_elements, rhs_rows, rhs_columns, result_elements, result_rows, result_columns))){
                cout<<"An error has occured while reading input data"<<endl;
                return -10;
            }
            break;
        }
        case '-':{
            float **rhs_elements;
            unsigned int rhs_rows, rhs_columns;
            if(!(input(rhs_elements, rhs_rows, rhs_columns))){
                cout<<"An error has occured while reading input data"<<endl;
                return -3;
            }
            if(!(sub(lhs_elements, lhs_rows, lhs_columns, rhs_elements, rhs_rows, rhs_columns, result_elements, result_rows, result_columns))){
                cout<<"An error has occured while reading input data"<<endl;
                return -10;
            }
            break;
        }
        case '*':{
            float **rhs_elements;
            unsigned int rhs_rows, rhs_columns;
            if(!(input(rhs_elements, rhs_rows, rhs_columns))){
                cout<<"An error has occured while reading input data"<<endl;
                return -3;
            }
            if(!(multiply(lhs_elements, lhs_rows, lhs_columns, rhs_elements, rhs_rows, rhs_columns, result_elements, result_rows, result_columns))){
                cout<<"An error has occured while reading input data"<<endl;
                return -10;
            }
            break;
        }
        case 'T':{
            if(!(transpose(lhs_elements, lhs_rows, lhs_columns, result_elements, result_rows, result_columns))){
                cout<<"An error has occured while reading input data"<<endl;
                return -10;
            }
            break;
        }
        case 'R':{
            if(!(reverse(lhs_elements, lhs_rows, lhs_columns, result_elements, result_rows, result_columns))){
                cout<<"An error has occured while reading input data"<<endl;
                return -10;
            }
            break;
        }
    }
    destroy(lhs_elements, lhs_rows);
    for(unsigned int i=0; i<result_rows; ++i){
        for(unsigned int j=0; j<result_columns; ++j){
            cout<<result_elements[i][j]<<" ";
        }
        cout<<endl;
    }
    destroy(result_elements, result_rows);
    return 0;
}
