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

	int v;
}trie;

trie *root = NULL;

void insert(const char *str) {
	if (root == NULL) {
		root = new trie;
	}
	trie *node = root;
	for (int i = 0; str[i] != '\0'; i++) {
		if (node->child[str[i]] != NULL) {
			node = node->child[str[i]];
			node->v++;
			continue;
		}
		trie *n = new trie;
		n->v = 1;
		n->child.clear();
		node->child[str[i]] = n;
		node = n;
	}
}

bool search(const char *str) {
	if (root == NULL) {
		return false;
	}
	trie *node = root;
	for (int i = 0; str[i] != '\0'; i++) {
		if (node->child[str[i]] == NULL ) {
			return false;
		}
		node = node->child[str[i]];
	}
	return node->v != 0;
}

void del(const char *str) {
	if (root == NULL) {
		return;
	}
	trie *node = root;
	for (int i = 0; str[i] != '\0'; i++) {
		if (node->child[str[i]] == NULL) {
			return;
		}
		node = node->child[str[i]];
	}
	node->v = 0;
	node->child.clear();
}

int main(void) {
	int n;
	char str[10], dic[40];
	while(scanf("%d", &n) != EOF) {
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
