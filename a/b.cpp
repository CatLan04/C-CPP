#include <iostream>
using namespace std;

int main()
{
	int array[4] = { 5, 8, 2, 7 };

	// in giá trị của biến array
	cout << "The array has value: " << array << '\n';

	// in địa chỉ của biến array
	cout << "The array has address: " << &array << '\n';

	// in địa chỉ của phần tử array[0]
	cout << "Element 0 has address: " << &array[1] << '\n';

	system("pause");
	return 0;
}

