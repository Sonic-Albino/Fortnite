#include <Windows.h>
#include <iostream>
#include "memory.h"
#include "vector.h"
#include "Offsets.h"

//-------------------

auto app = Memory{ "csgo.exe" };
auto client = app.GetModuleAddress("client.dll");
auto engine = app.GetModuleAddress("engine.dll");

//-------------------

#define FL_ONGROUND (1 << 0)
#define JUMP 6
#define DONT_JUMP 4

//-------------------

bool Run = true;
bool Menu_update = false;

//-------------------

DWORD Player(DWORD varient)
{
	return app.Read<DWORD>(client + dwEntityList + varient * 0x10);
}

DWORD PlayerTeam(DWORD varient)
{
	return app.Read<DWORD>(Player(varient) + m_iTeamNum);
}

DWORD LocalPlayer()
{
	return app.Read<DWORD>(client + dwLocalPlayer);
}

DWORD LocalTeam()
{
	return app.Read<DWORD>(LocalPlayer() + m_iTeamNum);
}

DWORD Flags(DWORD varient)
{
	return app.Read<DWORD>(varient + m_fFlags);
}

DWORD CrosshairID()
{
	return app.Read<DWORD>(LocalPlayer() + m_iCrosshairId);
}

DWORD Fov()
{
	return app.Read<DWORD>(LocalPlayer() + m_iDefaultFOV);
}

DWORD Attack()
{
	app.Write<DWORD>(client + dwForceAttack, 6);
	Sleep(1);
	app.Write<DWORD>(client + dwForceAttack, 4);
	return 0;
}

Vector3 AimPunch()
{
	return app.Read<Vector3>(LocalPlayer() + m_aimPunchAngle) * 2;
}

DWORD Health(DWORD varient)
{
	return app.Read<DWORD>(varient + m_iHealth);
}

DWORD ClientState()
{
	return app.Read<DWORD>(engine + dwClientState);
}

DWORD GlowObject()
{
	return app.Read<DWORD>(client + dwGlowObjectManager);
}

DWORD GlowIndex(DWORD varient)
{
	return app.Read<DWORD>(Player(varient) + m_iGlowIndex);
}

Vector3 ViewAngles()
{
	return app.Read<Vector3>(ClientState() + dwClientState_ViewAngles);
}

//-------------------

void Clear()
{
	system("cls");
}

void Bhop()
{

	if (!LocalPlayer())
		return;

	if (GetAsyncKeyState(VK_SPACE))
	{
		if (Flags(LocalPlayer()) & FL_ONGROUND)
			app.Write<DWORD>(client + dwForceJump, JUMP);
		else
			app.Write<DWORD>(client + dwForceJump, DONT_JUMP);
	}

}

bool Trigger()
{
	static int time = 0;
	//static int return_time = 0;


	if (!GetAsyncKeyState(VK_XBUTTON1) & 1)
		return false;

	if (!LocalPlayer())
		return false;

	

	for (int i = 0; i < 32; i++)
	{

		DWORD crosshair = CrosshairID();

		if (crosshair != 0 && crosshair < 64)
		{
			time++;

			if (PlayerTeam(crosshair - 1) == LocalTeam())
				continue;

			if (time >= 1)
			{
				Attack();
				time = 0;
			}
		}
	}

	//if (return_time >= 70)
	//{
	//	return_time = 0;
	//	time = 0;
	//}
	//else
	//{
	//	return_time++;
	//}

	return true;
}

bool Radar_Reveal()
{
	static bool work = true;

	if (!LocalPlayer())
		return false;

	if (GetAsyncKeyState(VK_HOME) & 1)
	{
		work = !work;
		Menu_update = true;
	}

	if (!work)
		return false;

	for (int i = 0; i < 32; i++)
	{
		DWORD e = Player(i);

		if (e == NULL)
			continue;

		app.Write<bool>(e + m_bSpotted, true);
	}

	return true;
}

void Custom_Fov()
{

	if (!LocalPlayer())
		return;

	if (GetAsyncKeyState(VK_UP) & 1)
	{
		if (Fov() + 10 > 160)
			return;

		app.Write<DWORD>(LocalPlayer() + m_iDefaultFOV, Fov() + 10);
		Menu_update = true;

	}
	else if (GetAsyncKeyState(VK_DOWN) & 1)
	{
		if (Fov() - 10 < 10)
			return;

		app.Write<DWORD>(LocalPlayer() + m_iDefaultFOV, Fov() - 10);
		Menu_update = true;

	}
	else if (GetAsyncKeyState(VK_RIGHT) & 1) //Camera Roll
	{

		app.Write<Vector3>(ClientState() + dwClientState_ViewAngles, { ViewAngles().x, ViewAngles().y, ViewAngles().z + 10 });
		Menu_update = true;

	}
	else if (GetAsyncKeyState(VK_LEFT) & 1) //Camera Roll
	{

		app.Write<Vector3>(ClientState() + dwClientState_ViewAngles, { ViewAngles().x, ViewAngles().y, ViewAngles().z - 10 });
		Menu_update = true;

	}

}

bool AutoFire()
{
	static bool work = false;

	if (!LocalPlayer())
		return false;

	if (GetAsyncKeyState(VK_F1) & 1)
	{
		work = !work;
		Menu_update = true;
	}

	if (work)
	{

		if (GetAsyncKeyState(VK_LBUTTON))
			Attack();

		return true;
	}
	else
		return false;

}

