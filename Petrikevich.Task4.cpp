#include <iostream>
#include <string.h>

using namespace std;

bool AreEqual(char*, char*);
void DeleteWord(char*, char*);

int main()
{
	const int lenght = 256;
	char* string = " ";
	char* word = " ";
	cout << "Enter your text: " << endl;
	cin.getline(string, lenght, '\n');
	cout << "Enter a word what sre you want to delete: " << endl;
	cin.getline(word, lenght, '\n');

	cout << "You text: " << endl;
	cout << string;
	DeleteWord(string, word);
	cout << "Text after delete words: " << endl;
	cout << string;
	system("pause");
	return 0;

	system("pause");
	return 0;
}

bool  AreEqual(char* string, char* word)
{
	{
		if (strlen(word) != strlen(string))
			return false;

		for (int i = 0; i < strlen(string); i++)
		{
			if (word[i] != string[i])
				return false;
		}
		return true;
	}
}

void DeleteWord(char* string, char* word)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* pWord = strpbrk(string, symbols);
	while (pWord)
	{
		int length = strspn(pWord, symbols);
		if (AreEqual(pWord, word))
			strcpy(pWord, pWord + length);
		else
			pWord += strlen(word);
		pWord = strpbrk(pWord, symbols);
	}
}
