/* 
Cho một dãy các số nguyên dương, hãy viết chương trình tìm các số nguyên tố trong dãy đó.

Đầu vào: 

Dòng đầu tiên chứa một số nguyên dương n là số lượng các số trong dãy. n<=10^6
Dòng tiếp theo chứa n số nguyên dương Ai (2<=Ai<=106) là các phần tử của dãy.
Đầu ra: In ra màn hình các số nguyên tố trong dãy đầu vào, cách nhau bởi dấu cách, không thay đổi thứ tự xuất hiện.

Gợi ý: Ban đầu tạo một mảng đánh dấu các số nguyên tố từ 2 đến 10^6. Sau đó dựa vào mảng này để tìm các số nguyên tố trong dãy số Ai.
*/


// I'm too exhausted to comment anything else. Bruh~
// This didn't passed those hidden cases. Idk why. Over-timed-complexity?

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long long t)
{
    for (int i = 2; i <= sqrt(t); ++i)
    {
        if (t % i == 0) { return false; }
    }
    return true;

}

int main()
{
    long long n = 0; cin >> n;
    vector<long long> OK;
    vector<long long> pp;
    for (long long i = 0; i < n; ++i)
    {
        long long temp = 0; cin >> temp;

        OK.push_back(temp);
    }

    for (long long i = 0; i < OK.size(); ++i)
    {
        long long temp = OK[i];
        if (temp == 2) { pp.push_back(temp); }
        else
        {
            if (temp > 2 && temp % 2 != 0)
            {
                if(isPrime(temp)) {pp.push_back(temp);}
            }
        }
    }

    for (long long i = 0; i < pp.size(); ++i)
    {
        cout << pp[i] << " ";
    }
}
