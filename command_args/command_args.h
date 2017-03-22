// (c) 2017 by Cool ABC Coder <coolabccoder@gmail.com>
#pragma once

#ifndef _COMMAND_ARGS_H_
#define _COMMAND_ARGS_H_

#include <vector>
#include <string>

namespace CommandArgs
{

using namespace std;

/// Class COMMAND_OPTION presents a description for a single command line parameter, i.e. -h or --help or -v or --version 
/// <para>Do not need to create one explicitly, use only COMMAND_ARGS <seealso cref="COMMAND_ARGS"/></para>
/// TODO: This class is not for export
class COMMAND_OPTION
{
private:
	/// <summary>Option short descriptions.
	/// <para>Just write in " " all the symbols, you want to describe your option.</para>  
	/// <seealso cref="COMMAND_OPTION::longName"/>  
	/// </summary>
	/// <example> You can use "hH" for <c>-h -H --help</c>, for example.  
	/// </example> 
	char* shortNames;

	/// <summary>Option long description.
	/// <para>Just write in " " all the symbols, you want to describe your option.</para>  
	/// <seealso cref="COMMAND_OPTION::shortNames"/>  
	/// </summary>
	char* longName;

	/// <summary>Flag denotes, if this option needs a value.
	/// <para>Default value is false.</para>  
	/// </summary>
	/// <example> You can specify, that your option <c>--length</c> need a value, i.e. <c>--length NUMBER</c> must be used.  
	/// </example> 
	bool needValue;

	/// <summary>Description of the option meaning.
	/// </summary>
	/// <example> You can specify, that your option <c>--help</c> means <c>"Print this help screen and exit"</c>.  
	/// </example> 
	char* description;

	/// <summary> Set member to new value.
	/// <param name="aMember">Pointer to member <c>char*</c> field</param>
	/// <param name="aMemberValue">Value of member field</param>
	/// </summary>
	void SetMemberStringValue(char** aMember, const char* aMemberValue);

public:
	/// COMMAND_OPTION constructor
	/// <summary> Constructor of class COMMAND_OPTION with values
	///<para>TODO: Check, if shortNames has repeating symbols, such as "hHh"</para>
	/// <para>TODO: Check, if longNames has wrong symbols such as ' ', '\t', '\n', '\r' and so</para>	
	// TODO: Check, if shortNames has repeating symbols, such as "hHh"
	// TODO: Check, if longNames has wrong symbols such as ' ', '\t', '\n', '\r' and so
	/// <param name="aShortNames">Value for shortNames<seealso cref="COMMAND_OPTION::shortNames"/></param>
	/// <param name="aLongName">Value for longNames<seealso cref="COMMAND_OPTION::longName"/></param>
	/// <param name="aNeedValue">Value for needValue<seealso cref="COMMAND_OPTION::needValue"/></param>
	/// <param name="aDescription">Value for description<seealso cref="COMMAND_OPTION::description"/></param>
	/// </summary>
	COMMAND_OPTION(const char* aShortNames, const char* aLongName, const bool aNeedValue, const char* aDescription);
	COMMAND_OPTION(const string aShortNames, const string aLongName, const bool aNeedValue, const string aDescription);
	COMMAND_OPTION();
	~COMMAND_OPTION();
	char* getShortNames() const { return this->shortNames; };
	char* getLongName() const { return this->longName; };
	char* getDescription() const { return this->description; };
	bool getNeedValue() const  { return this->needValue; };
};



/// <summary>Class COMMAND_ARGS, containing and processing command options</summary>
class COMMAND_ARGS
{
private:
	/// <summary>List with command options.</summary>
	vector <COMMAND_OPTION*> commandOptions;

public:
	COMMAND_ARGS();
	/// <simmary>Constructor with all parameters in it
	/// <param name="aCommandOptions">Vector of Command options</param>
	/// </summary>
	COMMAND_ARGS(vector<COMMAND_OPTION> aCommandOptions);
	/// <simmary>Constructor with all parameters in it
	/// <param name="aCommandOptions">Vector of Command options</param>
	/// </summary>
	COMMAND_ARGS(vector<COMMAND_OPTION*> aCommandOptions);
	~COMMAND_ARGS();
	/// <summary>Add command option to list COMMAND_ARGS::commandOptions
	/// <para>TODO: Check, if such a option allready exists</para>
	// TODO: Check, if such a option allready exists
	/// <param name="aShortNames">Value for shortNames<seealso cref="COMMAND_OPTION::shortNames"/></param>
	/// <param name="aLongName">Value for longNames<seealso cref="COMMAND_OPTION::longName"/></param>
	/// <param name="aNeedValue">Value for needValue<seealso cref="COMMAND_OPTION::needValue"/></param>
	/// <param name="aDescription">Value for description<seealso cref="COMMAND_OPTION::description"/></param>
	/// </summary>
	COMMAND_OPTION* AddOption(const char* aShortNames, const char* aLongName, const bool aNeedValue, const char* aDescription);
	/// <summary>Add command option to list COMMAND_ARGS::commandOptions with string parameters.
	/// <param name="aShortNames">Value for shortNames<seealso cref="COMMAND_OPTION::shortNames"/></param>
	/// <param name="aLongName">Value for longNames<seealso cref="COMMAND_OPTION::longName"/></param>
	/// <param name="aNeedValue">Value for needValue<seealso cref="COMMAND_OPTION::needValue"/></param>
	/// <param name="aDescription">Value for description<seealso cref="COMMAND_OPTION::description"/></param>
	/// </summary>
	COMMAND_OPTION* AddOption(const string aShortNames, const string aLongName, const bool aNeedValue, const string aDescription);
	/// <summary>Add command option to list COMMAND_ARGS::commandOptions for usage in 
	/// <param name="aCommandOption">Option to add<seealso cref="COMMAND_OPTION"/></param>
	/// </summary>
	COMMAND_OPTION* AddOption(const COMMAND_OPTION& aCommandOption);

	
	/// Count of elements in list COMMAND_ARGS::commandOptions
	int OptionsCount() { return this->commandOptions.size(); };
};

}

#endif