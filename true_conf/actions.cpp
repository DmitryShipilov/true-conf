#include "stdafx.h"
#include "actions.h"

void FillVectorAndMap(vector<int>& v, map<int, int>& m)
{
	for (int i = 0; i < v.capacity(); ++i)
	{
		v.push_back(rand() % (highBorder - lowBorder) + lowBorder);
	}

	for (int i = 0; i < v.capacity(); ++i)
	{
		m.insert(make_pair(i, rand() % (highBorder - lowBorder) + lowBorder));
	}
}

void ShowVectorAndMap(const vector<int>& v, const map<int, int>& m)
{
	cout << "Vector contains : " << endl;
	unsigned int index = 0;
	for (auto vec : v)
	{
		cout << "vec[" << index << "] = " << vec << endl;
		index++;
	}
	cout << endl;

	cout << "Map contains :" << endl;
	for (auto map_elem : m)
	{
		cout << "map [" << map_elem.first << "] == " << map_elem.second << endl;
	}

}

void DeleteFromVectorAndMap(vector<int>& v, map<int, int>& m, int numberOfDeleting)
{
	// deleting for vector
	cout << "Deleting..." << endl;
	int deletingMembersFromVector = 0;
	while (deletingMembersFromVector < numberOfDeleting)
	{
		int randIndexForDeleting = rand() % (v.size());
		int index = 0;
		for (auto elemIter = v.begin(); elemIter != v.end(); ++elemIter)
		{
			if (index != randIndexForDeleting)
			{
				index++;
				continue;
			}
			else
			{
				v.erase(elemIter);
				deletingMembersFromVector++;
				break;
			}
		}
	}

	// deleting for map

	int deletingMembersFromMap = 0;
	while (deletingMembersFromMap < numberOfDeleting)
	{
		int randIndexForDeleting = rand() % (m.size());
		int inedxForDeleting = 0;
		for (auto elemIter = m.begin(); elemIter != m.end();)
		{
			if (inedxForDeleting == randIndexForDeleting)
			{
				m.erase(elemIter++);
				deletingMembersFromMap++;
				break;
			}
			else
			{
				++elemIter;
			}
		}
	}
	cout << "Deleting ended" << endl;
}


void Sync(vector<int>& v, map<int, int>& m)
{
	cout << "Syncying..." << endl;
	// checking elements of VECTOR in MAP
	bool lastElemInVector = false;

	while (!lastElemInVector)
	{
		for (auto vecIterator = v.begin(); vecIterator != v.end(); )
		{
			if (vecIterator == v.end() - 1)
				lastElemInVector = true;

			bool elemExistsInMap = false;
			for (auto mapIterator = m.begin(); mapIterator != m.end(); ++mapIterator)
			{
				if (*vecIterator == mapIterator->second)
				{
					elemExistsInMap = true;
					break;
				}
			}
			if (!elemExistsInMap)
			{
				v.erase(vecIterator++);
				break;
			}
			else
			{
				vecIterator++;
			}
		}
	}
	// checking elements of MAP in VECTOR

	for (auto mapIterator = m.begin(); mapIterator != m.end();)
	{
		bool elemExistsInVector = false;
		for (auto vecIterator = v.begin(); vecIterator != v.end(); ++vecIterator)
		{
			if (mapIterator->second == *vecIterator)
			{
				elemExistsInVector = true;
				break;
			}
		}
		if (!elemExistsInVector)
		{
			m.erase(mapIterator++);
		}
		else
		{
			++mapIterator;
		}
	}
	cout << "Syncying ended" << endl;
}

int IntNumberFromZeroToFifteen(void)
{
	return rand() % 16;
}