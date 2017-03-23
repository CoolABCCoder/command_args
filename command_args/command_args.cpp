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

COMMAND_ARGS::COMMAND_ARGS(const vector<COMMAND_OPTION*>& aCommandOptions)
{
	for (auto commandOption : aCommandOptions)
	{
		this->AddOption(*commandOption);
	}
}

COMMAND_ARGS::COMMAND_ARGS(const vector<COMMAND_OPTION>& aCommandOptions)
{
	for (auto commandOption : aCommandOptions)
	{
		this->AddOption(commandOption);
	}
}

int COMMAND_ARGS::OptionsCount() 
{ 
	return this->commandOptions.size(); 
};

const COMMAND_OPTION* COMMAND_ARGS::Option(int i) 
{
	if (i >= this->OptionsCount())
		return nullptr;
	return this->commandOptions.at(i);
};

const COMMAND_OPTION* COMMAND_ARGS::AddOption(const string& aShortNames, const string& aLongName, const bool aNeedValue, const string& aDescription)
{
	for (auto option : this->commandOptions)
	{
		if (! aDescription.compare(option->getDescription()))
			return NULL; // Repeated description - no addition;
		if (! aLongName.compare(option->getLongName()))
			return NULL; // Repeated description - no addition;
		for(auto p: aShortNames)
		{
			if (option->getShortNames().find(p) != string::npos  ) // some symbols in aShortNames allready used
				return NULL;
		}
	}
	this->commandOptions.push_back(new COMMAND_OPTION(aShortNames, aLongName, aNeedValue, aDescription));
	return this->commandOptions.back();

}


const COMMAND_OPTION* COMMAND_ARGS::AddOption(const COMMAND_OPTION& aCommandOption)
{
	return this->AddOption(aCommandOption.getShortNames(), aCommandOption.getLongName(), aCommandOption.getNeedValue(), aCommandOption.getDescription());
}


COMMAND_OPTION::COMMAND_OPTION()
	: shortNames(""s), longName(""s), needValue(false), description(""s)
{
	
}

COMMAND_OPTION::~COMMAND_OPTION()
{
	this->shortNames.clear();
	this->longName.clear();
	this->description.clear();
}

void COMMAND_OPTION::SetMemberStringValue(string& aMember, const string& aMemberValue)
{
	aMember = aMemberValue;
}

COMMAND_OPTION::COMMAND_OPTION(const string& aShortNames, const string& aLongName, const bool aNeedValue, const string& aDescription)
	:COMMAND_OPTION()
{
	string tmpShortNames(""s);

	// TODO: No parameters with empty values "" - HOWTO process?

	for(auto c: aShortNames)
	{
		if (tmpShortNames.find(c) == string::npos) // no such name (symbol)
			tmpShortNames.push_back(c);
	}

	SetMemberStringValue(this->shortNames, tmpShortNames);
	SetMemberStringValue(this->longName, aLongName);
	SetMemberStringValue(this->description, aDescription);
	this->needValue = aNeedValue;

}
