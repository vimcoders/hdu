/* 
 * File Name: 5687.cpp
 * Descript: 
 * 
 * Version: 1.0 
 * Created Time: 08/04/17 05:26:57
 * Compiler: 
 * Editor: vim 
 * Author: Jimbo 
 * Mail: jimboo.lu@gmail.com 
 *
 * Company: 
 */
 
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct trie {
	map<char, trie*> child;

	int num;

}trie;

trie *root = NULL;

bool dfs(trie *node) {
	if (node == NULL || node->num < 0) {
		return false;
	}
	if (node->child.empty() && node->num > 0) {
		return true;
	}
	map<char, trie*>::iterator it;
	for (it = node->child.begin(); it != node->child.end(); it++) {
		if (dfs(it->second) == true ) {
			return true;
		}
	}
	return false;
}

void insert(const char *str) {
	if (root == NULL) {
		root = new trie;

	}
	trie *node = root;
	for (int i = 0; str[i] != '\0'; i++) {
		if (node->child[str[i]] != NULL) {
			node = node->child[str[i]];
			continue;

		}
		trie *n = new trie;
		n->num = 0;
		node->child[str[i]] = n;
		node = n;

	}
	node->num++;

}

bool search(const char *str) {
	if (root == NULL) {
		root = new trie;

	}
	trie *node = root;
	for (int i = 0; str[i] != '\0'; i++) {
		if (node->num < 0) {
			return false;

		}
		if (node->child[str[i]] == NULL) {
			return false;

		}
		node = node->child[str[i]];

	}
	return dfs(node);

}

void del(const char *str) {
	if (root == NULL) {
		return;

	}
	trie *node = root;
	for (int i = 0; str[i] != '\0'; i++) {
		if (node == NULL) {
			return;

		}
		node = node->child[str[i]];

	}
	node->num = -1;

}

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		char str[10];
		char dic[40];
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			scanf("%s", dic);
			if (strcmp(str, "insert") == 0) {
				insert(dic);

			}
			else if (strcmp(str, "search") == 0) {
				if (search(dic) == true) {
					printf("Yes\n");

				}
				else {
					printf("No\n");

				}

			}
			else if (strcmp(str, "delete") == 0) {
				del(dic);

			}

		}

	}

	return 0;

}
