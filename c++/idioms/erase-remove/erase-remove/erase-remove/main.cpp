#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::remove, std::remove_if, std::copy
#include <iterator>  // std::ostream_iterator

using namespace std;

int main()
{
	// https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
	// https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Erase-Remove
	vector<int> v1{1,2,3,99,5,99,7,8,9,99};
	v1.erase(remove(v1.begin(), v1.end(), 99), v1.end());
	std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
	cout << endl;

	vector<int> v2{ 1,2,3,99,5,99,7,8,9,99 };
	v2.erase(remove_if(v2.begin(), v2.end(), [](int a) { return a == 99; }), v2.end());
	std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
	cout << endl;

	return 0;
}
