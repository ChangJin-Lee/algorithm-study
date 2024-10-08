#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    int n,k,a,b;
    string input;
    vector<pair<int,int>> v;
    set<tuple<int, int, int>> movable;
    set<tuple<int, int, int>> movable2;
    pair<int,int> cur;
    cin >> n >> k;
    cin >> input;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;

        movable.insert({a+b, a, b}); // b, c
        movable2.insert({a-b, a, b}); // a, d

        if(i == 0)
        {
            cur = {a,b};
        }
        
    }

    for(int idx = 0; idx < k; idx++)
    {
        int x = cur.first;
        int y = cur.second;

        switch (input[idx])
        {
        case 'A':
            {
                auto it = movable2.find({x-y, x, y});
                if(it != prev(movable2.end()))
                {
                    tuple<int, int, int> t;
                    t = *next(it);
                    if(get<0>(t) == x-y)
                    {
                        movable2.erase({x-y,x,y});
                        movable.erase({x+y,x,y});
                        cur = {get<1>(t), get<2>(t)};
                    }
                }
            }
            break;
        case 'D':
            {
                auto it = movable2.find({x-y, x, y});
                if(it != movable2.begin())
                {
                    tuple<int, int, int> t;
                    t = *prev(it);
                    if(get<0>(t) == x-y)
                    {
                        movable2.erase({x-y,x,y});
                        movable.erase({x+y,x,y});
                        cur = {get<1>(t), get<2>(t)};
                    }
                }
            }
            break;
        case 'B':
            {
                auto it = movable.find({x+y, x, y});
                if(it != prev(movable.end()))
                {
                    tuple<int, int, int> t;
                    t = *next(it);
                    if(get<0>(t) == x+y)
                    {
                        movable2.erase({x-y,x,y});
                        movable.erase({x+y,x,y});
                        cur = {get<1>(t), get<2>(t)};
                    }
                }
            }
            break;
        case 'C':
            {
                auto it = movable.find({x+y, x, y});
                if(it != movable.begin())
                {
                    tuple<int, int, int> t;
                    t = *prev(it);
                    if(get<0>(t) == x+y)
                    {
                        movable2.erase({x-y,x,y});
                        movable.erase({x+y,x,y});
                        cur = {get<1>(t), get<2>(t)};
                    }
                }
            }
            break;
        default:
            break;
        }
    }

    cout << cur.first << " " << cur.second;
}