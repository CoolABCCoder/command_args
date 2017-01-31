// (c) 2017, coolabccoder@gmail.com
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

}

COMMAND_OPTION::~COMMAND_OPTION()
{
	delete[] this->mShortNames;
	delete[] this->mLongName;
}