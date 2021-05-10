#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
typedef const unsigned int cu;
typedef long double ld;
using namespace std;
int main() {
/*#ifndef ONLINE_JUDGE
    FILE* stream;
    freopen_s(&stream, "file_input.txt", "r", stdin);
    freopen_s(&stream, "file_output.txt", "w", stdout);
#endif*/
    string filename("file_input.txt");
    ifstream myfile(filename);
    if (!myfile.is_open())
    {
        cout << "couldnt open this file please fix the error and try again";
        return EXIT_FAILURE;
    }
    ll n;
    cout << "enter the number of rows which you want to distribute the data (number of class interval)" << endl;
    cin >> n;
    //cout << n << "n";
    vector<ll>v;
    ll mx = INT_MIN,mn=1e9+1;
    while (!myfile.eof())
    {
        ll a;
        myfile >> a;
        v.push_back(a);
        mx = max(mx, a);
        mn = min(mn, a);
    }
    ll width_interval = (ll)(mx - mn) / n;
    //vector<pair<ll,ll> >interval(n, 0);
    ll temp = mn;
    sort(v.begin(), v.end());
   /* for (ll i = 0;i < 100000;i++)
    {
        cout << rand() % 10000 + 100<<endl;
    }*/

    while (temp < mx)
    {
            cout << temp <<" "<<temp+width_interval;
            ll c = 0;
            for(ll i = 0;i < v.size();i++)
            {
                if (v[i] >= temp && v[i] <= temp+width_interval)
                {
                    c++;
                }
               // if (temp + width_interval < v[i])
                 //   break;
                //else break;
            }
            cout << " " << c <<"  "<<(double)c/v.size()*100<< endl;
            temp += width_interval+1;
    }


 

    myfile.close();
    return EXIT_SUCCESS;
}
