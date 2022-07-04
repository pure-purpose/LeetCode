#include<iostream>
#include<stack>
#include<unordered_set>
#include<unordered_map>

int main(int argc, char const *argv[])
{
    std::string s = "bpfbhmipx"; //"aabaab!bb";
    std::unordered_map<char, int> map;
    int ans = 0;
    int last_repeat = 0;
    size_t len = s.size();
    for(int i = 0; i< len; i++)
    {
        if(map.find(s[i]) != map.end())
        {
            ans = std::max(ans, (int)map.size());
            for(int j = last_repeat, last_repeat = map[s[i]]; j < last_repeat; j++)
            {
                map.erase(s[j]);
            }
        }
        map[s[i]] = i;   
        for(auto it : map)
        {
            std::cout << it.first << " " << it.second << ",";
        }
        std::cout << std::endl;
    }
    ans = std::max(ans, (int) map.size());
    // for (auto c : s)
    // {
    //     if (set.find(c) != set.end())
    //     {
    //         ans = std::max(ans, (int)set.size());
    //         set.erase(set.begin(), set.find(c));
    //         set.erase(set.find(c));
    //     }
    //     set.insert(c);
    // }
    // std::stack<int> data;
    // int tmp = data.top();
    // size_type
    std::cout << ans << std::endl;
    return 0;
}