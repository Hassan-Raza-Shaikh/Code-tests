#include <iostream>
#include <string>
using namespace std;

struct IncidentNode
{
    int inc_no;
    string inc_text;
    IncidentNode* next;
};

struct AreaNode
{
    int loc_no;
    int hgt;
    AreaNode* left;
    AreaNode* right;
    IncidentNode* inc_head;
};

int getHeight(AreaNode* p)
{
    if (p == NULL)
        return -1;
    return p->hgt;
}

AreaNode* makeArea(int id)
{
    AreaNode* p = new AreaNode();
    p->loc_no = id;
    p->left = NULL;
    p->right = NULL;
    p->inc_head = NULL;
    p->hgt = 0;
    return p;
}

AreaNode* rightRotate(AreaNode* y)
{
    AreaNode* x = y->left;
    AreaNode* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->hgt = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->hgt = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AreaNode* leftRotate(AreaNode* x)
{
    AreaNode* y = x->right;
    AreaNode* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->hgt = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->hgt = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int balanceVal(AreaNode* p)
{
    if (p == NULL)
        return 0;
    return getHeight(p->left) - getHeight(p->right);
}

AreaNode* addArea(AreaNode* root, int id)
{
    if (root == NULL)
        return makeArea(id);

    if (id < root->loc_no)
        root->left = addArea(root->left, id);
    else if (id > root->loc_no)
        root->right = addArea(root->right, id);
    else
        return root;

    root->hgt = max(getHeight(root->left), getHeight(root->right)) + 1;
    int diff = balanceVal(root);

    if (diff > 1 && id < root->left->loc_no)
        return rightRotate(root);

    if (diff < -1 && id > root->right->loc_no)
        return leftRotate(root);

    if (diff > 1 && id > root->left->loc_no)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (diff < -1 && id < root->right->loc_no)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

AreaNode* findArea(AreaNode* root, int id)
{
    if (root == NULL || root->loc_no == id)
        return root;

    if (id < root->loc_no)
        return findArea(root->left, id);

    return findArea(root->right, id);
}

void insertIncident(AreaNode* a, int no, string text)
{
    IncidentNode* temp = new IncidentNode();
    temp->inc_no = no;
    temp->inc_text = text;
    temp->next = a->inc_head;
    a->inc_head = temp;
}

void removeIncident(AreaNode* a, int no)
{
    IncidentNode* cur = a->inc_head;
    IncidentNode* prev = NULL;

    while (cur != NULL)
    {
        if (cur->inc_no == no)
        {
            if (prev == NULL)
                a->inc_head = cur->next;
            else
                prev->next = cur->next;

            delete cur;
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

void showIncidents(IncidentNode* p)
{
    while (p != NULL)
    {
        cout << "   Incident ID: " << p->inc_no
             << " | " << p->inc_text << endl;
        p = p->next;
    }
}

void showAreas(AreaNode* root)
{
    if (root != NULL)
    {
        showAreas(root->left);
        cout << "\nLocation ID: " << root->loc_no << endl;
        showIncidents(root->inc_head);
        showAreas(root->right);
    }
}

int main()
{
    AreaNode* cityRoot = NULL;

    cityRoot = addArea(cityRoot, 120);
    cityRoot = addArea(cityRoot, 115);
    cityRoot = addArea(cityRoot, 125);

    AreaNode* a = findArea(cityRoot, 120);
    insertIncident(a, 1, "Fire near bank");
    insertIncident(a, 2, "Traffic accident");

    a = findArea(cityRoot, 115);
    insertIncident(a, 1, "Suicide attack");

    a = findArea(cityRoot, 125);
    insertIncident(a, 1, "Car blast");

    cout << "\n--- Emergency Records ---\n";
    showAreas(cityRoot);

    return 0;
}
