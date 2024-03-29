#include "actions.h"

int main()
{
	srand(time(nullptr));

	unsigned int numberOfElements = 0;
	
	while (numberOfElements <= minNumberOfElements)
	{
		cout << "Input number of elements in containers (> 15)" << endl;
		cin >> numberOfElements;
	}

	vector<int> vec;
	vec.reserve(numberOfElements);

	map<int, int> m;

	FillVectorAndMap(vec, m);
	//ShowVectorAndMap(vec, m);

	int numberOfDeleting = IntNumberFromZeroToFifteen();
	//cout << "Will be deleted " << numberOfDeleting << endl;
	DeleteFromVectorAndMap(vec, m, numberOfDeleting);
	//cout << "After deleting" << endl;
	//ShowVectorAndMap(vec, m);

	Sync(vec, m);
	//cout << "After sync" << endl;
	//ShowVectorAndMap(vec, m);

	system("pause");
	return 0;
}