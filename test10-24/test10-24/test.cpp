#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include<string>
#include<assert.h>

//length()
//operator[]
//operator+
//operator+=
//operator > < >= <= == !=
/////////////////////////////////////////
class String;
ostream& operator<<(ostream &out, const String &str);

class String
{
	friend ostream& operator<<(ostream &out, const String &str);
public:
	//���캯��
	String(const char *str = "")
	{
		if (str == NULL)
		{
			m_data = NULL;
		}
		else
		{
			m_data = new char[strlen(str) + 1];
			strcpy(m_data, str);
		}
		
	}
	String(const String &str)//�������캯��
	{
		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
		
	}

	//����[]�����
	char& operator[](int index)
	{
		assert(index >= 0 && index < _length());
		return this->m_data[index];
	}
	//���� + �����
	String& operator+(const String&str)
	{
		char *tmp;
		
		tmp = new char[strlen(str.m_data) + strlen(m_data) + 1];
		strcpy(tmp, m_data);
		strcat(tmp, str.m_data);
		String tmps(tmp);
		delete[]tmp;
		return tmps;
	}

	//���� += �����
	String& operator+=(const String&str)
	{
		char *temp = m_data;
		int size = str._length() + _length();
		m_data = new char[size + 1];
		strcpy(m_data, temp);
		strcat(m_data, str.m_data);
		delete[]temp;
		return *this;
	}
	bool operator>(const String&str)
	{
		if (strcmp(this->m_data, str.m_data) > 0)
			return true;
		else
			return false;
	}
	bool operator<(const String&str)
	{
		if (strcmp(this->m_data, str.m_data) < 0)
			return true;
		else
			return false;
	}
	bool operator>=(const String&str)
	{
		if (strcmp(this->m_data, str.m_data) < 0)
			return false;
		else
			return true;
	}
	bool operator<=(const String&str)
	{
		if (strcmp(this->m_data, str.m_data) > 0)
			return false;
		else
			return true;
	}

	//���� == �����
	bool operator==(const String&str)
	{
		if (strlen(this->m_data) != strlen(str.m_data))
			return false;
		else
			return strcmp(this->m_data, str.m_data) ? false : true;
	}

	//���� ��= �����
	bool operator!=(const String&str)
	{
		return !(*this == str);
	}

	//���� = �����
	String& operator=(const String &str)
	{
		if (this != &str)
		{
			free(m_data);
			m_data = new char[strlen(str.m_data) + 1];
			strcpy(m_data, str.m_data);
		}
		return *this;
	}
	//��������
	~String()
	{
		delete[]m_data;
		m_data = NULL;
	}
	//��ȡ����
	int _length()const
	{
		
		return strlen(this->m_data);
	}
private:
	char *m_data;
};

ostream& operator<<(ostream &out, const String &str)
{
	out << str.m_data;
	return out;
}

int main()
{
	String s1("Hello"); //s1[0] ==> H
	String s2("Bit.");
	String s3("linda");
	String s4("linda");
	String s5("World.");
	for (int i = 0; i < s1._length(); ++i)
		cout << s1[i];
	cout << endl;
	String s = s1 + s2; //s = HelloBit
	cout << s << endl;
	s1 += s5;
	cout << s1;
	cout << endl;
	if (s1 == s2)
		cout << "s1 == s2" << endl;
	if (s1 != s2)
		cout << "s1 != s2" << endl;

	if (s1 > s2)
		cout << "s1 > s2" << endl;
	if (s1 < s2)
		cout << "s1 < s2" << endl;
	if (s3 >= s4)
		cout << "s1 >= s2" << endl;
	if (s3 <= s4)
		cout << "s1 <= s2" << endl;
		
	system("pause");
	return 0;
}





