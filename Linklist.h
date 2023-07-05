#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

typedef struct word* Wrdptr;
typedef struct syn* Synptr;

struct word
{
	string word;
	Wrdptr next_wrd;
	Synptr next;
};
struct syn
{
	string syn;
	Synptr next_syn;
};
class Alphabets
{
private:
	Wrdptr head;
	Wrdptr tail;

	Synptr tail_syn;
public:
	Alphabets();
	Wrdptr traverse(string wrd);
	void add_wrd(string wrd);
	void delete_wrd(string wrd);
	void search_wrd(string wrd);
	void add_syn(string wrd, string synm);

	fstream open_file_R(string input);
	fstream open_file_W(string input);
	Alphabets readFile(fstream& obj);
	void writefile(string word);

	void print_wrd_list();
	void print_syn(string wp);
};