#include <string.h>  
#include <iostream>  
#include <map>  
#include <utility>  
#include<vector> 
using namespace std;

vector< map<string,int>::const_iterator> vec;
map<string,int> m;
vector< map<string,int>::const_iterator> check_m(const map<string,int> m, int val){
    // for( map<string, int>::iterator i=m.begin(); i!=m.end(); ++i)  
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second == val){
          vec.push_back(it);
        }  
  }
  return vec;
}

int main() {
  return 0;
}
