// (c) 2017 by Cool ABC Coder <coolabccoder@gmail.com>

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../command_args/command_args.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace command_args_test
{		
	TEST_CLASS(CommandOptionTest)
	{
	public:
		// Test COMMAND_OPTION constructor
		/// <summary>Test COMMAND_OPTION constructor</summary>
		TEST_METHOD(COMMAND_OPTION_CONSTRUCTOR_DESTRUCTOR)
		{
			COMMAND_OPTION *commandOption;
			const char testShortNames[] = "hH";
			// TODO: Add test for such short name of option
			const char testShortNamesWrong[] = "hHh -";
			const char testLongName[] = "help";
			const char testDescription[] = "Print help screen and exit";
			const bool testNeedValue = false;
			
			try
			{
				commandOption = new COMMAND_OPTION(testShortNames, testLongName, testNeedValue, testDescription);
			}
			catch (...)
			{
				Assert::Fail(L"COMMAND_OPTION constructor error");
			}
			Assert::AreEqual(strlen(testShortNames), strlen(commandOption->getShortNames()), L"COMMAND_OPTION.shortNames wrong length");
			Assert::AreEqual(0, memcmp(testShortNames, commandOption->getShortNames(), strlen(commandOption->getShortNames())), L"COMMAND_OPTION.shortNames wrong value");

			Assert::AreEqual(strlen(testLongName), strlen(commandOption->getLongNames()), L"COMMAND_OPTION.longNames wrong length");
			Assert::AreEqual(0, memcmp(testLongName, commandOption->getLongNames(), strlen(commandOption->getLongNames())), L"COMMAND_OPTION.longNames wrong value");

			Assert::AreEqual(strlen(testDescription), strlen(commandOption->getDescription()), L"COMMAND_OPTION.description wrong length");
			Assert::AreEqual(0, memcmp(testDescription, commandOption->getDescription(), strlen(commandOption->getDescription())), L"COMMAND_OPTION.description wrong value");

			Assert::AreEqual(testNeedValue, commandOption->getNeedValue(), L"COMMAND_OPTION.needValue wrong value");

			try
			{
				delete commandOption;
				commandOption = new COMMAND_OPTION();
				delete commandOption;
			}
			catch (...)
			{
				Assert::Fail(L"COMMAND_OPTION destructor error");
			}
		}

		

	};


	TEST_CLASS(CommandArgsTest)
	{
	public:
		// Test COMMAND_ARGS constructor
		/// <summary>Test COMMAND_ARGS constructor method</summary
		TEST_METHOD(COMMAND_ARGS_CONSTRUCTOR_DESTRUCTOR)
		{
			COMMAND_ARGS *commandArgs;
			const char testShortNames[] = "hH";
			const char testLongName[] = "help";
			const char testDescription[] = "Print help screen and exit";
			const bool testNeedValue = true;

			try
			{
				commandArgs = new COMMAND_ARGS;
			}
			catch (...)
			{
				Assert::Fail(L"COMMAND_ARGS constructor error");
			}

			commandArgs->AddOption(testShortNames, testLongName, testNeedValue, testDescription);

			try
			{
				delete commandArgs;
			}
			catch (...)
			{
				Assert::Fail(L"COMMAND_ARGS destructor error");
			}
		}


		TEST_METHOD(COMMAND_ARGS_ADD_OPTION)
		{
			COMMAND_ARGS *commandArgs;
			const char testShortNamesHelp[] = "hH";
			const char testShortNamesRepeat[] = "H";
			const char testShortNamesVersion[] = "vV";
			const char testLongNameHelp[] = "help";
			const char testLongNameVersion[] = "version";
			const char testLongNameWrong[] = "help me please";
			const char testDescriptionHelp[] = "Print help screen and exit";
			const char testDescriptionVersion[] = "Print version screen and exit";
			const bool testNeedValue = false;

			commandArgs = new COMMAND_ARGS;
			commandArgs->AddOption(testShortNamesHelp, testLongNameHelp, testNeedValue, testDescriptionHelp);
			commandArgs->AddOption(testShortNamesHelp, testLongNameVersion, testNeedValue, testDescriptionVersion);
			commandArgs->AddOption(testShortNamesRepeat, testLongNameVersion, testNeedValue, testDescriptionVersion);
			Assert::AreEqual(1, commandArgs->OptionsCount(), L"In commandArgs added wrong option (repetition of short name)");


			commandArgs->AddOption(testShortNamesVersion, testLongNameHelp, testNeedValue, testDescriptionVersion); // same long name
			Assert::AreEqual(1, commandArgs->OptionsCount(), L"In commandArgs added wrong option (repetition of long name)");

			commandArgs->AddOption(testShortNamesVersion, testLongNameVersion, testNeedValue, testDescriptionHelp); // same descrition
			Assert::AreEqual(1, commandArgs->OptionsCount(), L"In commandArgs added wrong option (repetition of long name)");

			commandArgs->AddOption(testShortNamesVersion, testLongNameVersion, testNeedValue, testDescriptionVersion); // same long name
			Assert::AreEqual(2, commandArgs->OptionsCount(), L"In commandArgs new option not added");

			delete commandArgs;

		}



	};
}