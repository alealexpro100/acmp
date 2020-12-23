//ЗАДАЧА №188   День рождения
// BigInteger based on http://e-maxx.ru/algo/big_integer
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

struct BigInteger {
private:
	constexpr static int base = 1000*1000*1000;
	vector<int> data_;
public:
    // Needed for building new number.
	BigInteger(short n):data_() {
		data_.push_back(n);
	}
	// Output
    string to_string() const {
        int buf_size=10;
        char buf[buf_size+1];
        buf[buf_size] = 0;
        if (data_.empty())
            sprintf(buf, "%d", 0);
        else
            sprintf(buf, "%d", data_.back());
        string s(buf);
        for (int i=(int)data_.size()-2; i>=0; i--) {
            // %09d - вывод с _нулями_.
            sprintf(buf, "%09d", data_[i]);
            s.append(buf);
        }
        return s;
    }
    void clear() {
	    data_.clear();
	    data_.push_back(0);
	}
	// Carry - переполнение.
	// cur - base+data[i]
	// Working with summarize.
	void operator+=(const BigInteger &b) {
		bool carry=0;
		for (unsigned int i=0; i<max(data_.size(),b.data_.size()) || carry; i++) {
			if (i == data_.size())
				data_.push_back (0);
            if (i<b.data_.size())
                data_[i]+=(int)carry+b.data_[i];
			else
                data_[i]+=(int)carry;
			carry=data_[i]>=base;
			if (carry)
                data_[i]-=base;
		}
	}
	// Only for int numbers.
	// 1 LL - long long 1 (для избежания переполнения типа int)
	void operator*=(unsigned int b) {
		int carry = 0;
		for (unsigned int i=0; i<b; i++) {
			if (i==data_.size())
				data_.push_back(0);
			long long cur=carry+data_[i]*1ll*b;
			data_[i]=int(cur%base);
			carry =int(cur/base);
		}
		while (data_.size()>1 && data_.back()==0)
			data_.pop_back();
	}
};

int main() {
	int N;
	cin >> N;
	BigInteger n(0), n1(0), n2(1); // !n, !(n-1), !(n-2)
	for (unsigned int i=2; i<=N; i++) {
        // !n=(!(n-2)+!(n-1))*(n-1)
		n=n1; n+=n2; n*=(i-1);
		n2=n1; n1=n;
	}
	cout << n.to_string();
	return 0;
}