/*
class Int;
ostream& operator<<(ostream &out, const Int &i);

class Int
{
	friend ostream& operator<<(ostream &out, const Int &i);
public:
	Int(long i = 0) : m_i(i)
	{}
public:
	Int operator+(const Int &x)
	{
		//Int tmp(m_i+x.m_i);
		//return tmp;
		return Int(m_i + x.m_i);
	}
	Int operator-(const Int &x)
	{
		return Int(m_i - x.m_i);
	}
	Int operator*(const Int &x)
	{
		return Int(m_i * x.m_i);
	}
	Int operator/(const Int &x)
	{
		if (x.m_i != 0)
		{
			return Int(m_i / x.m_i);
		}
	}
	Int operator%(const Int &x)
	{
		if (x.m_i != 0)
		{
			return Int(m_i % x.m_i);
		}
	}
public:
	Int& operator+=(const Int &x) // a += b;
	{
		Int tmp(m_i += x.m_i);
		//m_i += x.m_i;
		return tmp;
	}
	Int& operator-=(const Int &x)
	{
		Int tmp(m_i -= x.m_i);
		return tmp;
		// return Int(m_i -= x.m_i) //Ϊʲô���������ԣ�
	}
	Int& operator*=(const Int &x)
	{
		Int tmp(m_i *= x.m_i);
		return tmp;
	}
	Int& operator/=(const Int &x)
	{
		Int tmp(m_i /= x.m_i);
		return tmp;
	}
	Int& operator%=(const Int &x)
	{
		Int tmp(m_i %= x.m_i);
		return tmp;
	}
public:
	Int operator>>(const Int &x) //a >> b
	{
		//Int tmp(m_i >> x.m_i);
		//return tmp;
		return Int(m_i >> x.m_i);
	}
	Int operator<<(const Int &x)
	{
		return Int(m_i << x.m_i);
	}
	Int operator>>=(const Int &x)
	{
		Int tmp(m_i);
		m_i = m_i >> x.m_i;
		return tmp;
	}
	Int operator<<=(const Int &x)
	{
		Int tmp(m_i);
		m_i = m_i << x.m_i;
		return tmp;
	}
public:
	bool operator==(const Int &x)//
	{
		if (this->m_i == x.m_i)
			return true;
		else
			return false;
	}
	bool operator!=(const Int &x)
	{
		if (this->m_i != x.m_i)
			return true;
		else
			return false;
	}
public:
	Int& operator++()//ǰ++
	{
		m_i++;
		return *this;
	}
	Int operator++(int) //��++
	{
		Int tmp(m_i);
		++*this;
		return tmp;
	}
	Int& operator--() //ǰ--
	{
		m_i--;
		return *this;
	}
	Int operator--(int) //��--
	{
		Int tmp(m_i);
		--*this;
		return tmp;
	}
public:
	int GetData()const
	{
		return m_i;
	}
private:
	long m_i;
};

ostream& operator<<(ostream &out, const Int &i)
{
	out << i.m_i;
	return out;
}



int main()
{
	Int i(1);
	Int c(2);
	Int d(3);
	Int e(4);
	Int f(1);
	Int g(1);
	Int v = i++;
	cout << "i = " << i << endl;
	cout << "v = " << v << endl;

	v = i + c;
	cout << "v = " << v << endl;
	v = i - c;
	cout << "v = " << v << endl;
	v = i * c;
	cout << "v = " << v << endl;
	v = i / c;
	cout << "v = " << v << endl;
	v = i % c;
	cout << "v = " << v << endl;
	cout << "------------------" << endl;

	d += c;
	cout << "d = " << d << endl;
	d -= c;
	cout << "d = " << d << endl;
	d *= c;
	cout << "d = " << d << endl;
	d /= c;
	cout << "d = " << d << endl;
	d %= c;
	cout << "d = " << d << endl;
	cout << "-------------------" << endl;

	e >> c;
	cout << "e = " << e << endl;
	e >>= c;
	cout << "e = " << e << endl;
	e << c;
	cout << "e = " << e << endl;
	e <<= c;
	cout << "e = " << e << endl;

	cout << "------------------" << endl;
	if (d != c)
	{
		cout << "�����" << endl;
	}
	if (g == f)
	{
		cout << "���" << endl;
	}
	system("pause");
	return 0;
}






class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
		display();//��const��Ա�����ڵ���������const��Ա����  ����
	}
	void display()const
	{
		
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl;
		Display();//const��Ա�����ڵ��������ķ�const��Ա����   ������
	}

	
private:
	int _year;
	int _month;
	int _day;
};

void main()
{
	const Date d1(2012, 3, 14);
	Date d2(2013, 4, 15);
	d1.Display();//const ������÷�const��Ա����   ������
	d2.display();//��const�������const��Ա����  ����

	system("pause");
}

*/