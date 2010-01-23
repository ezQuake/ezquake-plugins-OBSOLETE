#include "../plugin.h"

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

int Plug_Init(int *args)
{
	if (Plug_Export("ExecuteCommand", Plug_ExecuteCommand))
	{
		Cmd_AddCommand("dummyplugin_cmd");
		Cvar_Register("dummyplugin_cvar", "", 0, "");

		return 1;
	}
	return 0;
}
