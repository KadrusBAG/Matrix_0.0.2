#include <iostream>
#include <sstream>

using namespace std;

int main(){
    float m1[][];
    unsigned int rows1, columns1;
    string stroka; char znak1;
    istringstream stream(stroka);
    if((stream>>rows1)&&(stream>>znak1)&&(stream>>columns1)){
        float ** m1 = new float *[ rows1 ];
        for( unsigned int i = 0; i < rows1; ++i ) {
            m1[ i ] = new float[ columns1 ];
            for( unsigned int j = 0; j < columns1; ++j ) {
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
    if(!(stream>>op)){
        cout<<"An error has occured while reading input data"<<endl;
        return -3;
    }
    if((op=='+')||(op=='-')||(op=='*')){
        float m2[][];
        unsigned int rows2, columns2;
        char znak2;
        if((stream>>rows2)&&(stream>>znak2)&&(stream>>columns2)){
            float ** m2 = new float *[ rows2 ];
            for( unsigned int i = 0; i < rows2; ++i ) {
                m2[ i ] = new float[ columns2 ];
                for( unsigned int j = 0; j < columns2; ++j ) {
                    if(!(stream>>m2[i][j])){
                        cout<<"An error has occured while reading input data"<<endl;
                        return -5;
                    }
                }
            }
        }
        else{
            cout<<"An error has occured while reading input data"<<endl;
            return -4;
        }
        if((op=='+')&&(rows1==rows2)&&(columns1==columns2)){
            for(int i=0; i<rows1; ++i){
                for(int j=0; j<columns1; ++j){
                    cout<<(m1[i][j]+m2[i][j])<<" ";
                }
                cout<<endl;
            }
        }
        if((op=='-')&&(rows1==rows2)&&(columns1==columns2)){
            for(int i=0; i<rows1; ++i){
                for(int j=0; j<columns1; ++j){
                    cout<<(m1[i][j]-m2[i][j])<<" ";
                }
                cout<<endl;
            }
        }
        if((op=='*')&&(columns1==rows2)){
            for(int i=0; i<rows1; ++i){
                for(int j=0; j<columns1; ++j){
                    int result_op=0;
                    for(int k=0; k<
            }
        }
        else{
            cout<<"ERROR"<<endl;
            return 1;
        }
