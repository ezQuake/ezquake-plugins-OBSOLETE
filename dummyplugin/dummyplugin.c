/**
	\file

	\brief
	The Dummy Plugin. To test and demonstrate the plugins functionality
	and to give a base for creating new plugins.

	\author
	johnnycz
**/

#include "../plugin.h"

// handler of ExecuteCommand event
int Plug_ExecuteCommand(int *args)
{
	char cmd[256];
	Cmd_Argv(0, cmd, sizeof(cmd));
	if (!strcmp("dummyplugin_cmd", cmd))
	{
		char buf[100];
		
		Con_Printf("This is dummy plugin talking.\n");
		if (Cvar_GetString("dummyplugin_cvar", buf, sizeof(buf))) {
			Con_Printf("dummyplugin_cvar value is: '%s'", buf);
		}
		else {
			Con_Printf("Something went wrong, cannot find dummyplugin_cvar\n");
		}
		return 1;
	}
	return 0;
}

// handler of Tick event
int Plug_Tick(int *args)
{
	int currenttime = args[0];
	return true;
}

static int Plug_InitHooks(void)
{
	// return true if registering of all hooks succeeds
	return
		Plug_Export("ExecuteCommand", Plug_ExecuteCommand)
		&& Plug_Export("Tick", Plug_Tick);
}

int Plug_Init(int *args)
{
	// first of all, register hooks this plugins needs
	if (Plug_InitHooks())
	{
		// proceed only if registering of all hooks succeeded

		// call engine function to register this plugin's command
		Cmd_AddCommand("dummyplugin_cmd");
		// call engine function to register this plugin's variable
		Cvar_Register("dummyplugin_cvar", "", 0, "");

		return 1;
	}
	return 0;
}