bool AntiFlash()
{
	static bool work = false;

	if (!LocalPlayer())
		return false;

	if (GetAsyncKeyState(VK_F2) & 1)
	{
		work = !work;
		Menu_update = true;
	}

	if (work)
	{
		app.Write<float>(LocalPlayer() + m_flFlashMaxAlpha, 0.0f);

		return true;
	}
	else
	{
		app.Write<float>(LocalPlayer() + m_flFlashMaxAlpha, 255.0f);

		return false;
	}
}

void Glow()
{
	static bool work = false;

	if (!LocalPlayer())
		return;
	
	if (GetAsyncKeyState(VK_F4) & 1)
	{
		work = !work;
		Menu_update = true;
	}

	if (work)
	{
		//m_iGlowIndex
		//dwGlowObjectManager

		for (int i = 0; i != 32; i++)
		{
			if (PlayerTeam(i) == LocalTeam())
				continue;

			DWORD Player_temp = Player(i);

			app.Write<DWORD>(GlowObject() + (GlowIndex(i)*38) + 0x4, 1);
			app.Write<DWORD>(GlowObject() + (GlowIndex(i)*38) + 0x8, 0);
			app.Write<DWORD>(GlowObject() + (GlowIndex(i)*38) + 0xC, 0);
			app.Write<DWORD>(GlowObject() + (GlowIndex(i)*38) + 0x14, 1);
		}
	}
}

//void SkinChanger()
//{
//
//	m_nFallbackPaintKit;
//	m_nFallbackSeed;
//	m_nFallbackStatTrak;
//	m_hActiveWeapon;
//	m_hMyWeapons;
//
//	//if (!LocalPlayer())
//	//	return;
//
//	DWORD My_weapons = app.Read<DWORD>(LocalPlayer() + m_hMyWeapons);
//
//	for (int i = 0; i != 3; i++)
//	{
//		DWORD Active_Weapon = app.Read<DWORD>(LocalPlayer() + m_hActiveWeapon);
//
//		if (My_weapons == Active_Weapon)
//		{
//			app.Write<DWORD>(i);
//			
//		}
//	}
//	
//}

void Menu()
{
	if (!Menu_update)
		return;

	Clear();

	std::cout << "--> Features <--" << "	 --> Keys <--\n\n";

	std::cout << "Custom Fov --> " << Fov() << "\n";

	std::cout << "Camera Roll --> " << ViewAngles().z << "	  (< and >)" << "\n";

	std::cout << "AntiFlash --> " << ((AntiFlash() && Run) ? "On" : "Off") << "	  (F2)" << "\n";

	std::cout << "Radar Reveal --> " << ((Radar_Reveal() && Run) ? "On" : "Off") << "	  (Home)" << "\n";

	std::cout << "Trigger --> " << ((Trigger() && Run) ? "On" : "Off") << "		  (Mouse4)" << "\n";

	std::cout << "AutoFire --> " << ((AutoFire() && Run) ? "On" : "Off") << "	  (F1)" << "\n";


	std::cout << "\nMaster Switch --> " << (Run ? "On" : "Off") << "	  (Insert)" << "\n";
	Menu_update = false;

}

void Reset()
{
	if (!LocalPlayer())
		return;
	app.Write<DWORD>(LocalPlayer() + m_iDefaultFOV, 90); //Custom Fov
	app.Write<Vector3>(ClientState() + dwClientState_ViewAngles, { ViewAngles().x, ViewAngles().y, 0 }); //Camera Roll
	app.Write<float>(LocalPlayer() + m_flFlashMaxAlpha, 255.0f); //AntiFlash

}

//-------------------

void KillSteam()
{
	system("taskkill /f /im steamservice.exe");
	Clear();
}

void KillSteamProcesses()
{
	system("taskkill /f /im steamwebhelper.exe");
	system("taskkill /f /im GameOverlayUI.exe");
	Clear();
}

void Find_CSGO()
{
	while (!client)
	{
		Clear();
		std::cout << "Waiting csgo." << std::endl;
		Sleep(500);
		Clear();
		std::cout << "Waiting csgo.." << std::endl;
		Sleep(500);
		Clear();
		std::cout << "Waiting csgo..." << std::endl;
		Sleep(500);
		Clear();

		KillSteam();
		KillSteamProcesses();
		
		app = Memory{ "csgo.exe" };
		client = app.GetModuleAddress("client.dll");
		engine = app.GetModuleAddress("engine.dll");
	}
}

void Draw_Setup()
{
	Clear();
	std::cout << "--> External By S0nic <-- " << "\n\n";

	std::cout << "Client.dll --> " << "0x" << client << "\n";
	std::cout << "Engine.dll --> " << "0x" << engine << "\n";
}

int main()
{
	SetConsoleTitleA("--> Start as admin <--");

	Find_CSGO();

	KillSteam();
	KillSteamProcesses();
	
	SetConsoleTitleA("External By S0nic");

	Draw_Setup();

	Sleep(1000);

	if (LocalPlayer())
		Reset();

	Menu_update = true;
	Menu();

	int loop_time = 0;

	while (!GetAsyncKeyState(VK_END) && app.GetModuleAddress("client.dll"))
	{

		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			Run = !Run;

			if (LocalPlayer())
				Reset();

			Menu_update = true;
			Menu();
		}

		if (!Run)
			continue;

		if (LocalPlayer())
		{
			Menu();
			Bhop();
			Custom_Fov();
			Radar_Reveal();
			Trigger();
			AutoFire();
			AntiFlash();
			//Glow();
			//SkinChanger();
		}
		else
		{
			Sleep(5000);
		}

		Sleep(1);

		if (loop_time >= 1000)
		{
			KillSteam();
			Menu_update = true;
			Menu();
			loop_time = 0;
		}

		loop_time++;
	}

	Reset();

	KillSteam();
	KillSteamProcesses();
}