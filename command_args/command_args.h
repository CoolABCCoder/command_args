#pragma once

// (c) 2017 by Cool ABC Coder <coolabccoder@gmail.com>

/// Class COMMAND_OPTION presents a description for a single command line parameter, i.e. -h or --help or -v or --version 
class COMMAND_OPTION
{
private: 
	/// <summary>Option short descriptions.
	/// <para>Just write in " " all the symbols, you want to describe your option.</para>  
	/// <seealso cref="COMMAND_OPTION::mLongName"/>  
	/// </summary>
	/// <example> You can use "hH" for <c>-h -H --help</c>, for example.  
	/// </example> 
	char *mShortNames;
	/// <summary>Option long description.
	/// <para>Just write in " " all the symbols, you want to describe your option.</para>  
	/// <seealso cref="COMMAND_OPTION::mShortNames"/>  
	/// </summary>
	char *mLongName;
	/// <summary>Flag denotes, if this option needs a value.
	/// <para>Default value is false.</para>  
	/// </summary>
	/// <example> You can specify, that your option <c>--length</c> need a value, i.e. <c>--length NUMBER</c> must be used.  
	/// </example> 
	bool mNeedValue;
	/// <summary>Description of the option meaning.
	/// </summary>
	/// <example> You can specify, that your option <c>--help</c> means <c>"Print this help screen and exit"</c>.  
	/// </example> 
	char *mDescription;

	void SetMemberValue(char **aMember, const char *aMemberValue);

public:
	COMMAND_OPTION(const char *aShortNames, const char *aLongName, const bool aNeedValue, const char *aDescription);
	COMMAND_OPTION();
	~COMMAND_OPTION();
};

class COMMAND_ARGS
{
private:
	

public:
	COMMAND_ARGS();
	~COMMAND_ARGS();
};