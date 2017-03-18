// (c) 2017 by Cool ABC Coder <coolabccoder@gmail.com>
#include <string.h>

#include "command_args.h"

COMMAND_ARGS::COMMAND_ARGS()
{
	
	

}

COMMAND_ARGS::~COMMAND_ARGS()
{
	for (auto commandOption : this->commandOptions)
	{
		delete commandOption;
	}
}

void COMMAND_ARGS::AddOption(const char * aShortNames, const char * aLongName, const bool aNeedValue, const char * aDescription)
{
	this->commandOptions.push_back(new COMMAND_OPTION(aShortNames, aLongName, aNeedValue, aDescription));
}

COMMAND_OPTION::COMMAND_OPTION()
{
	this->shortNames = 0;
	this->longName = 0;
	this->needValue = false;
	this->description = 0;
}

COMMAND_OPTION::~COMMAND_OPTION()
{
	delete[] this->shortNames;
	delete[] this->longName;
	delete[] this->description;
}

void COMMAND_OPTION::SetMemberStringValue(char **aMember, const char *aMemberValue)
{
	int tmpStrLen;

	delete[] * aMember;
	*aMember = new char[tmpStrLen = strlen(aMemberValue) + 1];
	memcpy(*aMember, aMemberValue, tmpStrLen);
}

COMMAND_OPTION::COMMAND_OPTION(const char *aShortNames, const char *aLongName, const bool aNeedValue, const char *aDescription)
	:COMMAND_OPTION()
{
	SetMemberStringValue(&(this->shortNames), aShortNames);
	SetMemberStringValue(&(this->longName), aLongName);
	SetMemberStringValue(&(this->description), aDescription);
	this->needValue = aNeedValue;
}
