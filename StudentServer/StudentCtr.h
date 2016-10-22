#pragma once
#include"Student2.h"
#include "DAO.h"
#include<iostream>
class StudentCtr
{
public:
	bool add(Student2);
	string showAll();
	StudentCtr();
	Student2 searchID(int);
	string convert1(int);
	void searchName();
	void searchSum();
	void searchMath();
	void searchPhys();
	void searchChem();
	bool edit(int, Student2);
	bool del(int);
	string thongke();
	void swap(Student2, Student2);
	void sort(list<Student2>);
	bool checkID(int);
	~StudentCtr();
};
