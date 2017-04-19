#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
  map<string, string> dict;
  int tries = 0;
  cin >> tries;
  for(int i = 0; i < tries; i++){
    string val = "";
    string key = "";
    cin >> key;
    cin >> val;
    //dict[key] = val;
    dict.insert(pair<string,string>(key,val) );
  }
  tries = 0;
  cin >> tries;
  map<string, string>::iterator it;
  for(int i = 0; i < tries; i++){
    string word = "";
    cin >> word;
    if (dict.count(word)>0){
      cout << dict.find(word)->second;
    }else{
      cout << word<<endl;
    }


  }
  return 0;
}
