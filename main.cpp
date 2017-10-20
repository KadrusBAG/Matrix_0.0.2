#include <iostream>
#include <sstream>
using namespace std;

bool proverka_mat(float mat[][]){
    bool f=1;
    string stroka;
    getline(cin,stroka);
    istringstream stream(stroka);
    unsigned int a;
    unsigned int b;
    stream>>a;
    stream.ignore( numeric_limits<streamsize>::max(), ',' );
    stream>>b;
    float **mat=new float*[a];
    for(int i=0; i<a; ++i){
        string stroka;
        getline(cin,stroka);
        istringstream stream(stroka);
        matrix[i]=new float[b];
        for(int j=0; j<b; ++j){
            if(!(stream>>mat[i][j])){
                f=0; break;
            }
        }
        if(!f){break;}
    }
    return f;
}

int main()
{
    float mat[][];
    if(proverka_mat(mat)){
        char op;
        cin>>op;
        if(op=='+'){
            int n1, k1;
            cin>>n1; cin>>k1;
            int mat1[n1][k1];
            if(proverka_mat(n1, k1, mat1)){
                cout<<endl;
                if((n==n1)&&(k==k1)){
                    for(int i=0; i<n; ++i){
                        for(int j=0; j<k; ++j){
                            cout<<(mat[i][j]+mat1[i][j])<<" ";
                        }
                        cout<<endl;
                    }
                }
                else{
                    cout<<"An error has occured while reading input data"<<endl;
                    return -1;
                }
            }
            else{
                cout<<"An error has occured while reading input data"<<endl;
                return -1;
            }
        }
        if(op=='-'){
            int n1, k1;
            cin>>n1; cin>>k1;
            int mat1[n1][k1];
            if(proverka_mat(n1, k1, mat1)){
                cout<<endl;
                if((n==n1)&&(k==k1)){
                    for(int i=0; i<n; ++i){
                        for(int j=0; j<k; ++j){
                            cout<<(mat[i][j]-mat1[i][j])<<" ";
                        }
                        cout<<endl;
                    }
                }
                else{
                    cout<<"An error has occured while reading input data"<<endl;
                    return -1;
                }
            }
            else{
                cout<<"An error has occured while reading input data"<<endl;
                return -1;
            }
        }
        if(op=='*'){
            int n1, k1;
            cin>>n1; cin>>k1;
            int mat1[n1][k1];
            if(proverka_mat(n1, k1, mat1)){
                cout<<endl;
                if(k==n1){
                    for(int i=0; i<n; ++i){
                        for(int j=0; j<k; ++j){
                            int result_op=0;
                            for(int l=0; l<n1; ++l){
                                result_op+=mat[i][l]*mat1[l][j];
                            }
                            cout<<result_op<<" ";
                        }
                    }
                }
                else{
                    cout<<"An error has occured while reading input data"<<endl;
                    return -1;
                }
            }
            else{
                cout<<"An error has occured while reading input data"<<endl;
                return -1;
            }
        }
        if(op=='T'){
            for(int i=0; i<n; ++i){
                for(int j=0; j<k; ++j){
                    cout<<mat[j][i]<<" ";
                }
                cout<<endl;
            }
        }  
    }
    else{
        cout<<"An error has occured while reading input data"<<endl;
        return -1;
    }
return 0;
}
