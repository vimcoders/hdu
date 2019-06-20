#include<cstdio>
#include<set>

using namespace std;

int main(void) 
{
	int t;
	int n;
	int color;
	set<int> pool;
	scanf("%d", &t);
	while(t--) 
	{
		scanf("%d", &n);

		int result = 1;
		pool.clear();

		for (int i = 0; i < n; i++) 
		{
			scanf("%d", &color);

			if (pool.count(color))
			{
				pool.clear();
				result++;
			}

			pool.insert(color);
		}

		printf("%d\n", result);
	}
}
