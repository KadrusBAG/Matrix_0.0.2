#include <iostream>
#include <sstream>
using namespace std;

bool proverka_mat(int mat[n][k]){
    bool result=true;
    for(int i=0; i<n; ++i){
        string stroka;
        getline(cin, stroka);
        istringstream stream(stroka);
        for(int j=0; j<k; ++j){
            if(!(stream>>mat[i][j])){
                result=false;
                break;
            }
        }
        if(!(result)){break;}
    }
    return result;
}

int main()
{
    int n, k;
    cin>>n; cin>>k;
    int mat[n][k];
    if(proverka_mat(mat)){
        char op;
        cin>>op;
        if(op=="+"){
            int n1, k1;
            cin>>n1; cin>>k1;
            int mat[n1][k1];
            if(proverka_mat(mat1)){
                cout<<endl;
                for(int i=0; i<n1; ++i){
                    for(int j=0; j<k1; ++j){
                        cout<<(mat1[i][j]+mat2[i][j])<<" ";
                    }
                    cout<<endl;
                }
            }
            else{
                cout<<"An error has occured while reading input data"<<endl;
                return -1;
            }
        }
        if(op=="-"){
            if(proverka_mat(mat2)){
                cout<<endl;
                for(int i=0; i<3; ++i){
                    for(int j=0; j<3; ++j){
                        cout<<(mat1[i][j]-mat2[i][j])<<" ";
                    }
                    cout<<endl;
                }
            }
            else{
                cout<<"An error has occured while reading input data"<<endl;
                return -1;
            }
        }
        if(op=="*"){
            if(proverka_mat(mat2)){
                cout<<endl;
                for(int i=0; i<3; ++i){
                    for(int j=0; j<3; ++j){
                        int result_op=0;
                        for(int k=0; k<3; ++k){
                            result_op+=mat1[i][k]*mat2[k][j];
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
        
    }
    else{
        cout<<"An error has occured while reading input data"<<endl;
        return -1;
    }
return 0;
}
