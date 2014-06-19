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
		string gametype;
		vector<string> classNames;
	public:
		rpClass(string gametype);
		void setClass(string name);
		bool ClassExistence(string name);
		int Clean(int type);
};

class rpPlayer
{
	private:
		string name;
		bool invloved = false;
	public:
		rpPlayer(string name);
		togglePlay();
};

class rpPlayers
{
	private:
		vector<rpPlayer> players;
	public:
		rpPlayers();
		string ListPlayers(bool playing);
		
};
#endif
