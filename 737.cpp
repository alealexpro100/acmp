// ЗАДАЧА №737	ДНК
// Из обсуждения.
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main ()
{
    char buffer[1300+1];
    cin>> buffer;
    string s1(buffer);
    cin>>buffer;
    string s2(buffer);
    vector <long long> mul(128,0);
    mul['A'] = 1LL << (16*0);
    mul['C'] = 1LL << (16*1);
    mul['G'] = 1LL << (16*2);
    mul['T'] = 1LL << (16*3);
    vector<long long> all;
    for (int len=(int)min(s1.size(),s2.size()); len >=1; len--)
    {
        all.clear();
        {
            long long code=0;
            for (int i=0; i < len; i++)
            {
                code+=mul[s1[i]];
            }
            all.push_back(code + 0 * 2 + 0);
            for (int i=len; i<(int)s1.size(); i++)
            {
                code+=mul[s1[i]];
                code-=mul[s1[i-len]];
                all.push_back(code+(i-len + 1)* 2 + 0);
            }
        }
        {
            long long code =0;
            for (int i=0; i<len; i++)
            {
                code+=mul[s2[i]];
            }
            all.push_back(code + 0 * 2 + 1);
            for (int i=len; i<(int)s2.size(); i++)
            {
                code+=mul[s2[i]];
                code-=mul[s2[i-len]];
                all.push_back(code+(i-len + 1
                                   )* 2 + 0);
            }
        }
        {
            long long code =0;
            for (int i=0; i<len; i++)
            {
                code+=mul[s2[i]];
            }
            all.push_back(code + 0 * 2 + 1);
            for (int i=len; i<(int)s2.size(); i++)
            {
                code+=mul[s2[i]];
                code-=mul[s2[i-len]];
                all.push_back(code+(i-len + 1 ) * 2 + 1);
            }
        }
        sort(all.begin(), all.end());
        for (int i=1; i<(int)all.size(); i++)
        {
            int set1=int(all[i] & 1);
            int set2= int(all[i-1] & 1);
            if ((all[i] >> 12) == (all[i-1] >> 12) && set1 !=set2)
            {
                int pos1=int(all[i]>>1) & 0x7FF;
                int pos2=int(all[i-1]>> 1) & 0x7FF;
                if (set1==1)
                {
                    swap(pos1,pos2);
                }
                cout<<len<<endl;
                cout<<pos1+1<<" "<<pos2+1;
                return 0;
            }
        }
    }
    cout<<("0");
    return 0;
}
