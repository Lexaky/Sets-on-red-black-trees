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
	Leaf(const Leaf* anotherLeaf); //����������� ����������� ����
	Leaf(char dataNode, bool defColor);
	Leaf* getParent();
	char getData();
	bool getColor();
	void setColor(bool color); //���������� ���� ����
	void setData(char data); //���������� ������
	void setRightLeaf(Leaf* rLeaf); //���������� ��������� �� ������ ���������
	void setLeftLeaf(Leaf* lLeaf); //���������� ��������� �� ����� ���������
	Leaf* right(); //��������� �� ������ ���������
	Leaf* left(); //��������� �� ����� ���������
	void printSubTree(Leaf* nodeFrom); //����������� ����� ������
	bool isContainValueSubTree(int data); //����� ����� � ���������� ������ data ������� � �������� ����
	bool isContainValueNode(int data); //������������� ������ ������� ���
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

	Set& operator * (const Set& anotherSet); //����������� (A and B)

	void add(int data);
	void del(int data);
	bool contain(int data);
	

};