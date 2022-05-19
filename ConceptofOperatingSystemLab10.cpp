#include <iostream>
using namespace std;
int page_fault = 0;
int temp[3] = {-1};

int hole = 0;
int g = 0;
int y = 0;
void fifo(int prs [], int total){
    cout << "FIFO page replacement" << endl;
    page_fault = 0;

    for(int i=0; i<total; i++)
        temp[i] = -1;

    for(int i=1; i<=total; i++){
        cout << prs[i] << ":   ";
        hole = 0;

        for(g=0; g<3; g++)
            if(temp[g] == prs[i]){
                hole = 1;
                break;
            }

        if(hole==0){
            temp[y] = prs[i];
            y=(y+1)%3;
            page_fault++;
            for(int l=0; l<3; l++)
                cout << temp[l] << " --- " ;
        }
        cout << endl;
    }
 cout<< endl << "FIFO~ page fault = " << page_fault << endl << endl;
}

void lru(int prs [], int total){
    int res[total]; int r=0;
    cout << "Least recently used page replacement " << endl;
    page_fault = 0;
    g=0; y=0;
    for(int i=0; i<total; i++)
        temp[i] = -1;
    for(int i=1; i<=total; i++){
        cout << prs[i] << ":   ";
        hole = 0;
        for(g=0; g<3; g++){
            if(temp[g] == prs[i]){
                hole=1;
                break;
            }
        }
        if(hole==0){
            for(g=0; g<3; g++)
                res[g] = 0;
            for(g=0, r=i-1; g<3-1; g++, r--){
                for(int q=0; q<3; q++){
                    if(temp[q] == prs[r])
                        res[q] = 1;
                }
 }
            for(g=0; g<3; g++)
                if(res[g] == 0)
                    y=g;
            temp[y] = prs[i];
            page_fault++;
            for(int l=0; l<3; l++)
                cout << temp[l] << " --- " ;
        }
        cout << endl;
    }
    cout << endl << "LRU~ page fault = " << page_fault << endl;
}

void optimal(int prs [], int total){
    cout << "Optimal page replacement " << endl;
    page_fault = 0;
    int res[total]; int max=0;
    g=0; y=0; int w=0; int flag=0, flag2 =0;
    for(int i=0; i<total; i++)
        temp[i] = -1;
    for(int i=1; i<=total; i++){
        cout << prs[i] << ":   ";
        hole = 0;
        flag = 0;
        for(g=0; g<3; g++){
            if(temp[g] == prs[i]){
                hole=1;
                flag =1;
                break;
  }
        }
        if(hole==0){
            for(g=0; g<3; ++g){
                if(temp[g] == -1){
                    page_fault++;
                    temp[g] = prs[i];
                    flag = 1;
                    break;
                }
            }
        if(flag==0){
            flag2=0;
            for(g=0; g<3; ++g){
                temp[g] = -1;
                for(w=i+1; i<3; ++w){
                    if(temp[g] == prs[i]){
                        res[g] = w;
                        break;
                    }
                }
            }
        }
        for(g=0; g<3; ++g){
            if(res[g] == -1){
                y=g;
                flag2=1;
                break;
            }
   }

            for(int l=0; l<3; l++)
                cout << temp[l] << " --- " ;
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout<< endl << "Optimal ~ page fault = " << page_fault << endl;
}

int main(){
    int prs[21] = {0,7,2,3,1,2,5,3,4,6,7,7,1,0,5,4,6,2,3,0,1};

    cout << " Page references: " << endl;
        for(int s=1; s<=21; s++)
                cout << prs[s] << " ";
        cout << endl << endl;
    fifo(prs, 20);
    lru(prs, 20);
    optimal(prs, 20);
}
