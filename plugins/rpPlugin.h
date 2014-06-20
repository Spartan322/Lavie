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

namespace rpActions
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
		string info;
	public:
		rpClass(string name);
		void setInfo(string info);
		string getName();
		string getInfo();
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
		rpClass cla;
	public:
		rpObject(string name, rpClass cla);
		string getName();
		rpClass getClass();
};

class rpPlayer
{
	private:
		string name;
		bool involved = false;
		vector<rpObject> inventory; //Or owned objects
	public:
		rpPlayer(string name);
		void togglePlay();
		string getName();
		vector<string> getInventory();
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
