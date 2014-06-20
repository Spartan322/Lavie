#include "rpPlugin.h"

int rp::handleCommand(string nick, string channel, vector<string> words)
{
		string reply = "";
		if(nick != "")
		{
				reply += nick + ": ";
		}
		if(words.at(0) == "roll")
		{
			if(words.length < 3)
			{
				rpActions::roll(words.at(1), words.at(2));
				return 1;
			}
			else
			{
				rpActions::roll(words.at(1), words.at(2), words.at(3), words;
			}
		}
}
