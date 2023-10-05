#pragma once
#include <iostream>

struct Leaf
{
	char data;
	bool color = false; // black it's false
	Leaf* nextRight;
	Leaf* nextLeft;
	Leaf* parent;
	Leaf(){}
	Leaf(char dataNode);
	Leaf(const Leaf* anotherLeaf); //Конструктор копирования ноды
	Leaf(char dataNode, bool defColor);
	Leaf* getParent();
	char getData();
	bool getColor();
	void setColor(bool color); //Установить цвет ноды
	void setData(char data); //Установить данные
	void setRightLeaf(Leaf* rLeaf); //Установить указатель на правое поддерево
	void setLeftLeaf(Leaf* lLeaf); //Установить указатель на левое поддерево
	Leaf* right(); //Указатель на правое поддерево
	Leaf* left(); //Указатель на левое поддерево
	void printSubTree(Leaf* nodeFrom); //Постфиксный вывод дерева
	bool isContainValueSubTree(int data); //Поиск нодов с уникальным ключом data начиная с текущего узла
	bool isContainValueNode(int data); //Рассматривает только текущий нод
};

class RBTree
{
private:
	Leaf *head;

public:
	RBTree()
	{
		head = new Leaf();
	}
	RBTree(char dataLeaf)
	{
		head = new Leaf(dataLeaf);
	}
	RBTree(const RBTree& anotherTree)
	{
		Leaf movement;
		this->head = new Leaf(anotherTree.head);
		
		
	}

	Leaf *getHead()
	{
		return head;
	}
	void addLeaf();
	void delLeafByData(char data);
	bool searchLeafByData(char data);
	void printTree();

	RBTree &operator = (const RBTree& anotherTree);

};

class Set
{
	RBTree *set;
	Set()
	{
		set = new RBTree();
	}
	Set(const Set& anotherSet);

	Set& operator = (const Set& anotherSet);

	Set& operator * (const Set& anotherSet); //Пересечение (A and B)

	void add(int data);
	void del(int data);
	bool contain(int data);
	

};