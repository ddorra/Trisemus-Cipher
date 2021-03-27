#include <string>
#include <iostream>

using namespace std;

#define N 6
#define M 6
char alphabet[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
void Delsymb(char symb, char c[])
{
    for (char* a = c, *b = alphabet; *a; ++a, ++b) {
        while (*a == symb) ++a;
        *b = *a;
    }

}

void Createtable(char t[][N], string& keyword)
{
    int cnt = 0;
    string::iterator it = keyword.begin();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (it != keyword.end())
            {
                t[i][j] = (*it);
                Delsymb(*it, alphabet);
                ++it;
            }
            else
            {
                t[i][j] = alphabet[cnt];
                cnt++;
            }
        }
}

void Encode(char t[][N], string& mes)
{
    string::iterator it = mes.begin();
    while (it != mes.end())
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (t[i][j] == (*it))
                {
                    if (i != (N - 1)) (*it) = t[i + 1][j]; else (*it) = t[0][j];
                    goto next;
                }
            }
    next:       ++it;
    }
}

void Decode(char t[][N], string& mes)
{
    string::iterator it = mes.begin();
    while (it != mes.end())
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (t[i][j] == (*it))
                {
                    if (i != 0) (*it) = t[i - 1][j]; else (*it) = t[N - 1][j];
                    goto next;
                }
            }
    next:       ++it;
    }
}

int main()
{
    char table[N][M];
    string keyword;
    cout << "Enter key word" << endl;
    getline(cin, keyword);
    Createtable(table, keyword);
    string message;
    cout << "Enter message" << endl;
    getline(cin, message);
    string mode;
    cout << "Choice: Encode or Decode" << endl;
    cin >> mode;
    if (mode == "ENCODE")
    {
        Encode(table, message);
        cout << "Coded text:  " << message.c_str() << std::endl;
    }
    else if (mode == "DECODE")
    {
        Decode(table, message);
        cout << "Decoded text:  " << message.c_str() << std::endl;
    }
    else cout << "Date entered incorrectly" << endl;
    return 0;
}