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
	BigInteger(short n):data_() {
		data_.push_back(n);
	}
    void print() const {
        printf ("%d", data_.empty() ? 0 : data_.back());
        for (int i=(int)data_.size()-2; i>=0; i--) {
            // %09d - вывод с _нулями_.
            printf("%09d", data_[i]);
        }
    }
    void clear() {
	    data_.clear();
	    data_.push_back(0);
	}
	// Carry - переполнение, cur - base+data[i]
	void operator+=(const BigInteger &b) {
		bool carry=0;
		for (unsigned int i=0; i<max(data_.size(),b.data_.size()) || carry; i++) {
			if (i == data_.size())
				data_.push_back (0);
            data_[i]+=(int)carry+(i < b.data_.size() ? b.data_[i] : 0);
			carry=data_[i]>=base;
			if (carry)
                data_[i]-=base;
		}
	}
	// Only for long long numbers.
	void operator*=(long long b) {
		int carry = 0;
		for (unsigned int i=0; i<b; i++) {
			if (i==data_.size())
				data_.push_back(0);
			long long cur=carry+data_[i]*b;
			data_[i]=int(cur%base);
			carry =int(cur/base);
		}
		while (data_.size()>1 && data_.back()==0)
			data_.pop_back();
	}
	// Not Needed.
	void operator=(const BigInteger &b) {
	    data_=b.data_;
	}
};

int main() {
	int N;
	cin >> N;
	BigInteger n(0), n1(0), n2(1), ns(0); // !n, !(n-1), !(n-2)
	for (unsigned int i=2; i<=N; i++) {
        // !n=(!(n-2)+!(n-1))*(n-1)
		n=n1; n+=n2; n*=(i-1);
		n2=n1; n1=n;
	}
	n.print();
	return 0;
}
