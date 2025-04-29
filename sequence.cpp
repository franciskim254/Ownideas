//an interview question on sequences
#include <iostream>
#include <vector>

using namespace std;

int classifyPattern(const vector<int>& theList){

	bool isNegative = false;
	bool isPositive = false;
	bool alternatingSign = true;
	bool strictlyIncr=true;
	bool strictlyDecr=true;

	if (theList.size()<2)return -1;

	for (int i=0; i+1<theList.size();i++){
		if(theList[i]>0)isPositive=true;
		if(theList[i]<0)isNegative=true;

		if(i>0){
			if (theList[i]*theList[i-1]>0)alternatingSign=false;
		}
		if(theList[i]<=theList[i+1])strictlyDecr=false;
		if(theList[i]>=theList[i+1])strictlyIncr=false;

	}
	if(strictlyIncr)return 1;
	if(strictlyDecr)return 2;
	if(alternatingSign)return 3;
	if(isNegative && !isPositive || !isNegative && isPositive)return 4;

	return 5;// eventually returns this if no pattern for signs is found
} 

int main(){
vector<vector<int>> testCases = {
        {1, 2, 3, 4, 5},         // strictly increasing → 1
        {9, 7, 5, 3, 1},         // strictly decreasing → 2
        {-1, 2, -3, 4, -5},      // alternating signs → 3
        {3, 3, 3},               // all positive → 4
        {-2, -2, -2},            // all negative → 4
        {3, -5, 2, 9, -1},       // random signs → 5
        {8}                      // too small → -1
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ": ";
        for (int num : testCases[i]) cout << num << " ";
        cout << "\n Classification: " << classifyPattern(testCases[i]) << "\n\n";
    }
	return 0;
}
