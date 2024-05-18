struct node
{
    void *value;
    node *left;
    node *right;
    node *parent;
};

node *find_common_ancestor(node *a, node *b)
{
    // back trace from the node to the root, which has a null parent, count the steps(depth)
    // caculate the difference between two depth
    node *p = a, *q = b;
    if (!p || !q)
        return nullptr;

    while (p && q && p->parent && q->parent && p != q)
    {
        p = p->parent;
        q = q->parent;
    }

    if (p == q)
        return p;

    node *o = (p->parent == nullptr) ? q : p; // let o point to the node which is not a root yet
    // count the diff
    int diff = 0;
    while (o && o->parent)
    {
        diff++;
        o = o->parent;
    }

    // let two pointers point to the two node
    // move the pointer to the lower node up by the difference
    node *p1 = (p->parent == nullptr) ? b : a;
    node *q1 = (p->parent == nullptr) ? a : b;
    while (diff > 0)
    {
        p1 = p1->parent;
    }

    // and move the two pointers up on parallel, until they meet each other
    while (p1 && p1->parent && q1 && q1->parent && q1 != p1)
    {
        p1 = p1->parent;
        q1 = q1->parent;
    }
    return p1;

    // it should be o(n) time complexity at the worst case
}
