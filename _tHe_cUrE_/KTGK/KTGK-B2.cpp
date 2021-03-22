/*
Viết chương trình nhập vào một dãy số gồm N phần tử, mỗi phần tử trong khoảng từ 0 đến 9. Kiểm tra xem giá trị số nào không xuất hiện.

Đầu vào:

Dòng đầu tiên chứa N(N<=100) là số lượng phần tử của dãy.
Dòng thứ 2 chứa N số nguyên ai cách nhau bởi dấu cách (0<=ai<=9)
Đầu ra: In ra màn hình danh sách các số không xuất hiện trong dãy sắp xếp từ nhỏ đến lớn và cách nhau bởi dấu cách. Nếu tất cả các số đều xuất hiện thì in ra "None".

VD: 
INPUT:  10
        1 2 0 1 2 3 2 9 6 2
OUTPUT: 4 5 7 8

INPUT:  10
        9 8 7 1 2 3 4 0 5 6
OUTPUT: None
*/

// Libraries and Namespaces
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Main
int main()
{
    // Init & Input the number of elements in the /vcc/ vector. Init the aforesaid vector.
    int numofvcc; cin >> numofvcc;
    vector<int> vcc;
    
    // The /based/ vector, just to check the numbers from 0 to 9
    vector<int> based = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // Loop. /vcc/ input.
    for (int i = 0; i < numofvcc; ++i)
    {
        int temp = 0; cin >> temp;
        vcc.push_back(temp);
    }

    // Sorting out /vcc/. The second line turns the vector into "an unique vector".
    // Example: vcc = {1, 3, 3, 2, 5, 8, 7, 1, 2, 3}
    sort(vcc.begin(), vcc.end()); // Sort: 1 1 2 2 3 3 3 5 7 8
    vcc.erase( unique(vcc.begin(), vcc.end()), vcc.end()); // After erase: 1 2 3 5 7 8
    
    // If /vcc/ = /based/. There is no difference. Output "None".
    if (vcc == based) 
    { 
        cout << "None"; 
    } 
    // Else - Print out the elements which are not available in /vcc/
    else
    {
        for (int i = 0; i < 10; ++i) // Looping through /based/
        {
            bool isBased = binary_search(vcc.begin(), vcc.end(), based[i]); // Binarysearch from the algorithm library. The bool is to check whether the number
                                                                            // in /based/ is also included in /vcc/
            if (isBased == false) {cout << based[i] << " ";}                // If not: Print it out.
        }
    }

}
