// musaab imran
// CY-5T
// 20i-1794

#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <bitset>
#include <sstream>
#include <string>
using namespace std;


string to_ascii(string st)
{
	//cout << endl;
	//cout << st << endl;
	stringstream sstream(st);
	string output;
	while (sstream.good())
	{
		bitset<8> bits;
		sstream >> bits;
		char c = char(bits.to_ulong());
		output += c;
	}

	return output;
}

int main()
{
	// array declaration
	int A[93]{};
	int B[84]{};
	int C[111]{};
	int key[20000]{};
	int plaintext[20000]{};
	int encrypt[20000]{};
	int decrypt[20000]{};

	// file reading
	fstream file;

	// variable declaration
	int count = 0;
	int count2 = 0;
	int len = 0;
	int num1 = 0, num2 = 0, num3 = 0;
	int temp1 = 0, temp2 = 0, temp3 = 0;

	// string declaration
	string input, str, save;
	string IV = "";
	string key_b = "";

	// IV from the file
	fstream file2;
	file2.open("data1.txt", ios::in);
	if (file2.is_open())
	{
		getline(file2, IV);
	}
	//cout << IV << endl;
	
	
	// key from the file
	fstream file3;
	file3.open("data2.txt", ios::in);
	if (file3.is_open())
	{
		getline(file3, key_b);
	}
	//cout << key_b << endl;
	

	// random number
	srand(time(0));


	// value of register A
	//cout << " Value of Register A:- ";
	for (int i = 0; i < 93; i++)
	{
		if (i <= 79)
		{
			A[i] = IV[i]-48;
		}

		else
		{
			A[i] = 0;
		}
		//cout << A[i];
	}


	// value of register B
	//cout << " Value of Register B:- ";
	for (int i = 0; i < 84; i++)
	{
		if (i <= 79)
		{
			B[i] = key_b[i] - 48;
		}

		else
		{
			B[i] = 0;
		}

		//cout << B[i];
	}
	//cout << endl;

	// value of register C
	//cout << " Value of Register C:- ";
	for (int i = 0; i < 111; i++)
	{
		if (i <= 107)
		{
			C[i] = 0;
		}

		else
		{
			C[i] = 1;
		}

		//cout << C[i];
	}
	//cout << endl;

	// taking input
	file.open("data.txt", ios::in);
	if (file.is_open())
	{
		getline(file, input);
	}
	cout << " Input: " << input;
	//cout << "\n Enter the Plaintext:- ";
	//getline(cin, input);
	cout << "\n Length of the Input String:- " << input.length() << endl;

	// string to binary
	for (int i = 0; i < input.length(); i++)
	{
		string str = bitset<8>(input[i]).to_string();
		save += str;
	}

	// length of plaintext in binary
	len = save.length();

	// converting the plain text into binary
	cout << "\n Plaintext: " << endl;
	cout << " Value of Plaintext: ";
	for (int i = 0; i <= len-1; i++)
	{

		plaintext[i]= save[i]-48;
		cout << plaintext[i];

	}
	cout << endl;

	// length of the plaintext
	cout << " Length of Plaintext:- " << len << endl;


	// warmup
	for (int i = 0; i <1152; i++)
	{
		num1 = A[90] & A[91];
		num1 = num1 ^ A[92];
		num1 = num1 ^ A[65];

		num2 = B[81] & B[82];
		num2 = num2 ^ B[83];
		num2 = num2 ^ B[68];

		num3 = C[108] & C[109];
		num3 = num3 ^ C[110];
		num3 = num3 ^ C[65];

		A[0] = num3 ^ A[68];
		B[0] = num1 ^ B[77];
		C[0] = num2 ^ A[86];

		for (int i = 92; i > 0; i--)
		{
			A[i] = A[i - 1];
		}

		for (int i = 83; i > 0; i--)
		{
			B[i] = B[i - 1];
		}

		for (int i = 110; i > 0; i--)
		{
			C[i] = C[i - 1];
		}

	}

	// key generation
	for (int i = 0; i <= len - 1; i++)
	{
		num1 = A[90] & A[91];
		num1 = num1 ^ A[92];
		num1 = num1 ^ A[65];

		num2 = B[81] & B[82];
		num2 = num2 ^ B[83]; 
		num2 = num2 ^B[68];

		num3 = C[108] & C[109];
		num3 = num3 ^ C[110];
		num3 = num3 ^ C[65];

		key[i] = num1 ^ num2;
		key[i] = key[i] ^ num3;
		
		A[0] = num3 ^ A[68];
		B[0] = num1 ^ B[77];
		C[0] = num2 ^ A[86];

		for (int i = 92; i > 0; i--)
		{
			A[i] = A[i - 1];
		}

		for (int i = 83; i > 0; i--)
		{
			B[i] = B[i - 1];
		}

		for (int i = 110; i > 0; i--)
		{
			C[i] = C[i - 1];
		}

		//cout << key[i];
		count2++;
	}

	// encryption with the key
	cout << "\n Encryption: ";
	string en,e;
	cout << "\n Encrypted Binary:- ";
	for (int i = 0; i <= count2-1; i++)
	{
		stringstream s;
		encrypt[i] = plaintext[i] ^ key[i];
		cout << encrypt[i];
		s << encrypt[i];
		s >> e;
		en += e;
	}

	// encrypted text
	cout << "\n\n Encrypted Text:- ";
	cout << "\n Encrypted Text:- ";
	string temp = to_ascii(en);
	cout << temp;


	// decryption using key and ciper text
	cout << "\n\n Decryption: ";
	string d, dn;
	cout << "\n Decrypted Binary:- ";
	for (int j = 0; j <= count2-1; j++)
	{
		stringstream s1;
		decrypt[j] = encrypt[j] ^ key[j];
		cout << decrypt[j];
		s1 << decrypt[j];
		s1 >> d;
		dn = dn + d;
	}

	// decrypted text
	cout << "\n\n Decrypted Text:- " << to_ascii(dn);

	cout << endl;
	cout << endl;

	return 0;
}
