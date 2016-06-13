//
//  main.c
//  tab1_AEDII
//
//  Created by Caio Arthur on 6/1/16.
//  Copyright © 2016 Caio Arthur. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct noh{
    int key;
    struct noh *left;
    struct noh *right;
};typedef struct noh tree;

int selectedOption;
tree **mainRoot;

int Menu(void);
void insert(tree *node, tree **root), selectOption(int value);

int main()
{
    //selectedOption = Menu();
    selectOption(Menu());
    main();
}

/*void inserir(tree **pRaiz, int numero){
    if(*pRaiz == NULL){
        *pRaiz = (tree *) malloc(sizeof(tree));
        (*pRaiz)->left = NULL;
        (*pRaiz)->right = NULL;
        (*pRaiz)->key = numero;
    }else{
        if(numero < (*pRaiz)->key)
            inserir(&(*pRaiz)->left, numero);
        if(numero > (*pRaiz)->key)
            inserir(&(*pRaiz)->right, numero);
    }
}*/

tree *createNode(int value)
{
    tree *newNode;
    newNode = (tree *)malloc(sizeof(tree));
    
    newNode->key = value;
    newNode->right = NULL;
    newNode->left = NULL;
    
    return newNode;
}

void insertOut()
{
    int valuetoBeInserted;
    tree *valueSettedtoNode;
    
    printf("\nNúmero à ser inserido: ");
    scanf("%d", &valuetoBeInserted);
    valueSettedtoNode = createNode(valuetoBeInserted);
    insert(valueSettedtoNode, mainRoot);
}

void insert(tree *node, tree **root)
{
    if ((*root) == NULL)
    {
        *root = (tree *)malloc(sizeof(tree));
        root = &node;
    }
    else
    {
        if (node->key < (*root)->key)
        {
            insert(node, &(*root)->left);
        }
        else if (node->key > (*root)->key)
        {
            insert(node, &(*root)->right);
        }
    }
}


void showValues(tree **root)
{
    if (root != NULL)
    {
        printf("%d, ", (*root)->key);
        showValues(&(*root)->left);
        showValues(&(*root)->right);
    }
}

int Menu(void)
{
    int option;
    printf("Inserir na árvore - 1\nExibir - 0\nOpção: ");
    scanf("%d", &option);
    return option;
}


void selectOption(int value)
{
   if (value == 1)
   {
       insertOut();
   }
   else if (value == 0)
   {
       showValues(mainRoot);
   }
}
