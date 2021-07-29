# 이분 탐색(Binary Search) 알고리즘

## Binary Search Algorithm
### 📖개념	
- <b>`정렬되어 있는` 리스트에서 탐색 범위를 절반씩 좁혀가며 데이터를 탐색하는 알고리즘</b>
### ✅특징
- <b>원리</b><br>
![1](https://user-images.githubusercontent.com/68049320/127440813-5a676719-2998-42bc-a6d0-0b7d4c5191f7.gif)
	- 변수(`low`, `high`, `mid`)를 이용하여 구현한다.
	- 찾으려는 데이터와 중간 위치에 있는 데이터를 반복적으로 비교하며 원하는 데이터를 찾는 것이 위의 과정이다.
- <b>STL</b>
	- `<algorithm>` 헤더를 include하면 아래의 함수들을 사용할 수 있으며, 반드시 오름차순 정렬된 상태의 리스트에서만 사용해야 한다.
		- `std::binary_search(iterator, iterator, T)`
			- 찾으려는 값이 있으면 true, 없다면 false를 반환한다.
			```c++
			vector<int> v;
			int findNumber = 5;
			bool isFind = binary_search(v.begin(), v.end(), findNumber);
			```
		- `std::lower_bound(iterator, iterator, T)`
			- 찾으려는 값과 같거나, 큰 숫자의 가장 앞에 있는 iterator를 반환한다.
			```c++
			vector<int> v;
			int findNumber = 5;
			iterator iter = lower_bound(v.begin(), v.end(), findNumber);
			int lower_index = lower_bound(v.begin(), v.end(), findNumber) - v.begin();
			```
		- `std::upper_bound(iterator, iterator, T)`
			- 찾으려는 값을 초과하는 숫자 중 가장 앞에 있는 iterator를 반환한다.
			```c++
			vector<int> v;
			int findNumber = 5;
			iterator iter = upper_bound(v.begin(), v.end(), findNumber);
			int upper_index = upper_bound(v.begin(), v.end(), findNumber) - v.begin();
			```
- <b>활용</b>
	- 리스트에 존재하는 X 이상 Y 이하의 값의 개수 구하기
	```c++
	sort(arr.begin(), arr.end());

	cout << upper_bound(arr.begin(), arr.end(), Y) - lower_bound(arr.begin(), arr.end(), X);
	```
	- [최장 증가 부분 수열(LIS)의 길이 구하기](https://github.com/seonpilKim/Algorithm/tree/master/Binary%20Search/Longest%20Increasing%20Subsequence)
	
- <b>시간 복잡도</b>
	- `O(log₂N)`
### 💻구현
```c++
bool binarySearch(const vector<int>& arr, const int& target) {
	int low = 0, high = arr.size() - 1, mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == target)
			return true;

		if (arr[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return false;
}
```
___