// (c) 2017 by Cool ABC Coder <coolabccoder@gmail.com>

#include "command_args.h"

using namespace CommandArgs;

COMMAND_ARGS::COMMAND_ARGS()
{
	
}

COMMAND_ARGS::~COMMAND_ARGS()
{
	for (auto commandOption : this->commandOptions)
	{
		delete commandOption;
	}
	this->commandOptions.clear();
}

COMMAND_ARGS::COMMAND_ARGS(vector<COMMAND_OPTION*> aCommandOptions)
{
	for (auto commandOption : aCommandOptions)
	{
		this->AddOption(*commandOption);
	}
}

COMMAND_ARGS::COMMAND_ARGS(vector<COMMAND_OPTION> aCommandOptions)
{
	for (auto commandOption : aCommandOptions)
	{
		this->AddOption(commandOption);
	}
}

COMMAND_OPTION* COMMAND_ARGS::AddOption(const string aShortNames, const string aLongName, const bool aNeedValue, const string aDescription)
{
	for (auto option : this->commandOptions)
	{
		if (!strcmp(option->getDescription(), aDescription.c_str()))
			return NULL; // Repeated description - no addition;
		if (!strcmp(option->getLongName(), aLongName.c_str()))
			return NULL; // Repeated description - no addition;
		for(auto p: aShortNames)
		{
			if (strchr(option->getShortNames(), p)) // some symbols in aShortNames allready used
				return NULL;
		}
	}
	this->commandOptions.push_back(new COMMAND_OPTION(aShortNames, aLongName, aNeedValue, aDescription));
	return this->commandOptions.back();

}

COMMAND_OPTION* COMMAND_ARGS::AddOption(const char* aShortNames, const char* aLongName, const bool aNeedValue, const char* aDescription)
{
	return this->AddOption(string(aShortNames), string(aLongName), aNeedValue, string(aDescription));
	
}

COMMAND_OPTION* COMMAND_ARGS::AddOption(const COMMAND_OPTION& aCommandOption)
{
	return this->AddOption(aCommandOption.getShortNames(), aCommandOption.getLongName(), aCommandOption.getNeedValue(), aCommandOption.getDescription());
}

COMMAND_OPTION::COMMAND_OPTION()
	: shortNames(0), longName(0), needValue(false), description(0)
{
	//this->shortNames = 0;
	// this->longName = 0;
	//this->needValue = false;
	// this->description = 0;
}

COMMAND_OPTION::~COMMAND_OPTION()
{
	delete[] this->shortNames;
	delete[] this->longName;
	delete[] this->description;
}

void COMMAND_OPTION::SetMemberStringValue(char** aMember, const char* aMemberValue)
{
	int tmpStrLen;

	delete[] * aMember;
	*aMember = new char[tmpStrLen = strlen(aMemberValue) + 1];
	memcpy(*aMember, aMemberValue, tmpStrLen);
}

COMMAND_OPTION::COMMAND_OPTION(const string aShortNames, const string aLongName, const bool aNeedValue, const string aDescription)
	:COMMAND_OPTION()
{
	// TODO: prepare aShortNames - should not have repeating symbols
	string tmpShortNames(""s);

	// TODO: No parameters with empty values "" - HOWTO process?

	//while (*shortNames)
	for(auto c: aShortNames)
	{
		if (tmpShortNames.find(c) == string::npos) // no such name (symbol)
			tmpShortNames.push_back(c);
	}

	//SetMemberStringValue(&(this->shortNames), aShortNames);
	SetMemberStringValue(&(this->shortNames), tmpShortNames.c_str());
	SetMemberStringValue(&(this->longName), aLongName.c_str());
	SetMemberStringValue(&(this->description), aDescription.c_str());
	this->needValue = aNeedValue;

}

COMMAND_OPTION::COMMAND_OPTION(const char* aShortNames, const char* aLongName, const bool aNeedValue, const char* aDescription)
	:COMMAND_OPTION(string(aShortNames), string(aLongName), aNeedValue, string(aDescription))
{
	
}

