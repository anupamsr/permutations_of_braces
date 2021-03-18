#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

bool is_balanced(const vector<char> & str)
{
    stack<char> s;
    for (const char & c : str)
    {
        if (c == '{')
        {
            s.push(c);
        }
        else
        {
            if (s.size() == 0)
            {
                return false;
            }
            else
            {
                if (s.top() == '{')
                {
                    s.pop();
                }
            }
        }
    }
    return s.size() == 0;
}


auto get_braces(const size_t n)
{
    set<string> res;
    switch (n)
    {
    case 0:
        return res;
    case 1:
        res.insert("{}");
        return res;
    }
    auto prev_results = get_braces(n - 1);
    for (const auto & prev_result : prev_results)
    {
        vector<char> start(prev_result.begin(), prev_result.end());
        for (size_t i = 0; i <= start.size() + 1; ++i)
        {
            for (size_t j = i + 1; j <= start.size() + 1; ++j)
            {
                auto new_str = start;
                new_str.insert(new_str.begin() + i, '{');
                new_str.insert(new_str.begin() + j, '}');
                if (is_balanced(new_str))
                {
                    string str(new_str.begin(), new_str.end());
                    res.insert(str);
                }
            }
        }
    }
    return res;
}

void print_results(const size_t n)
{
    auto res = get_braces(n);
    for (const auto & str : res)
    {
        cout << str << endl;
    }
}

int main()
{
    print_results(4);
    return 0;
}
