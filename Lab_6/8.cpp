#include <iostream>
#include <string>

bool Check(std::string s, std::string t, long long count)
{
    bool move_right = 1;
    for (int i = 0; i < t.size() - 1; i++)
    {

        if (count < s.size() - 1)
        {
            if (s.at(count + 1) == t.at(i + 1) && move_right)
            {
                count++;
                continue;
            }
            if (count > 0)
                if (s.at(count - 1) == t.at(i + 1))
                {

                    move_right = 0;
                    count--;
                    continue;
                }

        }
        if (count > 0)
        {
            move_right = 0;
            if (s.at(count - 1) == t.at(i + 1))
            {
                count--;
                continue;
            }

           
            return 0;
        }
        
        return 0;
    }
    return 1;
}

int main()
{
    int num = 0;
    std::cin >> num;
    bool check = false;
    std::string s, t;
    for (int i = 0; i < num; ++i)
    {
        check = false;
        
        std::cin >> s >> t;

        int size = s.size();
        for (int j = 0; j < size; ++j)
        {
            if (s.at(j) == t.at(0))
                if (Check(s, t, j))
                {
                    check = true;
                    break;
                }
        }
        
        check ? std::cout << "YES\n" : std::cout << "NO\n";

    }
    return 0;
}