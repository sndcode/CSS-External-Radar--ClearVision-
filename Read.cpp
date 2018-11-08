#include "Read.h"

read_s Read;
CBasePlayer_s CBasePlayer;
CBasePlayer_s CBaseEntity[32];
RadarArray_s RadarArray[32];

extern target_s Target;

struct addr_s
{
	DWORD BasePlayer = 0x4C6708;
	DWORD RadarBase = 0x50C150; 
}Address;

void read_s::AccessProcess()
{
	if (Target.hWindow)
	{
		GetWindowThreadProcessId(Target.hWindow, &ProcessID);

		if (Handle = OpenProcess(PROCESS_VM_READ, 0, ProcessID))
		{
			Client = GetModule("client.dll");
			Server = GetModule("server.dll");
			Engine = GetModule("engine.dll");

			//printf_s("0x%X\n", Server);
		}
		else
		{
			MessageBox(0, "Cannot open the process!", "Error!", MB_OK | MB_ICONERROR);
			exit(1);
		}
	}
}

void read_s::ReadMemory()
{
	if (Handle)
	{
		Read.GetBasePlayer();
		Sleep(1);
	}
}

void read_s::GetBasePlayer()
{
	GetMemory((LPVOID)(Client + Address.BasePlayer), &ClientRef, sizeof(DWORD));
	GetMemory((LPVOID)(Client + Address.RadarBase), &RadarRef, sizeof(DWORD));
	GetMemory((LPVOID)(ClientRef), &CBasePlayer, sizeof(CBasePlayer_s));
}

void read_s::GetRadarBase(int i)
{
	GetMemory((LPVOID)(RadarRef + (i * 0x140)), &RadarArray[i], sizeof(RadarArray_s));
}

void read_s::GetMemory(LPVOID offset, LPVOID buffer, DWORD size)
{
	ReadProcessMemory(Handle, offset, buffer, size, 0);
}

DWORD read_s::GetModule(char * module)
{
	DWORD Output;
	MODULEENTRY32 Entry;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcessID);

	if (Module32First(hSnap, &Entry))
	{
		while (Module32Next(hSnap, &Entry))
		{
			if (strcmp(Entry.szModule, module) == false)
			{
				Output = (DWORD)Entry.modBaseAddr;
				break;
			}
		}
	}
	return Output;
}
