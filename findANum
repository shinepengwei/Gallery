#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std;
void main(){
    const int N=5;
    vector<int> BigInt[N];
    BigInt[1].push_back(0);//除以N余数为1的最小数为1，则表示第0位为1
    bool updated=false;
    for(int i=1,j=10%N;;i++,j=(j*10)%N){//i表示我们现在即考虑10^i+Y,j表示(10^i)%N
        cout<<"i:"<<i<<endl;
        cout<<"j:"<<j<<endl;
        updated=false;
        if(BigInt[j].empty()){
            BigInt[j].push_back(i);
            updated=true;
        }
        for(int k=1;k<N;k++){
            //遍历余数为k的最小数
            if(!BigInt[k].empty()
                &&(i>BigInt[k][BigInt[k].size()-1])//表示不是这一轮放进去的
                &&((k+j)%N)!=0&&BigInt[(k+j)%N].empty()){
                BigInt[(k+j)%N]=BigInt[k];
                BigInt[(k+j)%N].push_back(i);
                updated=true;
            }
            if(!BigInt[k].empty()&&((k+j)%N)==0){
                BigInt[0]=BigInt[k];
                BigInt[0].push_back(i);
                cout<<"Number match:"<<endl;
                for(int c=1,m=BigInt[0].size()-1,t=m;m>=0;m--,c++)
                {
                    
                    while((t-1)>m){
                        cout<<"0";
                        t--;
                    }
                    cout<<"1";
                    if(c%3==0){
                        cout<<" ";
                    }
                    t=m;
                }
                return;
                //END
            }
        }
        if(!updated){
            cout<<"no num matched"<<endl;
            return;//没有结果
        }
    }

}
