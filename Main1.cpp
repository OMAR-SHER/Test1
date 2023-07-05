#include"Linklist.h"
int main()
{
	int op;
	string word;
	Alphabets dict;
	//Alphabets A;
	do {
		cout << " 1. Search meanings \n 2. Delete word \n 3. Add word \n 4. Display all words \n 5. Exit " << endl;
		cin >> op;
		if (op == 1)
		{
			cout << "Enter the word" << endl;
			cin >> word;
			fstream file = dict.open_file_R(word);
			//file open wala functiononononomioimmoniin
			dict = dict.readFile(file);//do not comment!!
			//file read fn returns obj
			//dict = obj
			dict.search_wrd(word);//do not comment!!
		}
		else if (op == 2)
		{
			cout << "Enter the word" << endl;
			cin >> word;
			dict.delete_wrd(word);

		}
		else if (op == 3)
		{
			cout << "Enter the word" << endl;
			cin >> word;
			dict.writefile(word);
			//dict.add_wrd(word);
			//dict.writefile();
		}
		else if (op == 4)
		{
			dict.print_wrd_list();
		}
		else if (op == 5)
		{
			exit;
		}
		else
		{
			cout << "enter invalid choice";
		}
		system("pause");
		system("cls");
	} while (op != 5);
	return 0;
}