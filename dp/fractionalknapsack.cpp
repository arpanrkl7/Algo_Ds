#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv){

    vector<int> wt {10,40,20,30};
    vector<int> val{60,40,100,120};
    int tw = 50;
    int maxival = 0;
    vector<int> ratio(wt.size(),0);
    for(int i = 0;i<ratio.size();i++){
        ratio[i] = val[i] / wt[i];
    }

    vector<bool> flag(ratio.size(), false);

    while(tw>0){
        int maxvalue = 0;
        int pos = 0;
        for(int i=0;i<ratio.size();i++){
            if(ratio[i] > maxvalue){
                maxvalue = ratio[i];
                pos = i;
            }
          //  flag[pos] = true;
            
        }
        if(wt[pos] <= tw && flag[pos] == false){
                flag[pos] = true;
        tw = tw - wt[pos];
        maxival+= val[pos];
        }
        else{
            maxival+= (ratio[pos] * tw);
            tw = 0;
        }
        
    }

    cout << maxival << endl;
}