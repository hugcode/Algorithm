#include <iostream>

using namespace std;

string str;
int cur;
int mod = 10000;

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
    int sum;
    int tmp;

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
        sum %= mod;
    }

    cout << sum%mod << endl;

    return 0;
}
