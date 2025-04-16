//lets try and sort whatever size of array or vector
#include <iostream>
#include <vector>

using namespace std;

int inspect(const vector<int>& nums){
	if (nums.empty())return -1;

	bool isPositive= false;
	bool isNegative= false;
	bool alternatingSigns= true;

	for (int i=0; i<nums.size(); i++){
		if (nums[i]>0)isPositive = true;
		if (nums[i]<0)isNegative = true;

		if(i>0){
			if (nums[i]>0 && nums[i-1]>0 || nums[i]<0 && nums[i-1]<0){
			alternatingSigns = false;
		     }
		}
		
	}
	if(isPositive && isNegative){
			if(alternatingSigns)return -2;
			return -3;
		}

	
	for (int i=0; i+1 < nums.size(); i++){
		//the above is because we want to access 2 elements at a time to prevent the second element from exceeding bounds when we are at the last item
		bool isEven=false;
		bool isOdd=false;
		bool currEven = nums[i] %2== 0;
		bool nextEven = nums[i+1] %2== 0;

		if(currEven && nextEven && nums[i]<nums[i+1])return 1;
		if(!currEven && !nextEven && nums[i]<nums[i+1])return 2;
		return 3;

	}
	

}

int main() {
    vector<vector<int>> testCases = {
        {2, 4, 6, 8},       // 1
        {1, 3, 5, 7},       // 2
        {3, 2, 7, 10},      // 3
        {},                 // -1
        {1, -2, 3, -4},     // -2
        {-1, 3, 2, -6},     // -3
        {2, 2, 4},          // 3 (not strictly increasing)
        {1, 4, 5, 7},       // 3
    };

    for (const auto& test : testCases) {
        cout << "Result: " << inspect(test) << endl;
    }

    return 0;
}

