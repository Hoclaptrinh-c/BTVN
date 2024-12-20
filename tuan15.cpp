#include <iostream>

using namespace std;

struct NODE
{
    int chapter; 
    int page; 
    int section; 
    int subsection; 
    NODE* left; 
    NODE* right;

    NODE(int c, int p, int s, int subs)
    {
        chapter = c;
        page = p;
        section = s;
        subsection = subs;
        left = NULL;
        right = NULL;
    }
};

int IS_EMPTY(NODE* root)
{
    return root == NULL;
}

NODE* MAKE_NODE(int c, int p, int s, int subs)
{
    NODE* ptr = new NODE(c, p, s, subs); 
    return ptr;
}

NODE* INSERT(NODE* root, int c, int p, int s, int subs) 
{
    if (root == NULL) return MAKE_NODE(c, p, s, subs);

    if (c < root->chapter) root->left = INSERT(root->left, c, p, s, subs);
    else if (c > root->chapter) root->right = INSERT(root->right, c, p, s, subs);

    return root;
}


void NUM_OF_CHAP(NODE* root)
{
    if(IS_EMPTY(root)) cout << "0 chapters";
    if(IS_EMPTY(root->right))
    {
        if(root->chapter == 1) cout << "1 chapter";
        else cout << root->chapter << " chapters";
    }
    else NUM_OF_CHAP(root->right);
}

int MAX_LEN(NODE* root, int &longest_chap)
{
    if(IS_EMPTY(root)) return 0;

    int max = 0;
    if(root->page > max) 
    {
        max = root->page;
        longest_chap = root->chapter;
    }
    MAX_LEN(root->left, longest_chap);
    MAX_LEN(root->right, longest_chap);

    return longest_chap;
}

void FIND(NODE* root, int chapter)
{
    if(IS_EMPTY(root)) 
    {
        cout << "EMPTY !!!" << endl;
        return;
    }
    if(chapter == root->chapter) cout << "Found!" << endl;
    else FIND(root->right, chapter);
}

void CHANGE(NODE* root, int del_chapter) 
{
    if (root == NULL) return;

    if (root->chapter > del_chapter) 
    {
        root->chapter--;
    }

    CHANGE(root->left, del_chapter);
    CHANGE(root->right, del_chapter);
}

void DEL1(NODE* root, int c)
{
    NODE* p1;
    int del_chapter;
    if(c == root->right->chapter)
    {
        p1 = root->right;
        if(!IS_EMPTY(root->right->right)) root->right = root->right->right;
        del_chapter = p1->chapter;
        delete p1;
    }
    CHANGE(root, del_chapter);
}   

void DEL(NODE* root, int c)
{
    if(c == root->chapter)
    {
        root = root->right;
        delete root->right;
    }
    DEL1(root, c);
}

void PREFIX(NODE* root)
{
    if(IS_EMPTY(root)) return;
    cout << "Chapter: " << root->chapter << "Page: " << root->page << " Section: " << root->section << " Subsection: " << root->subsection;
    cout << endl;
    PREFIX(root->left);
    PREFIX(root->right); 
}

int main()
{
    NODE* root = NULL;

    int chapter;
    int page;
    int section;
    int subsection;

    for(int i = 0; i < 3; i++)
    {
        cout << " Chapter: ";
        cin >> chapter;
        cout << " Page: ";
        cin >> page;
        cout << " Section: ";
        cin >> section;
        cout << " subsection: ";
        cin >> subsection;

        root = INSERT(root, chapter, page, section, subsection);
    }

    PREFIX(root); cout << endl;

    NUM_OF_CHAP(root); cout << endl;

    int longest_chap;
    longest_chap = MAX_LEN(root, longest_chap);
    cout << longest_chap << endl;
    FIND(root, 2); cout << endl;
    DEL(root, 2);


    return 0;
}