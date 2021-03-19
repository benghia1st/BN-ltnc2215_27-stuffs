#include <iostream> // Of course ~
#include <sstream> // For the String to StringStream to Int, urggggg
#include <fstream> // Working with file
#include <utility> // Pair-y the Platypus
#include <vector> // Vector<>
#include <algorithm> // Sort Sort Sort
using namespace std;
 
int main()
{
	ifstream love;
	string path = "";
	//cout << "PATH TO LOVE: ";
 	cin >> path;

	love.open(path);
	if (love.fail() == true)
	{
		cout << "NO LOVE";
		return 0;
	}
	pair<string, int> hocsinh;
	vector<pair<string, int>> HSLIST; 
  
	while(!love.eof())
	{
		string number;
		getline(love, number, ',');
		int num = 0; stringstream intoNum(number);
		intoNum >> num;

		string name;
		getline(love, name);
		if (name != "")
		{
			hocsinh = make_pair(name, num); 
			HSLIST.push_back(hocsinh); 	
		}
	}
	sort(HSLIST.begin(), HSLIST.end());
	int numofHS = HSLIST.size();
	for (int points = 10; points >= 0; --points)
	{
		for (int HSid = 0; HSid < numofHS; ++HSid)
		{
			if (HSLIST[HSid].second == points) { cout << HSLIST[HSid].first << endl; }
		}
	}

	return 0;
}

// Giải thích thuật toán:
/*
    > Đọc đường dẫn file, rồi đọc file
    >> Đọc các nội dung trong file:
    - Lọc số dưới dạng string, đưa về dạng stringstream rồi lại đưa về int <hơi thừa, có thể tối giản bằng cách sử dụng nguyên dưới dạng string>
    ! Vì không thể dùng stoi nên phải lằng nhằng như thế.
    - Lọc xâu tên học sinh: nếu xâu không rỗng thì đưa vào một xâu chứa tên.
    >>> Đưa tên học sinh và điểm vào mảng kép <pair>. Đưa mảng kép vừa tạo vào một vector.
    
    > Xử lí: Vì pair có dạng <điểm, tên>, nên khi sắp xếp bằng thuật toán sort (thư viện algorithm), ta được
    một mảng gồm các phần tử tên đã được sắp thứ tự Alphabet (bên trái); các phần tử bên phải phụ thuộc vào sự sắp xếp này.
    >> Vòng lặp kép <cần tối ưu hơn>:
    - Vòng ngoài: từ 10 đến 0 là số điểm i <giảm dần>
    - Vòng trong: Từ học sinh thứ nhất đến học sinh cuối:
    + Nếu điểm bạn đó bằng với i thì in ra tên. Do đã được sắp xếp theo tên nên đầu ra hợp lệ.
    
    <Tự đánh giá> Code chưa chú thích, chưa phân thành hàm, chưa thực sự tối ưu <đã nêu trên>.
*/

/* Ví dụ: LOVE.txt
-INPUT <LOVE.txt>:-
10,Dai Ca Giang Ho
9,Kha Ba Ngo
2,Ngo Ba Kha
3,Chu Cuoi
5,Chu Dong Tu
5,Le Van Hews
3,Cac Cu Co Cau
2,Cac Cau Co

-OUTPUT:-
Dai Ca Giang Ho
Kha Ba Ngo
Chu Dong Tu
Le Van Hews
Cac Cu Co Cau
Chu Cuoi
Cac Cau Co
Ngo Ba Kha
	
*/
