#include"Linklist.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

Alphabets::Alphabets()
{
	head = tail = NULL;
	tail_syn = NULL;
}

Wrdptr Alphabets::traverse(string wrd)
{
	Wrdptr temp;
	temp = head;
	while (temp != NULL)
	{
		if (temp->word == wrd)
		{
			return temp;
			break;
		}
		else
		{
			temp = temp->next_wrd;
		}
	}
	if (temp == NULL)
	{
		cout << "Word not found.." << endl;
		return NULL;
	}
}


void Alphabets::add_wrd(string wrd)
{
	Wrdptr newword = new word;
	newword->word = wrd;
	newword->next_wrd = NULL;
	newword->next = NULL;
	if (head == NULL)
	{
		head = newword;
		tail = newword;
	}
	else
	{
		tail->next_wrd = newword;
		tail = newword;
	}
}
void Alphabets::delete_wrd(string wrd)
{
	//cout << "check0";
	Wrdptr temp = traverse(wrd);
	Wrdptr prenode = head;
	while (prenode != NULL)
	{
		//cout << "check1";
		if (prenode->next_wrd == temp || prenode == temp)
		{
			if (prenode == head)
			{
				head = temp->next_wrd;
			}
			//cout << "check2";
			prenode->next_wrd = temp->next_wrd;
			temp->next_wrd = NULL;
			delete temp;
			break;
		}
		else
		{
			prenode = prenode->next_wrd;
		}
	}
}
void Alphabets::search_wrd(string wrd)
{
	print_syn(wrd);
}

void Alphabets::add_syn(string wrd, string synm)
{
	Synptr newsyn = new syn;
	Wrdptr wptr = traverse(wrd);
	newsyn->syn = synm;
	newsyn->next_syn = NULL;
	if (wptr->next == NULL)
	{
		wptr->next = newsyn;//linkage
		tail_syn = newsyn;
	}
	else
	{
		tail_syn->next_syn = newsyn;
		tail_syn = newsyn;
	}
}

void Alphabets::print_wrd_list()
{
	string l;
	cout << "Enter letter" << endl;
	cin >> l;
	Alphabets dict;
	fstream obj = open_file_R(l);
	readFile(obj);
	Wrdptr temp = head;
	while (temp != NULL)
	{
		cout << temp->word << " " << endl;
		print_syn(temp->word);
		temp = temp->next_wrd;

	}
}

void Alphabets::print_syn(string wd)
{
	Wrdptr wp = traverse(wd);
	//cout << "Word he " << wd << endl;
	int a = 0;
	string s;
	//cout << "MIll Gaya!!" << wp->word << endl;
	if (wp->next != NULL)
	{
		//cout << "Sunonym print karraha hun!!!!" << endl;
		Synptr sm = wp->next;
		//cout << sm->syn << endl;
		while (sm != NULL)
		{
			cout << sm->syn << " ";
			sm = sm->next_syn;
		}
	}
	else
	{
		cout << "No synonium found" << endl << "Press 1 to add Synonium and 0 to Exit" << endl;
		cin >> a;
		if (a == 1)
		{

			cin >> s;
			add_syn(wd, s);
		}

	}
}
fstream Alphabets::open_file_R(string input)
{
	string  name;
	char ch;
	ch = input[0];
	cout << ch << endl;
	name.push_back(ch);
	name = name + ".txt";
	cout << name << endl;
	fstream obj;
	obj.open(name);
	if (obj.is_open())
	{
		cout << "success";
	}
	return obj;
}
fstream Alphabets::open_file_W(string input)
{
	string  name;
	char ch;
	ch = input[0];
	cout << ch << endl;
	name.push_back(ch);
	name = name + ".txt";
	cout << name << endl;
	fstream obj;
	obj.open(name, std::ios_base::app);
	//obj.open(name);
	if (obj.is_open())
	{
		cout << "success";
	}
	return obj;
}
Alphabets Alphabets::readFile(fstream& obj)
{
	int i = 0;
	string input, chr, syno;
	Alphabets dict;
	// obj = open_file(input);
	cout << "displyaing all the words from file" << endl;
	while (!obj.eof())
	{
		getline(obj, chr);
		i = 0;
		cout  << chr << endl;
		input = "";
		while (chr[i] != '>')
		{
			input.push_back(chr[i]);
			//cout << input << endl;/////////////////////////////
			//input = input + temp;
			i++;
			if (chr.length() == i - 1)
				break;//to control out of bound
		}
		//cout << "Check1" << input << endl;//////////////////////////
		dict.add_wrd(input);
		//cout << "check2" << input << endl;//////////////////////////
		//syno = "";
		i++;
		while (chr[i] != ';')
		{
			if (chr.length() == i)
				break;
			syno = "";
			while (chr[i] != ':' && chr[i] != ';')// Experiance of anas
			{

				syno.push_back(chr[i]);
				//syno = syno + temp;
				i++;
			}

			i++;
			dict.add_syn(input, syno);
			//syno = "";

		}
	}
	return dict;
}

void Alphabets::writefile(string word)
{
	Alphabets dict;
	string syn[3];
	fstream obj = open_file_W(word);
	//dict.readFile(obj);
	dict.add_wrd(word);

	cout << "Enter 3 synonyms" << endl;
	for (int j = 0; j < 3; j++)
	{
		//cout << j << ': ';
		cin >> syn[j];
		dict.add_syn(word, syn[j]);
	}
	obj << word << '>' << syn[0] << ':' << syn[1] << ':' << syn[2] << ';'<<"\n";


}
