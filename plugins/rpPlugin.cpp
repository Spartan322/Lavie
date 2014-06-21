#include "rpPlugin.h"

#define RP_NAME_SAY 0

int rp::handleCommand(string nick, string channel, vector<string> words)
{
		string reply = "";
		if(nick != "")
		{
				reply += (RP_SAY_NAME == 1) ? nick + ": " : channel + " GameMaster: ";
		}
		/*Roll Command*/
		if(words.at(0) == "roll")
		{
			string text;
			if(words.size() < 3)
			{
				text = rpActions::roll(words.at(1), words.at(2));
				return 1;
			}
			else
			{
				vector<string> swords;
				for(int i = 2; i < words.size(); i++)
				{
					swords.at(i-2) = words.at(i);
				}
				text = rpActions::roll(words.at(1), words.at(2), words.at(3), swords);
				~swords();
			}
			reply += text;
			return 1;
		}
		if(words.at(0) == "rules")
		{
			string text;
			text = "The Rules:\n"
			text+= rpRules::GetRules();
		}
		/*End Roll Command*/
		return 0;
}

int rp::handleMessage(string nick, string channel, vector<string> words)
{
	string reply = "";
	if(words.find("rules") - words.find("are") <= 2 || stringsUtils::toLower(words.at(words.find("rules") - 3)) == "what")
	{
		reply = "The Rules:\n";
		reply+= rpRules::GetRules();
		return 1;
	}
	return 0;
}

int rp::doTick()
{
	return 0;
}

int rp::startupOptions(vector<string> args)
{
	return 0;
}
