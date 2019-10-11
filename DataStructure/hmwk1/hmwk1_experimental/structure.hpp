#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#define LENGTH 100
#define nullptr NULL

typedef struct function{
    int s;
    int e;
    int sum;
}piece;

typedef struct PieceTree{
    piece p;
    struct PieceTree *left;
    struct PieceTree *right;
} pt;

piece setPiece(int s, int e, int sum)
{
    piece p;
    p.s = s;
    p.e = e;
    p.sum = sum;
    return p;
}

pt setPieceTree(piece p, pt *left, pt *right)
{
    pt temp;
    temp.p = p;
    temp.left = left;
    temp.right = right;
    return temp;
}

#endif