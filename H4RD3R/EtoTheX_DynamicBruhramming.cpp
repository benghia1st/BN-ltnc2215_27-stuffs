#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const double EPSILON = 0.001;

// Chuỗi e^x = Tổng sigma từ x^0/0! cho đến x^n/n! (thỏa mãn Tổng sau - Tổng trước < Sai số)
long double findE(long double x)
{
	long double output = 0.0f;
	long double pre_output = 0.0f;
	vector<long double> factorial;
	vector<long double> x_n;

	// factorial[2] = {1, 1}
	factorial.push_back(1); // 0! = 1
	factorial.push_back(1); // 1! = 1
	// x_n[2] = {1, x}
	x_n.push_back(1); // x ^ 0 = 1
	x_n.push_back(x); // x ^ 1 = x

	output += 1.0f;

	long long i = 1;
	while (output - pre_output > EPSILON)
	{
		pre_output = output;
		output += x_n[i]/factorial[i];
		++i;

		// Tính phân số tiếp theo: x^n / Giai thừa n!
		x_n.push_back(x_n[i - 1] * x);
		factorial.push_back(i * factorial[i - 1]);

	} 

	return output;
}

int main ()
{
	// Chương trình tính số e^x bằng quy hoạch động (phiên bản 0.1 - từ dưới lên)
	long double x = 0, eNUM = 0; // Khởi tạo biến, đặt giá trị 0

	cout << "----------------------------------" << endl;
	cout << "Nhap so x: "; // Lời gọi nhập số
	cin >> x; // Nhập số

	// Tính toán bằng vòng lặp
	eNUM = findE(x);

	// In kết quả
	cout << endl;
	cout << "So e^" << x;
	cout << fixed << setprecision(4) << " co gia tri la: " << eNUM << endl;	
	cout << endl << "----------------------------------" << endl;
	

	return 0;
}
