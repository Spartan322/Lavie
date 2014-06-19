#include "../plugin.h"

#ifndef RP_HEADER
#define RP_HEADER

using namespace std;

class rp:public plugin 
{
	public:
		int handleCommand(string nick, string channel, vector<string> words);
		int handleMessage(string nick, string channel, vector<string> words);
		int doTick();
		int startupOptions(vector<string> args);
};

class rpActions
{
	public:
		rpActions();
		int roll(string rolls, string faces);
		int roll(string rolls, string faces, string playerNum, const vector<string>);
		
};

class rpClass
{
	private:
		string name;
}

class rpClasses
{
	private:
		string gametype;
		vector<rpClass> classes;
	public:
		rpClasses(string gametype);
		void setClass(rpClass classes);
		bool ClassExistence(string name);
		int Clean(int type);
};

class rpObject
{
	private:
		string name;
		
	public:
};

class rpPlayer
{
	private:
		string name;
		bool involved = false;
		vector<string> inventory; //Or owned objects
	public:
		rpPlayer(string name);
		void togglePlay();
		bool getInvolved();
};

class rpPlayers
{
	private:
		vector<rpPlayer> players;
	public:
		rpPlayers();
		string ListPlayers(bool playing);
		rpPlayer GetPlayer(string name);
		bool isPlaying(string name);
};
#endif
