#include "header.h"

int main() {
    // deklarasi tree
    tree T;
    char chr;
    scanf(" %c", &chr);
    // membuat tree/root utama
    makeTree(chr, &T); // a

    // line 11 - 37 memasukkan isi ke simpul
    scanf(" %c", &chr);
    addLeft(chr, T.root); // b
    scanf(" %c", &chr);
    addRight(chr, T.root); // c
    scanf(" %c", &chr); 
    addLeft(chr, T.root->right); // d
    scanf(" %c", &chr); 
	addRight(chr, T.root->left); // e
    scanf(" %c", &chr); 
	addRight(chr, T.root->right); // f
    scanf(" %c", &chr); 
	addLeft(chr, T.root->left->right); // g
    scanf(" %c", &chr); 
	addRight(chr, T.root->right->left); // h
    scanf(" %c", &chr); 
	addRight(chr, T.root->left->right); // i
    scanf(" %c", &chr); 
	addRight(chr, T.root->right->right); // j
    scanf(" %c", &chr); 
	addLeft(chr, T.root->right->right); // k
    scanf(" %c", &chr); 
	addLeft(chr, T.root->left->right->left); // l
    scanf(" %c", &chr); 
	addLeft(chr, T.root->right->left->right); // m
    scanf(" %c", &chr); 
	addRight(chr, T.root->right->left->right);

    printf("Pre Order:\n");
	printTreePreOrder(T.root, T.root); // mencetak pre order

    delLeft(T.root->left->right->left); // menghapus L
    printf("\nIn Order:\n");
	printTreeInOrder(T.root); // mencetak in order

	delRight(T.root->right->right); // menghapus J
    printf("\nPost Order:\n");
	printTreePostOrder(T.root, T.root); // mencetak post order
    printf("\n");
    return 0;
}