#include <iostream>

using namespace std;

string str;
int cur;

unsigned int get_num()
{
    unsigned int num = 0;

    while(str[cur] >='0' && str[cur] <= '9')
    {
        num = num*10 + (str[cur]-'0');
        cur++;
    }

    return num;
}

int main(void)
{
    unsigned long long sum;
    unsigned long long tmp;

    cin >> str;

    cur = 0;
    sum = 0;
    while(cur <= str.length())
    {
        tmp = get_num();
        while (str[cur] == '*')
        {
            cur++;
            tmp *= get_num();
        }
        cur++;
        sum += tmp;
    }

    cout << sum << endl;

    return 0;
}
