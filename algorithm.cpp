#include"Header.h"

int devide(int n, int a)
{
	int i = 0;
	if (a == -1)
	{
		if (n / a > 0)
			return 1;
		else return 0;
	}
	while (abs(n)%a == 0)
	{
		n /= a;
		i++;
	}
	return i;
}

int LejandrSymbol(int a, int p)
{
	while (a < 0)
		a += p;
	if (a%p == 0) return 0;
	if (a == 1) return 1;
	if (a == 2) return pow(-1, (p*p - 1) / 8);
	if (a < p) return pow(-1, (a - 1)*(p - 1) / 4)*LejandrSymbol(p, a);
	return LejandrSymbol(a%p, p);
}

bool* sieve_of_eratosthenes(int n) {
	if (n < 2)
		return nullptr;
	bool *primes = new bool[n + 1];
	primes[0] = primes[1] = false;
	for (int i = 2; i <= n; i++)
		primes[i] = true;

	int sq_rt = sqrt(n);
	for (int i = 2; i <= sq_rt; i++) {
		if (primes[i]) {
			for (int j = i*i; j <= n; j += i)
				primes[j] = false;
		}
	}
	return primes;
}

vector<int> BaseCreate(int n, int max)
{
	vector<int> nums;
	nums.push_back(-1);
	bool *primes = sieve_of_eratosthenes(max);
	for (int i = 0; i <= max; i++)
	{
		if (primes[i] == true)
		{
			//if (LejandrSymbol(n, i) == 1)
				nums.push_back(i);
		}
	}
	delete[]primes;
	return nums;
}

void BMfactorize(int n)
{
	long buf;
	vector<int> a, p, sqrp, u, v;
	a.push_back(int(sqrt(n)));
	v.push_back(1);
	u.push_back(a[0]);
	p.push_back(a[0]);
	buf = (p[0] * p[0]) % n;
	if (buf > n / 2)
		buf -= n;
	sqrp.push_back(int(buf));
	int ix = 1;
	while (ix < 20)
	{
		v.push_back(abs(sqrp[ix - 1]));
		a.push_back(int((sqrt(n) + u[ix - 1]) / v[ix]));
		u.push_back(a[ix] * v[ix] - u[ix - 1]);
		if (ix > 1)
		{
			buf = (a[ix] * p[ix - 1] + p[ix - 2]) % n;
			p.push_back(int(buf));
		}
		else
		{
			buf = (a[ix] * p[ix - 1] + 1) % n;
			p.push_back(int(buf));
		}
		buf = (p[ix] * p[ix]) % n;
		if (buf > n / 2)
			buf -= n;
		sqrp.push_back(int(buf));
		ix++;
	}
	cout << "i" << "\t" << "a" << "\t" << "p" << "\t" << "p^2" << "\t" << "u" << "\t" << "v" << endl;
	for (int ix = 0; ix < a.size(); ix++)
		cout << ix << "\t" << a[ix] << "\t" << p[ix] << "\t" << sqrp[ix] << "\t" << u[ix] << "\t" << v[ix] << endl;
	vector<int> base = BaseCreate(n, 30);
//проверить этот момент
	map<int, map<int, int>> nums;
	for (int ix = 0; ix < p.size(); ix++)
		for (int j = 0; j < base.size(); j++)
			nums[p[ix]][base[j]] = devide(sqrp[ix],base[j]);
	cout << "\n\nP";
	for (int i = 0; i < base.size(); i++)
		cout << "\t" << base[i];
	cout << endl << endl;
	for (int it = 0; it < p.size(); it++)
	{
		cout << p[it];
		for (int j = 0; j < base.size(); j++)
			cout << "\t" << nums[p[it]][base[j]];
		cout << endl;
	}
}