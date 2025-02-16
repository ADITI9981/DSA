
#include<iostream>
using namespace std;

class Solution {
  public:
    int dataTypeSize(string str) {
        if(str=="Character"){
            return sizeof(char);
        }
        else if(str=="Integer"){
            return sizeof(int);
        }
        else if(str=="Long"){
            return sizeof(long);
        }
        else if(str=="Float"){
            return sizeof(float);
        }
        else if(str=="Double"){
            return sizeof(double);
        }
       
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
