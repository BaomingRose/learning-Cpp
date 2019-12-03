#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

#if 0
void testFile() {
#if 0
	const char* filename = "test.txt";
	fopen(filename, "r");
	fgetc, fgets, fread;
	fclose();
#endif
	int a = 100;
	char c = 'a';
	ofstream fout("test.txt");
	fout << a << endl; 
	fout << c << endl;
	fout.close();

	ifstream fin("test.txt");
	int ia;
	char ic;
	//文本形式读，和控制台读差不多
	fin >> ia;		//atoi
	fin >> ic;
	fin.get(c);
	//fin.getline();
	fin.close();
#endif
void testFile() {
	int a = 100;
	char c = 'a';
	ofstream fout("test.txt");
	fout << a << endl;
	fout << c << endl;
	fout.close();
	ifstream fin("test.txt");
	int ia;
	char ic;
	fin >> ia;
	fin >> ic;
	fin.close();
}

struct ServerInfo {
	char ip[100];
	int port;
};

class config {
public:
	config(string filename = "config") : _binaryFile(filename + ".cfg"), _textFile(filename + ".txt") {	}

	void ReadText(ServerInfo& info) {
		ifstream fin(_textFile.c_str());
		fin >> info.ip;
		fin >> info.port;
		fin.close();
	}

	void WriteText(const ServerInfo& info) {
		ofstream fout(_textFile.c_str());
		fout << info.ip << endl;
		fout << info.port << endl;
		fout.close();
	}

	void ReadBin(ServerInfo& info) {
		ifstream fin(_binaryFile.c_str());
		fin.read((char*)&info, sizeof(ServerInfo));
		fin.close();
	}

	void WriteBin(const ServerInfo& info) {
		ofstream fout(_binaryFile.c_str());
		fout.write((char*)&info, sizeof(ServerInfo));
		fout.close();
	}

private:
	string _binaryFile;
	string _textFile;
};

void testConfig() {
	ServerInfo info;
	config cfg;

	strcpy(info.ip, "192.168.1.1");
	info.port = 3066;

	cfg.WriteText(info);
	cfg.WriteBin(info);

	ServerInfo info2;
	ServerInfo info3;
	cfg.ReadBin(info2);
	cfg.ReadText(info3);
}

int main() {
	int a, b;
	//testFile();
	testConfig();
	//scanf("%f", &a);	//a值不确定，特别大
	scanf("%d,%d", &a, &b);
	cout << a << ' ' << b << endl;
	cerr << a << endl;
	clog << a << endl;

	return 0;
}