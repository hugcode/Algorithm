#include <iostream>
#include <stdlib.h>

using namespace std;

string str;
int cur;
int adj = 1;

int get_num()
{
    int num = 0;
    int sign = 1;
   
    if(str[cur] == '+') {
        sign = 1;
        cur++;
    }
    else if(str[cur] == '-') {
        sign = -1;
        cur++;
    }

    while(str[cur] >='0' && str[cur] <= '9')
    {
        num = num*10 + (str[cur]-'0');
        cur++;
    }

    /* move all to left side of formula */
    return adj*sign*num;
}

int main(void)
{
    cin >> str;
    int num;
    long long var, con;
    char name;

    cur = 0;
    var = 0;
    con = 0;
    while(cur < str.length())
    {
        num = get_num();
        //cout << num << endl;

        if (str[cur] >= 'a' && str[cur] <= 'z') 
        {
            name = str[cur];
            var += num;    
            cur++;
        }
        else
        {
            con += num;
            if(str[cur] == '=')
            {
                adj = -1;
                cur++;
            }
        }
    }

    /* move var to right side of formula */
    var = 0 - var;
    
    //cout << "var " << var << " con " << con << endl;
    if (con == 0) var=abs(var);
    printf("%c=%.3f\n", name, (double)con/var);

    return 0;
}
