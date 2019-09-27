#pragma once
int IntNumberFromZeroToFifteen(void);													// returns random value in range [1, 15]

void FillVectorAndMap(vector<int>& v, map<int, int>& m);								// fills vector and map with random values

void ShowVectorAndMap(const vector<int>& v, const map<int, int>& m);					// shows vector and map

void DeleteFromVectorAndMap(vector<int>& v, map<int, int>& m, int numberOfDeleting);	//deletes from vector and map

void Sync(vector<int>& v, map<int, int>& m);											// syncying vector and map
