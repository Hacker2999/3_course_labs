#include <iostream>
#include <cstdarg>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

class Song {
	int song_number;
	string song_name;
	string composer;
	string poet;
	string singer;
public:
	void show() {
		cout << setw(16) << "Название песни: " << song_name << endl;
		cout << setw(16) << "Композитор: " << composer << endl;
		cout << setw(16) << "Поэт: " << poet << endl;
		cout << setw(16) << "Исполнитель: " << singer << endl;
	};
	Song() {

	}
	Song(string n, string c, string p, string r) {
		song_name = n;
		composer = c;
		poet = p;
		singer = r;
	}
	~Song() {}
	void set_number(int x) {
		song_number = x;
	}
	void show_number() {
		cout << setw(16) << "Номер песни: " << song_number << endl;
	}
	string get_name() {
		return song_name;
	}
	string get_singer() {
		return singer;
	}
};

class Disk {
	string name;
	int cost;
	vector<Song> songs;
public:
	Disk() {}
	Disk(string n, int c) {
		name = n;
		cost = c;
	}
	~Disk() {}
	int find_song_by_name(string n) {
		for (int i = 0; i < songs.size(); i++) {
			if (songs[i].get_name() == n) {
				songs[i].show_number();
				songs[i].show();
				cout << endl;
				return 0;
			}
		}
		printf("Песня по вашему запросу не найдена\n");
	}
	int find_song_by_singer(string s) {
		for (int i = 0; i < songs.size(); i++) {
			if (songs[i].get_singer() == s) {
				songs[i].show_number();
				songs[i].show();
				cout << endl;
				return 0;
			}
		}
		printf("Песня по вашему запросу не найдена\n");
	}
	void show_songs() {
		vector<string> songs2;
		for (int i = 0; i < songs.size(); i++) {
			songs2.push_back(songs[i].get_name());
		}
		sort(songs2.begin(), songs2.end());
		for (int i = 0; i < songs2.size(); i++) {
			find_song_by_name(songs2[i]);
		}
	}
	void add_song(Song song) {
		song.set_number(songs.size() + 1);
		songs.push_back(song);
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Song one("Кристал нахт", "Бубенцов", "Бубенцов", "Бубенцов");
	Song two("Кристальная ночь", "Бубенцов", "Бубенцов", "Бубенцов");
	Song test("Зимний день", "Биба", "Боба", "Зилибоба");
	Disk x("Тень первого облака", 300);
	x.add_song(test);
	x.add_song(one);
	x.add_song(two);
	x.show_songs();
	x.find_song_by_singer("Бубенцов");
}
