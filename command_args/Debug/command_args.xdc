<?xml version="1.0"?><doc>
<members>
<member name="T:COMMAND_OPTION" decl="false" source="c:\users\владимир\source\repos\command_args\command_args\command_args.h" line="5">
Class COMMAND_OPTION presents a description for a single command line parameter, i.e. -h or --help or -v or --version 
</member>
<member name="F:COMMAND_OPTION.mShortNames" decl="false" source="c:\users\владимир\source\repos\command_args\command_args\command_args.h" line="9">
<summary>Option short descriptions.
<para>Just write in " " all the symbols, you want to describe your option.</para>  
<seealso cref="F:COMMAND_OPTION.mLongName"/>  
</summary>
<example> You can use "hH" for <c>-h -H --help</c>, for example.  
</example> 
</member>
<member name="F:COMMAND_OPTION.mLongName" decl="false" source="c:\users\владимир\source\repos\command_args\command_args\command_args.h" line="16">
<summary>Option long description.
<para>Just write in " " all the symbols, you want to describe your option.</para>  
<seealso cref="F:COMMAND_OPTION.mShortNames"/>  
</summary>
</member>
<member name="F:COMMAND_OPTION.mNeedValue" decl="false" source="c:\users\владимир\source\repos\command_args\command_args\command_args.h" line="21">
<summary>Flag denotes, if this option needs a value.
<para>Default value is false.</para>  
</summary>
<example> You can specify, that your option <c>--length</c> need a value, i.e. <c>--length NUMBER</c> must be used.  
</example> 
</member>
<member name="F:COMMAND_OPTION.mDescription" decl="false" source="c:\users\владимир\source\repos\command_args\command_args\command_args.h" line="27">
<summary>Description of the option meaning.
</summary>
<example> You can specify, that your option <c>--help</c> means <c>"Print this help screen and exit"</c>.  
</example> 
</member>
</members>
</doc>