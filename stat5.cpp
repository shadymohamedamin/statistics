#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
typedef const unsigned int cu;
typedef long double ld;
using namespace std;
/*float geometric(vector<int>&v)
{
	float shady = 0;
	for (int i = 0;i < v.size();i++)
	{
		shady += log(v[i]);
	}
	shady = shady / v.size();
	return exp(shady);
}*/
int main() {
	/*#ifndef ONLINE_JUDGE
		FILE* stream;
		freopen_s(&stream, "file_input.txt", "r", stdin);
		freopen_s(&stream, "file_out.txt", "w", stdout);
	#endif*/
	string filename("file_out.txt");
	ifstream myfile(filename);
	if (!myfile.is_open())
	{
		cout << "couldnt open this file please fix the error and try again";
		return EXIT_FAILURE;
	}
	vector<ll>v;
	ll mx = INT_MIN, mn = 1e9 + 1;
	ll sum1 = 0;
	ll f = 1;
	float harm = 0;
	float geo = 0;
	while (!myfile.eof())
	{
		ll a;
		myfile >> a;
		v.push_back(a);
		mx = max(mx, a);
		mn = min(mn, a);
		sum1 += a;
		geo += log(a);
		harm += (double)1/a;
	}
	
	cout << v.size() <<"			the size of elements"<<endl;
	cout << mx <<"			the maxinmum element"<< endl;
	cout << mn <<"			the minimum element"<< endl;
	cout <<(double) sum1 / v.size() <<"			arithmetic mean"<< endl;
	ll sum2 = 0, sum3 = 0;
	//cout << v[0] << " " << v[99];
	//cout << v[88];
	for (int i =10 ;i <89;i++)//v.size()-1-trimed mean
	{
		sum2 += v[i];
	}
	for (int i = 20;i < 79;i++)
	{
		sum3 += v[i];
	}
	cout << (double)sum2 / 80 <<"			10% trimmed mean"<< endl;
	cout << (double)sum3 / 60 << "			20% trimmed mean" << endl;
	cout << (double)exp(geo/v.size()) <<"			geometric mean"<< endl;
	cout << (float)v.size() / harm <<"			harmonic mean"<< endl;
	sort(v.begin(), v.end());
	cout << (double)(v[49]+v[50]) / 2 <<"			median"<< endl;
	cout << (double)(mx + mn) / 2 <<"			midrange"<< endl;
	int mxx1 = 0,mxx2=0,mxx3=0,el1=0,el2=0,el3=0;
	map<int, int>mp;
	for (int i = 0;i < v.size();i++)
		mp[v[i]]++;
	for (auto& i : mp)
	{
		if (i.second > mxx1)
		{
			mxx1 = i.second;
			el1 = i.first;
		}
	}
	for (auto& i : mp)
	{
		if (i.second > mxx2&&i.first!=el1)
		{
			mxx2 = i.second;
			el2 = i.first;
		}
	}
	for (auto& i : mp)
	{
		if (i.second > mxx3&& i.first != el1&& i.first != el2)
		{
			mxx3 = i.second;
			el3 = i.first;
		}
	}
	//cout << mxx1 << " " << mxx2 << " " << mxx3 << endl;
	if (mxx1 > mxx2 && mxx1 > mxx3) cout << mxx1 << "			unimodal" << endl;
	//else if (mxx1 == mxx2 && mxx2 == mxx3) cout << mxx1 << "			multimodel"<< endl;
	else if (mxx1 == mxx2 && mxx1 != mxx3) cout << mxx1 << "			biomodal" << endl;
	else if (mxx1 == mxx3 && mxx1 != mxx2) cout << mxx1 << "			biomodal" << endl;
	else cout << mxx1 << "			multimodal" << endl;
	

	myfile.close();
	return EXIT_SUCCESS;
}
