<?xml version="1.0"?><doc>
<members>
<member name="T:COMMAND_OPTION" decl="false" source="c:\users\владимир\source\repos\command_args\command_args\command_args.h" line="3">
Class COMMAND_OPTION presents a description for a single command line parameter
</member>
<member name="F:COMMAND_OPTION.mShortNames" decl="false" source="c:\users\владимир\source\repos\command_args\command_args\command_args.h" line="7">
<summary>Option short descriptions.
<para>Just write in " " all the symbols, you want to describe your option.</para>  
<seealso cref="F:COMMAND_OPTION.mLongName"/>  
</summary>
<example> You can use "hH" for <c>-h -H --help</c>, for example.  
</example> 
</member>
<member name="F:COMMAND_OPTION.mLongName" decl="false" source="c:\users\владимир\source\repos\command_args\command_args\command_args.h" line="14">
<summary>Option long description.
<para>Just write in " " all the symbols, you want to describe your option.</para>  
<seealso cref="F:COMMAND_OPTION.mShortNames"/>  
</summary>
</member>
<member name="F:COMMAND_OPTION.mNeedValue" decl="false" source="c:\users\владимир\source\repos\command_args\command_args\command_args.h" line="19">
<summary>Flag denotes, if this option needs a value.
<para>Just write in " " all the symbols, you want to describe your option.</para>  
</summary>
<example> You can specify, that your option <c>--length</c> need a value, i.e. <c>--length NUMBER</c> must be used.  
</example> 
</member>
</members>
</doc>