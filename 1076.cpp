#include<cstdio>

using namespace std;

int main(void) 
{

	int t;
	int y;
	int n;
	int end;

	scanf("%d", &t);

	while(t--) 
	{
		scanf("%d%d", &y, &n);

		end = y + n * 4 * 2;

		for (int i = y; i < end; i++) 
		{

			if (i % 4 != 0) 
			{
				continue;
			}

			if (i % 100 == 0 && i % 400 != 0) 
			{
				continue;
			}

			n--;

			if (n == 0)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
}
