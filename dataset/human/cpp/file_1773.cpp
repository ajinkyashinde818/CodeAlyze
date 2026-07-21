#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char **argv)
{
	int nLength, nRequests;

	cin >> nLength >> nRequests;

	vector<int> tmpRequests;
	tmpRequests.reserve(nRequests);

	for (int i = 0; i < nRequests; i++)
	{
		int query;
		cin >> query;
		tmpRequests.push_back(query);
	}

	vector<int> requestVec;
	set<int> requestSet;

	requestVec.reserve(nRequests);

	for (int i = 0; i < nRequests; i++)
	{
		int query = tmpRequests[nRequests - 1 - i];

		if (requestSet.find(query) == requestSet.end())
		{
			requestVec.push_back(query);
			requestSet.insert(query);
		}
	}

	for (int i = 0; i < requestVec.size(); i++)
		cout << requestVec[i] << endl;

	for (int i = 1; i <= nLength; i++)
	{
		if (requestSet.find(i) == requestSet.end())
			cout << i << endl;
	}

	return 0;
}
