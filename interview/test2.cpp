#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

bool isContained(const string &s1, const string &s2){
    if(s1.size() < s2.size()) return false;
    if(s1.size() == s2.size() && s1 != s2) return false;
    // 用双指针法
    int p1 = 0, p2 = 0;
    for(p1 = 0; p1 < s1.size(); ++ p1){
        if(s1[p1] == s2[p2]){
            p2 ++;
        }
        if(p2 == s2.size()) return true;
    }
    return false;
}


int main(){
    int n;
    cin >> n;
    vector<bool> result;
    for (int i = 0; i < n; ++ i){
        string s1, s2;
        cin >> s1; cin >> s2;
        bool tmp = isContained(s1, s2);
        result.push_back(tmp);
    }

    //output
    for(int i = 0; i < result.size(); ++ i){
        if(result[i])
            cout << "yes" << endl;
        else
            cout  << "no" << endl;
    }

    return 0;
}