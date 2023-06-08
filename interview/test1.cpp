#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdio>

using namespace std;

int main(){
    int n;
    vector<int> nums;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
        // cin >> nums[i];
        // scanf("%d ", &nums[i]);
    }

    // key = 数字， value = 下标
    unordered_map<int, int> umap;
    for(int i = 0; i < nums.size(); i ++){
        umap[nums[i]] = i;
    }

    int num = 1, count = 0;
    bool foundAll = true;
    while(count < nums.size()){
        if(umap.count(num) == 0){
            foundAll = false;
            cout << num -1 << endl;
        }
        num ++;
        count ++;
    }
    if(foundAll)
        cout << num - 1 << endl;

    return 0;
}