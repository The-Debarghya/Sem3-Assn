#include <stdio.h>
#include <stdlib.h>
 
char legal_chars[] = "abcdefghijklmnopqrstuvwxyz0123456789_-./";
int  chr_idx[256] = {0};
char idx_chr[256] = {0};
 
#define FNAME 0
typedef struct trie_t *trie, trie_t;
struct trie_t {
    trie next[sizeof(legal_chars)]; /* next letter; slot 0 is for file name */
    int eow;
};
 
trie trie_new() { return calloc(sizeof(trie_t), 1); }
 
#define find_word(r, w) trie_trav(r, w, 1)
/* tree traversal: returns node if end of word and matches string, optionally
 * create node if doesn't exist
 */
trie trie_trav(trie root, const char * str, int no_create){
    int c;
    while (root != NULL) {
        if ((c = str[0]) == '\0') {
            if (!root->eow && no_create) return 0;
            break;
        }
        if (! (c = chr_idx[c]) ) {
            str++;
            continue;
        }
 
        if (!root->next[c]) {
            if (no_create) return 0;
            root->next[c] = trie_new();
        }
        root = root->next[c];
        str++;
    }
    return root;
}

int trie_all(trie root, char path[], int depth, int (*callback)(char *)){
    int i;
    if (root->eow && !callback(path)) return 0; 
    for (i = 1; i < sizeof(legal_chars); i++) {
        if (!root->next[i]) continue; 
        path[depth] = idx_chr[i];
        path[depth + 1] = '\0';
        if (!trie_all(root->next[i], path, depth + 1, callback))
            return 0;
    }
    return 1;
}
 
void add_index(trie root, const char *word, const char *fname){
    trie x = trie_trav(root, word, 0);
    x->eow = 1; 
    if (!x->next[FNAME])
        x->next[FNAME] = trie_new();
    x = trie_trav(x->next[FNAME], fname, 0);
    x->eow = 1;
} 
int print_path(char *path){
    printf(" %s", path);
    return 1;
} 
const char *files[] = { "file1.txt", "file2.txt", "file6.txt" };
//const char *text[][5] ={{ "Apple", "pear", "mango", "banana" },{ "Mango", "banana", "apple", "pear" },{"Banana", "Kiwi", "strawberry"}};
FILE *fp1;
    char* text[5][5], c, *p;
    int i=0;
    fp1 = fopen("text.txt", "r");
    if(fp1 == NULL){
        printf("Error in opening file \n");
        exit(0);
    }
    c = getc(fp1);
    while(c != EOF){
        ungetc(c, fp1);
        fgets(text[i], 80, fp1);
        if ((p=strchr(names[i], '\n')) != NULL) *p = '\0';
        i++;
        c = getc(fp1);
    }
    fclose(fp);
 
trie init_tables(){
    int i, j;
    trie root = trie_new();
    for (i = 0; i < sizeof(legal_chars); i++) {
        chr_idx[(int)legal_chars[i]] = i + 1;
        idx_chr[i + 1] = legal_chars[i];
    }

//#define USE_ADVANCED_FILE_HANDLING 0
/*#if USE_ADVANCED_FILE_HANDLING
    void read_file(const char * fname) {
        char cmd[1024];
        char word[1024];
        sprintf(cmd, "perl -p -e 'while(/(\\w+)/g) {print lc($1),\"\\n\"}' %s", fname);
        FILE *in = popen(cmd, "r");
        while (!feof(in)) {
            fscanf(in, "%1000s", word);
            add_index(root, word, fname);
        }
        pclose(in);
    };
 
    read_file("file1.txt");
    read_file("file2.txt");
    read_file("file6.txt");*/
//#else
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            if (!text[i][j]) break;
            add_index(root, text[i][j], files[i]);
        }
    }
//#endif
    return root;
} 
void search_index(trie root, const char *word){
    char path[1024];
    printf("Search for \"%s\": ", word);
    trie found = find_word(root, word);
 
    if (!found) printf("not found\n");
    else {
        trie_all(found->next[FNAME], path, 0, print_path);
        printf("\n");
    }
} 
int main(){
    trie root = init_tables(); 
    search_index(root, "Kiwi");
    search_index(root, "pear");
    search_index(root, "Banana");
    search_index(root, "litchi");
    return 0;
}
