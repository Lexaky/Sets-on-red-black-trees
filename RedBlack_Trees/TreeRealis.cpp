#include "Tree.h"
#include <iostream>

Leaf::Leaf(char dataNode)
{
	data = dataNode;
}
Leaf::Leaf(const Leaf* anotherLeaf)
{
	this->data = anotherLeaf->data;
	this->color = anotherLeaf->color;
}
Leaf::Leaf(char dataNode, bool defColor)
{
	this->data = dataNode;
	this->color = defColor;
}
Leaf* Leaf::getParent()
{
	return parent;
}
bool Leaf::getColor()
{
	return color;
}
char Leaf::getData()
{
	return data;
}
void Leaf::setColor(bool color)
{
	this->color = color;
}
void Leaf::setData(char data)
{
	this->data = data;
}
void Leaf::setRightLeaf(Leaf* rLeaf)
{
	this->nextRight = rLeaf;
	rLeaf->parent = this;
}
void Leaf::setLeftLeaf(Leaf* lLeaf)
{
	this->nextLeft = lLeaf;
	lLeaf->parent = this;
}
Leaf* Leaf::right()
{
	return nextRight;
}
Leaf* Leaf::left()
{
	return nextLeft;
}
void Leaf::printSubTree(Leaf* nodeFrom)
{
	if (nodeFrom->right() != nullptr)
		printSubTree(nodeFrom->right());
	if (nodeFrom->left() != nullptr)
		printSubTree(nodeFrom->left());
	std::cout << nodeFrom->getData() << ",";
}
bool Leaf::isContainValueNode(int data)
{
	if (this->data == data)
		return false;
	else return true;
}
bool Leaf::isContainValueSubTree(int data)
{
	if (this->isContainValueNode(data))
		return true;
	else if (this->right()->isContainValueSubTree(data))
		return true;
	else if (this->left()->isContainValueSubTree(data))
		return true;
	return false;
}


void RBTree::printTree()
{
	head->printSubTree(head);
}
bool RBTree::searchLeafByData(char data)
{
	return this->head->isContainValueSubTree(data);
}