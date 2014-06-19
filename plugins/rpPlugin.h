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
#endif
