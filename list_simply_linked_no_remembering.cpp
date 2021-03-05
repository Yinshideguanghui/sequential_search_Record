#include"list_simply_linked_no_remembering.h"
#include<iostream>
#include<string>
using namespace std;

template <class List_entry>				//��λ
Node<List_entry>* List<List_entry>::set_position(int position)const
{
	Node<List_entry>* q = head;
	for (int i = 0; i < position; i++)q = q->next;
	return q;
}

template <class List_entry>				//���ƹ��캯��
List<List_entry>::List(const List<List_entry>& copy)
{
	clear();
	if (copy.empty()) { head = NULL; }
	else
	{
		Node<List_entry>* copy_ptr, new_copy_ptr;
		copy_ptr = copy.head;
		new_copy_ptr = new Node<List_entry>(copy_ptr->entry);
		head = new_copy_ptr;
		count = 1;
		while (copy_ptr->next != NULL)
		{
			copy_ptr = copy_ptr->next;
			new_copy_ptr->next = new Node<List_entry>(copy_ptr->entry);
			new_copy_ptr = new_copy_ptr->next;
			count++;
		}
	}
}

//void operator = (const List<List_entry>& copy);

template <class List_entry>				//��ǰ��С
int List<List_entry>::size()const
{
	return count;
}

template <class List_entry>				//�Ƿ�Ϊ��
bool List<List_entry>::empty()const
{
	return count == 0;
}

template <class List_entry>				//���
void List<List_entry>::clear()
{
	List_entry temp;
	while (!empty()) remove(0,temp);
}

//void traverse(void(*visit)(List_entry&))

template <class List_entry>				//ȡ��ֵ
Error_code List<List_entry>::retrieve(int position, List_entry& x)const
{
	if (position < 0 || position > count)return Range_error;
	x = set_position(position)->entry;
	return success;
}

//Error_code replace(int position, const List_entry& x)

template <class List_entry>				//�Ƴ�
Error_code List<List_entry>::remove(int position, List_entry& x)
{
	if (position < 0 || position > count)return Range_error;
	if (count == 0) return underflow;
	Node<List_entry>* previous, * following;
	if (position > 0)
	{
		previous = set_position(position - 1);
		following = previous->next;
		previous->next = following->next;
	}
	else
	{
		following = head;
		head = following->next;
	}
	x = following->entry;	//��¼ԭ��λ��ֵ
	delete following;
	following = NULL;
	count--;
	return success;
}

template <class List_entry>				//����
Error_code List<List_entry>::insert(int position, const List_entry& x)
{
	if (position < 0 || position > count)return Range_error;
	Node<List_entry>* new_node, * previous = NULL, * following;
	if (position > 0)
	{
		previous = set_position(position - 1);
		following = previous->next;
	}
	else following = head;
	new_node = new Node<List_entry>(x, following);
	if (new_node == NULL)return overflow;
	if (position == 0) head = new_node;
	else previous->next = new_node;
	count++;
	return success;
}