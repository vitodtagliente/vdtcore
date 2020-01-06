#include <iostream>
#include <vdtcore/core.h>

using namespace std;
using namespace core;

int fibonacci(int n)
{
	if (n < 3) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	Time time;
	fibonacci(42);
	time.tick();
	cout << "Time: " << time.getTime() << endl;
	cout << "DeltaTime: " << time.getDeltaTime() << endl;

	cout << "Press a key to continue..." << endl;
	return getchar();
}