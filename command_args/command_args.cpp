// (c) 2017, coolabccoder@gmail.com
#include <string.h>

#include "command_args.h"

COMMAND_ARGS::COMMAND_ARGS()
{

}

COMMAND_ARGS::~COMMAND_ARGS()
{

}

COMMAND_OPTION::COMMAND_OPTION()
{
	this->mShortNames = 0;
	this->mLongName = 0;
	this->mNeedValue = false;
	this->mDescription = 0;
}

COMMAND_OPTION::~COMMAND_OPTION()
{
	delete[] this->mShortNames;
	delete[] this->mLongName;
	delete[] this->mDescription;
}

void COMMAND_OPTION::SetMemberValue(char **aMember, const char *aMemberValue)
{
	int tmpStrLen;

	*aMember = new char[tmpStrLen = strlen(aMemberValue) + 1];
	memcpy(*aMember, aMemberValue, tmpStrLen);
}

COMMAND_OPTION::COMMAND_OPTION(const char *aShortNames, const char *aLongName, const bool aNeedValue, const char *aDescription)
{
	SetMemberValue(&(this->mShortNames), aShortNames);
	SetMemberValue(&(this->mLongName), aLongName);
	SetMemberValue(&(this->mDescription), aDescription);
	this->mNeedValue = aNeedValue;
}
