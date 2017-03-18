// (c) 2017 by Cool ABC Coder <coolabccoder@gmail.com>
#pragma once

#include <list>

using namespace std;

/// Class COMMAND_OPTION presents a description for a single command line parameter, i.e. -h or --help or -v or --version 
class COMMAND_OPTION
{
private: 
	/// <summary>Option short descriptions.
	/// <para>Just write in " " all the symbols, you want to describe your option.</para>  
	/// <seealso cref="COMMAND_OPTION::longName"/>  
	/// </summary>
	/// <example> You can use "hH" for <c>-h -H --help</c>, for example.  
	/// </example> 
	char *shortNames;

	/// <summary>Option long description.
	/// <para>Just write in " " all the symbols, you want to describe your option.</para>  
	/// <seealso cref="COMMAND_OPTION::shortNames"/>  
	/// </summary>
	char *longName;

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
	char *description;

	/// <summary> Set member to new value.
	/// <param name="aMember">Pointer to member <c>char*</c> field</param>
	/// <param name="aMemberValue">Value of member field</param>
	/// </summary>
	void SetMemberStringValue(char **aMember, const char *aMemberValue);

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
	COMMAND_OPTION(const char *aShortNames, const char *aLongName, const bool aNeedValue, const char *aDescription);
	COMMAND_OPTION();
	~COMMAND_OPTION();
	char* getShortNames() { return this->shortNames; };
	char* getLongNames() { return this->longName; };
	char* getDescription() { return this->description; };
	bool getNeedValue() { return this->needValue; };
};

/// <summary>Class, containing and processing command options</summary>
class COMMAND_ARGS
{
private:
	/// <summary>List with command options.</summary>
	list <COMMAND_OPTION*> commandOptions;

public:
	COMMAND_ARGS();
	~COMMAND_ARGS();
	/// <summary>Add command option to list COMMAND_ARGS::commandOptions
	/// <para>TODO: Check, if such a option allready exists</para>
	// TODO: Check, if such a option allready exists
	/// <param name="aShortNames">Value for shortNames<seealso cref="COMMAND_OPTION::shortNames"/></param>
	/// <param name="aLongName">Value for longNames<seealso cref="COMMAND_OPTION::longName"/></param>
	/// <param name="aNeedValue">Value for needValue<seealso cref="COMMAND_OPTION::needValue"/></param>
	/// <param name="aDescription">Value for description<seealso cref="COMMAND_OPTION::description"/></param>
	/// </summary>
	void AddOption(const char *aShortNames, const char *aLongName, const bool aNeedValue, const char *aDescription);
	/// Count of elements in list COMMAND_ARGS::commandOptions
	int OptionsCount() { return this->commandOptions.size(); };
};